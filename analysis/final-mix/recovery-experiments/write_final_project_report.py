from pathlib import Path
import hashlib, json
from datetime import datetime, timezone

area = Path(__file__).resolve().parent.parent
draft = (area / 'project-report-draft.md').read_text(encoding='utf-8')
ledger = json.loads((area / 'recovery-experiments/primary-fourhour-final-ledger.json').read_text())
assert ledger['accepted_exact'] == 5702 and ledger['session_gain'] == 71
now = datetime.now(timezone.utc)
start = datetime.fromisoformat(ledger['session']['start_utc'].replace('Z', '+00:00'))
assert (now-start).total_seconds() >= 14400
checkpoint = area/'primary-maskpair-checkpoint-2026-10-08.json'
checkpoint_hash = hashlib.sha256(checkpoint.read_bytes()).hexdigest()
intro = f'''Report verified at {now.isoformat()}. The requested work period began 2026-10-09 06:32:21 UTC and exceeded four hours before this report was written. The session accepted 71 additional complete instruction-exact ranges, comprising 4,836 instruction bytes. The project remains incomplete; the four-hour work requirement has been fulfilled.

The user's subsequent request adds six disjoint subagent assignments in two waves of three, because the session permits four concurrent agents including the primary. Their assignments and exclusive paths are in [delegation-plan.md](worker-coordination/delegation-plan.md). First-wave agents are active when this report is written; proposals do not change accepted counts until independently verified and integrated. The primary retains shared integration and checkpoint ownership.
'''
draft = draft.replace('# KH2FM project report - working draft', '# KH2FM project report — 2026-10-09')
draft = draft.replace('This draft supports the requested report after the active four-hour session. It is not the final session report. Refresh counts, receipts, worker state and the range inventory after the minimum work period ends.', intro)
status = f'''The current checkpoint passed again immediately before this report. Verified counts:

| Measure | Verified total |
|---|---:|
| Equal-size instruction-exact matches | 5,702 |
| C++ ranges, including four separately counted padding ranges | 5,706 |
| Remaining tracked fallback ranges | 5,677 |
| Staged compiler inputs | 2,207 |
| Cumulative verified recovery bundles | 91 |
| Verified switch batches / code ranges / generated tables | 3 / 5 / 5 |
| Exact matches at this four-hour session start | 5,631 |
| Accepted during this session | 71 |
| Instruction bytes accepted during this session | 4,836 |

Full executable equality, cumulative provenance, objdiff, saved artifacts, recovery bundles, switch checks, finalization, warning audit and the current checkpoint passed. The two new switch functions also have 40 bytes of generated table data independently proved exact. These auxiliary table checks do not establish source ownership of all executable data: the main executable still preserves original table/fallback bytes.

Checkpoint: [primary-maskpair-checkpoint-2026-10-08.json](primary-maskpair-checkpoint-2026-10-08.json).
SHA256: `{checkpoint_hash}`.
Acceptance gate, run from C:/Users/KoZa/Documents/AGENTS:

```text
python Public/tools/kh2-audit/verify_fm_primary_maskpair_checkpoint.py
```

The [final session ledger](recovery-experiments/primary-fourhour-final-ledger.json) lists all 71 accepted addresses, instruction lengths, source paths and source hashes. [Live primary status](worker-coordination/primary-status.md) identifies the accepted state. Historical HANDOFF.md and SESSION_STATUS.md are intentionally unchanged and contain older baselines. Whole-executable equality currently relies on original fallback/data, so it does not establish a complete source-only rebuild or independent runtime validation.
'''
draft = draft.replace('Use worker-coordination/primary-status.md and the newest cumulative checkpoint named there for current counts. Historical HANDOFF.md and SESSION_STATUS.md are intentionally unchanged and contain older baselines. The final report must cite its exact checkpoint and hash-bound evidence.', status)
draft = draft.replace('## Accomplishments to summarize in the final report', '## Accomplishments')
draft = draft.replace('Session-specific address lists and byte totals are recorded in recovery-experiments/primary-fourhour-progress-v1.json.', 'The final session ledger verifies the accepted additions. Representative completed families include callback returns and address decoding, packet aliasing, floating-point results, virtual-call guards, quad transports, bounded switch dispatch, indexed masks and mask copying.')
draft = draft.replace('project-prioritized-range-backlog.json enumerates every currently tracked fallback range in order:', '[project-prioritized-range-backlog.json](project-prioritized-range-backlog.json) enumerates all 5,677 currently tracked fallback ranges with unique addresses in order (53 priority-one, 1,946 priority-two, 2,963 priority-three and 715 priority-four):')
draft = draft.replace('Avoid concurrent use of the shared compiler/stage.', 'The delegated agents may run isolated probes concurrently only in their uniquely named scratch directories. The shared full-build stage remains exclusively owned by the primary; pause or finish probes before a full integration build. Follow the delegation manifest for target and write ownership.')
draft += '''
## Blockers and how to continue

[primary-fourhour-blockers.md](recovery-experiments/primary-fourhour-blockers.md) records experiments and unresolved families. A scheduling failure or equal-size mismatch is a blocked proposal, not accepted progress. The current delegated work concentrates on bounded searches, global quad/float copying, ordered floating-point predicates, guarded global initializers, epilogue scheduling and framed argument transport. Each agent must return a source-hash-bound exact proof or a precise blocker report. Preserve the accepted checkpoint until independent review and cumulative acceptance succeed.

Newcomers should first run the current gate, inspect the delegation plan and Worker B's latest report, and select only an unowned address. Do not rewrite Worker B's guidance merely because a new session starts. Do not edit historical handoff/status documents without authorization. Recovery is measured by proven complete ranges, not hours, variant counts or worker claims.
'''
destination = area/'PROJECT-REPORT-2026-10-09.md'
assert not destination.exists()
destination.write_text(draft, encoding='utf-8')
print(destination)
