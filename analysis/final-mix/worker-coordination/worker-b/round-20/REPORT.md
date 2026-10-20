# Worker B — Round 20

16 unregistered ranges claimed, all 16 verified against the original ELF and against
`/root/kh2fm-build/layout.tsv`.

**Result: 0 exact, 16 unresolved — and a conclusive diagnosis for fifteen of them.**

## What this round established

The batch reduced to two shapes: a **fifteen-member byte-regular family** — every
member is `func_002b6708(2, K, param_1)` for K = 8, 9, 10, 16, 18, 26, 36, 44, 46, 47,
50, 51, 52, 53, 54 — and one singleton, 002b4fb8.

The family's target body is:

```
addiu sp,sp,-32
sd   s8,16(sp)
sd   ra,24(sp)
move s8,sp
sw   a0,0(s8)
li   a0,2
li   a1,K
jal  0x2b6708
lw   a2,0(s8)          <- delay slot
move t7,v0
move v0,t7
move sp,s8
ld   s8,16(sp)
ld   ra,24(sp)
jr   ra
addiu sp,sp,32
```

v02 reproduces the spill exactly — GCC emits `sw a0,0(sp)` and reloads it as
`lw a2,0(sp)` in the `jal` delay slot, in the same positions as the target — but
addresses the frame through **`sp`** and emits no frame-pointer instructions at all.
The target uses **`fp`** throughout and brackets the body with
`sd s8,16(sp)` / `move s8,sp` and `move sp,s8` / `ld s8,16(sp)`.

That difference is exactly what omitting the frame pointer produces, and it is not a
scheduling accident or a spelling I can adjust in C: **these translation units were
built with `-fno-omit-frame-pointer`.** Worker B cannot set compiler flags, so the
class is closed.

This also confirms and enlarges the class first parked in round 7. The four earlier
members — 002b99a0, 002b6ab8, 002b81ec, 002b8214 — plus all fifteen from this round
make **nineteen members** of one build-flag difference. It is now the largest and
best-evidenced remaining class, and it is the clearest case for primary: recovering
these fifteen costs one flag on the original build, not fifteen source reconstructions.

## 002b4fb8 — 64/64, 9 differing words

Two independent faults, neither yet solved:

- The target loads `move v0,zero` before the first test so both branch paths converge
  on a single exit. GCC folds the two branch targets into one `beqz` and drops it.
- The trailing call is rewritten to `j 0x28acc8` even with a trailing
  `asm volatile ("")`, so the target's real `jal` followed by `ld ra` is not
  reproduced.

## Picker lesson

Sixteen addresses were only two compilations. Checking for byte-identical duplicates
and constant-parameterised families *before* writing sources would have made this one
probe instead of thirty-two. The `r20_dump_orig.py` range hashes were the right place
to do it — duplicates show up as identical sha256 values before any source is written.

## Standing position

Unchanged from earlier rounds: `volatile` on a global when the target re-reads it,
plain when it indexes the value it already loaded; trailing `asm volatile ("")` to
block a sibling-call rewrite; symbol values whose high half is truncating
(`V>>16 == hi` and `V&0xffff == lo16`); constants needing `addiu` spelled as the
address of an absolute linker symbol.
