# Return 002278e0 for a declaration correction

The two submitted rec133 sources declare the same C-linkage callee `func_00227930(u8*)` with incompatible return types: u32 in 00225690 v1 and void in 002278e0 v1. Both isolated probes are exact, but the declarations should agree before the batch is integrated. The packet lists no accepted source declaration for this callee. The caller at 00225690 preserves its callee result; at 002278e0 the result is ignored and the other path leaves v0 unset.

Orchestrator review: DO NOT MERGE 002278e0 v1 pending correction. Return it through O4. The worker's authorized follow-up changes only its callee declaration to u32 in a new v2 source, claims the same address again, and obtains a new exact proof. The old source and proof remain evidence. This is a correction to the already claimed sixth target, not permission to claim a seventh target. A new independent reviewer must inspect the corrected submission with the rest of rec133.
