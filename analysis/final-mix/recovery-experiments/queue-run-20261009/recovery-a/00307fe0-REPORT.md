# Argument transport recovery 00307fe0

The live range is 56 bytes. Symbolic func_00307ee8 fixes ori versus addiu materialization but retains t7 as the temporary for incoming third argument. Original uses v0. Pinning incoming third argument to $2 with an empty register barrier produces the desired first move but reorders stack store, saved ra, and argument setup. Both failures preserved.

Next: use a fixed $2 value only at the final call argument boundary, after stack store; test barrier placement after stack store rather than at function entry. Primary pause arrived; drained without further probes.

```json
[
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_00307fe0_2cf389a4_v1.verification.json",
    "proof_sha256": "fa97742a8246a2c26de5c036460f3a06017017d1ce0d7c9b8fca5a8895a12749",
    "source_sha256": "c69e69b7fb2d07b64245b5db7e343c1e3f24f9e2a0134d1ce0bddd31cc5761d4",
    "row": {
      "address": "00307fe0",
      "symbol": "_Z13func_00307fe0jjjj",
      "compiled_size": 56,
      "target_size": 56,
      "ghidra_body_size": 56,
      "boundary_agreement": true,
      "exact_match": false,
      "compiled_hex": "e0ffbd272d78c0000000a4af2d40e0002d30a0001000bfff3000043c2d38e001e87e8424741c0c0c2d28a0031000bfdf0800e0032000bd27",
      "target_hex": "e0ffbd272d10c0000000a4af2d40e0002d30a0003000043c1000bfffe87e84242d384000741c0c0c2d28a0031000bfdf0800e0032000bd27"
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_00307fe0_2cf389a4_v2.verification.json",
    "proof_sha256": "aec571e6554dfe1c85423c73056dcbe6ef8563fd3ed0b4580b67b5c6bf5b0ffe",
    "source_sha256": "4a644c56960528032822d12529751aa16fe3ddec798e55e56d5814bebc4bff73",
    "row": {
      "address": "00307fe0",
      "symbol": "_Z13func_00307fe0jjjj",
      "compiled_size": 56,
      "target_size": 56,
      "ghidra_body_size": 56,
      "boundary_agreement": true,
      "exact_match": false,
      "compiled_hex": "e0ffbd272d10c0001000bfff2d30a0002d40e0000000a4af2d3840002d28a0033000043c741c0c0ce87e84241000bfdf0800e0032000bd27",
      "target_hex": "e0ffbd272d10c0000000a4af2d40e0002d30a0003000043c1000bfffe87e84242d384000741c0c0c2d28a0031000bfdf0800e0032000bd27"
    }
  }
]
```
