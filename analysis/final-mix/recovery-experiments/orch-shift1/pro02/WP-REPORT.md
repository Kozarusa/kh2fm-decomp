# pro02 report
Status: stopped: orchestrator
Worker: orch1-pro02, model opus. Started 2026-10-10T00:00:00Z, ended 2026-10-12T18:13:42Z.

| Address | Bytes | Result | Versions | Best words | File |
| --- | ---: | --- | ---: | ---: | --- |
| 001375f0 | - | blocked:prologue-epilogue | 7 | 0 | orch1_pro02_001375f0_v7.cpp |
| 001d5b78 | - | blocked:prologue-epilogue | 5 | 0 | orch1_pro02_001d5b78_v5.cpp |
| 002006b0 | 76 | blocked:prologue-epilogue | 11 | 2 | orch1_pro02_002006b0_v11.cpp |
| 00265740 | 60 | blocked:prologue-save-order | 5 | 2 | orch1_pro02_00265740_v5.cpp |

Totals: 0 submitted, 4 blocked, 0 released.
Problems: none in the environment; all four targets stalled on the same residual, the callee-save store order in the prologue (`sd ra,8(sp)` before `sd s0,0(sp)`), which the harness compiler emits in the opposite order.
Exact next step (only if partial or stopped): rerun 00265740 from the barrier-free v4 shape (`s32 got=func_00257770(); u32 object=(u32)got; func_00139d78((u32)got);`) — it is the only variant that compiles the body and the ra-first prologue exactly, and only its `sd s0,0(sp)` needs to be kept out of the first `jal` delay slot with an instruction-neutral asm that has an operand rather than a memory barrier.