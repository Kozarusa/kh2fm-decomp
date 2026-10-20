# 00102180 list scan branch layout

Full 76-byte original range inspected. Native Node layout: next +12, state +28; global head 0038aa40. Eight isolated ordinary C++ variants preserve the scan algorithm but cannot match original branch-likely fetch, immediate null return, and interior alignment nop. Loop variants v0-v5 compile to 72 bytes; explicit lexical goto variants v6-v7 compile to 76 bytes but move the global fetch to an out-of-line edge and change allocation. No exact proof.

Next hypothesis: original SDK routine used hand-scheduled branch-likely fetch and an aligned body label. Investigate callsites and neighboring SDK code before introducing narrowly justified branch glue. Do not pad or substitute binary bytes.

Hash-bound evidence:

```json
[
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_00102180_48c4fb44_v0.verification.json",
    "proof_sha256": "048600a6a97425e0bddc1777e8fa4623bc7a18dc3f8de32787c4c81e5f474547",
    "source_sha256": "4125b2671d611a8351309400e3793bf8a9c0b00fe6f6e62c51c583b51f4ff7a4",
    "compiled_size": 72,
    "exact_match": false,
    "compiled_hex": "2d6800002d10000039000b3c01000c240200a01140aa6e8d0c00ae8d0800c011000000001c00cf8df9ffec152d68c00100008eac01004224f5ff0010040084240800e00300000000",
    "target_hex": "2d6800002d10000039000b3c01000c240200a0550c00ae8d40aa6e8d0400c0152d68c0010800e00300000000000000001c00cf8df6ffec150000000000008eac01004224f2ff001004008424"
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_00102180_48c4fb44_v1.verification.json",
    "proof_sha256": "a0c1f42add02d390aa615480bdf7f2adb53972e31393eba4a125f815a9681d89",
    "source_sha256": "ef30a3e46eaf75e74d3990161d349c4d65134dcfad7a184d901549a575fb7dd8",
    "compiled_size": 72,
    "exact_match": false,
    "compiled_hex": "2d6800002d10000039000b3c01000c240200a01140aa6e8d0c00ae8d0800c0112d68c0011c00cf8df9ffec150000000000008eac01004224f5ff0010040084240800e00300000000",
    "target_hex": "2d6800002d10000039000b3c01000c240200a0550c00ae8d40aa6e8d0400c0152d68c0010800e00300000000000000001c00cf8df6ffec150000000000008eac01004224f2ff001004008424"
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_00102180_48c4fb44_v2.verification.json",
    "proof_sha256": "9beb4a9267225545e8cd8d7230759822ea94a93b108b298943dd0ef04e1e24ef",
    "source_sha256": "ff7da14f2dd505d9a80e3b6edb476af3131106c8272666f14ac33cfa7fe36fac",
    "compiled_size": 72,
    "exact_match": false,
    "compiled_hex": "2d6800002d10000039000c3c01000b240200a01140aa8e8d0c00ae8d0800c0112d68c0011c00cf8df9ffeb150000000000008eac01004224f5ff0010040084240800e00300000000",
    "target_hex": "2d6800002d10000039000b3c01000c240200a0550c00ae8d40aa6e8d0400c0152d68c0010800e00300000000000000001c00cf8df6ffec150000000000008eac01004224f2ff001004008424"
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_00102180_48c4fb44_v3.verification.json",
    "proof_sha256": "29f53cf7fcc525a9917d3a92cf268d345bee53451a7db63ea0a2bbd93921a81d",
    "source_sha256": "d8d2f924c7015c78b8de2abc527a8d4898abd4376f9e62a086239f1a7b989fe0",
    "compiled_size": 72,
    "exact_match": false,
    "compiled_hex": "2d6800002d10000039000b3c01000c240200a01140aa6e8d0c00ae8d0800c0112d68c0011c00cf8df9ffec150000000000008eac01004224f5ff0010040084240800e00300000000",
    "target_hex": "2d6800002d10000039000b3c01000c240200a0550c00ae8d40aa6e8d0400c0152d68c0010800e00300000000000000001c00cf8df6ffec150000000000008eac01004224f2ff001004008424"
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_00102180_48c4fb44_v4.verification.json",
    "proof_sha256": "3cc35219ce5b952cfd5189940b701250f904749b7b1f8557e543939363e3a386",
    "source_sha256": "c3f07166cb73311a72e8337272757f19b8dda0af9ad014c4780db99cc540ef7f",
    "compiled_size": 72,
    "exact_match": false,
    "compiled_hex": "2d6800002d10000039000b3c01000c240200a01140aa6e8d0c00ae8d0800c0112d68c0011c00cf8df9ffec150000000000008eac01004224f5ff0010040084240800e00300000000",
    "target_hex": "2d6800002d10000039000b3c01000c240200a0550c00ae8d40aa6e8d0400c0152d68c0010800e00300000000000000001c00cf8df6ffec150000000000008eac01004224f2ff001004008424"
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_00102180_48c4fb44_v5.verification.json",
    "proof_sha256": "1a33bc2a81ec51e392d57d690d8d4a35e394e6e3c2cdbad294417785f832f15b",
    "source_sha256": "b5fd17c25d091415d6ba39a03f16f22da1eb76f35a2b73781229d8e030192e6e",
    "compiled_size": 72,
    "exact_match": false,
    "compiled_hex": "2d6800002d10000039000b3c01000c240200a01140aa6e8d0c00ae8d0800c0112d68c0011c00cf8df9ffec150000000000008eac01004224f5ff0010040084240800e00300000000",
    "target_hex": "2d6800002d10000039000b3c01000c240200a0550c00ae8d40aa6e8d0400c0152d68c0010800e00300000000000000001c00cf8df6ffec150000000000008eac01004224f2ff001004008424"
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_00102180_48c4fb44_v6.verification.json",
    "proof_sha256": "9365524fe4c22b540302b3c50cf313950aa2d7320b343b56f746f09691286602",
    "source_sha256": "0d9dd660bc8ab27b952a59ba7896e5e63e0d01a0c1661a33582231874cefbee3",
    "compiled_size": 76,
    "exact_match": false,
    "compiled_hex": "2d6000002d1000000e00801139000f3c0c008d8d0900a0112d60a0011c00ae8d01000f24f8ffcf150000000000008dac01004224f4ff0010040084240800e00300000000f3ff001040aaed8d",
    "target_hex": "2d6800002d10000039000b3c01000c240200a0550c00ae8d40aa6e8d0400c0152d68c0010800e00300000000000000001c00cf8df6ffec150000000000008eac01004224f2ff001004008424"
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_00102180_48c4fb44_v7.verification.json",
    "proof_sha256": "7d1026411c0c8cdef76cb844c6d4640d8cc86e17a340647e84c3424f517ae8ac",
    "source_sha256": "8528885cd92fc4bece136e00794adb966084a393e8bb98f20bcdcc1fdbe84148",
    "compiled_size": 76,
    "exact_match": false,
    "compiled_hex": "2d6000002d1000000e00801139000f3c0c008d8d0900a0112d60a0011c00ae8d01000f24f8ffcf150000000000008dac01004224f4ff0010040084240800e00300000000f3ff001040aaed8d",
    "target_hex": "2d6800002d10000039000b3c01000c240200a0550c00ae8d40aa6e8d0400c0152d68c0010800e00300000000000000001c00cf8df6ffec150000000000008eac01004224f2ff001004008424"
  }
]
```
