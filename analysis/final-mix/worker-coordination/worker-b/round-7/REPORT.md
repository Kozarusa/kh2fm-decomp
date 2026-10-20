# Worker B — Round 7 Report

Date: 2026-10-08
Assignment: 10 unregistered ranges picked by `round-7/pick_targets.py` (framed targets only — functions opening with `addiu sp,sp,-N` and containing at least one `sd`/`ld`, size 20–120 B, excluding every worker-B round-1..6 address and 29 primary-reserved addresses). Picker reported 1195 candidates; 10 disjoint ones were claimed.

All 10 ranges were re-derived from the original ELF
(`SLPM_666.75`, sha256 `d869ce4b8edd61cb978c4ff9ede595fe4d7d7b21cbb96a145275217120d8bc87`),
cross-checked against `/root/kh2fm-build/layout.tsv`, and **all 10 range hashes matched**
(`round-7/r7_range_hashes.txt`, helper `round-7/r7_dump_orig.py`).

## Result: 8 / 10 byte-exact

| address | size | source | proof |
| --- | --- | --- | --- |
| 00196170 | 40 | `fm_worker_b_round7_00196170_solved.cpp` | `…_solved.verification.json` |
| 0023fb00 | 40 | `fm_worker_b_round7_0023fb00_solved.cpp` | `…_solved.verification.json` |
| 002954e0 | 36 | `fm_worker_b_round7_002954e0_solved.cpp` | `…_solved.verification.json` |
| 003062a0 | 32 | `fm_worker_b_round7_003062a0_solved.cpp` | `…_solved.verification.json` |
| 003062c0 | 32 | `fm_worker_b_round7_003062c0_solved.cpp` | `…_solved.verification.json` |
| 003062e0 | 32 | `fm_worker_b_round7_003062e0_solved.cpp` | `…_solved.verification.json` |
| 00306300 | 32 | `fm_worker_b_round7_00306300_solved.cpp` | `…_solved.verification.json` |
| 00366db0 | 32 | `fm_worker_b_round7_00366db0_solved.cpp` | `…_solved.verification.json` |

Every one of the eight has `exact_match: true` and `boundary_agreement: true` in its
own proof file, probed from the promoted `_solved.cpp` copy (not from the exploratory `vNN` file).

Source sha256:

```
00196170 5f91dc9097775384539aefea0d38a9676c8e7b1c7662d3e4669228ec3c9e3cc9
0023fb00 c6a22e3ba4ac96b19c1fad517871b81081590426a807f2cfec3da140847b6ba1
002954e0 1f8599294969142cf541f5b9827b9c408ace5362b71e05b064f598aeafedf29a
003062a0 70e5c38f64ee722281b14118f1b94da89a1531d5453ee1420270e60a62b0ec35
003062c0 8dd691ab2c642a2313d2a4462f8798731b3e927d500251ecc0a23a765c192623
003062e0 9df962b84c186ce0a62ac42c3cad1c9de62e0af7aa9775714d3fe3aa69440a5e
00306300 419c16452c2b71a96df7ea252d730a85c8402e74574b9c822f5fbecd5bf16382
00366db0 ed9442fd3e20f5fcae7745a4181ee1c40b3047a53d2ef4906d413f68dd694175
```

## Mechanisms (reusable)

1. **`asm volatile("sync");`** reproduces a trailing `sync` instruction exactly
   (003062a0/c0/e0/300). The callee must be spelled `func_` + **8** hex digits —
   the probe harness auto-generates `func_<8hex> = 0x<addr>;` linker definitions
   for every such name in the source, and a 7-digit name silently fails to link.
2. **`u16` parameter** puts the `andi a0,a0,0xffff` mask in the callee's delay
   slot (00366db0).
3. **A trailing empty `asm volatile("");`** prevents GCC 3.2 from rewriting the
   second of two sequential calls into a sibling tail call, which keeps the real
   `jal` with `move a0,v0` in its delay slot (002954e0). Without it the function
   is 32 B instead of 36 B.
4. **Global symbols follow the non-carry rule**: with `lui hi / lw|sw lo` the
   declared value must be `(hi << 16) + sign_extend(lo)` with **no** carry
   adjustment between the halves. 0x36ebe0 / 0x36ebec (0023fb00) and
   0x350330 / 0x1c61b00 (00196170) both confirm it against Ghidra's spelling,
   which is one page low.

## Open (compiler-level, not forced with inline asm)

- **00308cd0** — 36/36 bytes, 2 differing words at offsets 16 and 24.
  Compiled `lui t7,0x36` + `sw zero,0x60dc(t7)`; target `lui v0,0x36` +
  `sw zero,0x60dc(v0)`. Everything else matches. Tried: plain `u32` global,
  `volatile u32` global, `*(u32 *)&DAT = 0`, a trailing `asm volatile("")`,
  and an `s32` global — all five emit `$t7`.
- **002b99a0** — target 40 B, best compile 24 B. The target uses the
  frame-pointer idiom for a leaf (`addiu sp,-16; sd s8,0(sp); move s8,sp; …
  move sp,s8; ld s8,0(sp)`) and never saves `ra`; GCC 3.2 -O2 emits either a
  frameless 12-byte body or a 16-byte frame that saves nothing. Forcing a frame
  via the address of a `volatile` local got the size class right but not the
  register choice.

## Isolation / ownership

No compiler-flag changes, no executable byte patching, no shared-stage writes,
no docker restarts. Every artifact below is worker-B-owned: this report,
`round-7/claim.json`, the helper scripts and dumps in `round-7/`, and the
`fm_worker_b_round7_*` sources plus proofs in
`analysis/final-mix/recovery-experiments/`. Stage integration remains primary's.

## Cumulative worker-B exact recoveries

round 2: 4, round 3: 3, round 4: 5, round 5: 5, round 6: 2, round 7: 8 → **27**.
