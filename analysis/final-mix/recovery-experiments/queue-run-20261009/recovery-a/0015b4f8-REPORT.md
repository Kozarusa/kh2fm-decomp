# Digit-loop arithmetic order residual 0015b4f8

Live range is128 bytes. Symbolic format D_0036b3c0 fixes address materialization. Original subtracts0x30 from signed digit before shifting; compiler folds the subtraction into a -192 load offset. An empty index constraint prevents folding and reaches128 bytes. It also moves the loop comparison below the character-zero branch. A separate more predicate constraint forces the comparison earlier but changes counter/flag allocation and character-load order. Three complete failed variants preserved.

Next: nonvolatile index constraint or signed digit-offset variable reused in a dependency before the zero branch, preserving original t5counter/t4more and t6character. Avoid constraining both predicates with volatile barriers unless needed.

```json
[
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_0015b4f8_6884e21c_v1.verification.json",
    "sha256": "e60f2a06fb1766b3172964dbcae6f0aeb243f10315f586d63d14b96c51da6a07",
    "source_sha256": "b26465974b57d29104d3b3d1cb3df3d24da1b3b60ea859b928aefa7a7886adb3",
    "row": {
      "address": "0015b4f8",
      "symbol": "_Z13func_0015b4f8iyPj",
      "compiled_size": 124,
      "target_size": 128,
      "ghidra_body_size": 128,
      "boundary_agreement": true,
      "exact_match": false,
      "compiled_hex": "d0ffbd272d78a0001000b0ff3700053c1800b1ffc0b3a5242000bfff2d80c0002d8880002d30e0019efb0b0c2d20a0032d1000002d6800002178ad030000ee810100ad251000ac290700c01180780e002170f1010100422440ffcf8d00000faef5ff8015040010261000b0df1800b1df2000bfdf0800e0033000bd27",
      "target_hex": "d0ffbd272d78a0001000b0ff3700053c1800b1ffc0b3a5242000bfff2d80c0002d8880002d30e0019efb0b0c2d20a0032d1000002d6800002178ad030000ee810100ad251000ac290800c011d0ffcf2580780f00010042242178f1010000ee8d00000eaef4ff8015040010261000b0df1800b1df2000bfdf0800e0033000bd27"
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_0015b4f8_6884e21c_v2.verification.json",
    "sha256": "d343f9005ac0adc61d18a257dcb7dbdfa4dbd84ab9b8da3fec9eda3626903dd8",
    "source_sha256": "b3f1953182e87500b03a1c662e07e5623df6dccf7af034ba701fd4643555c060",
    "row": {
      "address": "0015b4f8",
      "symbol": "_Z13func_0015b4f8iyPj",
      "compiled_size": 128,
      "target_size": 128,
      "ghidra_body_size": 128,
      "boundary_agreement": true,
      "exact_match": false,
      "compiled_hex": "d0ffbd272d78a0001000b0ff3700053c1800b1ffc0b3a5242000bfff2d80c0002d8880002d30e0019efb0b0c2d20a0032d1000002d6000002178ac030000ee8101008c250900c011d0ffcf250100422480780f0010008d292178f1010000ee8d00000eaef4ffa015040010261000b0df1800b1df2000bfdf0800e0033000bd27",
      "target_hex": "d0ffbd272d78a0001000b0ff3700053c1800b1ffc0b3a5242000bfff2d80c0002d8880002d30e0019efb0b0c2d20a0032d1000002d6800002178ad030000ee810100ad251000ac290800c011d0ffcf2580780f00010042242178f1010000ee8d00000eaef4ff8015040010261000b0df1800b1df2000bfdf0800e0033000bd27"
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_0015b4f8_6884e21c_v3.verification.json",
    "sha256": "5c7a140e1c69880db1c27c22693f819311409f2ddda329f9b2403b7a0a2da22a",
    "source_sha256": "57778adfe1590ecb605d5e233b3d888f3f6e731ba1062587477dcfa9621a567e",
    "row": {
      "address": "0015b4f8",
      "symbol": "_Z13func_0015b4f8iyPj",
      "compiled_size": 128,
      "target_size": 128,
      "ghidra_body_size": 128,
      "boundary_agreement": true,
      "exact_match": false,
      "compiled_hex": "d0ffbd272d78a0001000b0ff3700053c1800b1ffc0b3a5242000bfff2d80c0002d8880002d30e0019efb0b0c2d20a0032d1000002d6000002170ac0301008c2510008d290000cf810800e011d0ffee250100422480780e002178f1010000ee8d00000eaef4ffa015040010261000b0df1800b1df2000bfdf0800e0033000bd27",
      "target_hex": "d0ffbd272d78a0001000b0ff3700053c1800b1ffc0b3a5242000bfff2d80c0002d8880002d30e0019efb0b0c2d20a0032d1000002d6800002178ad030000ee810100ad251000ac290800c011d0ffcf2580780f00010042242178f1010000ee8d00000eaef4ff8015040010261000b0df1800b1df2000bfdf0800e0033000bd27"
    }
  }
]
```
