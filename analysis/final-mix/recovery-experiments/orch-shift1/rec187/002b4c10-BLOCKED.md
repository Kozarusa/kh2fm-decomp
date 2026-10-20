# 002b4c10 blocked
Range: 002b4c10, 116 bytes. Versions tried: 1. Best: v1 with 27 differing words (112/116 bytes).
First difference of the best version: !! 002b4c18: ffb00000 sd s0,0(sp) | 002b4c18: 0c0902e8 jal 240ba0 <func_00240ba0>.
Changes tried: Initial source preserves the entire call sequence, tail result and defined unsigned address transport. The compiler places the s0 save in the first call delay slot, removing the original nop. All subsequent instructions match at a one-instruction offset.
Why it stops here: Conservative R12 block. The first difference is compiler-managed saved-register scheduling; no cookbook control covers an omitted original nop without instruction-emitting assembly.
Next hypothesis: Find a permitted compiler scheduling control for the first-call saved-register delay slot without changing the ABI.
