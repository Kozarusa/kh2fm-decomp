# pro02 progress
start 2026-10-12T17:58:21Z
claims: 0/6
claim 001375f0 token 32e40ea5c69d4e3ab6cd02f7923c3a8f attempts 3 (claims 1/6)
v1: copy of pro01 v1, 2 words (addiu t7/sd ra swap) -> next: blocker hypothesis, input-only address use in non-volatile float asm
v2: 6 words, first diff at 4: hypothesis (input-only use) - load folds lo_sum anyway, addiu sinks to delay slot -> next: C11d second +r marker to lengthen addiu priority path
v3: 2 words, first diff at 4: C11d double marker no effect -> next: extra reader of address (asm on second param with address input)
v4: 2 words, first diff at 4: C11 extra address reader no effect -> next: two extra readers (second and third) to raise depend count above sd ra
v5: 3 words, first diff at 3: addiu now before sd ra but move a3 pushed after (asm on third orders it) -> next: both extra readers on second instead of third
v6: 3 words, first diff at 3: addiu ahead of both move a3 and sd ra (3 readers) -> next: single extra reader on object instead of second
v7: 13 words, 68 bytes (reader on object adds move a0,s0) -> stop: no improvement over v1 for 3+ versions
blocked 001375f0 -> prologue-epilogue
claim 001375f0 token 5a138dd471fe4c07a44fd006acd480ca attempts 4 (claims 2/6) - re-issued own blocked address; released, moving to next queue
claim 001d5b78 token 03c16dfcd14140d584b6f50b42725649 attempts 2 (claims 3/6) queue prologue-load-scheduling
v1 (001d5b78): copy of recovery_a v1 renamed, 2 words (lw t6 / sd ra swapped) -> next: blocker hypothesis, t6 register output asm after sll
v2: 5 words, first diff at 5: prefix fixed (sd ra, sll, lw t6) but tail reordered (lui t0, lw a2, or) -> next: C11d marker on pointer without the shifted input
v3: 4 words, first diff at 6: lw a2 now before lui t0/li a3 -> next: C11a move the shift back into the call expression
v4: 4 words, first diff at 6: identical to v3 -> next: C11b drop the t6 register binding, keep marker
v5: 9 words, first diff at 1: binding removal breaks allocation -> stop: no improvement over v1 for 3 versions
blocked 001d5b78 -> prologue-epilogue
claim 002006b0 token c6ed9be8141c4d459942e5acdcb231dc attempts 2 (claims 4/6) queue prologue-save-order (skipped prologue-epilogue: holds only my own blocked addresses)
restart 2026-10-12T18:09:15Z worker orch1-pro02 resuming claim 4/6 002006b0
v1: 2 words, first diff at 1: baseline copy of recovery-b v2_bothloads -> next: C11d trailing asm volatile marker (precedent fm_worker_b_round24_002007e0_v03)
v2: 2 words, first diff at 1: C11d trailing asm volatile (no effect) -> next: C9 drop volatile loads + memory barriers, adopt accepted sibling 002007e0 shape
v3: 11 words, first diff at 3: C9/C12 sibling shape fixed prologue order (ra then s0) but s0 used for load chain and 2nd call tail-called -> next: C13 prevent tail call with trailing asm volatile
note 2026-10-12T18:09:58Z original instance (session that claimed 001375f0, 001d5b78, 002006b0) found a second orch1-pro02 instance working 002006b0 in this directory; original instance stops without touching 002006b0 or its lease; the restarted instance owns the remaining claims (4/6 used)
v4: 12 words, first diff at 3: C13 trailing asm kept both calls; still s0 scratch for outer load and a0+176 instead of s0 update -> next: C11d register marker on loaded pointer
v5: 14 words, first diff at 1: C11d marker on loaded pointer no effect and reverted prologue order -> next: C7/C10 second argument as explicit base+176 assignment into s0
v6: 3 words, first diff at 3: C7 second arg as explicit base+176 -> 76/76 bytes, prologue order and second-call shape fixed; only load-chain registers left -> next: C9 volatile outer load
v7: 3 words, first diff at 3: C9 volatile outer load no effect -> next: C11c bind load chain to t7/t6 and swap addu operand order
v8: 2 words, first diff at 1: C11c bindings t7/t6 gave exact body; only prologue save order wrong (s0 before ra) -> next: bind only t6, leave link to allocator
v9: 2 words, first diff at 1: bind only t6 kept exact body, still s0-first prologue -> next: C11b no register binding, distinct link/offset/base variables
v10: 2 words, first diff at 1: C11b no bindings, exact body with natural t7/t6, still s0-first prologue -> next: C11c integer-style link (no pointer type)
v11: 2 words, first diff at 1: C11c integer-style link no effect; 3 versions without improvement -> stop (R7)
blocked 002006b0 -> prologue-epilogue
claim 00265740 token 7fa738d2a6104fafb1821f4230245c4c attempts n/a queue prologue-save-order (claims 5/6)
v1: baseline copy of recovery-b v2_signedbarriers
v1: 2 words, first diff at 1: baseline -> next: C11c bind the saved pointer to s0
v2: 2 words, first diff at 1: C11c bind pointer to s0 no effect -> next: C11d operand marker on the saved pointer
v3: 3 words (prologue + move a0,s0): C11d marker drops the barrier and loses the v0 copy -> next: C11e keep helper result live in v0, no barrier
v4: 56B, 13 differing words: C11e (no barrier, result live in v0) flips prologue to ra-first but sd s0 lands in the jal delay slot -> next: C11f barrier before the first call to pull the save back
v5: 2 words, s0-first again: C11f barrier before the call reverts the ra-first order; no probe left, blocking per R12
