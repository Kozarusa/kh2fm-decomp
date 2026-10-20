# Symbol-address family follow-up

The 00160ac0 exact isolated result supplies a positive control: an integer fourth-call argument produced ori and a displaced delay-slot zero setup, while an extern char function-address expression produced the original addiu and schedule without emitting instructions manually.

The expanded census compares ori/addiu pairs by register fields and low immediate independent of position. This catches 00160ac0, which a same-offset-only search misses. The census is a hypothesis generator; coincident low immediates can be false positives. Complete original range bytes were independently extracted from original ELF load segments and SHA256-bound in symbol-address-census-original-evidence.json. The original ELF identity was checked.

Priority follow-up after atomic claims:

1. 0031b070: three vtable-like integer address stores, 80-byte complete range, four original differences. Replace 0x348590, 0x347e60, 0x347f98 with addresses of extern char D symbols. A negative low immediate should automatically correct the first upper half from 0x34 to 0x35. Preserve existing barrier initially.
2. 0014a138: a constructor-like call uses literal 0x14a0a0 as fourth argument. Replace only that expression with extern char func_0014a0a0 address and retain measured global 0032b96c. Complete call-argument width and delay-slot scheduling may need further evidence.
3. 00173518: third call argument 0x1734b0 should be a symbolic function address. The original second argument remains numeric 0x36b2. Extract only this function from the multi-function archive; preserve required declarations before the first definition.
4. 0015d730: two global object arguments 0x34af40 and 0x34b0e0 recur in four condition branches. Use extern char D symbols; low halves are negative, so high halves should adjust. Preserve condition structure before testing signature widths.

No census target was claimed or modified during the primary exclusive integration window. No compiler probes ran while paused. Integration remains primary-owned.
