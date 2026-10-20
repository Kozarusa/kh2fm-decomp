# 002713a0: branch-delay address materialization

The complete original range is40 bytes. Typed canonical/direct models match size but use bnel rather than bne and allocate constant3 to t7 rather than t6. A precise count lifetime plus post-pointer-store memory dependency fixes every word except the first bnel opcode. Both branch-probability hints leave that same one-word difference. Adding an else-edge marker changes bnel to bne but prevents the original duplicated high-address LUI delay-slot placement, producing44 bytes. Shared high materialization folds the branch into a conditional move and32 bytes. All failures are preserved. Next hypothesis: vary branch representation or pointer load visibility to permit ordinary bne with the else-path LUI in its delay slot while retaining the original duplicate fallthrough LUI; do not repeat likelihood hints or broad else barriers.

002713a0-blocked-evidence.json binds each complete original range, isolated source and compiler proof.
