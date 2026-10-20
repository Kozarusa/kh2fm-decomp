# nm17 progress
start 2026-10-14T01:09:11Z
claim 1 of 1: 001bdff0 token fc5993b034674b0194baffccc4aa321f attempts 3
packet and all rec93/nm14 reports and versions read; independently confirmed old best 2 words; v1 adds memory clobber only to cursor guard; initial write command syntax error caused nonexistent-file probe, no compilation or proof produced
001bdff0 v1: 2 words; best v1 2 words; streak 0
v1 first diff instruction 6: C12 -> next accepted callee return declaration normalization
001bdff0 v2: 2 words; best v1 2 words; streak 1
v2 first diff instruction 6: C11 -> next memory clobber base guard
001bdff0 v3: 2 words; best v1 2 words; streak 2
Accounting correction per orchestrator: initial failed write/missing-source probe counts as attempt 1; v1-v3 compiled attempts 2-4; total 4 attempts. Initial failure has no source/proof, best established by subsequent v1.
v3 first diff instruction 6: C11 -> next bind base t7, untried
001bdff0 v4: 2 words; best v1 2 words; streak 3; stop R7. Total 5 attempts including initial missing-source invocation, 4 compiled versions.
blocked 001bdff0 -> prologue-epilogue; queue confirmed; K exhausted
