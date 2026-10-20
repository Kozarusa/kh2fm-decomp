# pro01 progress
start 2026-10-12T17:18:19Z
R0 done 2026-10-12T17:18:35Z
claim 0028b7f8 token 99394f7a423840a4825451e400bc122e attempts 3 (claims: 1/6) queue address-prologue-scheduling
v1: 2 words, first diff at 4: C10 (sd ra/sw swap) -> next: report hypothesis, hide object base via asm +r so store may alias frame saves
v2: 12 words, first diff at 2: C10 -> next: v1 + volatile asm barrier that uses the table address before the store (report hypothesis: table-address lifetime)
v3: 4 words, first diff at 2: C10 -> next: v1 with trailing asm barrier replaced by dead assignment (barrier adds t7-use dependents to sw)
v4: exact
submitted 0028b7f8 v4
claim 00315678 token 2871a61870504f4589d2d8e5fb624bd7 attempts 3 (claims: 2/6) queue address-prologue-scheduling
v1 probed (copy of eight_hour voidpointer_1)
v1: 2 words, first diff at 4: C10 -> next: replace trailing asm barrier with dead assignment (fix from 0028b7f8)
v2: exact
submitted 00315678 v2
claim 00315700 token 9ff799266ceb4cb694b222b081d3c8f6 attempts 3 (claims: 3/6) queue address-prologue-scheduling
v1: 2 words, first diff at 4: C10 -> next: dead assignment instead of trailing asm barrier
v2: exact
submitted 00315700 v2
claim 00316890 token 094a3fe6bd8c405b893ff09b8d3f6cbd attempts 3 (claims: 4/6) queue address-prologue-scheduling
v1: 2 words, first diff at 4: C10 -> next: dead assignment instead of trailing asm barrier
v2: exact
submitted 00316890 v2
claim 001b1bb8 token cc211510be754b13a7cc6f31287cb52e attempts 2 (claims: 5/6) queue byte-prologue-scheduling
v1: 3 words, first diff at 4: C10 -> next: C10(a) reorder source stores to 1,2,3 (compiled looks like source rotated right by one)
v2: exact
submitted 001b1bb8 v2
claim 001375f0 token e39c109788274002983260c3656eaed9 attempts 2 (claims: 6/6 = K) queue float-address-prologue
v1: 2 words, first diff at 4: C9/C10 (addiu t7 vs sd ra) -> next: C9 volatile read of the global instead of register binding + asm marker
v2: 14 words (lo folded into lwc1), first diff at 1: C1 -> next: back to v1, drop the \ register binding (keep asm marker)
v3: 2 words, first diff at 4: C10/C12 (no change) -> next: replace +r marker (which becomes last t7 setter) with an asm lwc1 that only reads the address
v4: 8 words, first diff at 1 -> stop: 3 versions without improvement
blocked 001375f0 -> prologue-epilogue
K=6 reached; WP-REPORT.md written 2026-10-12T17:32:10Z
