# tool03 report
Status: done
Worker: orch1-tool03, model sonnet. Started 2026-10-12T21:57:38Z.

Changes to Codex\orchestration\tools\kh2w.py (original saved as tool03\kh2w.py.orig), only inside prior_attempts and the proof loop of packet:
- prior_attempts: proofs tuples gained a 6th element (source path or None). After the glob scan, it reads queue_row(address) (read-only), takes metadata.best_proposal, and if its proof file (relative to Codex\) exists, is not already in the list, and has a row with the target address, appends it with the same differing-words computation; source is set only if best_proposal.source exists on disk. Errors in metadata/JSON are ignored.
- packet: loop unpacks the 6th element, prints "(source: `<path>`)" after the proof path, and sorts queue-proposal entries first (so the 15-entry cap cannot drop them), then newest first.

Test 1: `python -I Codex\orchestration\tools\kh2w.py packet 001702e0 <WP>\t1c`
- "- 14 differing words, 52/60 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_00_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_00_0.cpp`)" listed first, followed by the rec35 attempts.

Test 2: `python -I Codex\orchestration\tools\kh2w.py packet 00146730 <WP>\t2c`
- 8 rec16 attempt lines present (v1-v8 as before), plus the fm_primary_orchaj EXACT entry; 5 nop (00000000) words still shown.

No other file changed except kh2w.py and files in the tool03 WP directory (test packets in t1b, t1c, t2b, t2c, 001702e0-packet.md, t2\00146730-packet.md). One attempt to delete earlier test packets was blocked and not retried; the extra test packet directories are harmless leftovers.
