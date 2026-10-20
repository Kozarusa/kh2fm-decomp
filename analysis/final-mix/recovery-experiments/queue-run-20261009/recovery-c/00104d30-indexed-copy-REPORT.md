# 00104d30 indexed table copy

Full108-byte original examined. Three input bytes copied in order0,2,1; table entry address is D0032bb30 + first*384 + second*6, field halfwords at16,18,20. Tail helper receives output+4 and input+4. Ordinary C++ generates expected EE mult/madd fused pair and matches size, but byte register allocation, early output argument increment, and halfword load order differ. Byte-sized temporaries and load statement reorder controls unchanged; pointer and explicit register constraints disturb scheduling instead of solve.

Next hypothesis: original typed header struct with embedded halfword array keeps copied header base independent of adjusted tail argument, avoiding early addiu. Investigate complete table record type and callers before further fixed-register constraints.

```json
[
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_00104d30_7e369537_v0.verification.json",
    "sha256": "715b7d720308b7d8b7fb358c1668d900acddad999165e466c239292876623d27",
    "verification": {
      "source_sha256": "93d7009e57b26cc8e7711120156364327c7c566f473055748ca6594ce72efda4",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_00104d30_7e369537_v0.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "00104d30",
          "symbol": "_Z13func_00104d30PhPKh",
          "compiled_size": 108,
          "target_size": 108,
          "ghidra_body_size": 108,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "f0ffbd2780010f240000bfff2d688000040084240000ac900100ab900200ae9018008f010000bfdf0200aea10400a5240000aca106000e240100aba100706e7133000f3c30bbef252170cf011000cc951400cb951200cf950400aca50600afa50800aba53c1304081000bd27",
          "target_hex": "f0ffbd2780010f240000bfff2d6880000000aa900100a99018004f010200ab9000008aa002008ba00400a524010089a006000f240000bfdf00702f710400842433000f3c30bbef252170cf011400cb951000cf951200cc950400afa50600aca50800aba53c1304081000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_00104d30_7e369537_v1.verification.json",
    "sha256": "0c644e13db61fa41372d2100fb3449514e1cf9c84c1d225d89a3b6cead8d4220",
    "verification": {
      "source_sha256": "d4f8b6fcc32833494a8aad855a8b25c1cf0a3c601e6ca254aac38b45aed81698",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_00104d30_7e369537_v1.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "00104d30",
          "symbol": "_Z13func_00104d30PhPKh",
          "compiled_size": 108,
          "target_size": 108,
          "ghidra_body_size": 108,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "f0ffbd2780010f240000bfff2d688000040084240000ac900100ab900200ae9018008f010000bfdf0200aea10400a5240000aca106000e240100aba100706e7133000f3c30bbef252170cf011000cc951400cb951200cf950400aca50600afa50800aba53c1304081000bd27",
          "target_hex": "f0ffbd2780010f240000bfff2d6880000000aa900100a99018004f010200ab9000008aa002008ba00400a524010089a006000f240000bfdf00702f710400842433000f3c30bbef252170cf011400cb951000cf951200cc950400afa50600aca50800aba53c1304081000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_00104d30_7e369537_v2.verification.json",
    "sha256": "0af6c41f62452f30d2561f96a80bfc36b802626edfcb30498cae22b5b81797f7",
    "verification": {
      "source_sha256": "2d105e804e70b8eb30e9eb7da14612dfe89bdc811cfde7a89b7c7739cd9cc937",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_00104d30_7e369537_v2.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "00104d30",
          "symbol": "_Z13func_00104d30PhPKh",
          "compiled_size": 108,
          "target_size": 108,
          "ghidra_body_size": 108,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "f0ffbd2780010f240000bfff2d688000040084240000ac900100ab900200ae9018008f010000bfdf0200aea10400a5240000aca106000e240100aba100706e7133000f3c30bbef252170cf011200cc951400cb951000cf950600aca50400afa50800aba53c1304081000bd27",
          "target_hex": "f0ffbd2780010f240000bfff2d6880000000aa900100a99018004f010200ab9000008aa002008ba00400a524010089a006000f240000bfdf00702f710400842433000f3c30bbef252170cf011400cb951000cf951200cc950400afa50600aca50800aba53c1304081000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_00104d30_7e369537_v3.verification.json",
    "sha256": "43c128226be05691a18a05a32f53e11be6ca7bc520f5b99bf11c248f8b4bf582",
    "verification": {
      "source_sha256": "846d4c61d24781808caec92c6004dc3fc56d51f429c954d19a265f9e0477ebed",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_00104d30_7e369537_v3.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "00104d30",
          "symbol": "_Z13func_00104d30PhPKh",
          "compiled_size": 108,
          "target_size": 108,
          "ghidra_body_size": 108,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "f0ffbd2780010f240000bfff2d6880000000ac900100ab900200ae9018008f010000bfdf02008ea00400a52400008ca006000e2401008ba000706e7133000f3c30bbef250400a4252170cf011000cc951400cb951200cf950400aca50600afa50800aba53c1304081000bd27",
          "target_hex": "f0ffbd2780010f240000bfff2d6880000000aa900100a99018004f010200ab9000008aa002008ba00400a524010089a006000f240000bfdf00702f710400842433000f3c30bbef252170cf011400cb951000cf951200cc950400afa50600aca50800aba53c1304081000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_00104d30_7e369537_v4.verification.json",
    "sha256": "f1ea89bb30b12ef41a5361409cebd7ef5a1f3e4ef37c65b448f1f3af5685950f",
    "verification": {
      "source_sha256": "e0592fb402eae7baea31ee92b6485e8564f38b3d141788a6fe76a06715355990",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_00104d30_7e369537_v4.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "00104d30",
          "symbol": "_Z13func_00104d30PhPKh",
          "compiled_size": 108,
          "target_size": 108,
          "ghidra_body_size": 108,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "f0ffbd2780010f240000bfff2d7080000000aa900100a9900200ab9018004f01010089a002008ba00400a52400008aa00000bfdf06000f240400c42500482f7133000f3c30bbef2521482f0110002d9514002c9512002f950400cda50600cfa50800cca53c1304081000bd27",
          "target_hex": "f0ffbd2780010f240000bfff2d6880000000aa900100a99018004f010200ab9000008aa002008ba00400a524010089a006000f240000bfdf00702f710400842433000f3c30bbef252170cf011400cb951000cf951200cc950400afa50600aca50800aba53c1304081000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_00104d30_7e369537_v5.verification.json",
    "sha256": "cb9ac00a0ebae66fa53577bb01e995c2ae74f89669f3dc26221ae4e45996e6e2",
    "verification": {
      "source_sha256": "93ddbcbbf30525a59aad9d0a49b901e5072b03fee78ca17cc67c94e9fcf87b74",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_00104d30_7e369537_v5.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "00104d30",
          "symbol": "_Z13func_00104d30PhPKh",
          "compiled_size": 108,
          "target_size": 108,
          "ghidra_body_size": 108,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "f0ffbd2780010f240000bfff2d7080000000aa900100a9900200ab9018004f01010089a002008ba00400a52400008aa00000bfdf06000f240400c42500482f7133000f3c30bbef2521482f0112002c9514002b9510002f950400cfa50600cca50800cba53c1304081000bd27",
          "target_hex": "f0ffbd2780010f240000bfff2d6880000000aa900100a99018004f010200ab9000008aa002008ba00400a524010089a006000f240000bfdf00702f710400842433000f3c30bbef252170cf011400cb951000cf951200cc950400afa50600aca50800aba53c1304081000bd27"
        }
      ]
    }
  }
]
```
