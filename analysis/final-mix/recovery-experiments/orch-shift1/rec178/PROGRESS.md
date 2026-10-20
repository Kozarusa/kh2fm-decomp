# rec178 progress
start 2026-10-18T02:33:26Z
claim 1 of 6: pending
lease 0029c958 token 1a3f3d454d944465b08dd58547bafc1b attempts 1 blocker null
blocked 0029c958 -> abi-layout; zero versions
claim 2 of 6: pending
lease 0029dd00 token dfe430865b504721bc69c6b64ba3f957 attempts 1 blocker null
0029dd00 v1 baseline new; R4.3 all exits outgoing func_002931a8 v0 preserved; R4.5 func_002ff2e8 declaration copied
0029dd00 v1: 0 words; best v1 0 words; streak 0; manual source audit passed; submitted 0029dd00 v1
claim 3 of 6: pending
lease 0029dda8 token 43d46e1846d64557b94cea947cb76e13 attempts 1 blocker null
0029dda8 v1 baseline new; all three exits preserve respective callee v0; shift through unsigned word
0029dda8 v1: 4 words; best v1 4 words; streak 0; first diff 5 C11; v2 baseline v1 single control reverse unsigned address addition operands
0029dda8 v2: 0 words; best v2 0 words; streak 0; manual source audit passed; submitted 0029dda8 v2
claim 4 of 6: pending
lease 0029e7b0 token 99637553f11541e089585bced82d7452 attempts 1 blocker null
0029e7b0 v1 baseline new; a0 unmasked word; both exits signed word result
0029e7b0 v1: 21 words; best v1 21 words; streak 0; first diff 1 C1 audit parameters/exits complete; v2 baseline v1 single control introduce default result temporary
0029e7b0 v2: 21 words; best v1 21 words; streak 1; v3 baseline v2 single control C11 bind existing initialized result to numeric $2
0029e7b0 v3: 0 words; best v3 0 words; streak 0; manual source audit passed; submitted 0029e7b0 v3
claim 5 of 6: pending
lease 0029ea30 token d09669fa93c545c0a07635316e48748a attempts 1 blocker null
blocked 0029ea30 -> boundary-review; zero versions
claim 6 of 6: pending
lease 0029ec40 token 2315f234fa9d43cb8c438ed17bbb9e5c attempts 1 blocker null
0029ec40 v1 baseline new; a0 unmasked word; both exits integer v0
0029ec40 v1: 20 words; best v1 20 words; streak 0; first diff 1 C1 audit complete; v2 baseline v1 single control default result temporary
0029ec40 v2: 20 words; best v1 20 words; streak 1; v3 baseline v2 single control C11 bind initialized result to $2
0029ec40 v3: 16 words; best v3 16 words; streak 0; first diff 3 branch-layout; v4 baseline v3 single control C11 guard existing result initialization
0029ec40 v4: 19 words; best v3 16 words; streak 1; v5 baseline v3 single control route match return through existing result
0029ec40 v5: 16 words; best v3 16 words; streak 2; v6 baseline v5 single control C11 empty guard at match result
0029ec40 v6: 3 words; best v6 3 words; streak 0; v7 baseline v6 single control C11 guard default return (single default indentation site)
0029ec40 v7: 2 words; best v7 2 words; streak 0; ERROR v7 replacement added guards at two sites, violates one-control rule; ineligible for submission. v8 baseline v6 single control guard only default return, anchored newline replacement
0029ec40 v8: 2 words; best v7 2 words; streak 1; budget8 reached; v8 valid isolated control
blocked 0029ec40 -> prologue-epilogue; K6 reached
