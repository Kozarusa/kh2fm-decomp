#!/usr/bin/env python3
"""Hash-bound placement of compiler-generated read-only data pools (tool2 trial).

gcc 3.2 puts jump tables in .rodata and float/double literal pools in .sdata. The full build starts from the
original ELF and only copies linked FUNCTION TEXT over it, so the final ELF always holds the ORIGINAL pool bytes.
What the link must get right is the ADDRESS of the pool (the lui/addiu word pairs of the compiled code). This
module therefore (1) turns a reviewed manifest into linker lines that put the object's pool section at its
original address, (2) checks the manifest against the original SLPM, the function layout and itself before the
link, and (3) after the link asserts that the linked pool bytes equal the original bytes, because `make verify`
compares the output ELF with the original and the output ELF never contains the linked pool bytes: without this
assertion a wrong float literal or jump-table entry would pass verify silently.

Manifest (JSON, always <root>/pool-placements.json; there is deliberately no override):
  {"version": 1, "slpm_sha256": "<sha256 of SLPM_666.75>",
   "entries": [{"function": "002cb188", "section": ".sdata", "address": "00375870", "size": 8,
                "original_sha256": "<sha256 of the original bytes at address..address+size>"}]}
One entry per (registered function, object section). Several functions of the same source that share the
object's section must repeat the identical address/size/hash; the section is placed once.
"""
from __future__ import annotations

import hashlib
import json
import struct
from dataclasses import dataclass
from pathlib import Path

POOL_PREFIXES = (".rodata", ".sdata", ".srodata", ".lit4", ".lit8")
SHF_ALLOC = 0x2
SHT_PROGBITS = 1
R_MIPS_HI16, R_MIPS_LO16 = 5, 6
ENTRY_KEYS = {"function", "section", "address", "size", "original_sha256"}


class PoolError(Exception):
    pass


@dataclass(frozen=True)
class PoolEntry:
    function: int
    section: str
    address: int
    size: int
    sha256: str


@dataclass(frozen=True)
class PoolGroup:
    source: str
    section: str
    address: int
    size: int
    sha256: str
    functions: tuple

    @property
    def out_name(self) -> str:
        return f".kh2pool_{self.address:08x}"


# ------------------------------------------------------------------ minimal ELF32-LE reader
def read_sections(path: Path):
    data = Path(path).read_bytes()
    if data[:6] != b"\x7fELF\x01\x01":
        raise PoolError(f"not a little-endian ELF32: {path}")
    shoff = struct.unpack_from("<I", data, 0x20)[0]
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", data, 0x2E)
    secs = []
    for n in range(shnum):
        nm, ty, fl, ad, off, sz, lk, inf, al, es = struct.unpack_from("<10I", data, shoff + n * shentsize)
        secs.append(dict(name_off=nm, type=ty, flags=fl, addr=ad, off=off, size=sz, link=lk, info=inf, align=al,
                         entsize=es))
    blob = data[secs[shstrndx]["off"]:secs[shstrndx]["off"] + secs[shstrndx]["size"]]
    for s in secs:
        s["name"] = blob[s["name_off"]:].split(b"\0", 1)[0].decode("ascii", "replace")
    return data, secs


def object_pool_sections(obj: Path) -> dict:
    """name -> (size, align) of every allocated pool-like input section of an object file"""
    _data, secs = read_sections(obj)
    return {s["name"]: (s["size"], max(s["align"], 1)) for s in secs
            if s["name"].startswith(POOL_PREFIXES) and s["size"] > 0 and s["flags"] & SHF_ALLOC}


# ------------------------------------------------------------------ manifest load + static checks
def sha(b: bytes) -> str:
    return hashlib.sha256(b).hexdigest()


def _hex8(text, what):
    if not isinstance(text, str) or len(text) != 8 or any(c not in "0123456789abcdef" for c in text):
        raise PoolError(f"{what}: expected 8 lowercase hex digits, got {text!r}")
    return int(text, 16)


def load_manifest(path: Path, slpm: bytes, to_foff, main_vaddr, ctors_vaddr) -> list:
    doc = json.loads(Path(path).read_text())
    if doc.get("version") != 1:
        raise PoolError(f"{path}: unsupported manifest version {doc.get('version')!r}")
    if doc.get("slpm_sha256") != sha(slpm):
        raise PoolError(f"{path}: slpm_sha256 does not match the SLPM in use (manifest is hash-bound to the original)")
    entries = []
    seen = set()
    for row in doc.get("entries", []):
        if set(row) != ENTRY_KEYS:
            raise PoolError(f"{path}: entry keys must be exactly {sorted(ENTRY_KEYS)}: {row}")
        func = _hex8(row["function"], "function")
        addr = _hex8(row["address"], "address")
        size = row["size"]
        section = row["section"]
        if not section.startswith(POOL_PREFIXES):
            raise PoolError(f"{row}: section must start with one of {POOL_PREFIXES}")
        if not isinstance(size, int) or size <= 0 or size % 4 or addr % 4:
            raise PoolError(f"{row}: size/address must be positive multiples of 4")
        if addr < main_vaddr or addr + size > ctors_vaddr:
            raise PoolError(f"{row}: pool must lie inside the main segment data below .ctors (0x{ctors_vaddr:08x})")
        want = slpm[to_foff(addr):to_foff(addr) + size]
        if len(want) != size or sha(want) != row["original_sha256"]:
            raise PoolError(f"{row}: original_sha256 does not match the original bytes at 0x{addr:08x}")
        key = (func, section)
        if key in seen:
            raise PoolError(f"duplicate entry for function {func:08x} section {section}")
        seen.add(key)
        entries.append(PoolEntry(func, section, addr, size, row["original_sha256"]))
    return entries


def build_groups(entries, cxx_sources: dict, boundaries, by_source: dict) -> list:
    """Group by (source object, section); check registration, consistency and all overlaps.

    by_source is the build's {source: [(addr, symbol)]} map of registered C++ rows that also exist in layout.tsv;
    normalize only asserts pools of sources in it, so every entry function and every group source must be there."""
    in_by_source = {addr for rows in by_source.values() for addr, _sym in rows}
    groups: dict = {}
    for e in entries:
        source = cxx_sources.get(e.function)
        if source is None:
            raise PoolError(f"function {e.function:08x} is not a registered C++ function in layout_status")
        if e.function not in in_by_source:
            raise PoolError(f"function {e.function:08x} has no layout.tsv row, its pool would never be asserted")
        groups.setdefault((source, e.section), []).append(e)
    out = []
    for (source, section), es in sorted(groups.items()):
        first = es[0]
        for e in es:
            if (e.address, e.size, e.sha256) != (first.address, first.size, first.sha256):
                raise PoolError(f"{source} {section}: functions disagree about the placement of one object section")
        if source not in by_source:
            raise PoolError(f"{source}: not a source with layout rows, its pool would never be asserted")
        out.append(PoolGroup(source, section, first.address, first.size, first.sha256,
                             tuple(sorted(e.function for e in es))))
    # key is (start, end) only: PoolGroup is not orderable, identical ranges must reach the overlap check
    spans = sorted(((g.address, g.address + g.size, g) for g in out), key=lambda t: (t[0], t[1]))
    for (a0, a1, g0), (b0, b1, g1) in zip(spans, spans[1:]):
        if b0 < a1:
            raise PoolError(f"pool overlap: {g0.source}:{g0.section} [{a0:08x},{a1:08x}) vs "
                            f"{g1.source}:{g1.section} [{b0:08x},{b1:08x})")
    for g in out:
        for b in boundaries:
            if g.address < b.addr + b.size and b.addr < g.address + g.size:
                raise PoolError(f"{g.source}:{g.section} [{g.address:08x},{g.address + g.size:08x}) overlaps function "
                                f"range {b.addr:08x}+{b.size}")
    return out


def check_objects(groups, root: Path, src_to_obj) -> None:
    """The compiled object must contain the section with exactly the manifest size and a compatible alignment."""
    for g in groups:
        obj = root / src_to_obj(g.source)
        if not obj.exists():
            raise PoolError(f"{g.source}: object {obj} missing; compile before generating link sections")
        pools = object_pool_sections(obj)
        if g.section not in pools:
            raise PoolError(f"{g.source}: object has no {g.section} (has {sorted(pools)})")
        size, align = pools[g.section]
        if size != g.size:
            raise PoolError(f"{g.source}:{g.section}: compiled section is {size} bytes, manifest says {g.size}")
        if g.address % align:
            raise PoolError(f"{g.source}:{g.section}: address {g.address:08x} violates section alignment {align}")


def ld_lines(groups, src_to_obj) -> list:
    lines = []
    for g in groups:
        lines.append(f"  {g.out_name} 0x{g.address:08x} : {{\n")
        lines.append(f"    KEEP(*{src_to_obj(g.source)}({g.section}))\n")
        lines.append("  }\n")
    return lines


# ------------------------------------------------------------------ post-link hard assertion
def verify_linked(linked_elf: Path, groups, slpm: bytes, to_foff) -> list:
    """Return a list of error strings; empty means every placed pool is byte-identical to the original."""
    data, secs = read_sections(linked_elf)
    counts: dict = {}
    for s in secs:
        counts[s["name"]] = counts.get(s["name"], 0) + 1
    by_name = {s["name"]: s for s in secs}
    errors = []
    for g in groups:
        s = by_name.get(g.out_name)
        if s is None:
            errors.append(f"{g.source}:{g.section}: linked ELF has no {g.out_name}")
            continue
        if counts[g.out_name] != 1:
            errors.append(f"{g.source}:{g.section}: linked ELF has {counts[g.out_name]} sections named {g.out_name}")
            continue
        if s["type"] != SHT_PROGBITS or not s["flags"] & SHF_ALLOC:
            errors.append(f"{g.source}:{g.section}: {g.out_name} has type {s['type']} flags {s['flags']:#x}, "
                          "expected PROGBITS with SHF_ALLOC")
            continue
        got = data[s["off"]:s["off"] + s["size"]]
        want = slpm[to_foff(g.address):to_foff(g.address) + g.size]
        if s["addr"] != g.address or len(got) != g.size:
            errors.append(f"{g.source}:{g.section}: linked at 0x{s['addr']:08x} size {len(got)}, "
                          f"expected 0x{g.address:08x} size {g.size}")
        elif got != want or sha(got) != g.sha256:
            diff = [i for i in range(0, g.size, 4) if got[i:i + 4] != want[i:i + 4]]
            errors.append(f"{g.source}:{g.section} @ {g.address:08x}: placed bytes differ from the original in "
                          f"{len(diff)} word(s), first at +0x{diff[0]:x}: linked {got[diff[0]:diff[0] + 4].hex()} "
                          f"original {want[diff[0]:diff[0] + 4].hex()}")
    return errors


# ------------------------------------------------------------------ derivation (same method as probe_auto.py)
def _sext16(v):
    return v - 0x10000 if v & 0x8000 else v


def derive_for_function(obj: Path, text_section: str, func_addr: int, slpm: bytes, to_foff) -> tuple:
    """Return (list of (section, base, size), notes) for one function's text section in a compiled object."""
    data, secs = read_sections(obj)
    pools = {s["name"]: s for s in secs
             if s["name"].startswith(POOL_PREFIXES) and s["size"] > 0 and s["flags"] & SHF_ALLOC}
    by_name = {s["name"]: s for s in secs}
    tsec = by_name[text_section]
    bases: dict = {}
    notes = []
    for s in secs:
        if s["type"] != 9 or secs[s["info"]]["name"] != text_section:
            continue
        symsec = secs[s["link"]]
        for k in range(s["size"] // 8):
            r_off, r_info = struct.unpack_from("<II", data, s["off"] + k * 8)
            idx, ty = r_info >> 8, r_info & 0xFF
            st_value, st_shndx = struct.unpack_from("<I", data, symsec["off"] + idx * 16 + 4)[0], \
                struct.unpack_from("<H", data, symsec["off"] + idx * 16 + 14)[0]
            if ty in (R_MIPS_HI16, R_MIPS_LO16) and 0 < st_shndx < len(secs) and secs[st_shndx]["name"] in pools:
                bases.setdefault(secs[st_shndx]["name"], []).append((r_off, ty, st_value))
    found: dict = {}
    for name, rels in bases.items():
        rels.sort()
        last_hi = None
        for r_off, ty, st_value in rels:
            w = struct.unpack_from("<I", data, tsec["off"] + r_off)[0]
            ow = struct.unpack_from("<I", slpm, to_foff(func_addr) + r_off)[0]
            if ty == R_MIPS_HI16:
                last_hi = (w & 0xFFFF, ow & 0xFFFF)
            elif last_hi is None:
                notes.append(f"{name}: LO16 at +{r_off:#x} without preceding HI16")
            else:
                comp = (last_hi[0] << 16) + _sext16(w & 0xFFFF)
                orig = (last_hi[1] << 16) + _sext16(ow & 0xFFFF)
                found.setdefault(name, {}).setdefault((orig - comp + st_value) & 0xFFFFFFFF, []).append(r_off)
    result = []
    for name, cands in found.items():
        if len(cands) > 1:
            notes.append(f"{name}: inconsistent derived bases {sorted(hex(b) for b in cands)} "
                         "(code differs from the original beyond addresses; do not trust)")
            continue
        base = next(iter(cands))
        result.append((name, base, pools[name]["size"]))
    for name in pools:
        if name not in found:
            notes.append(f"{name}: no HI16/LO16 reference from {text_section}, base not derivable here")
    return result, notes
