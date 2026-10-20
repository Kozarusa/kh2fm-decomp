# 002ab100 blocked
- Range: 002ab100, 128 bytes. Versions tried: 8. Best: v8 with 13 differing words (128/128 bytes).
- First difference of the best version: !! 002ab10c: 8deef610 lw t6,-2544(t7) | 002ab10c: 8deaf610 lw t2,-2544(t7).
- Changes tried: v1 fresh 29 words; C1 parameter narrowing audit v2 31; result transport v3 31; C11(b) loop mask temporary v4 25; v5 bundled base temporary/operand reversal 29 (no isolated effect); v6 operand restoration 29; C11(c) loop counter binding v7 22; C11(b) positive mask temporary v8 13.
- Why it stops here: budget reached (8).
- Next hypothesis: C11(b) introduce a loop base temporary preserving base-first operand order, then test bindings separately.
- Problems: v5 bundled a temporary with addition operand reversal; preserved v4/v5 and correction in PROGRESS. v5 ineligible as future baseline pending source-policy review. v6 restoration consumed normal version and streak; no counter resets.

Review follow-up: DEVIATIONS22 remains; v5 is ineligible. v6 restores operand order but retains reassociation. v7 branches from valid v4. Future submission must establish the s32 entry argument domain because original bgez tests the incoming register while v2 onward narrowed the initial s64 parameter. No isolated v5 effect is established. Static source evidence does not independently prove historical tool timing or polling.
