# Fresh wrapper investigation: 00137c50

The complete 56-byte initialization proposal has six independent word stores and a final direct helper call. Reversing equivalent source-store groups reduces the mismatch to three stores while preserving the prologue, constants, argument preparation, tail jump, and stack restore. Narrow field dependencies and volatile commit markers perturb other scheduling; none is accepted. Next examine aggregate field typing or a store group representation that keeps the already correct prologue and moves only the last zero and two intermediate stores. Do not repeat the recorded store permutations or memory commit markers.

`00137c50-fresh56-evidence.json` binds 24 complete proposals and original-range comparisons. No unsuccessful source is registered. No compiler-impossibility claim is made.
