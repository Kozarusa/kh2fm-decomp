# 00102bd8 callback initialization

Complete 60-byte original range examined. Grouped shared base D0032b968 and typed volatile stores reached 60 bytes with only words4/5 exchanged: second callback high-address LUI should precede first callback store. C++ nonvolatile stores reorder callback assignments; barriers and paired register constraints disturb many unrelated instructions. Seven probes retained.

Next hypothesis: original callback table type or qualifier induces early second pointer address materialization without an empty asm scheduling barrier. Consider shared SDK table declaration evidence and address-taken callback signatures. Avoid repeating tested broad barriers.

```json
[
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_00102bd8_b0228066_v0.verification.json",
    "sha256": "0fee23810c09ec7ae051cbf1cf34e4e216c17b69fb0a9880fa7587062343fc30",
    "verification": {
      "source_sha256": "fb1cb3b9a62a0d4f80615a00ef938fdcd5cf91a3707add1d7be17d3524fdc259",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_00102bd8_b0228066_v0.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "00102bd8",
          "symbol": "_Z13func_00102bd8v",
          "compiled_size": 60,
          "target_size": 60,
          "ghidra_body_size": 60,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "10000f3c33000d3c902bef25f0ffbd278cb9afad10000e3c0000bfff702ace2533000f3c33000d3c88b9eead94b9a0ad0000bfdfd60a04081000bd27",
          "target_hex": "33000d3c10000f3c68b9ad25902bef2510000e3c2400afadf0ffbd27702ace250000bfff33000f3c2000aead0000bfdf94b9e0add60a04081000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_00102bd8_b0228066_v1.verification.json",
    "sha256": "1491ad69e59f92a52c626f719ba84c88960edf0b64dc94940078a0b47edfdf01",
    "verification": {
      "source_sha256": "860aa807e3f678f57f4602ecbb0d7d2ba765eaf9070e10c4255f67b61b9d47cd",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_00102bd8_b0228066_v1.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "00102bd8",
          "symbol": "_Z13func_00102bd8v",
          "compiled_size": 60,
          "target_size": 60,
          "ghidra_body_size": 60,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "33000d3c10000f3c68b9ad25702aef2510000e3c2000afadf0ffbd27902bce250000bfff33000f3c2400aead0000bfdf94b9e0add60a04081000bd27",
          "target_hex": "33000d3c10000f3c68b9ad25902bef2510000e3c2400afadf0ffbd27702ace250000bfff33000f3c2000aead0000bfdf94b9e0add60a04081000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_00102bd8_b0228066_v4.verification.json",
    "sha256": "eadbffa219d03e62e1f75f9d0433aa1287d6090c9f9ce846f5f7ee958edce2ae",
    "verification": {
      "source_sha256": "ac95cf5824090aec48710f3701ed52106116de823956d97cdf886e30ae3dbd9a",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_00102bd8_b0228066_v4.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "00102bd8",
          "symbol": "_Z13func_00102bd8v",
          "compiled_size": 60,
          "target_size": 60,
          "ghidra_body_size": 60,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "33000d3c10000f3cf0ffbd2768b9ad25902bef250000bfff2400afad33000e3c0000bfdf94b9c0ad10000f3c702aef252000afadd60a04081000bd27",
          "target_hex": "33000d3c10000f3c68b9ad25902bef2510000e3c2400afadf0ffbd27702ace250000bfff33000f3c2000aead0000bfdf94b9e0add60a04081000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_00102bd8_b0228066_v5.verification.json",
    "sha256": "bbf67b31a68fe6ddb82703e3bd448050cf772431ffd5e55ae9fc123df2dccb9c",
    "verification": {
      "source_sha256": "2a854bdc82ad77ecb44fb7cbb41f1e44007d360969396e4833070f707217095a",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_00102bd8_b0228066_v5.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "00102bd8",
          "symbol": "_Z13func_00102bd8v",
          "compiled_size": 60,
          "target_size": 60,
          "ghidra_body_size": 60,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "33000d3c10000f3c68b9ad25902bef252400afad10000e3cf0ffbd27702ace250000bfff33000f3c2000aead0000bfdf94b9e0add60a04081000bd27",
          "target_hex": "33000d3c10000f3c68b9ad25902bef2510000e3c2400afadf0ffbd27702ace250000bfff33000f3c2000aead0000bfdf94b9e0add60a04081000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_00102bd8_b0228066_v6.verification.json",
    "sha256": "d4ac0cea7db58caa5c13245eb55c560c0cf7abcba417240e2b1877a41c7716b1",
    "verification": {
      "source_sha256": "eab42f27994f2dc16ef4d7c008d740156d4e3a2b0d72d5247e06d6676e324946",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_00102bd8_b0228066_v6.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "00102bd8",
          "symbol": "_Z13func_00102bd8v",
          "compiled_size": 60,
          "target_size": 60,
          "ghidra_body_size": 60,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "33000d3c10000f3c68b9ad25902bef252400afadf0ffbd270000bfff10000e3c33000f3c94b9e0ad702ace250000bfdf2000aeadd60a04081000bd27",
          "target_hex": "33000d3c10000f3c68b9ad25902bef2510000e3c2400afadf0ffbd27702ace250000bfff33000f3c2000aead0000bfdf94b9e0add60a04081000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_00102bd8_b0228066_v7.verification.json",
    "sha256": "9876f3b48e555d29d5875fb04c629e7d5ad70b1877df13259cae21debf3fdd3f",
    "verification": {
      "source_sha256": "80aa1587ca11e8a588cf3495cdb339af73b088eca14369d6d1b4dcc4a4f7369b",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_00102bd8_b0228066_v7.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "00102bd8",
          "symbol": "_Z13func_00102bd8v",
          "compiled_size": 60,
          "target_size": 60,
          "ghidra_body_size": 60,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "33000d3c33000c3c94b9a0ad10000f3cf0ffbd2768b98c25902bef250000bfff10000e3c24008fad702ace250000bfdf20008eadd60a04081000bd27",
          "target_hex": "33000d3c10000f3c68b9ad25902bef2510000e3c2400afadf0ffbd27702ace250000bfff33000f3c2000aead0000bfdf94b9e0add60a04081000bd27"
        }
      ]
    }
  }
]
```
