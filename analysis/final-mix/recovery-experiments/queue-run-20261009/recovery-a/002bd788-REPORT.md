# Original-instruction correction 002bd788

Original instructions establish byte store D_003617f8 in the first jal delay slot, not archived word store after call; allocation size is 0x5cc60, not 0xcc65; global argument is D_0032b91c, not D_0032b924. Correcting these and symbolic callback yields 80-byte v2 differing only by t6/t7 base assignment for first global and byte stores. Barrier between first stores reshuffles prologue and does not solve it.

Next: Constrain independent first-store global bases to t6 for D_003617ec and t7 for D_003617f8 without inserting instruction or memory-order barriers.

All failed variants retained. Shared registry/layout/stage/checkpoints untouched. Compiler drained for primary acceptance.

```json
[
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_002bd788_e9ac9b42_v1.verification.json",
    "sha256": "971fbe1af45ab0660020950233af1b2faa9ccc1a20553754d49a41cad2b34bab",
    "source_sha256": "535ba66e21f59783ce2a6161c40824bc57b491f728b51a269ad626a589769dae",
    "row": {
      "address": "002bd788",
      "symbol": "_Z13func_002bd788j",
      "compiled_size": 80,
      "target_size": 80,
      "ghidra_body_size": 80,
      "boundary_agreement": true,
      "exact_match": false,
      "compiled_hex": "f0ffbd2736000f3c0000bfffc7e10a0cec17e4ad36000f3c33000e3cf817e0a10500063c1cb9c48d2c00073c70d8e7242d280000e209040c60ccc63436000f3c0000bfdff417e2ad0800e0031000bd27",
      "target_hex": "f0ffbd2736000e3c36000f3c0000bfffec17c4adc7e10a0cf817e0a133000f3c0500063c1cb9e48d2c00073c70d8e7242d280000e209040c60ccc63436000f3c0000bfdff417e2ad0800e0031000bd27"
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_002bd788_e9ac9b42_v2.verification.json",
    "sha256": "c66fefb0020f68e0022e3cf5341c09db0c6abd6390b58bbc0b45b26b271bcad8",
    "source_sha256": "5fcfffe8f43953ee2cb71949a00e21276cebe123b2c6158287802f4e7d2d8889",
    "row": {
      "address": "002bd788",
      "symbol": "_Z13func_002bd788j",
      "compiled_size": 80,
      "target_size": 80,
      "ghidra_body_size": 80,
      "boundary_agreement": true,
      "exact_match": false,
      "compiled_hex": "f0ffbd2736000e3c36000f3c0000bfffec17e4adc7e10a0cf817c0a133000f3c0500063c1cb9e48d2c00073c70d8e7242d280000e209040c60ccc63436000f3c0000bfdff417e2ad0800e0031000bd27",
      "target_hex": "f0ffbd2736000e3c36000f3c0000bfffec17c4adc7e10a0cf817e0a133000f3c0500063c1cb9e48d2c00073c70d8e7242d280000e209040c60ccc63436000f3c0000bfdff417e2ad0800e0031000bd27"
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_002bd788_e9ac9b42_v3.verification.json",
    "sha256": "be6b4f0c3c92e2ad39dbae7f0014736a8c168ded281cefeea080bb58709f718e",
    "source_sha256": "068bac48de44459831da0c8022ceb9435d1fe26f31f92234a14ea1aa224e358a",
    "row": {
      "address": "002bd788",
      "symbol": "_Z13func_002bd788j",
      "compiled_size": 80,
      "target_size": 80,
      "ghidra_body_size": 80,
      "boundary_agreement": true,
      "exact_match": false,
      "compiled_hex": "f0ffbd2736000f3c0000bfffec17e4ad36000f3cc7e10a0cf817e0a133000f3c0500063c1cb9e48d2c00073c70d8e7242d280000e209040c60ccc63436000f3c0000bfdff417e2ad0800e0031000bd27",
      "target_hex": "f0ffbd2736000e3c36000f3c0000bfffec17c4adc7e10a0cf817e0a133000f3c0500063c1cb9e48d2c00073c70d8e7242d280000e209040c60ccc63436000f3c0000bfdff417e2ad0800e0031000bd27"
    }
  }
]
```
