# Disjoint recovery assignments

The user requested four to six subagents. This session supports four concurrent agents including the primary, so six subagent assignments run in two waves of three. Wave two starts as slots become available. An assignment is complete when its isolated exact proposals or evidence-backed blocker report are saved and reviewed.

| Agent | Exclusive target addresses | Exclusive output directory under recovery-experiments/delegated | Source prefix | Wave |
|---|---|---|---|---|
| lookup_search | 00114438, 00114490, 00124c48 | lookup-search | sa_lookup_ | 1 |
| global_copy | 00158ac8, 00158b20 | global-copy | sa_copy_ | 1 |
| float_predicates | 0010f6f8, 00148638 | float-predicates | sa_float_ | 1 |
| global_initializers | 0014ec40, 00158fd8, 00159c58 | global-initializers | sa_init_ | 2 |
| framed_epilogues | 0014dc48, 0014dca8, 002e5f70 | framed-epilogues | sa_frame_ | 2 |
| framed_transport | 00143470, 0013e610 | framed-transport | sa_transport_ | 2 |

Each agent owns only its target addresses and output directory. Historical sources, original instructions and shared audit tools may be read. Unique source prefixes provide separate isolated-probe scratch directories. Agents must not register functions, synchronize the shared stage, run full builds, edit accepted sources, alter compiler settings, change claims/status/checkpoints, or delegate further. Worker B's assignment and three unresolved round-27 targets remain outside these assignments.

The primary owns integration, the project report and all shared mutations. It independently curates and re-probes proposed matches, snapshots the accepted state, checks source hashes and range overlap, and performs registration, named synchronization and cumulative acceptance sequentially. Isolated probes can run concurrently in separate scratch directories; full shared builds require an exclusive integration window after probe activity is paused or finished.

Every report must identify original range size, best source and source hash, probe result, exact remaining instruction differences, attempted hypotheses and a concrete next hypothesis. Equal size or plausible semantics alone do not qualify. Preserve failed versions; avoid repeating prior experiments without new evidence. No failed proposal changes the accepted count.

Baseline: 5,702 exact matches, 5,706 C++ ranges including four separately counted padding ranges, 5,677 fallback ranges, 2,207 staged inputs. Current gate: Public/tools/kh2-audit/verify_fm_primary_maskpair_checkpoint.py. The original executable hash and pinned toolchain remain authoritative.

## Integration result

All six agents were actually spawned. The first five completed their reports before the integration window; framed_transport continued afterward. Independent curation and re-probing accepted five proposals in batch primary-delegatedbatch: 00148638, 0014ec40, 00158b20, 00158fd8 and 00159c58, totaling 440 bytes. Snapshot: accepted-snapshots/2026-10-08-before-delegatedbatch. All 92 cumulative bundles and three switch batches passed, together with full executable equality/provenance/objdiff, finalization, warning audit and the new checkpoint.

The new accepted total is 5,707 exact matches, 5,711 C++ ranges, 5,672 fallback ranges and 2,212 staged inputs. Current gate: Public/tools/kh2-audit/verify_fm_primary_delegatedbatch_checkpoint.py. Delegated failed proposals remain isolated. The root's existing primary claim is an umbrella reservation; address-level work ownership during this delegation is the exclusive table above, not simultaneous primary experimentation.
