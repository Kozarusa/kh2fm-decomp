# Agent roster

Who may do what. The orchestrator edits this file; an agent never edits it. Any agent, whatever model it runs, follows the same worker manual (`briefs/_shared.md`) and is judged by the same mechanical checks, so the roster only decides who gets which work and who may integrate.

## Roles

| Role | May do | Never |
| --- | --- | --- |
| Orchestrator (exactly one at a time, holds `locks/ORCHESTRATOR.lock`) | Spawn and stop workers, review, integrate (RECIPES O3), bookkeeping | Write recovery C++ |
| Worker (any number up to the cap in ORCHESTRATION rule 3) | Claim targets, probe, submit or block | Anything outside its WP directory |
| Reviewer | Read a finished WP and write `REVIEW.md` | Probe, build, integrate |

## Tiers and what each tier may claim

| Tier | Intended for | Queues (in this order) | Size | Version budget |
| --- | --- | --- | --- | --- |
| T1 | Small, fast or cheaper models | `general` | up to 128 bytes | 8 |
| T2 | Strong general models | `general`, then the consolidated specialties `register-allocation`, `store-order`, `branch-layout` | any | 12 |
| T3 | Strongest models | any specialist queue, `medium-register-and-branch`, `large-control-flow` | any | 12 |

A new or unfamiliar agent starts at T1 for its first WP regardless of model, and moves up only when the orchestrator has reviewed one of its WPs with no DO NOT MERGE.

## Agents

| Worker-id prefix | Tool | Model | Tier | Launched by | Notes |
| --- | --- | --- | --- | --- | --- |
| `orch1-rec181`, `orch1-rec182` | Codex collaboration subagents | GPT-6 inherited | General recovery | gpt6-orch-oct18 | Renewed interval; K6 budget8 strict R7; after orchew fresh preflight and usage. Separate all controls, literal return/declaration policies. |
| `orch1-rec183`, `orch1-rec184` | Codex collaboration subagents | GPT-6 inherited | General recovery | gpt6-orch-oct18 | K6 budget8 strict R7; after rec181/182 closure and eligible publication, fresh preflight/usage. |
| `orch1-nm34` | Codex collaboration subagent | GPT-6 inherited | Named scheduling retry | gpt6-orch-oct18 | K1 budget8 strict R7;002a74c0 rec181v2 baseline, isolate existing bit binding; after rec184 closure/publication and fresh preflight/usage. |
| `orch1-nm35` | Codex collaboration subagent | GPT-6 inherited | Exact sibling retry | gpt6-orch-oct18 | K1 budget8 strict R7;002aa450 result binding then separate guard, named002aab90 sibling; after nm34 closure/publication and fresh preflight/usage. |
| `orch1-rec185`, `orch1-rec186` | Codex collaboration subagents | GPT-6 inherited | General recovery | gpt6-orch-oct18 | K6 budget8 strict R7; after rec184/nm34 closure and eligible publication, fresh preflight/usage; serial at60%. |
| `orch1-rec187`, `orch1-rec188` | Codex collaboration subagents | GPT-6 inherited | General recovery | gpt6-orch-oct18 | K6, budget8, strict R7; after rec185/186 closure and eligible publication, fresh preflight/usage. Preserve address association and operand order. |
| `orch1-nm36` | Codex collaboration subagent | GPT-6 inherited | Named prologue/epilogue retry | gpt6-orch-oct19-retry | K1, budget8 new attempts, strict R7; only 002b6ab8. Start at v8 from rec189 evidence; isolate accepted 002b6b84 explicit frame restoration. |
| `orch1-rec190`, `orch1-rec191` | Codex collaboration subagents | GPT-6 inherited | General recovery | gpt6-orch-oct19-retry | K6, budget8, strict R7; after nm36 publication and fresh preflight/usage. Preserve literal R4.3/R4.5, defined semantics, isolated controls and complete receipts. |
| `orch1-rec180`, `orch1-rec181` | Codex collaboration subagents | GPT-6 inherited | General recovery | gpt6-orch-oct17 | K6 budget8 strict R7; after rec178/179 closure and eligible integration, fresh preflight/usage. Serial at60%; every temporary, binding and guard separate. |
| `orch1-rec178`, `orch1-rec179` | Codex collaboration subagents | GPT-6 inherited | General recovery | gpt6-orch-oct17 | K6 budget8 strict R7 each; after nm32/nm33 closure and eligible integration, fresh preflight/usage. Serial at60%; defined source semantics and unique failed-probe versions. |
| `orch1-nm33` | Codex collaboration subagent | GPT-6 inherited | Named signed-comparison retry | gpt6-orch-oct17 | K1 budget8 strict R7;00294408 rec175v3 one word, isolate signed result temporary while preserving accepted callee declaration. After rec176/177 closure/publication. |
| `orch1-nm32` | Codex collaboration subagent | GPT-6 inherited | Named register-allocation retry | gpt6-orch-oct17 | K1 budget8 strict R7,00293148 earliest rec174v3 two words; isolate index/count initialization order. After rec176/177 closure and eligible integration. |
| `orch1-fix04` | Codex collaboration subagent | GPT-6 inherited | Named source-semantics correction | gpt6-orch-oct17 | K1 budget2; rejected00292a58 baseline then isolated defined unsigned shift with original signed word transport. After W31 publication and O4; before nm31/rec175. |
| `orch1-rec176`, `orch1-rec177` | Codex collaboration subagents | GPT-6 inherited | General recovery | gpt6-orch-oct17 | K6 budget8 strict R7; after nm31/rec175 closure and eligible integration, fresh preflight/usage. Serial at60%; failed probes consume unique versions. |
| `orch1-rec175` | Codex collaboration subagent | GPT-6 inherited | General recovery | gpt6-orch-oct17 | K6 budget8 strictR7; partner nm31 after rec173/174 closure and eligible integration, fresh preflight/usage. Serial at60%. |
| `orch1-nm31` | Codex collaboration subagent | GPT-6 inherited | Named register-allocation retry | gpt6-orch-oct17 | K1 budget8 strictR7,0028f690 earliest rec172v4 fourwords; isolate address temporary preserving operand order. After rec173/174 closure/integration. |
| `orch1-rec173`, `orch1-rec174` | Codex collaboration subagents | GPT-6 inherited | General recovery | gpt6-orch-oct17 | K6 budget8 strict R7 each; after nm29/nm30 closure and eligible integration, fresh preflight/usage. Serial at60%. |
| `orch1-nm30` | Codex collaboration subagent | GPT-6 inherited | Named input-width retry | gpt6-orch-oct17 | K1 budget8 strictR7; explicit register-allocation queue for0028b078. After rec172/nm29 closure and eligible integration. nm28 remains closed with no compiler work. |
| `orch1-nm29` | Codex collaboration subagent | GPT-6 inherited | Named branch-layout retry | gpt6-orch-oct17 | K1 budget8 strictR7;0028d068 rec171v4 two words, isolate outer early return. After nm28/rec172 closure/integration and baseline review. |
| `orch1-rec172` | Codex collaboration subagent | GPT-6 inherited | General recovery | gpt6-orch-oct17 | K6 budget8 strictR7; after nm28 closure and eligible integration, fresh preflight/usage. Serial at60%. |
| `orch1-nm28` | Codex collaboration subagent | GPT-6 inherited | Named input-width retry | gpt6-orch-oct17 | K1 budget8 strictR7;0028b078 earliest rec167v1, isolate count-width correction. After rec170/171 closure/integration; alone at60%. |
| `orch1-rec170`, `orch1-rec171` | Codex collaboration subagents | GPT-6 inherited | General recovery | gpt6-orch-oct17 | K6 budget8 strictR7 each; after nm27/rec169 closure/integration and fresh preflight/usage. Serial at60%; literalR4.3/R4.5 and defined optional cursors. |
| `orch1-rec169` | Codex collaboration subagent | GPT-6 inherited | General recovery | gpt6-orch-oct17 | K6 budget8 strictR7; all claims count. After fix02 closure/integration, partner nm27 below60%, otherwise serial. Literal R4.3/R4.5 and pure-leaf distinction required. |
| `orch1-fix03` | Codex collaboration subagent | GPT-6 inherited | Named source-semantics correction | gpt6-orch-oct17 | K1 budget2; unchanged baseline then isolated unsigned integer cursor for00288f60. After fix02 rejection/closure, before nm27/rec169. |
| `orch1-fix02` | Codex collaboration subagent | GPT-6 inherited | Named pure-leaf recovery | gpt6-orch-oct17 | K2 budget8 strictR7; 00288f60/00288fd8 overblocked by rec168. Literal void case, no policy exception. After rec167/168 closure/integration, before nm27. |
| `orch1-nm27` | Codex collaboration subagent | GPT-6 inherited | Named condition-layout retry | gpt6-orch-oct17 | K1 budget8 strictR7; 00266678 from rec156v2, retain memory barrier, isolate C7. After rec167/168 closure/integration; alone at60%. |
| `orch1-rec168` | Codex collaboration subagent | GPT-6 inherited | General recovery | gpt6-orch-oct17 | K6 budget8 strictR7, every claim counts; literal R4.3/R4.5. After nm26/rec166 closure and eligible integration; serial at60%. |
| `orch1-fix01` | Codex collaboration subagent | GPT-6 inherited | Named correction/resubmission | next authorized successor | K3: reprobe00285d18 unchanged; copy/probe then isolated u32-to-s32 callee declaration repairs for002865d0/00287430. New explicit resume, fresh preflight/usage; no extra rec164 versions. |
| `orch1-nm26` | Codex collaboration subagent | GPT-6 inherited | Named register-allocation retry | gpt6-orch-oct16-resume | K1 budget8 strictR7; only00284ea8, separate table temporary/binding/callback binding, accepted00276b10 pattern. After164/165 closure/integration and fresh preflight/usage; alone above60%. |
| `orch1-rec166`, `orch1-rec167` | Codex collaboration subagents | GPT-6 inherited | General recovery | gpt6-orch-oct16-resume | Ready after164/165 closure/integration, fresh preflight/usage; serial above60%. K6 budget8 strictR7 literalR4.3. |
| `orch1-rec164`, `orch1-rec165` | Codex collaboration subagents | GPT-6 inherited | General recovery | gpt6-orch-oct16-resume | Ready after rec162/163 reviewed and closed, eligible integration and fresh preflight/usage. K6 budget8 strictR7; literal R4.3 and isolated controls. |
| `orch1-rec163` | Codex collaboration subagent | GPT-6 inherited | General recovery | gpt6-orch-oct16-resume | Partner rec162 only after new explicit human continue, fresh preflight and usage; K6 budget8 strictR7, literal R4.3, one control per version. |
| `orch1-rec162` | Codex collaboration subagent | GPT-6 inherited | General recovery | next authorized successor | Ready only after a new explicit human resume, fresh preflight and usage checks; K6 budget8 strictR7, literal R4.3, one control per version. |
| `orch1-rec160`, `orch1-rec161` | Codex collaboration subagents | GPT-6 inherited | General recovery | gpt6-orch-oct16-resume | K6 budget8 strictR7 every claim counts, every-exit R4.3; after rec158/159 integration and fresh preflight/usage. |
| `orch1-rec158`, `orch1-rec159` | Codex collaboration subagents | GPT-6 inherited | General recovery | gpt6-orch-oct16-resume | K6 budget8 strictR7 every claim counts; every-exit R4.3; after rec156/157 integration and fresh preflight/usage. |
| `orch1-rec157` | Codex collaboration subagent | GPT-6 inherited | General recovery | gpt6-orch-oct16-resume | K6 budget8 strictR7 every claim counts; every-exit R4.3; after fresh orchee preflight. |
| `orch1-rec155`, `orch1-rec156` | Codex collaboration subagents | GPT-6 inherited | General recovery | gpt6-orch-oct16 | K6 each, budget8, strictR7, every claim counts, every-exit return audit; after nm25/rec154 close, serial at 5h60%. |
| `orch1-nm25` | Codex collaboration subagent | GPT-6 inherited | Named strong retry | gpt6-orch-oct16 | K1 budget12 strictR7; 00242908 from nm24 v3, shared-done-label guard hypothesis; only after rec152/153 close and fresh preflight. |
| `orch1-rec154` | Codex collaboration subagent | GPT-6 inherited | General recovery | gpt6-orch-oct16 | K6 budget8 strictR7 every claim counts; partner nm25 after rec152/153 close; every-exit return audit. |
| `orch1-nm13`, `orch1-nm14` (Shift 2) | Codex collaboration subagent | GPT-6 inherited from the user-requested orchestrator | Per named brief | gpt6-orch | User's 2026-10-13 handoff authorizes GPT-6 orchestration and the named retry wave. Claude model names are unavailable here; retain nm13's 12-version and nm14's 8-version limits and all manual checks. These are local managed subagents, not external sessions. |
| `orch1-rec132`, `orch1-rec133`, `orch1-nm15`, `orch1-nm16` (Shift 2) | Codex collaboration subagent | GPT-6 inherited | Per named brief | gpt6-orch | Continue user-authorized alternating general and retry rounds. Version limits are 8 for general, 1 for trap-only targets, 8 for nm15 entry-register target and 12 for nm16. |
| `orch1-nm17`, `orch1-rec134`, `orch1-rec135` (Shift 2 resume) | Codex collaboration subagent | GPT-6 inherited | Per brief | gpt6-orch | nm17 K1 budget12; general K6 budget8. Start only after fresh preflight PASS. |
| `orch1-nm18` (Shift 2 resume) | Codex collaboration subagent | GPT-6 inherited | Strong retry | gpt6-orch | K2 named targets, budget12, strict R7. Dispatch after rec134/rec135 close. |
| `orch1-nm19` (Shift 2 resume) | Codex collaboration subagent | GPT-6 inherited | Strong specialist retry | gpt6-orch | K2 budget12; only the verified lq/sq and four-op VU primitives in its brief may emit instructions. |
| `orch1-rec136`, `orch1-rec137` (ready) | Codex collaboration subagents | GPT-6 inherited | General recovery | gpt6-orch | K6 each, budget8, strict R7, every claim counts. Serial at5h60%; dispatch after nm18/nm19 close. |
| `orch1-nm20` (ready) | Codex collaboration subagent | GPT-6 inherited | Strong specialist retry | gpt6-orch | K1, budget12; deferred001b27f0 in store-order after general round; only verified lq/sq primitive. |
| orch1-nm22 (ready) | Codex collaboration subagent | GPT-6 inherited | Strong retry | gpt6-orch-nm20 | K2budget12strictR7, 002341e8/00234298 four-word residuals; after rec141/142, usage permitting. |
| orch1-rec141, orch1-rec142 (ready) | Codex collaboration subagents | GPT-6 inherited | General recovery | gpt6-orch-nm20 | K6budget8strictR7; every claim counts; after nm21/rec140, serial at5h60%. |
| orch1-rec140 (ready) | Codex collaboration subagent | GPT-6 inherited | General recovery | gpt6-orch-nm20 | K6budget8strictR7, every claim counts; partner nm21 after rec138/139. |
| orch1-nm21 (ready) | Codex collaboration subagent | GPT-6 inherited | Strong retry | gpt6-orch-nm20 | K2 budget12 strictR7, 0022f528 and00232110 after rec138/139; no emitted asm. |
| orch1-rec138, orch1-rec139 (ready) | Codex collaboration subagents | GPT-6 inherited | General recovery | gpt6-orch-nm20 | K6 each, budget8, strict R7; every claim counts. Dispatch after nm20 closes; serial at 5h60%. |
| orch1-rec143 | Codex collaboration subagent | GPT-6 inherited | General recovery | gpt6-orch-24h | K6 budget8 strictR7 every claim counts; active after orchdv preflight PASS. |
| orch1-rec144 | Codex collaboration subagent | GPT-6 inherited | General recovery | gpt6-orch-24h | K6 budget8 strictR7 every claim counts; ready after nm22/rec143 close and preflight PASS. |
| orch1-rec145 | Codex collaboration subagent | GPT-6 inherited | General recovery | gpt6-orch-24h | K6 budget8 strictR7 every claim counts; ready after nm22/rec143 close and preflight PASS. |
| orch1-nm23 | Codex collaboration subagent | GPT-6 inherited | Strong retry | gpt6-orch-24h | K3 budget12 strictR7, named reviewed two-word residuals after rec144/145 close and preflight PASS. |
| orch1-rec146 | Codex collaboration subagent | GPT-6 inherited | General recovery | gpt6-orch-24h | K6 budget8 strictR7 every claim counts; ready partner nm23 after rec144/145 close and preflight PASS. |
| orch1-rec147 | Codex collaboration subagent | GPT-6 inherited | General recovery | gpt6-orch-24h | K6 budget8 strict R7; every claim counts; ready after nm23/rec146 close and fresh preflight PASS. |
| orch1-rec148 | Codex collaboration subagent | GPT-6 inherited | General recovery | gpt6-orch-24h | K6 budget8 strict R7; every claim counts; ready after nm23/rec146 close and fresh preflight PASS. |
| orch1-rec149 | Codex collaboration subagent | GPT-6 inherited | General recovery | gpt6-orch-oct15 | K6 budget8 strictR7, every claim counts; after rec147/148 close and fresh preflight. |
| orch1-rec150 | Codex collaboration subagent | GPT-6 inherited | General recovery | gpt6-orch-oct15 | K6 budget8 strictR7, every claim counts; after rec147/148 close and fresh preflight. |
| orch1-nm24 | Codex collaboration subagent | GPT-6 inherited | Named strong retry | gpt6-orch-oct15 | K1 budget12 strictR7; only00242908 after149/150. |
| orch1-rec151 | Codex collaboration subagent | GPT-6 inherited | General recovery | gpt6-orch-oct15 | K6 budget8 strictR7 every claim counts; partner nm24 after149/150. |
| orch1-rec152 | Codex collaboration subagent | GPT-6 inherited | General recovery | gpt6-orch-oct15 | K6 budget8 strictR7 everyclaimcounts; after nm24/rec151. |
| orch1-rec153 | Codex collaboration subagent | GPT-6 inherited | General recovery | gpt6-orch-oct15 | K6 budget8 strictR7 everyclaimcounts; after nm24/rec151. |
| `orch1-` | Claude Code subagent | sonnet (T1/T2), opus (T3) | per brief | the orchestrator (Agent tool) | Counts against Claude usage |
| `cdx1-` ... | Codex CLI | (user's choice) | T1 until proven | the user, in a terminal | Needs WSL permission, see `agents/LAUNCH.md` |
| `opc1-` ... | opencode | (user's choice; "space bunny" noted by the user) | T1 until proven | the user, in a terminal | Same |
| `cdx1-rec10` | Codex CLI (assumed; rename to `opc1-` if it is opencode) | GPT-6 | T1 (first WP) | the user, in a terminal | Brief `briefs/cdx1-rec10.md`; first launch arrived with an unfilled template and stopped safely (no claims) |
| `cdx1-rec12` | Codex CLI | GPT-6 | T1 (second WP) | the user, in a terminal | Brief `briefs/cdx1-rec12.md`: general queue, K=6. Its first WP cdx1-rec10 ran clean once WSL access was granted (6 blocked under the old R3 wording, all later recovered by fam01/fam02). |
| `opc1-rec11` | opencode | space-bunny (provider unknown) | T1 (probation passed 2026-10-13) | the user, in a terminal | Probation brief `briefs/opc1-rec11.md`: 3 listed addresses, one lease at a time. Result: 2 exact, 1 blocked, every report line matched the queue and files (rec11 REVIEW.md). The suspension is lifted; it may take normal T1 general-queue briefs under a new id. |
| SUSPENDED: `orch1-pro02` (second instance) | opencode | space-bunny (provider unknown; opencode.ai/data/unknown/space-bunny) | T3 by inheritance (it took over pro02) | the user, 2026-10-12 18:09Z | Picked up pro02 from its PROGRESS.md and continued claim 4/6 (`002006b0`); SUSPENDED 2026-10-12 18:13Z: held 11 leases at once (DEVIATIONS #1); user asked to stop it; it stopped at 18:13:42Z with 0 submitted, 4 blocked. A retry needs its own id (`opc1-rec11`), a fresh T1 REC brief, and a lease check after its first claim. Future outside agents get their own `<prefix><n>-` id. |
| `recovery-a/b/c` | earlier Codex workers | - | - | - | `recovery-a` parked by the user; do not use any of the three unless the user says so |

Add a row for every new agent before it starts. The worker id must start with the prefix of its row and be unique among running agents (it is also the `--worker` name in the queue).

## WP ids for external agents

Each running agent gets its own WP id and directory, never shared: the compiler scratch folder is named after the source file, so two agents using the same WP id would overwrite each other's compiles. Give external agents ids of the form `<prefix><n>` followed by the brief name, for example `cdx1-rec06` with directory `recovery-experiments\orch-shift1\cdx1-rec06`. The brief is the matching template filled in (`REC-template.md` for T1, `SPEC-template.md` for T2/T3), saved as `briefs\cdx1-rec06.md`.

## Concurrency limits

- At most 2 workers at once by default (rule 3); the user may raise it. External agents count.
- At most 3 probes run at once across all agents (`kh2w.py probe` enforces this).
- One integration at a time, only with no leases and no live worker.








