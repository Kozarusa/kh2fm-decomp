# 00284ea8 submitted
- Range: 00284ea8, 68 bytes. Source: orch1_nm26_00284ea8_v4.cpp (exact). Versions tried: 4.
- Changes that mattered: C11b isolated the table without changing output (v2: 3 words); C11c bound the initialized table to $14 (v3: 2 words); a separate C11c bound the initialized callback to $15 (v4: exact).
- Emitted assembly or register bindings: no emitted instructions or guards. Initialized table binding $14 preserves original t6 table load; initialized callback binding $15 preserves original t7 callback load and jalr. Each has its own why comment.
- Provisional: names and types are inferred from instructions only.
- R4.3: the sole exit returns the genuine callback result after clearing D_0035f2c0. No invented result or uninitialized binding.
- Baselines: v1 copies rec165 v1; v2 compares against nm26 v1; v3 against nm26 v2; v4 against nm26 v3. Complete source comparisons inspected before saving successors; only one control changed per version.
