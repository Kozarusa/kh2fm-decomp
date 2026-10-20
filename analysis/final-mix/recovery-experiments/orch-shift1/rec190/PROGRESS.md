# rec190 progress
start 2026-10-20T01:45:40Z
claim 1 of 6: 002b740c token c3b5bcea5da045359118f0d79de1053c attempts 1
packet 002b740c: 52 bytes; baseline new v1; C19 frame transport suspected
v1 source inspected: one control, volatile four-word payload preserves argument stores
v1: 13 words, first diff at 0: C19 -> next: base payload on __builtin_frame_address(0)
002b740c v1: 13 words; best v1 13 words; streak 0
v2 baseline v1 inspected: only payload ownership changed from local array to frame address
v2: 13 words, first diff at 0: C19 -> next: accepted 002b6b84 explicit frame transport
002b740c v2: 13 words; best v1 13 words; streak 1
v3 baseline v2 inspected: one C19 control, accepted explicit frame transport including t7/v0 return
v3: 13 words, first diff at 0: C11 -> next: align function to original 4-byte boundary
002b740c v3: 13 words; best v1 13 words; streak 2
v4 baseline v3 inspected: only function alignment changed to 4 bytes
v4: compile error, alignment may not be specified: C11 -> stop
002b740c v4: compile error; best v1 13 words; streak 3
blocked 002b740c -> abi-layout
claim 2 of 6: 002b81ec token 8cbdb0b629d943f299cbbb5210331c2f attempts 1
packet 002b81ec: 40 bytes; baseline new v1; accepted 002b6b84 C19 frame and symbol alias
v1 source inspected: one C19 control, full accepted explicit frame transport adapted to one argument
002b81ec v1: 0 words; best v1 0 words; streak 0
submitted 002b81ec v1
claim 3 of 6: 002b8214 token c173de1cb3c740418023c9a6f80f38a7 attempts 1
packet 002b8214: 40 bytes; baseline exact sibling 002b81ec v1
v1 source inspected: address-only adaptation of exact sibling, C19 transport unchanged
002b8214 v1: 0 words; best v1 0 words; streak 0
submitted 002b8214 v1
claim 4 of 6: 002b84b8 token 4906523aa05142f0a96a369072a82611 attempts 1
packet 002b84b8: 124 bytes; baseline new v1; nine-argument retry loop and global return
v1 source inspected: one control, literal original loop with inferred ninth stack argument
v1: 29 words, first diff at 1: C19 -> next: accepted explicit frame transport and volatile result spill
002b84b8 v1: 29 words; best v1 29 words; streak 0
v2 baseline v1 inspected: one C19 control adds explicit frame transport; condition and call unchanged
v2: 27 words, first diff at 0: C12 -> next: remove redundant 16-byte argumentArea
002b84b8 v2: 27 words; best v2 27 words; streak 0
v3 baseline v2 inspected: only argumentArea and empty memory output removed
v3: 27 words, first diff at 0: C11 -> next: guard D_01e22040 address rematerialization
002b84b8 v3: 27 words; best v2 27 words; streak 1
v4 baseline v3 inspected: one empty guard added only to buffer address
v4: 30 words, first diff at 0: C7 -> next: explicit infinite loop with break on zero
002b84b8 v4: 30 words; best v2 27 words; streak 2
v5 baseline v3 inspected: only loop condition shape changed to while(1) plus break
v5: 27 words, first diff at 0: C11 -> stop
002b84b8 v5: 27 words; best v2 27 words; streak 3
blocked 002b84b8 -> prologue-epilogue
claim 5 of 6: 002b8a70 token 1b435f4669804f549d713e0be242ca05 attempts 1
packet 002b8a70: 80 bytes; accepted callee declaration copied from conditionfinish
v1 source inspected: one control, volatile pointer mirrors two original reloads
v1: 20 words, first diff at 0: C19 -> next: accepted explicit frame transport
002b8a70 v1: 20 words; best v1 20 words; streak 0
v2 baseline v1 inspected: one C19 control replaces local pointer preservation with explicit frame payload
v2: 15 words, first diff at 5: C11 -> next: bind first computed destination to t7
002b8a70 v2: 15 words; best v2 15 words; streak 0
v3 baseline v2 inspected: only first computed destination gains t7 binding and guard
v3: 5 words, first diff at 5: C11 -> next: bind first payload reload to t6
002b8a70 v3: 5 words; best v3 5 words; streak 0
v4 baseline v3 inspected: only first payload reload gains t6 binding and guard
v4: 5 words, first diff at 5: C11 -> next: materialize and update first destination in t7
002b8a70 v4: 5 words; best v3 5 words; streak 1
v5 baseline v4 inspected: only target binding initialization split into t7 constant then t7 addition
v5: 4 words, first diff at 5: C11 -> next: make t6 reload guard volatile
002b8a70 v5: 4 words; best v5 4 words; streak 0
v6 baseline v5 inspected: only first payload reload guard changed to volatile
v6: 2 words, first diff at 13: C11 -> next: bind second computed destination to t7
002b8a70 v6: 2 words; best v6 2 words; streak 0
v7 baseline v6 inspected: only second computed destination gains t7 binding and guards
v7: 8 words, first diff at 13: C11 -> next: bind second payload reload to t6
002b8a70 v7: 8 words; best v6 2 words; streak 1
v8 baseline v7 inspected: only second payload reload gains t6 binding and guard
v8: 2 words, first diff at 10: C11 -> stop
002b8a70 v8: 2 words; best v6 2 words; streak 2
blocked 002b8a70 -> register-allocation
claim 6 of 6: 002b9bd0 token 08cf5cd30cf4470cbc8ce084f2d9e29b attempts 1
packet 002b9bd0: 96 bytes; accepted func_00102788 and func_002bd538 declarations copied
v1 source inspected: one control, literal call order and final result-preserving tail call
v1: compile/probe error, no definitions found; best none; streak 1
v2 baseline v1 inspected: only unsupported target symbol alias removed
v2: 11 words, first diff at 14: C20 -> next: pass address through signed 32-bit transport
002b9bd0 v2: 11 words; best v2 11 words; streak 0
v3 baseline v2 inspected: only final pointer cast changed u32 to s32
v3: 4 words, first diff at 17: C11 -> next: introduce final-call temporaries in original materialization order
002b9bd0 v3: 4 words; best v3 4 words; streak 0
v4 baseline v3 inspected: only final-call constants split into source-ordered temporaries
v4: 4 words, first diff at 17: C11 -> next: bind final-call temporaries to a1/a2/a3
002b9bd0 v4: 4 words; best v3 4 words; streak 1
v5 baseline v4 inspected: only final-call temporaries gain outgoing-register bindings and guards
v5: 5 words, first diff at 17: C11 -> next: make a2 materialization guard volatile
002b9bd0 v5: 5 words; best v3 4 words; streak 2
v6 baseline v5 inspected: only a2 guard changed to volatile
v6: 7 words, first diff at 14: C11 -> stop
002b9bd0 v6: 7 words; best v3 4 words; streak 3
blocked 002b9bd0 -> register-allocation
