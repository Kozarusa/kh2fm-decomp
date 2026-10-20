# KH2FM project playbook

How this project should be run. The acceptance rules in `HANDOFF.md` and `WORKER_BRIEF.md` are the existing, enforced rules. This playbook adds the operating practice around them. Items marked **Proposed** are recommendations that are not yet in place; adopt, change or drop them.

## 1. Principles

1. **Proof over plausibility.** A recovery counts only if the pinned compiler reproduces the complete original range byte for byte, independently re-probed and accepted through a full-build checkpoint. Reports, filenames and near-matches never count.
2. **One source of truth per question.** Current numbers live in `STATUS.md`. Rules live in `HANDOFF.md`. Worker procedure lives in `WORKER_BRIEF.md`. History lives in the README changelog and the archive. If a fact appears in two places, one of them is a link.
3. **Keep the evidence, shrink the prose.** Failed experiments, logs and hashes stay. Repeated status paragraphs do not.
4. **Honest scope.** Never say "decompiled" when the build still falls back to original bytes. Say "N of M ranges recovered" and name what is not covered.
5. **Move on when stuck.** Bounded effort per target, a written blocker, then a different target.

## 2. Roles

| Role | Owns | Must not |
| --- | --- | --- |
| Primary | Registration, stage sync, full builds, checkpoints, receipts, Ghidra project, `STATUS.md` | Accept anything without independent re-probe |
| Worker | Isolated proposals, proofs, logs, own report | Touch shared registries, stage, or run full builds |
| Specialist (per blocker family) | Hard targets routed by family (epilogue scheduling, store order, float lifetimes, initializers, switches) | Repeat constraints already recorded as failed |
| Reviewer (can be the primary on a different day) | Spot-checks accepted batches against raw original bytes | Rely on the worker's own proof file |

Only one actor holds the compiler stage for a full build at a time. Queue status must show zero leases before an integration window opens.

## 3. The work loop

**Per target (worker):** claim, read prior blockers, probe isolated source, iterate within a bounded budget, then either submit with proof or block with a report and a concrete hypothesis.

**Per batch (primary):** pause queue, drain leases, curate and re-probe, register, sync, full build, provenance, objdiff, bundles and switches, finalize, warning audit, new checkpoint, resolve queue entries, resume.

**Per day or session:**
1. Run the current gate before any change.
2. Integrate pending submissions first, then new probing.
3. End with a clean state: queue resumed, compiler status idle, `STATUS.md` updated.

**Proposed: effort budget.** Cap a target at roughly 10 probe variants or 45 minutes. After that, write the blocker and route it to the specialist queue. This prevents long runs from burning hours on one-to-three-instruction scheduling puzzles.

## 4. Definitions of done

| Level | Meaning | Evidence |
| --- | --- | --- |
| Exported | Bytes or pseudocode extracted | Hash of input, export ledger |
| Probe-exact | Isolated source matches the complete range | Source hash, byte proof |
| Curated-exact | Curated source re-probed independently | Second proof bound to curated hash |
| Accepted | Registered, full ELF equal, provenance, objdiff, bundles, switches, finalization, warnings, checkpoint | Checkpoint manifest + gate pass |
| Source-only | Region rebuilt with no original-byte fallback | **Not yet achieved for any section** |

Only "Accepted" moves the headline count. Report the others separately.

## 5. Measuring progress honestly

Function counts hide the real denominator, because remaining functions are larger and harder. **Partly adopted:** `STATUS.md` now carries a byte-coverage table for the main code ranges only (`orchestration/tools/coverage.py`). The remaining rows below, covering data, IOP, overlays and VU, are still proposed:

| Section | Total bytes | Accepted C++ bytes | Fallback bytes | Notes |
| --- | ---: | ---: | ---: | --- |
| Main text | ? | ? | ? | Functions |
| Main data / tables / vtables | ? | 0 | ? | Not tracked by function counts |
| Overlays (5) | ? | 0 | ? | Layout unconfirmed |
| IOP modules (24) | ? | 0 | ? | Not in current build proof |
| VU microprograms (14, 22,008 B) | 22,008 | 0 | 22,008 | Not disassembled |

Fill the `?` cells from the existing layout and registry files with a small script (see section 9). Track accepted-bytes-per-week as well as function count, so scheduling-heavy long functions are not undervalued.

## 6. Prioritizing remaining work

1. Near-exact proposals (up to three differing words) from the prioritized backlog.
2. Families with a proven recipe (see `recovery-lessons.md`): argument width, signed-low address splits, branch-likely delay slots, quadword copies, float argument transport.
3. Large, structurally simple functions, because they yield many bytes at modest effort.
4. Blocker-family specialists on the hard targets, using new evidence only.
5. Non-function work that blocks a source-only rebuild: data and tables, relocation ownership, jump tables (22 unresolved), overlay placement, VU.

**Decision point to revisit:** a long tail of functions may cost much more per byte than the rest. If the cost curve becomes steep, decide explicitly whether a documented equivalent-check tier is acceptable for them, rather than drifting.

## 7. Documentation rules

- Update `STATUS.md` after every accepted checkpoint. Do not append status paragraphs to the README, brief or handoff.
- Do not copy counts into other documents. Link to `STATUS.md`.
- The README's per-batch paragraphs belong in a changelog. **Proposed:** move them to `analysis/final-mix/CHANGELOG.md` and keep the README to a structured overview; archive the original first.
- Name checkpoints by the real date. The inherited `...-2026-10-08.json` naming for later checkpoints is confusing.
- Every document that quotes a hash or count states the date it was reconciled.
- Never edit hash-bound manifests to fix paths. Fix the helper instead.

## 8. Evidence and storage

- Accepted-checkpoint snapshots hold about 1.43 GB (roughly 135,000 files) of near-identical copies. **Proposed:** after confirming every snapshot's hashes against its manifest, archive each into a `.tar.zst` with a SHA-256 sidecar, keep the three newest uncompressed, and record the plan in a dry run before deleting anything.
- Keep failed proposals and logs. They are the project's memory of what does not work. Compress old ones rather than deleting.
- Back up the SQLite queue with the backup API, not by copying the live file.
- **Proposed:** put the source tree, registries and docs (not the ISO, binaries or Ghidra databases) under git, so history is diffable and snapshots stop being a rollback mechanism.

## 9. Tooling worth adding

| Tool | Purpose |
| --- | --- |
| `status_gen.py` | Read the latest checkpoint and queue, and emit the table in `STATUS.md`, so counts cannot drift |
| One parameterized gate | `verify_checkpoint.py <manifest>` replacing one script per checkpoint with hard-coded counts |
| Coverage script | Bytes per section accepted vs fallback, from layout and registry |
| Snapshot verifier/archiver | Verify and compress old accepted snapshots (dry run first) |
| Doc linter | Flag counts or hashes in docs that disagree with `STATUS.md` |
| Preflight | One command to check Docker/WSL, stage hashes, idle compiler status and queue leases before a session |

## 10. Risks and mitigations

| Risk | Mitigation |
| --- | --- |
| A stale doc sends an agent down the wrong path | Single status page, reconciled date on every doc, doc linter |
| Whole-ELF equality mistaken for completion | Coverage table in bytes, "Source-only" level kept visibly at zero |
| Single machine and toolchain (WSL, Docker, 32-bit compiler) | Record image digest, keep compiler archive hash, back up the stage setup script |
| Path migration leaves old roots in helpers | Preflight check; fix helpers, never manifests |
| Autonomous agents running unchecked | Leases, pause/drain protocol, primary-only registration, periodic spot-check by a reviewer |
| Evidence sprawl | Compression plan, git for source and docs |
| Game data and copyright | Keep the ISO, extracted binaries and pseudocode private. If any of this is ever published, share only original-address-named source, hashes and tooling. |

## 11. Milestones (suggested)

1. **Housekeeping done** (this change): single status page, trimmed brief, archive of replaced docs.
2. **Measured**: per-section coverage table and one parameterized gate.
3. **Lean**: snapshots archived, source and docs under git, README split from changelog.
4. **Large-range push**: bytes-weighted backlog, specialists on blocker families.
5. **Beyond functions**: data and tables, jump tables, overlay layout, IOP and VU plan with acceptance criteria for each.
6. **Source-only rebuild**: fallback dependency count reaches zero for the main executable, then each other section.

## 12. Escalate to the project owner when

- A checkpoint gate fails and cannot be restored from the previous snapshot.
- The toolchain image or compiler hash changes.
- A proposed change would alter compiler flags, edit original bytes, or rewrite hash-bound evidence.
- The cost per recovered byte rises enough to justify the equivalent-check decision in section 6.
