# rec163 progress
start 2026-10-16T20:26:36.1988570Z
claim 1 of 6: 0027aed8 token 321079d70e1e43d2877bab87f9cedac1 attempts 1
0027aed8 R4.3 audit: args a0 s32,a1/a2 output pointers. value==0 exit leaves entry v0 untouched; nonzero exit leaves 0027ae20 callee v0. No fabricated zero or void permitted; R4.8 forbids v1 asm to capture entry. R12 conservative ABI block zero versions.
blocked 0027aed8 -> abi-layout
claim 2 of 6: 0027bf20 token f813d1cc10f34ae086706757834a6851 attempts 1
0027bf20 audit: incoming a0 index; v0 explicit true or normalized compare on all exits. v1 baseline fm_global_probes_v3_03_1.cpp function; mandatory only isolated function, plain names, include unchanged, referenced D global exact.
0027bf20 v1: 6 words; best v1 6 words; streak 0. C11a v2 baseline orch1_rec163_0027bf20_v1.cpp; single control compute left halfword first in separate statement; subtraction order preserved.
0027bf20 v2: 8 words; best v1 6 words; streak 1. C11c v3 baseline orch1_rec163_0027bf20_v2.cpp; single control bind count original t4, all expressions unchanged.
0027bf20 v3: 7 words; best v1 6 words; streak 2. C11d v4 baseline orch1_rec163_0027bf20_v3.cpp; one control empty count guard after first halfword read at one site.
0027bf20 v4: 7 words; best v1 6 words; streak 3; stop R7
blocked 0027bf20 -> store-order
claim 3 of 6: 0027ead0 token 3b694df9980a4c30a15a4d6a80a64f1e attempts 1
0027ead0 audit: no arguments; tail j returns 0028da70 v0. Globals lb signed index, lw signed transport, lh signed data. v1 baseline packet initial scalar translation.
0027ead0 v1: 8 words; best v1 8 words; streak 0. C11b v2 baseline orch1_rec163_0027ead0_v1.cpp; single control introduce object argument temporary before call, index expression unchanged.
0027ead0 v2: 8 words; best v1 8 words; streak 1. C11b v3 baseline orch1_rec163_0027ead0_v2.cpp; single control base-plus-index pointer temporary preserving exact addition order.
0027ead0 v3: 7 words; best v3 7 words; streak 0. C11c v4 baseline orch1_rec163_0027ead0_v3.cpp; one control bind pointer t4 to original address transport.
0027ead0 v4: 4 words; best v4 4 words; streak 0. C11c v5 baseline orch1_rec163_0027ead0_v4.cpp; one control bind object a0 to original argument register.
0027ead0 v5: 4 words; best v4 4 words; streak 1. C11d v6 baseline orch1_rec163_0027ead0_v5.cpp; one control empty object guard immediately after initialization at one site.
0027ead0 v6: 10 words; best v4 4 words; streak 2. C9 v7 baseline orch1_rec163_0027ead0_v5.cpp (one control against this baseline); make object global read volatile to constrain timing; no guard carried from v6.
0027ead0 v7: 10 words; best v4 4 words; streak 3; stop R7
blocked 0027ead0 -> address-materialization
claim 4 of 6: 00281cf0 token 2a5be53ab6304369b07ce639ea9623cd attempts 1
00281cf0 audit: a0 scalar retained and low16 stored; no entry mask so s32. f0 transports constant to store before call, outgoing callee 00281b30 v0 survives halfword store; return u32. v1 baseline packet initial scalar translation.
00281cf0 v1: 14 words; best v1 14 words; streak 0. C5/C11b v2 baseline orch1_rec163_00281cf0_v1.cpp; single control explicit constant address array representation (original forms address then lwc1 offset0).
00281cf0 v2: 14 words; best v1 14 words; streak 1. C11b v3 baseline orch1_rec163_00281cf0_v2.cpp; one control introduce constant pointer temporary before byte store.
00281cf0 v3: 14 words; best v1 14 words; streak 2. C11c v4 baseline orch1_rec163_00281cf0_v3.cpp; one control bind constant pointer original t7.
00281cf0 v4: 14 words; best v1 14 words; streak 3; R7 stop
blocked 00281cf0 -> address-materialization
claim 5 of 6: 002831e0 token e3927b52439f417cb09818716605befb attempts 1
002831e0 audit: incoming a0 scalar,a1 stored word; tail 002833f8 callee v0 forwarded, no entry-return path. v1 baseline packet initial scalar translation.
002831e0 v1: 0 words; best v1 0 words; streak 0; review PASS one function no asm no Ghidra names outgoing tail result forwarded
submitted 002831e0 v1
claim 6 of 6: 00283618 token d9e2d2b666a14331a94d7cfc77b03bd4 attempts 1
00283618 audit: no arguments; first/second nonzero exits return 00139d78 result; both zero returns 002839f0 result. v1 baseline packet initial scalar translation retaining each result.
00283618 v1: 0 words; best v1 0 words; streak 0; review PASS one function no asm return path audit preserved
submitted 00283618 v1; K6 exhausted
