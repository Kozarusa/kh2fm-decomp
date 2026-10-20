"""Offline corpus census: learn GCC's if/else arm-inlining rule from REAL exact matches.

No compiler and no Docker required.  The trick: for every function the primary has
already recovered byte-exactly, the ORIGINAL bytes on the disc ARE what the source
must reproduce.  So we can read the original instruction stream straight out of
SLPM_666.75, see which arm GCC made the fall-through, and correlate that with the
polarity the recovered source spells.  With thousands of exact matches this turns a
guess about the assigned targets into a measured rule.

Addresses: analysis/final-mix/native-build/compiler-range-verification.json rows with
unmodified_compiled_symbol_match true.  Sources: /root/kh2fm-build/src/**.cpp
(docker/tools/src/anon on the Windows side is a stale mirror - the real src tree
lives in the Linux stage).  Image: /root/kh2fm-build/SLPM_666.75.

Run under WSL:
  MSYS_NO_PATHCONV=1 wsl -d Ubuntu-24.04 -u root -- python3 \
    /mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/worker-coordination/worker-b/round-4/census_polarity.py
"""

import json
import os
import re
import sys
from collections import defaultdict

STAGE = "/root/kh2fm-build"
WORKSPACE = "/mnt/c/Users/KoZa/Documents/AGENTS/Codex"  # project root after the 2026-10-08 move to AGENTS/Codex
ELF = os.path.join(STAGE, "SLPM_666.75")
VERIF = os.path.join(WORKSPACE, "analysis/final-mix/native-build/compiler-range-verification.json")


def addr_to_off(addr):
    return addr - 0x100000 + 0x1000


def be32(blob, off):
    # THE DISC IS LITTLE-ENDIAN ON DISK.  ee-objdump prints big-endian words, which
    # is exactly the trap that made an earlier version of this script report 4247 of
    # 4249 "branch targets" outside their own function.  Do not "fix" this to big.
    return int.from_bytes(blob[off:off + 4], "little")


def w_off(w):
    """Sign-extended 16-bit branch displacement."""
    v = w & 0xFFFF
    return v - 0x10000 if v & 0x8000 else v


# --------------------------------------------------------------- decode bits
def op(w):
    return w >> 26


def rs(w):
    return (w >> 21) & 0x1F


def rt(w):
    return (w >> 16) & 0x1F


def is_call(w):
    return op(w) == 3            # jal


def branch_info(w):
    """Return (kind, tests_zero) for conditional branches, else None."""
    o = op(w)
    if o == 4:
        return ("beq", rs(w) == 0 or rt(w) == 0)
    if o == 5:
        return ("bne", rs(w) == 0 or rt(w) == 0)
    if o == 6:
        return ("blez", True)
    if o == 7:
        return ("bgtz", True)
    if o == 1:
        rt_ = rt(w)
        if rs(w) in (0, 16):          # bltz / bltzal
            return ("bltz", True)
        if rs(w) in (1, 17):          # bgez / bgezal
            return ("bgez", True)
    return None


# --------------------------------------------------------------- source bits
FUNC_HEAD = re.compile(r"\bfunc_([0-9a-f]{8})\s*\(")


def strip_comments(t):
    t = re.sub(r"/\*.*?\*/", " ", t, flags=re.S)
    t = re.sub(r"//[^\n]*", " ", t)
    return t


def function_bodies(path):
    """address -> body text, for every func_<8hex> defined in one source file."""
    try:
        text = strip_comments(open(path, encoding="utf-8", errors="replace").read())
    except OSError:
        return {}
    out = {}
    for m in FUNC_HEAD.finditer(text):
        addr = m.group(1)
        i = text.find("{", m.end())
        if i < 0:
            continue
        depth = 0
        end = None
        for j in range(i, len(text)):
            c = text[j]
            if c == "{":
                depth += 1
            elif c == "}":
                depth -= 1
                if depth == 0:
                    end = j
                    break
        if end is not None:
            out.setdefault(addr, text[m.start():end + 1])
    return out


CALL_RE = re.compile(r"\b(func_[0-9a-f]{8}|FUN_[0-9a-f]{8})\s*\(")


def polarity(body):
    """Which zero-test the source spells at the top level."""
    if re.search(r"if\s*\([^()]*?==\s*0\s*\)", body):
        return "== 0"
    if re.search(r"if\s*\([^()]*?!=\s*0\s*\)", body):
        return "!= 0"
    return None


def if_else_arms(body):
    """Split a simple `if (cond) {A} else {B}` into (cond, A, B)."""
    m = re.search(r"\bif\s*\(", body)
    if not m:
        return None
    i = body.index("(", m.start())
    depth = 0
    cond_end = None
    for j in range(i, len(body)):
        if body[j] == "(":
            depth += 1
        elif body[j] == ")":
            depth -= 1
            if depth == 0:
                cond_end = j
                break
    if cond_end is None:
        return None
    k = body.find("{", cond_end)
    if k < 0:
        return None
    depth = 0
    arm_end = None
    for j in range(k, len(body)):
        if body[j] == "{":
            depth += 1
        elif body[j] == "}":
            depth -= 1
            if depth == 0:
                arm_end = j
                break
    if arm_end is None:
        return None
    tail = body[arm_end + 1:]
    em = re.match(r"\s*else\b", tail)
    if not em:
        return None
    b = tail.find("{", em.end())
    if b < 0:
        return None
    depth = 0
    bend = None
    for j in range(b, len(tail)):
        if tail[j] == "{":
            depth += 1
        elif tail[j] == "}":
            depth -= 1
            if depth == 0:
                bend = j
                break
    if bend is None:
        return None
    return (body[i + 1:cond_end], body[k + 1:arm_end], tail[b + 1:bend])


def main():
    blob = open(ELF, "rb").read()
    rows = json.load(open(VERIF))
    if isinstance(rows, dict):
        rows = rows.get("rows")

    by_src = defaultdict(list)
    for r in rows:
        if not r.get("unmodified_compiled_symbol_match"):
            continue
        if not r.get("source"):
            continue
        by_src[r["source"]].append((r["address"], r.get("declared_range_size") or 0))

    total = 0
    readable = 0
    stats = defaultdict(int)
    tally = defaultdict(int)
    detail = []

    for rel, entries in sorted(by_src.items()):
        path = os.path.join(STAGE, rel)
        if not os.path.exists(path):
            continue
        readable += len(entries)
        bodies = function_bodies(path)
        if not bodies:
            continue
        for addr, size in entries:
            total += 1
            body = bodies.get(addr)
            if not body:
                continue
            arms = if_else_arms(body)
            if not arms:
                stats["no if/else"] += 1
                continue
            cond, then_txt, else_txt = arms
            # Relaxed: do NOT require both arms to call.  The exact corpus is
            # dominated by leaf wrappers, so the strict filter had zero instances.
            # The question that matters is: when the source spells an explicit
            # == 0 / != 0 test, which arm does GCC leave inline?
            ce = CALL_RE.findall(then_txt) + CALL_RE.findall(else_txt)
            pol = polarity(cond + ")")
            if pol is None:
                stats["no == 0 / != 0 spelling"] += 1
                continue
            if size < 16 or size % 4:
                stats["bad size"] += 1
                continue
            off = addr_to_off(int(addr, 16))
            ws = [be32(blob, off + 4 * k) for k in range(size // 4)]
            br = None
            for i, w in enumerate(ws):
                if branch_info(w):
                    br = i
                    break
            if br is None or br + 1 >= len(ws):
                stats["no conditional branch in original"] += 1
                continue
            kind, zero = branch_info(ws[br])
            # Where does the branch GO?  If the target is inside this function and
            # past the delay slot, the ELSE arm was emitted out of line, so the
            # fall-through is the THEN arm -- standard C semantics, and inverting
            # == 0 / != 0 in the source swaps which arm that is.  If the target is
            # outside the range (or before the branch) GCC swapped the arms.
            off16 = w_off(ws[br])
            target = (addr + 4 * (br + 1) + 4 * off16) & 0xFFFFFFFF
            lo, hi = addr, addr + size
            swapped = not (lo <= target < hi) or target <= addr + 4 * (br + 1)
            stats["analysed"] += 1
            tally[(pol, kind, "SWAPPED" if swapped else "standard")] += 1
            detail.append((addr, rel, pol, kind,
                           "SWAPPED" if swapped else "standard",
                           "then" if CALL_RE.search(then_txt[:40]) else "else"))

    print(f"exact rows with a source path : {total}")
    print(f"rows whose source was readable : {readable}")
    print("\nfilter funnel:")
    for k in sorted(stats, key=lambda x: -stats[x]):
        print(f"   {k:<38} {stats[k]}")
    print(f"\nsource polarity x emitted branch x arm layout:")
    for k in sorted(tally, key=lambda x: (-tally[x], str(x))):
        print(f"   {k[0]:>6}  {k[1]:>5}  {k[2]:<10} {tally[k]}")
    if not tally:
        print("   (none: the exact corpus contains ZERO functions whose source spells an")
        print("    explicit == 0 / != 0 if/else, so it cannot answer the polarity question)")

    # ---- pass 2: the measurement that DOES generalise ------------------------------
    # For every byte-exact function containing an internal conditional branch, is the
    # branch target inside the function (else-arm emitted out of line, THEN arm inline)
    # or outside it (arms swapped)?  This is the rule the assigned targets 00109e30 and
    # 00242500 depend on, and it is measurable here because an exact match means the
    # original bytes ARE what the recovered source produces.
    seen = inside = outside = 0
    swap_examples = []
    for rel, entries in sorted(by_src.items()):
        if not os.path.exists(os.path.join(STAGE, rel)):
            continue
        for addr, size in entries:
            if size < 16 or size % 4:
                continue
            a = int(addr, 16)
            off = addr_to_off(a)
            ws = [be32(blob, off + 4 * k) for k in range(size // 4)]
            br = None
            for i, w in enumerate(ws):
                if branch_info(w):
                    br = i
                    break
            if br is None:
                continue
            seen += 1
            t = (a + 4 * (br + 1) + 4 * w_off(ws[br])) & 0xFFFFFFFF
            if a <= t < a + size:
                inside += 1
            else:
                outside += 1
                if len(swap_examples) < 20:
                    swap_examples.append((addr, rel, branch_info(ws[br])[0], f"{t:08x}"))
    print(f"\narm-layout census over ALL byte-exact functions with an internal branch:")
    print(f"   conditional branches found      : {seen}")
    print(f"   branch target INSIDE the function: {inside}   (else arm out of line, THEN arm inline)")
    print(f"   branch target OUTSIDE            : {outside}   (arms swapped)")
    for e in swap_examples:
        print("     swapped example:", e)
    arm_stats = (seen, inside, outside)

    out = os.path.join(WORKSPACE, "analysis/final-mix/worker-coordination/worker-b/round-4/polarity_census.txt")
    with open(out, "w", newline="\n") as f:
        f.write(f"exact rows with a source path : {total}\n")
        f.write(f"rows whose source was readable : {readable}\n\nfilter funnel:\n")
        for k in sorted(stats, key=lambda x: -stats[x]):
            f.write(f"   {k:<38} {stats[k]}\n")
        f.write("\nsource polarity x emitted branch x arm layout:\n")
        for k in sorted(tally, key=lambda x: (-tally[x], str(x))):
            f.write(f"{k[0]:>6} {k[1]:>5} {k[2]:<10} {tally[k]}\n")
        f.write("\naddress source polarity branch layout inline-arm\n")
        for d in detail:
            f.write(" ".join(str(x) for x in d) + "\n")
        f.write(f"\narm-layout census over ALL byte-exact functions with an internal branch:\n")
        f.write(f"conditional branches found       : {arm_stats[0]}\n")
        f.write(f"branch target INSIDE the function : {arm_stats[1]}  (else out of line, THEN inline)\n")
        f.write(f"branch target OUTSIDE             : {arm_stats[2]}  (arms swapped)\n")
    print("\nwrote", out)


if __name__ == "__main__":
    main()