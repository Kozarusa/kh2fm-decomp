# 0019f8f8 submitted
- Range: 0019f8f8, 84 bytes. Source: orch1_rec71_0019f8f8_v5.cpp (exact). Versions tried: 5.
- Changes that mattered: C11(c)(d) s0 register binding for the stored-through pointer (6 to 1 words); C11 call argument uses the original parameter, not the bound one (1 to 0). v5 only adds a why comment to v4.
- Emitted assembly or register bindings: register base asm("$16") plus empty asm to keep the object in s0 as the original does.
- Provisional: names and types are inferred from instructions only.
