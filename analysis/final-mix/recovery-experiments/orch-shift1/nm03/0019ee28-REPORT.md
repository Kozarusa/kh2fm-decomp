# 0019ee28 submitted
- Range: 0019ee28, 52 bytes. Source: orch1_nm03_0019ee28_v5.cpp (exact). Versions tried: 5.
- Changes that mattered: explicit base pointer to D_00350448 for the +32 float store (7 to 5 words), C10(d) memory barrier for store order (5 to 2), zero declared after the base pointer so mtc1 follows the lui (2 to 0).
- Emitted assembly or register bindings: empty asm("" : "+r"(base)) to materialize the base pointer in its own register; empty asm volatile memory barrier to keep store order.
- Provisional: names and types are inferred from instructions only.
