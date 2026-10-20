# 001044f0 layout residual

Ordinary typed source reaches112B with only saved-base roles swapped. Two volatile clear stores fix base roles, but ordinary third store hoists ahead of second; allvolatile changes roles and restorations. Barriers fix all first20 words, leaving final high-address LUI and saved s0 restore scheduling. Next: pre-materialize third-store address high at precise boundary, inspect native shared resource structure.

Six failed source controls and full original ranges preserved.

```json
[
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001044f0_bf1a50d5_v0.verification.json",
    "sha256": "8611df09e27e0c67044664d0a16aa5ac3438a2eb890c1012fd2e1067db51309d",
    "verification": {
      "source_sha256": "4f05ef41cf44d50c2ae0cdb123b3bfa27d2a56e44d3f0de5c2ada3e78045e608",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_001044f0_bf1a50d5_v0.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "001044f0",
          "symbol": "_Z13func_001044f0v",
          "compiled_size": 112,
          "target_size": 112,
          "ghidra_body_size": 112,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "e0ffbd271000bfff0000b0ff0800b1ff74c3050c3300103c3300113c28160c0c020004243300053c0100042405607c0c90baa52400c3050cc0ba248e00c3050cbcba048ec8c0050c2d200000c0ba20ae33000f3cbcba00aec4bae0ad0000b0df0800b1df1000bfdf0800e0032000bd27",
          "target_hex": "e0ffbd271000bfff0000b0ff0800b1ff74c3050c3300103c3300113c28160c0c020004243300053c0100042405607c0c90baa52400c3050cc0ba048e00c3050cbcba248ec8c0050c2d200000c0ba00ae33000f3cbcba20aec4bae0ad0000b0df0800b1df1000bfdf0800e0032000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001044f0_bf1a50d5_v1.verification.json",
    "sha256": "2443ee46abee690735027ca8ebefa0175a9bce61aca498c16e3d5e5dc22d1ac8",
    "verification": {
      "source_sha256": "35072976d9b474aea41a1e9020448678d02fc125755c823c5a7d967413e79ea9",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_001044f0_bf1a50d5_v1.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "001044f0",
          "symbol": "_Z13func_001044f0v",
          "compiled_size": 112,
          "target_size": 112,
          "ghidra_body_size": 112,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "e0ffbd271000bfff0000b0ff0800b1ff74c3050c3300103c3300113c28160c0c020004243300053c0100042405607c0c90baa52400c3050cc0ba048e00c3050cbcba248ec8c0050c2d200000c0ba00ae33000f3cc4bae0adbcba20ae0000b0df0800b1df1000bfdf0800e0032000bd27",
          "target_hex": "e0ffbd271000bfff0000b0ff0800b1ff74c3050c3300103c3300113c28160c0c020004243300053c0100042405607c0c90baa52400c3050cc0ba048e00c3050cbcba248ec8c0050c2d200000c0ba00ae33000f3cbcba20aec4bae0ad0000b0df0800b1df1000bfdf0800e0032000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001044f0_bf1a50d5_v2.verification.json",
    "sha256": "a85612b16f6005aef57b9cdfbe0cde67311eb0f92ef57088092bcb4b890740d2",
    "verification": {
      "source_sha256": "03dbca0ca2037cad0c545ef567214876149adee4a567f7071301503077e25f1c",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_001044f0_bf1a50d5_v2.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "001044f0",
          "symbol": "_Z13func_001044f0v",
          "compiled_size": 112,
          "target_size": 112,
          "ghidra_body_size": 112,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "e0ffbd271000bfff0000b0ff0800b1ff74c3050c3300103c3300113c28160c0c020004243300053c0100042405607c0c90baa52400c3050cc0ba248e00c3050cbcba048ec8c0050c2d200000c0ba20ae33000f3c1000bfdfbcba00ae0800b1dfc4bae0ad0000b0df0800e0032000bd27",
          "target_hex": "e0ffbd271000bfff0000b0ff0800b1ff74c3050c3300103c3300113c28160c0c020004243300053c0100042405607c0c90baa52400c3050cc0ba048e00c3050cbcba248ec8c0050c2d200000c0ba00ae33000f3cbcba20aec4bae0ad0000b0df0800b1df1000bfdf0800e0032000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001044f0_bf1a50d5_v3.verification.json",
    "sha256": "b3130cdd6f8671d628a9cdc8d08b01987b7802bf6d24d42d99a9774b8b276fc1",
    "verification": {
      "source_sha256": "2ef34cc9451668cc16779a9e74ff441b366f40a614259c31ac737528d455a145",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_001044f0_bf1a50d5_v3.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "001044f0",
          "symbol": "_Z13func_001044f0v",
          "compiled_size": 112,
          "target_size": 112,
          "ghidra_body_size": 112,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "e0ffbd271000bfff0000b0ff0800b1ff74c3050c3300103c3300113c28160c0c020004243300053c0100042405607c0c90baa52400c3050cc0ba248e00c3050cbcba048ec8c0050c2d200000c0ba20aebcba00ae33000f3c0000b0dfc4bae0ad0800b1df1000bfdf0800e0032000bd27",
          "target_hex": "e0ffbd271000bfff0000b0ff0800b1ff74c3050c3300103c3300113c28160c0c020004243300053c0100042405607c0c90baa52400c3050cc0ba048e00c3050cbcba248ec8c0050c2d200000c0ba00ae33000f3cbcba20aec4bae0ad0000b0df0800b1df1000bfdf0800e0032000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001044f0_bf1a50d5_v4.verification.json",
    "sha256": "e6bb504d01e0008fef1cb7aa8564a4484369bc74b6d0c44dfbe1fd9a23b5217c",
    "verification": {
      "source_sha256": "b23f9ea5f3e25b32dddca48772d87439302ba50f7932a6043f92f129dc126053",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_001044f0_bf1a50d5_v4.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "001044f0",
          "symbol": "_Z13func_001044f0v",
          "compiled_size": 112,
          "target_size": 112,
          "ghidra_body_size": 112,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "e0ffbd271000bfff0000b0ff0800b1ff74c3050c3300103c3300113c28160c0c020004243300053c0100042405607c0c90baa52400c3050cc0ba048e00c3050cbcba248ec8c0050c2d200000c0ba00aebcba20ae33000f3c0000b0dfc4bae0ad0800b1df1000bfdf0800e0032000bd27",
          "target_hex": "e0ffbd271000bfff0000b0ff0800b1ff74c3050c3300103c3300113c28160c0c020004243300053c0100042405607c0c90baa52400c3050cc0ba048e00c3050cbcba248ec8c0050c2d200000c0ba00ae33000f3cbcba20aec4bae0ad0000b0df0800b1df1000bfdf0800e0032000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001044f0_bf1a50d5_v5.verification.json",
    "sha256": "7ab65dab76d1b91a6d15a253db5084d8e8e991514597fde8035c1dc9782d881c",
    "verification": {
      "source_sha256": "71e291817b73f9e7c772b0242590a0133f01aac8156d430878535a11062da5ed",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_001044f0_bf1a50d5_v5.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "001044f0",
          "symbol": "_Z13func_001044f0v",
          "compiled_size": 112,
          "target_size": 112,
          "ghidra_body_size": 112,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "e0ffbd271000bfff0000b0ff0800b1ff74c3050c3300103c3300113c28160c0c020004243300053c0100042405607c0c90baa52400c3050cc0ba048e00c3050cbcba248ec8c0050c2d200000c0ba00aebcba20ae33000f3c0000b0dfc4bae0ad0800b1df1000bfdf0800e0032000bd27",
          "target_hex": "e0ffbd271000bfff0000b0ff0800b1ff74c3050c3300103c3300113c28160c0c020004243300053c0100042405607c0c90baa52400c3050cc0ba048e00c3050cbcba248ec8c0050c2d200000c0ba00ae33000f3cbcba20aec4bae0ad0000b0df0800b1df1000bfdf0800e0032000bd27"
        }
      ]
    }
  }
]
```
