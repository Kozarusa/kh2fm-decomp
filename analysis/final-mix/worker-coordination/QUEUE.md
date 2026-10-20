# Persistent recovery queue

The host-local SQLite queue replaces wave scheduling for workers that adopt this protocol. It does not launch agents or keep a Codex session alive. The primary supplies up to three long-lived workers; each worker repeats claim, isolated probe, submit or block, then claim again. Existing manual workers must finish or migrate their claims before their reserved addresses are released. Worker B's guidance remains unchanged.

Run commands from `C:/Users/KoZa/Documents/AGENTS`:

```text
python Public/tools/kh2-audit/recovery_queue.py status
python Public/tools/kh2-audit/recovery_queue.py claim --worker recovery-1 --count 2
python Public/tools/kh2-audit/recovery_queue.py heartbeat --address ADDRESS --token TOKEN
python Public/tools/kh2-audit/recovery_queue.py submit --address ADDRESS --token TOKEN --source SOURCE.cpp --proof PROOF.verification.json
python Public/tools/kh2-audit/recovery_queue.py block --address ADDRESS --token TOKEN --specialty framed-epilogues --report REPORT.md --hypothesis "Next experiment supported by new evidence"
python Public/tools/kh2-audit/recovery_queue.py claim --worker epilogue-specialist --queue framed-epilogues --count 2
python Public/tools/kh2-audit/recovery_queue.py release --address ADDRESS --token TOKEN
```

Claims are atomic batches, default two functions, with independent unguessable lease tokens and 15-minute leases. Renew every five minutes and before submission. Every command reclaims expired leases; stale tokens cannot mutate a reassigned target. After losing a lease, stop work on that address and preserve isolated artifacts. Never reuse another lease's output directory: include worker, address and token in filenames and compiler scratch paths. Use this database on the Windows host only; WSL workers invoke the host CLI rather than opening a copied database. SQLite serializes writers and records transitions transactionally.

Workers must inspect returned metadata, prior proposals and blocker evidence before probing. General queue order is priority, attempts, address. A blocked function immediately returns to the specified specialist queue with a hash-bound report and concrete hypothesis. Specialists must use new evidence rather than repeat recorded constraints. If no eligible work exists, stop or let the primary reassign the worker; do not spin. The original ten unresolved delegated targets remain covered by legacy reservations where applicable, or in the general backlog; the primary can route them after reviewing their reports.

Submission requires the actual source and proof files, matching source SHA256, exactly one target row, complete backlog range length, equal compiled/target bytes and consistent exact-size fields. Submission creates a review candidate, never an accepted recovery. The primary must still verify against the original ELF, independently curate and re-probe, check source hashes, ownership and overlap, and run the existing cumulative acceptance transaction. Queue validation is not a substitute for that gate. Proof bytes are worker claims until independently verified.

Primary integration:

```text
python Public/tools/kh2-audit/recovery_queue.py pause
python Public/tools/kh2-audit/recovery_queue.py status
python Public/tools/kh2-audit/recovery_queue.py review
python Public/tools/kh2-audit/recovery_queue.py resolve --address ADDRESS --accepted --evidence VERIFIED_CHECKPOINT.json
python Public/tools/kh2-audit/recovery_queue.py resume
```

Pause prevents new claims. Existing workers must finish or release leases and stop compiler probes before the primary enters the exclusive full-build window; status must show zero leases. Heartbeats remain available while draining. Resolve is primary-only by protocol: this CLI is a trusted local coordination tool, not a security boundary. Do not mark accepted until the independent cumulative gate passes. Omit `--accepted` to return a rejected submission or released legacy reservation to a queue; add `--queue SPECIALTY` to route it. Resolution always requires saved evidence. Accepted state never changes source registries or project counts automatically.

Seed imports the current prioritized backlog idempotently and reserves addresses from the primary and Worker B legacy claims. It never resets existing queue state. Before importing a newer inventory, reconcile newly accepted or removed addresses through primary resolution; seed alone does not refresh boundaries or prove current fallback status. Inspect the live layout before any claim is worked. The queue covers tracked functions, not undiscovered code or data recovery.

Database: `worker-coordination/recovery-queue.sqlite3`. Keep its WAL and SHM files together while open; use SQLite's backup API for a live backup. Audit history is the `events` table. Existing claims, reports, checkpoints and accepted sources are preserved.

For a specific evidence-backed candidate, add `--address ADDRESS` to `claim` (repeat for multiple addresses). This filter claims only ready targets in the requested queue and never steals another lease or legacy reservation.
