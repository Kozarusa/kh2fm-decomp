# Restore-order recovery attempt 0014dca8

Live layout agrees with the 96-byte archived full original proof. Five explicit saved-register clobber variants were compiled under the pinned compiler. None matches. Clobbering s0 or s1 upgrades its save/restore from sd/ld to sq/lq and increases the frame to 48 bytes while retaining 96 total code bytes. This is a compiler ABI side effect, not a boundary problem. The original nearest proposal differs only in swapping ld s0,0(sp) and ld s1,8(sp) at offsets 72/76.

Next: constrain low-width saved-register values through register inputs after the final stores; avoid clobbers that upgrade ABI saves. Preserve the original inline stores, which remain provisional instruction-preserving source.

```json
[
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_0014dca8_b99d2a2e_v1.verification.json",
    "sha256": "f308d986af270e938707e1a8f9c4d90f0b493fe2bc4c498eed7281b394f34bf5",
    "source_sha256": "2fa88e4ad3075bbd8661505bc15c62e1e26c5df907e63e2d11b1ba9a9fd51247",
    "compiled_size": 96,
    "target_hex": "e0ffbd27ffffa5300000b0ffffffe7300800b1ffffff08311000b2ff2d8080001800bfffffff3131bc99050c2d904001d00112aed40111a6d90100a2d60100a2d70100a2d80100a20800b1df0000b0df1000b2df1800bfdf0800e0032000bd27",
    "exact_match": false
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_0014dca8_b99d2a2e_v2.verification.json",
    "sha256": "20061433b9cff3f375331e9be51892ecf8f13f5cbef090ff1624bf8e04bb1293",
    "source_sha256": "a5ef6524bc658d2c1cd938ce45eee717e84c945a43d26f2fe47165bdea4f5387",
    "compiled_size": 96,
    "target_hex": "e0ffbd27ffffa5300000b0ffffffe7300800b1ffffff08311000b2ff2d8080001800bfffffff3131bc99050c2d904001d00112aed40111a6d90100a2d60100a2d70100a2d80100a20800b1df0000b0df1000b2df1800bfdf0800e0032000bd27",
    "exact_match": false
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_0014dca8_b99d2a2e_v3.verification.json",
    "sha256": "f26804a00f5d512154c31f0f2314b7c7e547456861a8b897e2a086849cb109e6",
    "source_sha256": "71be747aa85381ec9afee747c3ffb5cc1698ec37dd9023ce48dfe802c1ef9f7d",
    "compiled_size": 96,
    "target_hex": "e0ffbd27ffffa5300000b0ffffffe7300800b1ffffff08311000b2ff2d8080001800bfffffff3131bc99050c2d904001d00112aed40111a6d90100a2d60100a2d70100a2d80100a20800b1df0000b0df1000b2df1800bfdf0800e0032000bd27",
    "exact_match": false
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_0014dca8_b99d2a2e_v4.verification.json",
    "sha256": "e82888cfd451f47309cadcea9256d6fa3bce8ccc2fe15aec63b9fd663bb39b3b",
    "source_sha256": "4824f32095fe1b1a596d448a1bc5218a266bac407b10a64c68e4171125fd2cc6",
    "compiled_size": 96,
    "target_hex": "e0ffbd27ffffa5300000b0ffffffe7300800b1ffffff08311000b2ff2d8080001800bfffffff3131bc99050c2d904001d00112aed40111a6d90100a2d60100a2d70100a2d80100a20800b1df0000b0df1000b2df1800bfdf0800e0032000bd27",
    "exact_match": false
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_0014dca8_b99d2a2e_v5.verification.json",
    "sha256": "92ba179aad5a7c3600579d61a23965fd2277fa40b1501ea618d0165315146824",
    "source_sha256": "9c7912b0cb9c1910d2bebfdfc528ccc0d7e276f0e1e54448070120622e9323e9",
    "compiled_size": 96,
    "target_hex": "e0ffbd27ffffa5300000b0ffffffe7300800b1ffffff08311000b2ff2d8080001800bfffffff3131bc99050c2d904001d00112aed40111a6d90100a2d60100a2d70100a2d80100a20800b1df0000b0df1000b2df1800bfdf0800e0032000bd27",
    "exact_match": false
  }
]
```
