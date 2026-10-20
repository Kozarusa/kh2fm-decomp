# nm30 progress
start 2026-10-17T21:03:38Z
claim 1 of 1: 0028b078 token b1fc7337d06b423a8f44a2131ec7d01a attempts 2
R4.3 audit: original reads object a0, full-width value a1 and count a2 without masks; sole exit tail-calls 0028b1b0 and returns its u32 result. v1 mandatory unchanged baseline rec167v1; full-source comparison identical. R4.5 declarations checked against accepted 00272a00.
0028b078 v1: 5 words; best v1 5 words; streak 0
v1: 5 words, first diff at 2: C3 -> next: count-only u16 to u32. Full-source diff v2 versus named v1 confirms only count width; all declarations, return, operand/store order unchanged.
v2 initial save failed: Set-Content NoNewline unsupported; no source/proof created. Recreated using supported Set-Content; identical intended count-only diff.
0028b078 v2: 22 words; best v1 5 words; streak 1
v2: 22 words, first diff at 1: C1 audit complete; next isolated value-width correction C3 from count-wide v2. Full-source diff v3 versus named v2 changes only value u16 to u32; sole tail return and exact accepted declarations preserved.
0028b078 v3: 22 words; best v1 5 words; streak 2
v3: 22 words, first diff at 1: C1 audit: all argument reads, paths, callee arguments and tail result accounted for; C10(a) source already matches original store order, (b) only one zero store; next C10(c) volatile stores. Full-source diff v4 versus named v3 only adds volatile to all four store accesses as one store-order control. Operand order, widths, declarations, sole tail return unchanged; no binding or guard.
0028b078 v4: 15 words; best v1 5 words; streak 3
blocked 0028b078 -> register-allocation
R11 report written; K1 exhausted, done.
Docs-only addendum: failed Set-Content -NoNewline was followed by heartbeat, kh2w.py probe of missing v2 source (FileNotFoundError), then diff of nonexistent proof. Supported Set-Content and successful same-number v2 probe followed. Conservative failed-probe counting reaches streak3 at v3; v4 exceeded that limit. WP-REPORT.md append preserves commands/errors. No original evidence altered; no new source/probe/claim.
