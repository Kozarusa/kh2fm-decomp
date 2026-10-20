# 001e7470 blocked
- Range: 001e7470, 104 bytes. Versions tried: 3. Best: v2 with 3 differing words (100/104 bytes).
- First difference of the best version: !! 001e74cc: adcf0000  sw	t7,0(t6)                                      | 001e74cc: 03e00008  jr	ra
- Changes tried: C7 explicit trailing goto epilogue in do loop (v1, 9 words); C18 register-block struct access replacing final store (v2, 3 words); C13 explicit void return expression (v3, 3 words).
- Why it stops here: R12 conservative block: all remaining differences are last-store delay-slot scheduling; brief forbids repeating barriers, and creating a real branch target would require extra behavior or instruction-emitting asm. R7 streak is 1, no budget overrun.
- Next hypothesis: orchestrator tooling review of final jr delay-slot constraint; no justified untried source-only cookbook change.
