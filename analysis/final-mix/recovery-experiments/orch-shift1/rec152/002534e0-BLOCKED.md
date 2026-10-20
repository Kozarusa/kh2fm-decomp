# 002534e0 blocked
- Range: 002534e0, 88 bytes. Versions tried: 2. Best: v1 with 19 differing words (84/88 bytes).
- First difference of the best version: !! 002534e8: ffb00000 sd s0,0(sp) | 0c09f702 jal 27dc08.
- Changes tried: R4.3 both outgoing results returned (19); C7 negate condition and swap blocks (19).
- Why it stops here: R12 conservative stop; original saves s0 before first jal and leaves nop delay; compiler schedules save into delay. No applicable untried C12 controls: locals neither volatile nor bound; result already separate.
- Next hypothesis: prologue scheduling specialist preserving literal return contract.
