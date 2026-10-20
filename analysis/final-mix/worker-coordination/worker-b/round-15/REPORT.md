# Worker B — Round 15 report

**Role:** isolated proposals/reports only. Primary retains active sources, `functions.tsv`, `layout.tsv`, stage sync, full builds, manifests, receipts, Ghidra, `HANDOFF.md`.
**Original ELF:** sha256 `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`.
**Claimed:** 16 ranges, all 16 range-hash OK with start/end/size agreeing with `/root/kh2fm-build/layout.tsv` (`r15_ranges.txt`, `r15_range_hashes.txt`, `r15_orig_disasm.txt`).

### One environment note for primary
The reference ELF is staged at **`/root/kh2fm-build/SLPM_666.75`** (same sha256). `/root/kh2fm-build/tools/` contains only `build_elf.py`, `common.py`, `objdiff.py` — there is **no `tools/kh2-reference/` subdirectory**, so any `ee-objdump` invocation pointed at `/work/tools/kh2-reference/SLPM_666.75` fails with "No such file or directory". `round-15/r15_disasm.sh` uses `-v /root/kh2fm-build:/work` and `/work/SLPM_666.75`.

## Result: 6 / 16 byte-exact

| address | bytes | variant | source sha256 |
|---|---|---|---|
| 001618b8 | 56/56 | v03 | `77291da46af7a642091a51ce6e7115b4108987d8e3ced3d7ab7b625a31429ee8` |
| 00167b60 | 56/56 | v02 | `c83b3c212962f0c7eb867e02bb6dec174506587cd70374d3dd9bb0388a352cb4` |
| 00167e70 | 56/56 | v02 | `383708e44e2b500c800967345ae7c1a936c26218fbf064507dfc9a6eab6c438b` |
| 00167ea8 | 56/56 | v02 | `2e735012d84c076ad0a4e965587f1931915826d61234559c4df404d3849afb74` |
| 0019c970 | 56/56 | v02 | `faa4f570194a96e4d05d3bc2db9c11ef99f0441ec9444c3efcb0f9a9d85633c1` |
| 0019c9a8 | 56/56 | v02 | `34012da4ef4f4d73c352051a7421ee13c8f26797369c7665621864a514fcbd95` |

Every one has its own `…_solved.verification.json` with `exact_match: true`, `boundary_agreement: true`, 0 differing words.

## Correction to round 14's note on symbol addresses

Round 14 reported a "page bias: the symbol must sit one page lower when `V & 0xffff >= 0x8000`". That was a misgeneralisation from a `lw` case, and this round's measurements correct it.

The assembler computes `hi = (V + 0x8000) >> 16` and `lo16 = V & 0xffff`, and it reproduces **whatever `(hi, signed lo)` pair you ask for** as long as the symbol sits at

```
V = (hi << 16) + sign_extend(lo)
```

— the **same no-carry value** already used for `lui` + `lw` globals. Verified in both directions:

| target pair | symbol to declare | Ghidra's value |
|---|---|---|
| `lui a2,0x1e` + `addiu a2,a2,-9608` | `func_001dda78` | 0x1dda78 |
| `lui t7,0x1e` + `addiu t7,t7,-9424` | `func_001ddb30` | 0x1ddb30 |
| `lui t7,0x36` + `addiu t7,t7,-3168` | `func_0035f3a0` | 0x35f3a0 |
| `lui a0,0x1e4` + `addiu a0,a0,-29080` | `func_01e38e68` | 0x1e38e68 |
| `lui s0,0x35` + `addiu s0,s0,-11328` | `func_0034d3c0` | 0x34d3c0 |

The `lw`/`sw` case genuinely differs: there the pair must satisfy `hi == V >> 16` exactly, and the conservative `hi` lands one page high whenever `V & 0xffff >= 0x8000`. That is why a symbol named after the **true** address produced `lui t7,0x1d6` + `lw a1,-29296(t7)` in round 14 — a `lw`, not an `addiu`.

**One sharp edge worth flagging:** `func_` names must be exactly **8 hex digits** or the harness does not auto-define them and the link fails. A 7-digit `func_01dda78` is silently undefined.

## The six exact sources

**001618b8** — two symbol-addressed constants; the plain `93000` still takes the `lui` + `ori` path, landing in the `jal` delay slot as the target has it.
```c
iVar1 = func_00102c18(1, 93000, (u32)(long)&func_001dda78);
*(u32 *)(iVar1 + 0x30) = (u32)(long)&func_001ddb30;
```

**00167b60 / 00167e70 / 00167ea8** — one source shape for all three. The callee address is live across both calls, so GCC keeps it in `$s0` exactly as the target does; the trailing empty asm keeps the second call a real `jal`.
```c
u32 uVar1;
uVar1 = (u32)(long)&func_0034d3c0;
func_001678f0(uVar1);
func_001678f0(uVar1 + 384);
asm volatile ("");
```

**0019c970 / 0019c9a8** — byte-identical to each other. The **operand order of the xor is load-bearing**: `(uVar2 ^ uVar1)` gives the target's `xor s0,t7,s0`, and the other order gives `xor s0,s0,t7` — the single word that separated v01 from v02.
```c
uVar1 = param_1;
func_0019cc20();
uVar2 = DAT_00350444;
if ((uVar2 ^ uVar1) == 0) { DAT_00350444 = 0; }
else { DAT_00350444 = uVar2; }
```

## Unresolved, with the measured blocker (10)

| address | best | measured | why |
|---|---|---|---|
| 00198700 | v01 | 52/56 | do/while whose loop variable is the call **result** and whose incoming `a0` is never updated — the target's back-edge delay slot is a `nop`, confirming `a0` is not rewritten. GCC hoists the live-in `move v0,a0` into the prologue above `sd ra`. v02 (callee takes no argument, 48/56), v03 (result in a separate variable, 64/56), v06 (barrier after the prologue, 52/56) all regressed. |
| 001ca950 | v01 | 52/56 | the callee's second value arrives in `$t1` in the `jal` delay slot (`move s1,t1`) — a non-O32 argument register, same not-expressible-in-C class as 002ba3b8, 001231f8, 00158050. |
| 0028b7f8 | v02 | 56/56, **2 words (one swap)** | target `sd s0,0(sp) ; sd ra,8(sp) ; sw t7,0(a0)`; GCC puts the store between the two prologue saves. v03 (barrier after the prologue), v04 (barrier between store and first call), v05 (two barriers) all widened the gap. |
| 00307fe0 | v01 | 56/56, 6 words | only the scratch register holding the third parameter differs — target `move v0,a2` / `move a3,v0`, compiled `move t7,a2` / `move a3,t7`. Frame and every other instruction match. |
| 0030df00 | v02 | 56/56, 7 words | the code constant is exact via the symbol-address mechanism; the rest is the DAT scratch register — target `lui v0,0x36` + `sw v1,24960(v0)`, compiled `lui t6,0x36` + `sw t7,24960(t6)` with −1 materialised into `t7`. **Fourth occurrence of the `$v0`-vs-`$t7` pattern.** |
| 002b7f84, 002b83b4, 002b9968, 002b9a00 | v01 | 28/56 | leaf frame-pointer idiom (`sd s8; move s8,sp; … move sp,s8; ld s8`); 002b7f84 additionally carries a redundant `move t7,v0; move v0,t7` pair the compiler never emits from C. |
| 002b823c | v01 | 36/56 | leaf frame-pointer idiom **and** a `gp`-relative `lw t7,-7460(gp)`, which the probe harness cannot place. |

## Standing observation for primary

The `$v0`-vs-`$t7` scratch-register choice now has **five** independent instances across three rounds — 00308cd0 (r7), 0030a2d0 (r11), 0030a690 (r14), 0018d808 (r14), 0030df00 (r15) — always with the target preferring `$v0` when a global address or a 16-byte move shares a body with a small return value. It is consistent enough to look like a **build-wide register-allocation setting difference** rather than a per-function accident. Worker B cannot set compiler flags, so this is recorded, not chased.