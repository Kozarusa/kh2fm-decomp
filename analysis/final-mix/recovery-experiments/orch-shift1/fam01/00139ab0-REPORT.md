# 00139ab0 submitted
- Range: 00139ab0, 116 bytes. Source: orch1_fam01_00139ab0_v1.cpp (exact). Versions tried: 1.
- Changes that mattered: C7/C9 ternary `cur == 0 ? head->next : *(Node* volatile*)&cur->next` in a comma-while condition; C11 load the list head unconditionally first (`head = D_00347f80`) so it lands in a0 in the bnez delay slot.
- Emitted assembly or register bindings: none (one volatile read, with a why comment).
- Provisional: names and types are inferred from instructions only.
