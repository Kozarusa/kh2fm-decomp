# lay01: specialist recovery, layout and ABI family

| Field | Value |
| --- | --- |
| WP | lay01 |
| Model | opus |
| Worker id | orch1-lay01 |
| WP directory | `C:\Users\KoZa\Documents\AGENTS\Codex\analysis\final-mix\recovery-experiments\orch-shift1\lay01` |
| WSL directory | `/mnt/c/Users/KoZa/Documents/AGENTS/Codex/analysis/final-mix/recovery-experiments/orch-shift1/lay01` |
| Queues, in order | `abi-layout`, `aggregate-abi-layout`, `constructor-buffer-alias`, `constructor-final-store-alias`, `initialization-store-groups`, `table-initializer-layout`, `teardown-global-allocation`, `variadic-frame-layout`, `sdk-frame-abi`, `context-save-runtime`, `indexed-header-copy` |
| K (targets to claim) | 6 |
| Version budget per target | 12, and stop after 3 versions without improvement (R7) |
| Size rule | none (do not release for size) |
| Depends on | nothing |
| Review | `review_wp.py` on the WP directory, then the reviewer agent |

## Steps

1. R0.
2. Repeat R1 to R10 until you have claimed K targets and each one is submitted or blocked. Every target in these queues was blocked before: R2 requires you to read its blocker report. Your first change must be the report's "next hypothesis" unless the report shows it was already tried; then take the next cookbook change for the symptom.
3. When you block again, use the consolidated specialty from the R9 table (not the old queue name), so the next specialist sees one queue per symptom.
4. R11.

## Family table (for O12: copy the matching queue list into the header)

| Family | Queues |
| --- | --- |
| pro (prologue/epilogue) | `prologue-epilogue`, `address-prologue-scheduling`, `byte-prologue-scheduling`, `float-address-prologue`, `prologue-load-scheduling`, `prologue-save-order`, `prologue-scheduling`, `sdk-callback-prologue`, `sdk-prologue-operation-scheduling`, `wrapper-prologue-save-order`, `primary-store-epilogues`, `float-epilogues`, `float-boolean-epilogue`, `tail-call-frame-elision`, `loop-save-order` |
| brl (branch and lifetime) | `branch-layout`, `register-allocation`, `store-order`, `float-transport`, `address-materialization`, `branch-delay-address-lifetime`, `branch-delay-lifetime`, `float-branch-layout`, `float-condition-block-layout`, `sdk-list-branch-layout`, `sdk-range-guard-branch-layout`, `control-transfer`, `dispatch-result-lifetime`, `float-predicate-lifetimes`, `float-result-register-allocation`, `bitmap-index-register-lifetime`, `linked-list-memory-lifetime`, `allocator-pointer-lifetimes`, `argument-register-scheduling`, `callback-address-scheduling`, `conditional-argument-transport`, `digit-loop-scheduling`, `indexed-bit-scheduling`, `indexed-table-scheduling`, `header-mirror-scheduling`, `float-conversion-scheduling` |
| lay (layout and ABI) | `abi-layout`, `aggregate-abi-layout`, `constructor-buffer-alias`, `constructor-final-store-alias`, `initialization-store-groups`, `table-initializer-layout`, `teardown-global-allocation`, `variadic-frame-layout`, `sdk-frame-abi`, `context-save-runtime`, `indexed-header-copy` |
| med (medium blockers) | `medium-register-and-branch` |
| big (large control flow) | `large-control-flow` |
| vu | `vu-macro` (only after the roadmap's phase-4 spec exists) |

Never assign `structured-startup-assembly-review`, `boundary-review` or `privileged-instructions` to a recovery WP; they wait for a spec WP or the user (roadmap phase 4).
