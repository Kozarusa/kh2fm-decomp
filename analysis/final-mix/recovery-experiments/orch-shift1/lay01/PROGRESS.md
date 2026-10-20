# lay01 progress
start 2026-10-12T17:32:03Z
R0 done; claims so far: 0/6
claim 001144e8 token 360b21278a6e492788d519437b45e28d attempts 2 (claim 1/6) blocker rec04/001144e8-BLOCKED.md
v1: 2 words, first diff at 1: C10 (sd a1 spill after lw) -> next: C10a reorder result=0 before entries load
v2: 2 words, first diff at 1: C10 (no change from reorder) -> next: C10d asm memory barrier at entry (C10b/c not applicable: no explicit stores)
v3: 0 words exact (C10d barrier)
submitted 001144e8 v3
claim 0017c0a0 token 9f669331703641eeb6a09c9048fc962e attempts 4 (claim 2/6) queue aggregate-abi-layout
0017c0a0 v1 = copy of recovery_c_0017c0a0_17ec437b_v2.cpp (2 words)
v1: 2 words, first diff at 3: a0/a2 arg setup order (C11a-like) -> next: blocker hypothesis: model output buffer as named aggregate return + by-value pass (copy at sp+16)
v2: 15 words (RVO removed copy; worse) -> next: explicit out pointer + by-value pass of addressable local (compiler-made copy, no lq/sq asm)
v3: 23 words (no copy, frame 48) -> next: aggregate return assigned into named local, pass &local (return temp + compiler copy)
v4: 7 words (natural copy, slots rotated) -> R7: 3 versions without beating 2; block
blocked 0017c0a0 -> address-materialization
claim 00127f40 token fd1cbd744bd04dd3abe15c765b6b07ab attempts 3 (claim 3/6) queue constructor-buffer-alias
v1: 23 words, 116/120, first diff at 5: no reload of header->end, stores reordered (C9/C10, header alias) -> next: header fields volatile (C9)
v2: 26 words (volatile adds masks; worse) -> next: back to v1 + C10d asm memory barrier after buffer origin store
v3: 22 words, 120/120, first diff at 5: barrier blocks ld ra hoist; original has true alias not barrier (C10d) -> next: targeted asm dependency: header->end modified after reading object->buffer (no full barrier)
v4: 22 words (targeted asm; no gain) -> next: from v1, C10c make Object store fields volatile
v5: 20 words, 116/120, stores now ordered; first diff at 5 -> next: C9 read header->offset as volatile so it follows the stores
v6: 21 words, 116/120 (tail lw offset now after stores; missing end reload) -> next: C11d second end read through an asm-opaque copy of header so CSE keeps the reload
v7: 24 words (opaque copy adds move; worse) -> next: v6 + targeted asm (+m header->end, m object->buffer) after origin store
v8: 17 words, 120/120, first diff at 10: start load sinks after origin store (C10) -> next: asm tying count before origin store (+m object->buffer, r count)
v9: 16 words, first diff at 5: vtable store sinks below start/end loads (C10) -> next: asm tying start/end loads after the table store
v10: 13 words, first diff at 11: end loaded before start, count reg t6 vs a1 (C11) -> next: C11a read start into its own variable first
v11: 13 words (identical; no gain) -> next (last, budget 12): from v10, C11b separate first/second/third variables
v12: 10 words (best); budget 12 reached -> block store-order
blocked 00127f40 -> store-order
claim 001c2ce8 token c209309c22ea43a6a171eed9eb81ee1d attempts 5 (claim 4/6) queue constructor-final-store-alias
001c2ce8 v1 = copy of eight_hour_001c2ce8_revisit_store_order_2.cpp with Ghidra names renamed
v1: 2 words, first diff at 14: final table/mode stores swapped (C10) -> next: blocker hypothesis canonical struct field layout (typed table pointer, natural |= order)
v2: 7 words (struct form swaps regs too; worse) -> next: v1 + non-volatile asm +m(mode field) : m(table field) between the final stores (C10)
v3: 2 words (asm tie had no effect) -> next: C10a source order flags, table, then mode read-modify-write (raw casts)
v4: 7 words; R7 3 versions without beating 2 -> block store-order
blocked 001c2ce8 -> store-order
claim 001c2c98 token b5c8e4ae47094624b89b09d3a52b8d2b attempts 6 (claim 5/6) queue constructor-final-store-alias
001c2c98 v1 = copy of eight_hour_001c2c98_revisit_store_order_2.cpp with names fixed
v1: 2 words, first diff at 14: final stores swapped (C10) -> next: asm +r(mode) : m(table field) after table store so the mode store data-depends on it
v2: 11 words (mode tie works but table store now floats above flags store; regs swapped) -> next: also tie the table value after the flags store
v3: 11 words (store order now exact; regs shifted t4/t5/t6 vs t5/t6/t7, ori late) -> next: C11c bind flags $13, mode $14, table $15
v4: 2 words (stores exact, only ori/addiu swapped); R7 3 versions without beating 2 -> block store-order
blocked 001c2c98 -> store-order
claim 00137c50 token 86d3cf2a154648a487b23c275312942c attempts 2 (claim 6/6 = K) queue initialization-store-groups
00137c50 v1 = copy of eight_hour_00137c50_v3_independent_store_order_7.cpp (3 words)
v1: 3 words, first diff at 6: store order (C10) -> next: non-volatile asm (+m a72 : m group, m a71) so a71 store anti-depends after group, not a barrier (earlier v5 used volatile)
v2: 0 words exact
submitted 00137c50 v2
K=6 claims reached; writing WP report
