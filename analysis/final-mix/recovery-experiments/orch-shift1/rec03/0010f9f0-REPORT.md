# 0010f9f0 submitted
- Range: 0010f9f0, 52 bytes. Source: orch1_rec03_0010f9f0_v4.cpp (exact). Versions tried: 4.
- Changes that mattered: C14 Quad typedef gives lq/sq (v1, 2 words off); empty asm barrier on destination pointer gives zero-offset sq (v3); C11c register bindings $15 (destination) and $8 (value) give t7/t0 (v4).
- Emitted assembly or register bindings: register Quad* destination asm("$15") plus empty asm("" : "+r"(destination)) (keeps zero-offset store address in t7); register Quad value asm("$8") (original moves the quad through t0).
- Provisional: names and types are inferred from instructions only.
