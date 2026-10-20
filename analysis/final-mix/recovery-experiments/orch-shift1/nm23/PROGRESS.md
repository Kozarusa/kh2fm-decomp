# nm23 progress
start 2026-10-15T08:40:00.5426825Z
claim 1 of 3: 00239e60 token 9be69da2157348869d400652d079ff18 attempts 2 blocker rec142/00239e60-BLOCKED.md
Independently recounted prior best: 2 differing 32-bit words from compiled_hex and target_hex (indices 2,3); accepted sibling uses pointer guard plus memory barrier.
00239e60 v1: 2 words; best v1 2 words; streak 0. C10c next: only y store volatile.
00239e60 v2: 2 words; best v1 2 words; streak 1. C10d next: memory barrier between x and y stores.
00239e60 v3: 2 words; best v1 2 words; streak 2. C11c next: initialized pointer bound to numeric register 15.
00239e60 v4: 2 words; best v1 2 words; streak 3. Stopped under R7.
blocked 00239e60 -> store-order
claim 2 of 3: 00239f18 token 612eabb8968f4cb3952dde53b60562dc attempts 2 blocker rec142/00239f18-BLOCKED.md
Independently recounted prior best: 2 differing words, indices 1 and 3. Actual global D_003714c4; x offset 308, y offset 312.
00239f18 v1: 2 words; best v1 2 words; streak 0. C10d next: memory barrier between x load and y store, matching accepted scheduling pattern.
00239f18 v2: 0 words; best v2 0 words; streak 0. R8 review passed: one function; only commented empty assembly; no bindings or Ghidra names.
submitted 00239f18 v2
claim 3 of 3: 0023c008 token 393f3cd93b2144359180fd871ca10500 attempts 2 blocker rec143/0023c008-BLOCKED.md
Independently recounted prior best: 2 differing words, indices 0 and 1; all remaining words match.
0023c008 v1: 2 words; best v1 2 words; streak 0. C10d next: defined global pointer with memory-clobber guard before first volatile store.
0023c008 v2: 2 words; best v1 2 words; streak 1. C10d next: memory-only barrier, allowing split address computation.
0023c008 v3: 2 words; best v1 2 words; streak 2. C10c next: remove volatility from only the first zero store to permit address scheduling.
0023c008 v4: 3 words; best v1 2 words; streak 3. Stopped under R7.
blocked 0023c008 -> address-materialization
R11 report completed 2026-10-15T08:43:53.9528010Z; no further claims permitted.
