# fix<NN>: <one-line title from DEVIATIONS.md row>

| Field | Value |
| --- | --- |
| WP | fix<NN> |
| Model | sonnet if the cause is known, opus if it must be found (rule 2) |
| Worker id | orch1-fix<NN> |
| Source | `DEVIATIONS.md` row <n>, reported by the user on <date>: "<the user's words, verbatim>" |
| Files you may change | <exact list; nothing else> |
| Depends on | nothing (fix WPs go to the front of the queue) |
| Review | <review_wp.py and reviewer agent for recovery fixes; the orchestrator's check for docs fixes> |

## Steps

1. <first concrete step, with the exact command or file>
2. <...>
3. Write `<WP directory>\WP-REPORT.md` in the R11 format of `briefs\_shared.md` and reply with it.

## Done when

<the observable result that shows the user's report is resolved, for example "review_wp.py shows no FAIL" or "STATUS.md shows ...">.

## Never

- Change accepted sources, registries, layout, checkpoints, build helpers or compiler settings. A fix that needs one of those is an O8 question for the user.
