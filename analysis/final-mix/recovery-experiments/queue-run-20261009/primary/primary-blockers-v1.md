# Primary queue-run blockers

00153610 is independently exact after ordering the constant addend before the linear product. It was accepted in queuealpha, all 100 bytes.

002c1950: three signed/unsigned/truncation variants replace daddiu with addiu but use saved s0 rather than incoming a1. A fixed incoming a1 lifetime marker expands the body from 64 to 68 bytes and moves argument setup before the floating load. The next experiment should preserve a1 until argument materialization without forcing a second move.

00305ce0 and 00308cd0: volatile stores, memory barriers, fixed value/base markers and canonical typed stores do not reproduce the original RA restore before the final store. No manual epilogue or patched instruction bytes were used. Next inspect actual data dependencies around the store and compiler return-value scheduling, rather than repeat memory clobbers.

primary-blockers-v1.json binds every saved source and proof and records all differing words. These failed proposals are not registered.
