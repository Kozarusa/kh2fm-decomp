# 002006b0 blocked

- Range: `002006b0`, 76 bytes. Versions tried: 11. Best: v10 and v11 with 2 differing words (76/76 bytes); v8 and v9 also 2 words.
- First difference of the best version:

```
!! 002006b4: ffbf0008  sd	ra,8(sp)   | 002006b4: ffb00000  sd	s0,0(sp)
!! 002006b8: ffb00000  sd	s0,0(sp)   | 002006b8: ffbf0008  sd	ra,8(sp)
```

- Changes tried, with differing-word counts after each:
  - v1 baseline: copy of `recovery_b_002006b0_871d6895_v2_bothloads` (volatile nested loads + memory barriers): 2 words, prologue save order `sd s0` then `sd ra` — the historical 2-word wall.
  - v2 C11d: trailing `asm volatile("")` added to that baseline: 2 words, no effect.
  - v3 C9/C12: dropped volatile loads and memory barriers, accepted-sibling `002007e0` shape (`u32*`, `u32` locals, `func_002f3f88(u32,u32)`): 11 words, but prologue order became correct (`sd ra` then `sd s0`) and the second call became a tail call.
  - v4 C13: trailing `asm volatile("")` keeps the second call a real `jal`: 12 words, prologue correct, body shape wrong (load chain in `s0`, second argument computed in `a0`).
  - v5 C11d: `asm volatile("" : "+r"(uVar1))` marker on the loaded pointer: 14 words, no effect, prologue order reverted.
  - v6 C7: second argument written as an explicit `base = base + 176` assignment so it lands in `s0` and is moved to `a0`: 3 words, 76/76 bytes, prologue correct, only the load chain (`s0`/`t7` instead of `t7`/`t6`) and the `addu` operand order differ.
  - v7 C9: volatile outer load: 3 words, no effect.
  - v8 C11c: `register u32 *link asm("$15")` and `register u32 offset asm("$14")`, `base = param_1 + offset`: 2 words, body fully exact, prologue order reverted to `sd s0` then `sd ra`.
  - v9 C11c: bind only `offset` to `$14`, leave `link` to the allocator: 2 words, body exact, prologue order wrong.
  - v10 C11b: no register bindings at all, distinct `link`/`offset`/`base` variables: 2 words, body exact (`lw t7,12(a1)`, `lw t6,4(t7)`, `addu s0,a0,t6`), prologue order wrong.
  - v11 C11c: integer-style `link` instead of a pointer: 2 words, same as v10.
- Why it stops here: budget rule R7 - three consecutive versions (v9, v10, v11) without beating the best differing-word count of 2. Version budget 12 is not the binding constraint; the 3-version stall is.
- Findings worth carrying forward:
  - The whole body (19 minus the two prologue stores) is reproducible: `lw t7,12(a1)`, `lw t6,4(t7)`, `lui a1,0x35`, `addiu a1,a1,0x4bc0`, `addu s0,a0,t6`, `jal`, `addiu a0,s0,160`, `addiu s0,s0,176`, `lui a1,0x35`, `move a0,s0`, `jal`, `addiu a1,a1,0x4be0`, `ld s0,0(sp)`, `ld ra,8(sp)`, `jr ra`, `addiu sp,sp,16`. Version 10 source is the cleanest (no register bindings, no asm except one trailing `asm volatile("")` that is required to stop the second call becoming a tail call).
  - The save-store order flips to the original `sd ra` / `sd s0` exactly when the first callee-saved register the body defines is `s0` (v3, v4, v6, v7) and flips back to `sd s0` / `sd ra` when the load chain legitimately uses `t7`/`t6` first (v8, v9, v10, v11). Register bindings on caller-saved registers (v5, v8, v9) also force `sd s0` first. Frame size 16 and both offsets (`s0` at 0, `ra` at 8) are correct in every version; only the emission order of the two stores is wrong.
  - The prior blocker report's excluded list (incoming-argument memory barriers, typed pointer parameters, volatile nested loads, return-type variants, 64-bit arguments) is confirmed excluded: none of them move the save order.
- Next hypothesis: bind the *callee-saved* value instead of the caller-saved chain - declare `register u32 base asm("$16")` (or add `asm volatile("" : "+r"(base))` immediately after `base = param_1 + offset;`) so `s0`'s save slot is created from an explicit binding while `t7`/`t6` stay naturally allocated. That combination (binding on `s0` instead of on `t7`/`t6`) has not been tried and is the one untried lever that could give both an exact body and `sd ra` first.