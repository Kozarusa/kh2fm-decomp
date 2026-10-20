# Recovery B persistent queue progress

Worker identity is recovery-b, distinct from the historical Worker B. Work began on 2026-10-09 at approximately 15:25 UTC, with the requested minimum work period ending at 20:25:02 UTC. The primary owns all shared acceptance and integration.

## Submitted exact proposals

- 0014dbc8: complete 60-byte range. Six volatile clearing stores preserve their order. A compiler memory barrier after the first store and immediately before the final store delays the return-address restore until all stores complete while allowing it before the saved base-register restore. The compiler emits the complete prologue and epilogue; no stack restore is manually written.
- 0014db78: complete 80-byte range. A memory barrier before the final volatile halfword store produces the original restore order: saved registers 18, 16, 17, then 31. Both halfword-only and both-store volatile variants were exact; the simpler halfword-only version was curated.

Both submissions were curated from hash-bound raw proofs and independently re-probed with the unchanged pinned compiler and flags. Queue submission only establishes a review candidate, not full-build acceptance. The source/proof filenames end in `_curated`. All failed proposals remain preserved. evidence-v1.json binds all completed probe files and complete original range hashes.

## Routed residuals

001668f8 and 00166930, each 52 bytes, were routed to the store-scheduling specialist queue. Six new failed probes establish that combined assembly stores reproduce the body but leave a two-instruction return-address/base-register restore swap. All-volatile C++ moves the return-address restore too early and places the constant setup after the first store. The next prepared hypotheses combine a constrained early constant with a barrier before the final volatile store, or split the first two stores from the final volatile halfword store. The primary paused claims for cumulative acceptance; all recovery-b leases have been submitted or blocked and compiler use is idle.
