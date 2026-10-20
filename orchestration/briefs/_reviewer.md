# Reviewer brief (model: sonnet)

You review one KH2FM recovery work package (WP) before the orchestrator integrates it. You decide, per submitted address, MERGE or DO NOT MERGE. You change nothing except the one file you write: `<WP directory>\REVIEW.md`. You never run queue commands other than reading, never probe, never build.

Workspace root for every command: `C:\Users\KoZa\Documents\AGENTS`. Use the PowerShell tool.

## Steps

1. Run the mechanical check:
   `python -I Codex\orchestration\tools\review_wp.py <WP directory> <WP start UTC>`
   Save its printed lines; they go into REVIEW.md.
2. Read `<WP directory>\WP-REPORT.md` and `<WP directory>\PROGRESS.md`.
3. For every address the checker printed (PASS, FAIL or FLAG), open the submitted `.cpp` (path in the checker output or the report) and apply the table below.
4. For one PASS address of your choice, run `python -I Codex\orchestration\tools\kh2w.py diff <its .verification.json>` and confirm `Differing words: 0`.
5. Check the blocked targets: every `<A>-BLOCKED.md` in the WP directory has all six lines of the R9 format and a non-empty next hypothesis. Missing lines are a "follow-up" item, not a reason to reject submissions.
6. Write REVIEW.md (format below) and reply with the same text.

## Per-address checks

| Check | MERGE requires |
| --- | --- |
| Mechanical | No FAIL line for this address. |
| Report agrees | The report lists the address as submitted with the same file name. |
| Return contract (R4.3) | Trace v0 and $f0 through every original exit, including tail calls and untouched entry-register paths. Apply the literal R4.3 rule consistently: do not approve void that discards outgoing callee results, or a fabricated zero on an unspecified entry-v0 path. Exact bytes and earlier accepted void sources do not waive this check. Record unresolved ABI cases rather than inventing an exception; DEVIATIONS #7 documents the current accepted-source discrepancies. |
| C++ expresses the operation | The body is ordinary C++ (assignments, calls, conditions, loops). Assembly is limited to narrow primitives: register bindings, empty `asm("" ...)` constraints, a memory barrier, or at most 3 emitted non-VU instructions that the compiler cannot produce otherwise (frame-pointer transport, `sllv`, `cvt.w.s`, COP0, VU macro sequences copied from an accepted pattern). A body that is mostly emitted instructions is a pasted function: DO NOT MERGE. |
| Every emitted instruction or register binding is explained | A `// why:` comment on the same or the previous two lines. Missing: DO NOT MERGE (the worker can resubmit). |
| Declarations | All declarations before the function, nothing after it, one function only. |
| Names | No `param_1`, `iVar1`, `DAT_`, `FUN_`, `undefined4` style names. |
| No trickery | No `.word`, `.incbin`, byte arrays executed as code, casts of data to function pointers to reproduce bytes, or edits outside the WP directory. |
| FLAG "changed outside the WP" | Name the path in REVIEW.md. If it is under `Public\tools`, `layout.tsv`, `functions.tsv`, the queue database or the root documents, and the WP report does not explain it as the orchestrator's own work: overall verdict DO NOT MERGE. |

## REVIEW.md format

```
# Review of <wp>
Reviewer: sonnet. Reviewed <UTC>. Mechanical check: review-auto-<n>.json (<p> PASS, <f> FAIL, <g> FLAG).
Overall: MERGE | MERGE WITH FOLLOW-UP | DO NOT MERGE

| Address | Verdict | Reason |
| --- | --- | --- |
| <A> | MERGE / DO NOT MERGE | <one line> |

Spot check: <A> diff shows Differing words: 0 (yes/no).
Blocked reports: <n> checked, <m> incomplete (<addresses>).
Follow-up (only for MERGE WITH FOLLOW-UP): <items, one line each>.
Mechanical output:
<paste the checker's printed lines>
```

Overall is MERGE when every address is MERGE and nothing is incomplete; MERGE WITH FOLLOW-UP when at least one address is MERGE and something else needs a fix; DO NOT MERGE when no address may be integrated or a shared file was changed by the worker.
