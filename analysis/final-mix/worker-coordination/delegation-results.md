# Six-agent recovery results

All six requested subagents were spawned and completed their exclusive assignments. At most three ran concurrently, alongside the primary. The assignment manifest contains 15 distinct target addresses; each worker wrote only its own directory and uniquely named isolated compiler scratch directories. Worker B's existing guidance was preserved.

| Assignment | Accepted recoveries | Unresolved targets |
|---|---|---|
| lookup_search | None | 00114438, 00114490, 00124c48 |
| global_copy | 00158b20 (84 bytes) | 00158ac8 |
| float_predicates | 00148638 (84 bytes) | 0010f6f8 |
| global_initializers | 0014ec40 (84), 00158fd8 (84), 00159c58 (104) | None |
| framed_epilogues | None | 0014dc48, 0014dca8, 002e5f70 |
| framed_transport | None | 00143470, 0013e610 |

The primary independently curated and re-probed all five successful proposals, then accepted one batch totaling 440 instruction bytes. Original source/proof hashes, target bytes, exact comparisons and exclusive target ownership are checked in delegated-proof-audit.json. Each assignment's REPORT.md is preserved under recovery-experiments/delegated. Duplicate exact variants count only once; failed proposals remain isolated.

Shared registration, synchronization and full acceptance were performed by the primary during an exclusive build window. All 92 cumulative recovery bundles and three switch batches pass. Current state: 5,707 equal-size exact matches, 5,711 C++ ranges including four separately counted padding ranges, 5,672 fallback ranges and 2,212 inputs. Gate: Public/tools/kh2-audit/verify_fm_primary_delegatedbatch_checkpoint.py. Snapshot before integration: accepted-snapshots/2026-10-08-before-delegatedbatch.

Ten assigned targets remain unresolved. Their reports explain exact instruction differences and next hypotheses. Revisit them only with new scheduling or allocation evidence. Use the refreshed prioritized backlog for another disjoint assignment; repeating the same failed constraints is not productive. The primary owns future integration and must retain full cumulative acceptance checks.
