# Default-result guard lifetime 001dccc8

Live range is 88 bytes. Symbolic D_00352b00, u8 second parameter and word-width helper arguments remove address and extension mismatches. Original intentionally initializes t5 zero and returns through v0 copies in both guard delay slots. Plain source optimizes the default t5 away (76 bytes). Fixed t5 result plus return constraint reaches84 bytes; adding initial read/write constraint reaches88 but changes mask/load order and delay slots. Explicit early return mask form remains unmatched. Six complete failed variants preserved.

Next: preserve an unconstrained zero result through only the second guard, while the first guard retains direct return0; avoid forcing t5 before the mask materialization because that changes scratch allocation.

```json
[
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_001dccc8_a4cd07fb_v1.verification.json",
    "sha256": "8b1419a0d72bf6949050c4818a05ec85e4f676ee12647167999e08f47c53bdf1",
    "source_sha256": "a47b9e9bc5eb2fb0ed3a811179348479aea29d4c1715fdcb13a328c8682b7905",
    "row": {
      "address": "001dccc8",
      "symbol": "_Z13func_001dccc8ic",
      "compiled_size": 84,
      "target_size": 88,
      "ghidra_body_size": 88,
      "boundary_agreement": true,
      "exact_match": false,
      "compiled_hex": "f0ffbd27002e05000000bfff00010f3c032e050008008e8c2470cf010a00c0152d1000000900a0100000bfdf1a8d070c1c00848c3c2802003500043c002b8424f20f050c3e2805000000bfdf0800e0031000bd27",
      "target_hex": "f0ffbd2700010f3c0000bfffff00a5302d68000008008e8c2470cf010b00c0152d1000000900a0102d10a0011a8d070c1c00848c3500043c2d284000f20f050c002b84242d6840002d10a0010000bfdf0800e0031000bd27"
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_001dccc8_a4cd07fb_v2.verification.json",
    "sha256": "6a2d20d06af5461f8c808481ae5be75d73464cf6457254a6f54796912bcbc21e",
    "source_sha256": "3ed2b8e4caeb422fe2c4f2321d416591a9aa74e870632cc748d906d138757399",
    "row": {
      "address": "001dccc8",
      "symbol": "_Z13func_001dccc8ih",
      "compiled_size": 80,
      "target_size": 88,
      "ghidra_body_size": 88,
      "boundary_agreement": true,
      "exact_match": false,
      "compiled_hex": "f0ffbd2700010f3c0000bfffff00a53008008e8c2470cf010a00c0152d1000000900a0100000bfdf1a8d070c1c00848c3c2802003500043c002b8424f20f050c3e2805000000bfdf0800e0031000bd27",
      "target_hex": "f0ffbd2700010f3c0000bfffff00a5302d68000008008e8c2470cf010b00c0152d1000000900a0102d10a0011a8d070c1c00848c3500043c2d284000f20f050c002b84242d6840002d10a0010000bfdf0800e0031000bd27"
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_001dccc8_a4cd07fb_v3.verification.json",
    "sha256": "21cb2cf10777565241882a0f74bc55bb453b69ea322510278903e5f79879f71d",
    "source_sha256": "b2338dc93d0d702c97efb25a225ab175d1dce92ff22993d037a59bd2235a5273",
    "row": {
      "address": "001dccc8",
      "symbol": "_Z13func_001dccc8ih",
      "compiled_size": 76,
      "target_size": 88,
      "ghidra_body_size": 88,
      "boundary_agreement": true,
      "exact_match": false,
      "compiled_hex": "f0ffbd2700010f3c0000bfffff00a53008008e8c2470cf010900c0152d1000000800a0100000bfdf1a8d070c1c00848c3500043c2d284000f20f050c002b84240000bfdf0800e0031000bd27",
      "target_hex": "f0ffbd2700010f3c0000bfffff00a5302d68000008008e8c2470cf010b00c0152d1000000900a0102d10a0011a8d070c1c00848c3500043c2d284000f20f050c002b84242d6840002d10a0010000bfdf0800e0031000bd27"
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_001dccc8_a4cd07fb_v4.verification.json",
    "sha256": "d7b945763ffc4147f96afd39ea975c3db070465c52101751acea245d74dd7ad6",
    "source_sha256": "442300c47b485f59fb03328c5e4e3420527a20d03db1026f19d896b9ebb7c58e",
    "row": {
      "address": "001dccc8",
      "symbol": "_Z13func_001dccc8ih",
      "compiled_size": 84,
      "target_size": 88,
      "ghidra_body_size": 88,
      "boundary_agreement": true,
      "exact_match": false,
      "compiled_hex": "f0ffbd2700010f3c0000bfffff00a53008008e8c2470cf010a00c0152d6800000800a010000000001a8d070c1c00848c3500043c2d284000f20f050c002b84242d6840000000bfdf2d10a0010800e0031000bd27",
      "target_hex": "f0ffbd2700010f3c0000bfffff00a5302d68000008008e8c2470cf010b00c0152d1000000900a0102d10a0011a8d070c1c00848c3500043c2d284000f20f050c002b84242d6840002d10a0010000bfdf0800e0031000bd27"
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_001dccc8_a4cd07fb_v5.verification.json",
    "sha256": "e88ba708c8e1b4a120e6b8b0d57c47cc1ecb943ff5f393a5419f86237da2190b",
    "source_sha256": "277bd6b137ce045fdd444bc785114cef2fcf2ce56220de1fb1653570acdfbbaf",
    "row": {
      "address": "001dccc8",
      "symbol": "_Z13func_001dccc8ih",
      "compiled_size": 88,
      "target_size": 88,
      "ghidra_body_size": 88,
      "boundary_agreement": true,
      "exact_match": false,
      "compiled_hex": "f0ffbd27ff00a5300000bfff2d68000008008f8c00010e3c2478ee010a00e015000000000800a0102d6800001a8d070c1c00848c3500043c2d284000f20f050c002b84242d6840000000bfdf2d10a0010800e0031000bd27",
      "target_hex": "f0ffbd2700010f3c0000bfffff00a5302d68000008008e8c2470cf010b00c0152d1000000900a0102d10a0011a8d070c1c00848c3500043c2d284000f20f050c002b84242d6840002d10a0010000bfdf0800e0031000bd27"
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_001dccc8_a4cd07fb_v6.verification.json",
    "sha256": "1c80728700ee3929f1e08a61638b8751836ea43e428b21cb982525b7b6364099",
    "source_sha256": "0c3be76c8080159d697a6595cc00548a97f3b1da13488d1186923797710d45cf",
    "row": {
      "address": "001dccc8",
      "symbol": "_Z13func_001dccc8ih",
      "compiled_size": 88,
      "target_size": 88,
      "ghidra_body_size": 88,
      "boundary_agreement": true,
      "exact_match": false,
      "compiled_hex": "f0ffbd2700010f3c0000bfffff00a5302d68000008008e8c2470cf010b00c0152d1000000800a010000000001a8d070c1c00848c3500043c2d284000f20f050c002b84242d6840002d10a0010000bfdf0800e0031000bd27",
      "target_hex": "f0ffbd2700010f3c0000bfffff00a5302d68000008008e8c2470cf010b00c0152d1000000900a0102d10a0011a8d070c1c00848c3500043c2d284000f20f050c002b84242d6840002d10a0010000bfdf0800e0031000bd27"
    }
  }
]
```
