# 001052a8 header mirror

Full88-byte original and dependent caller examined. Calls00104d30 with D0032bae0 and incoming header. Copies source bytes0,2,1 to D0032bb30+12,+14,+13, preserving store order14,12,13. Original keeps global high17 and local header low16 across call. A typed unknown read/write pointer16 constraint reproduces all initial9 words exactly. Three volatile source byte loads improve original order, but remaining table address/load slots and saved-register restores differ; broad trailing clobbers enlarge100-byte output. Seven isolated variants retained.

Caller00104da0 v1 explicit header argument itself proves exact60 bytes; parent informed for replacement.

Next hypothesis: native typed header struct and mirror table declaration can enforce original byte alias/order without volatile loads causing early RA restore. Avoid repeated broad clobbers or memory barriers.

```json
[
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001052a8_3c3ec2d4_v0.verification.json",
    "sha256": "ce9320d7d01ada5e3336baa35987ddb5d5e09062e999389c5b8a5ca0eb317c33",
    "verification": {
      "source_sha256": "9a9843fbb42267cdd7fab3926aea4674e88eef52b1a19c2db82d432b0e540ea4",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_001052a8_3c3ec2d4_v0.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "001052a8",
          "symbol": "_Z13func_001052a8PKh",
          "compiled_size": 88,
          "target_size": 88,
          "ghidra_body_size": 88,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "f0ffbd272d2880000000b0ff0800bfff3300103c4c13040ce0ba042633000f3ce0ba0b92e2baed9133000e3ce1bacc9133000f3c0000b0df3ebbeda133000e3c3cbbcba133000f3c0800bfdf3dbbeca10800e0031000bd27",
          "target_hex": "e0ffbd272d2880000800b1ff0000b0ff3300113c1000bfffe0ba30264c13040c2d200002e0ba2c9233000f3c02000d9230bbef2501000e920e00eda10c00eca10d00eea10000b0df0800b1df1000bfdf0800e0032000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001052a8_3c3ec2d4_v1.verification.json",
    "sha256": "6c8196c5ee47cf3a13454293c2daf3cfa2fdd044775cecd7351311f7c9a00f26",
    "verification": {
      "source_sha256": "34088b5241d09432eaa01881e04fcbbd53eb7af6fee10bbd30061213fe93a62b",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_001052a8_3c3ec2d4_v1.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "001052a8",
          "symbol": "_Z13func_001052a8PKh",
          "compiled_size": 88,
          "target_size": 88,
          "ghidra_body_size": 88,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "e0ffbd272d2880000800b1ff0000b0ff3300113c1000bfffe0ba30264c13040c2d20000201000d9233000f3ce0ba2c9230bbef2502000e920800b1df0d00eda10e00eea10c00eca10000b0df1000bfdf0800e0032000bd27",
          "target_hex": "e0ffbd272d2880000800b1ff0000b0ff3300113c1000bfffe0ba30264c13040c2d200002e0ba2c9233000f3c02000d9230bbef2501000e920e00eda10c00eca10d00eea10000b0df0800b1df1000bfdf0800e0032000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001052a8_3c3ec2d4_v2.verification.json",
    "sha256": "f7708d54181620bf5b17ea0ab875dfeaa0530c91a0aa48f64027ac8a49332196",
    "verification": {
      "source_sha256": "723ccaa82468ee00dd016255ebe69a2a4628ed3ca083aa3812fdf3f2bf3075a3",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_001052a8_3c3ec2d4_v2.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "001052a8",
          "symbol": "_Z13func_001052a8PKh",
          "compiled_size": 88,
          "target_size": 88,
          "ghidra_body_size": 88,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "e0ffbd272d2880000800b1ff0000b0ff3300113c1000bfffe0ba30264c13040c2d20000201000c9233000f3c02000d9230bbef25e0ba2e920000b0df0e00eda10800b1df0c00eea11000bfdf0d00eca10800e0032000bd27",
          "target_hex": "e0ffbd272d2880000800b1ff0000b0ff3300113c1000bfffe0ba30264c13040c2d200002e0ba2c9233000f3c02000d9230bbef2501000e920e00eda10c00eca10d00eea10000b0df0800b1df1000bfdf0800e0032000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001052a8_3c3ec2d4_v3.verification.json",
    "sha256": "3934abb36c8d8af9f52fcdf5a166c378500f89ef8f27bafde36bd852c7b5e0e9",
    "verification": {
      "source_sha256": "c4a330018538dbdb05b530488ff51afba13af9317d7ed831611b4175046c2ced",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_001052a8_3c3ec2d4_v3.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "001052a8",
          "symbol": "_Z13func_001052a8PKh",
          "compiled_size": 88,
          "target_size": 88,
          "ghidra_body_size": 88,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "e0ffbd272d2880000800b1ff0000b0ff3300113c1000bfffe0ba30264c13040c2d200002e0ba2c9233000f3c30bbef251000bfdf02000d920800b1df01000e920e00eda10d00eea10c00eca10000b0df0800e0032000bd27",
          "target_hex": "e0ffbd272d2880000800b1ff0000b0ff3300113c1000bfffe0ba30264c13040c2d200002e0ba2c9233000f3c02000d9230bbef2501000e920e00eda10c00eca10d00eea10000b0df0800b1df1000bfdf0800e0032000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001052a8_3c3ec2d4_v4.verification.json",
    "sha256": "77604a246b6dade70115ee2e291cf5dc122ccc136a1d6a7fb2aa8d6453258e11",
    "verification": {
      "source_sha256": "e0c7d48fd2d92181eed331363d7ab8ed94f4a0620f88fbd1178537271b26e1af",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_001052a8_3c3ec2d4_v4.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "001052a8",
          "symbol": "_Z13func_001052a8PKh",
          "compiled_size": 96,
          "target_size": 88,
          "ghidra_body_size": 88,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "e0ffbd272d2880000800b1ff0000b0ff3300113c1000bfffe0ba30264c13040c2d200002e0ba2d9233000e3c30bbce2502000c92ff00ad3101000f920e00cca1ff00ef310c00cda10d00cfa10000b0df0800b1df1000bfdf0800e0032000bd27",
          "target_hex": "e0ffbd272d2880000800b1ff0000b0ff3300113c1000bfffe0ba30264c13040c2d200002e0ba2c9233000f3c02000d9230bbef2501000e920e00eda10c00eca10d00eea10000b0df0800b1df1000bfdf0800e0032000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001052a8_3c3ec2d4_v5.verification.json",
    "sha256": "ae88601f8b49c35ddcc02bfe7282fdf7df06d24dd6f54c8075e25be241913dcc",
    "verification": {
      "source_sha256": "3a0e177acfd77b9b8c92fb859cdb0c0768aa1a4d250645a802f0bb58882e068f",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_001052a8_3c3ec2d4_v5.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "001052a8",
          "symbol": "_Z13func_001052a8PKh",
          "compiled_size": 100,
          "target_size": 88,
          "ghidra_body_size": 88,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "d0ffbd272d2880001000b17f0000b07f3300113c2000bfffe0ba30264c13040c2d200002e0ba2c9233000d3c30bbad2502000f92ff008c3101000e92ff00ef310e00afa1ff00ce310c00aca10d00aea10000b07b1000b17b2000bfdf0800e0033000bd27",
          "target_hex": "e0ffbd272d2880000800b1ff0000b0ff3300113c1000bfffe0ba30264c13040c2d200002e0ba2c9233000f3c02000d9230bbef2501000e920e00eda10c00eca10d00eea10000b0df0800b1df1000bfdf0800e0032000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001052a8_3c3ec2d4_v6.verification.json",
    "sha256": "b85aeaed31269c48fbc57cdeaeda03e1e041c8d4a3ba9ca32de54f5125feab0e",
    "verification": {
      "source_sha256": "c34cd53f11661c1184ce1d74468e3e5828dc5360e7646b6531409a9aaa5f3f19",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_001052a8_3c3ec2d4_v6.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "001052a8",
          "symbol": "_Z13func_001052a8PKh",
          "compiled_size": 100,
          "target_size": 88,
          "ghidra_body_size": 88,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "e0ffbd272d2880000800b1ff0000b0ff3300113c1000bfffe0ba30264c13040c2d200002e0ba2c9233000d3c30bbad2502000f92ff008c3101000e92ff00ef310e00afa1ff00ce310c00aca10d00aea10000b0df0800b1df1000bfdf0800e0032000bd27",
          "target_hex": "e0ffbd272d2880000800b1ff0000b0ff3300113c1000bfffe0ba30264c13040c2d200002e0ba2c9233000f3c02000d9230bbef2501000e920e00eda10c00eca10d00eea10000b0df0800b1df1000bfdf0800e0032000bd27"
        }
      ]
    }
  }
]
```
