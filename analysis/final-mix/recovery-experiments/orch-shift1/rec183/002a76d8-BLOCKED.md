# 002a76d8 blocked
- Range: 002a76d8, 128 bytes. Versions tried: 0. Best: none with no differing-word count (not compiled/128 bytes).
- First difference of the best version: none; no probe.
- Changes tried: none. Return audit: both globals zero reaches jr ra with untouched entry v0/f0; nonzero globals call 00106420 or an indirect destructor, whose outgoing result reaches jr ra. Mixed untouched-entry and outgoing-callee-result paths cannot be represented under literal R4.3.
- Why it stops here: R12 unresolved ABI contract.
- Next hypothesis: establish the return ABI covering untouched-entry and outgoing-callee-result paths before drafting.

Closure correction, 2026-10-18T13:22:23Z: Independent reviewer found SAFE TO CLOSE; no integration. Precise return audit: when the second global is nonzero, destructor calls run, but the final 00106420 call at 002a7734 supersedes their results. When only the first global is nonzero, the final call is 00106420 at 002a76f8. When both globals are zero, the function returns with untouched entry v0/f0. The mixed untouched-entry/outgoing-callee-result contract remains unresolved under literal R4.3, so the abi-layout block remains valid. Root verified no outstanding packet/objdump processes on Windows or WSL. Final status: stopped: command receipt loss; no environment failure established. No claims, source edits, or probes performed during this correction.
