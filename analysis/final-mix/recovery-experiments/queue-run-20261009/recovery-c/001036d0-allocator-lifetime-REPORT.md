# 001036d0 paired allocator initialization

Complete 120-byte original range inspected. Original defaults null base to D01f18014, builds signed -0x68000 in saved s0, assigns base to saved s1, adds size to s0, then adds resulting size to s1 in first call delay slot. First allocator arguments remain original base and adjusted size. Second allocator gets the end pointer and +0x68000. Final typed stores already reproduce epilogue in closest controls.

Twelve controls preserve intended pointer algorithm. Native u64/s64 casts introduce unwanted extensions; pointer parameters remove those. Precomputing next pointer reduces output to116 bytes and one saved register. Explicit offset and next pointer constraints reach120 bytes but initial prologue/conditional/parameter roles still differ. Symbol-backed D01f18014 reproduces relocation-style LUI/addiu; numeric pointer emits ORI alternative.

Next hypothesis: retain original base specifically in incoming a0 until first call, and preserve signed offset s0 lifetime without constraining the completed next-pointer calculation. Need original SDK allocator declaration evidence before more constraints.

```json
[
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001036d0_14a059d6_v0.verification.json",
    "sha256": "69bc65ffa789e526a2bcf38314458e122ebd88ca5b2d9673dda3d172d42a91c8",
    "verification": {
      "source_sha256": "5f96b70ab08be6b5072e9d452e48985bdd136fac28a6a7067dd586b1136d47a0",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_001036d0_14a059d6_v0.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "001036d0",
          "symbol": "_Z13func_001036d0yi",
          "compiled_size": 132,
          "target_size": 120,
          "ghidra_body_size": 120,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "e0ffbd27f9ff0e3c0000b0fff1010f3c0800b1ff0080ce351480ef351000bfff2d8080002188ae000a80e4012d2820025e18040c2d2000023c80100033000f3c3f8010002180110214bae2ad0600053c2d2000025e18040c0080a53433000f3c0000b0df18bae2ad01000e240800b1df33000f3c1000bfdf30baeea10800e0032000bd27",
          "target_hex": "e0ffbd270000b0ff0800b1ff1000bfff03008014f9ff103cf2010f3c1480e4252d888000008010362180b0002d2800025e18040c2188300233000f3c0600053c14bae2ad2d2020025e18040c0080a53433000f3c0000b0df18bae2ad01000e240800b1df33000f3c1000bfdf30baeea10800e0032000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001036d0_14a059d6_v1.verification.json",
    "sha256": "3f6b5f6904d60d6d931c7a9952aa6aab0c5f089f4cd4b7e7b55a0b197e6214da",
    "verification": {
      "source_sha256": "4bd0aeb08de09fc8f57cba6836a9e0fb889d2bcbfdfad06c5e1324c019a04046",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_001036d0_14a059d6_v1.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "001036d0",
          "symbol": "_Z13func_001036d0xi",
          "compiled_size": 132,
          "target_size": 120,
          "ghidra_body_size": 120,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "e0ffbd270000b0ff0800b1ff1000bfff2d808000030080142d88a000f101103c14801036f9ff0f3c2d2000020080ef3521882f025e18040c2d28200233000f3c3c20100014bae2ad3f2004000600053c212091005e18040c0080a53433000f3c0000b0df18bae2ad01000e240800b1df33000f3c1000bfdf30baeea10800e0032000bd27",
          "target_hex": "e0ffbd270000b0ff0800b1ff1000bfff03008014f9ff103cf2010f3c1480e4252d888000008010362180b0002d2800025e18040c2188300233000f3c0600053c14bae2ad2d2020025e18040c0080a53433000f3c0000b0df18bae2ad01000e240800b1df33000f3c1000bfdf30baeea10800e0032000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001036d0_14a059d6_v10.verification.json",
    "sha256": "2df0a50ef84586d827f8b4d8846eab570dd8aac0fa53ad79ef3a8a7d7e28c9ab",
    "verification": {
      "source_sha256": "39c630365f50fdd4c14e16043b4275e238fb56b6e22d96fbc39bb57188ce3543",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_001036d0_14a059d6_v10.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "001036d0",
          "symbol": "_Z13func_001036d0Phi",
          "compiled_size": 120,
          "target_size": 120,
          "ghidra_body_size": 120,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "e0ffbd270000b0ff0800b1fff9ff103c1000bfff0300801400801036f2010f3c1480e4252d888000218005025e18040c2d2800022180300233000f3c0600053c14bae2ad2d2000025e18040c0080a53433000f3c0000b0df18bae2ad01000e240800b1df33000f3c1000bfdf30baeea10800e0032000bd27",
          "target_hex": "e0ffbd270000b0ff0800b1ff1000bfff03008014f9ff103cf2010f3c1480e4252d888000008010362180b0002d2800025e18040c2188300233000f3c0600053c14bae2ad2d2020025e18040c0080a53433000f3c0000b0df18bae2ad01000e240800b1df33000f3c1000bfdf30baeea10800e0032000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001036d0_14a059d6_v11.verification.json",
    "sha256": "70ea3e511e1b901ce04519d878d4314885e5d15d6b6fad353a41dbd3004ca3b9",
    "verification": {
      "source_sha256": "a103934a91b878d28517022ddbd5961e69c6d1b1ba2d1dd71159ddf9d5cfcc1b",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_001036d0_14a059d6_v11.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "001036d0",
          "symbol": "_Z13func_001036d0Phi",
          "compiled_size": 120,
          "target_size": 120,
          "ghidra_body_size": 120,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "e0ffbd270000b0ff0800b1fff9ff103c1000bfff0300801400801036f2010f3c1480e4252d888000218005025e18040c2d2800022180300233000f3c0600053c14bae2ad2d2000025e18040c0080a53433000f3c0000b0df18bae2ad01000e240800b1df33000f3c1000bfdf30baeea10800e0032000bd27",
          "target_hex": "e0ffbd270000b0ff0800b1ff1000bfff03008014f9ff103cf2010f3c1480e4252d888000008010362180b0002d2800025e18040c2188300233000f3c0600053c14bae2ad2d2020025e18040c0080a53433000f3c0000b0df18bae2ad01000e240800b1df33000f3c1000bfdf30baeea10800e0032000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001036d0_14a059d6_v2.verification.json",
    "sha256": "cb45c03beb36c6c938062f119649e30372af011e1cdb60466e78d668f2975fda",
    "verification": {
      "source_sha256": "052498a3089d87a5aa1f3f0cd615d1873e0e79a7632d8959adb3efec2407977e",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_001036d0_14a059d6_v2.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "001036d0",
          "symbol": "_Z13func_001036d0xi",
          "compiled_size": 132,
          "target_size": 120,
          "ghidra_body_size": 120,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "e0ffbd27f9ff0e3c0000b0fff1010f3c0800b1ff0080ce351480ef351000bfff2d8080002188ae000a80e4012d2820025e18040c2d2000023c80100033000f3c3f8010002180110214bae2ad0600053c2d2000025e18040c0080a53433000f3c0000b0df18bae2ad01000e240800b1df33000f3c1000bfdf30baeea10800e0032000bd27",
          "target_hex": "e0ffbd270000b0ff0800b1ff1000bfff03008014f9ff103cf2010f3c1480e4252d888000008010362180b0002d2800025e18040c2188300233000f3c0600053c14bae2ad2d2020025e18040c0080a53433000f3c0000b0df18bae2ad01000e240800b1df33000f3c1000bfdf30baeea10800e0032000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001036d0_14a059d6_v3.verification.json",
    "sha256": "4f8ed02679480330f3d4ef11fdac280b18d6339a147c431921b8c68315dd499d",
    "verification": {
      "source_sha256": "def248f8d489c873b8461d67575319edf05468dec512b561f592dccd4b59a88b",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_001036d0_14a059d6_v3.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "001036d0",
          "symbol": "_Z13func_001036d0Phi",
          "compiled_size": 124,
          "target_size": 120,
          "ghidra_body_size": 120,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "e0ffbd27f1010f3c0000b0fff9ff0e3c0800b1ff0080ce351480ef351000bfff2d8080002188ae000a80e4012d2820025e18040c2d2000022180110233000f3c0600053c14bae2ad2d2000025e18040c0080a53433000f3c0000b0df18bae2ad01000e240800b1df33000f3c1000bfdf30baeea10800e0032000bd27",
          "target_hex": "e0ffbd270000b0ff0800b1ff1000bfff03008014f9ff103cf2010f3c1480e4252d888000008010362180b0002d2800025e18040c2188300233000f3c0600053c14bae2ad2d2020025e18040c0080a53433000f3c0000b0df18bae2ad01000e240800b1df33000f3c1000bfdf30baeea10800e0032000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001036d0_14a059d6_v4.verification.json",
    "sha256": "b18a384a7aeca49345d118ad111c241894fddd724fddf70201acfa8568d270c6",
    "verification": {
      "source_sha256": "16be85687ee4529de3af1ed5de4d1c390555b067aa6bc5e4e9f086f9c5292b69",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_001036d0_14a059d6_v4.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "001036d0",
          "symbol": "_Z13func_001036d0Phi",
          "compiled_size": 124,
          "target_size": 120,
          "ghidra_body_size": 120,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "e0ffbd270000b0ff0800b1ff1000bfff2d808000030080142d88a000f101103c14801036f9ff0f3c2d2000020080ef3521882f025e18040c2d28200233000f3c0600053c14bae2ad212011025e18040c0080a53433000f3c0000b0df18bae2ad01000e240800b1df33000f3c1000bfdf30baeea10800e0032000bd27",
          "target_hex": "e0ffbd270000b0ff0800b1ff1000bfff03008014f9ff103cf2010f3c1480e4252d888000008010362180b0002d2800025e18040c2188300233000f3c0600053c14bae2ad2d2020025e18040c0080a53433000f3c0000b0df18bae2ad01000e240800b1df33000f3c1000bfdf30baeea10800e0032000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001036d0_14a059d6_v5.verification.json",
    "sha256": "b0a4603422c0d63d90478a18b70be6cd78119b75730bb66d334e2b6e9bf00e7b",
    "verification": {
      "source_sha256": "9d0bb402b0463b60859cd0aa6d47dbaea62bda9a7351a3f8d2aec58780521791",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_001036d0_14a059d6_v5.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "001036d0",
          "symbol": "_Z13func_001036d0Phi",
          "compiled_size": 116,
          "target_size": 120,
          "ghidra_body_size": 120,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "f0ffbd27f1010e3c0000b0ff1480ce35f9ff0d3c0800bfff2d8080000080ad350a80c4012178ad002d2000022d28e0015e18040c21800f0233000f3c0600053c14bae2ad2d2000025e18040c0080a53433000f3c0000b0df18bae2ad01000e240800bfdf33000f3c30baeea10800e0031000bd27",
          "target_hex": "e0ffbd270000b0ff0800b1ff1000bfff03008014f9ff103cf2010f3c1480e4252d888000008010362180b0002d2800025e18040c2188300233000f3c0600053c14bae2ad2d2020025e18040c0080a53433000f3c0000b0df18bae2ad01000e240800b1df33000f3c1000bfdf30baeea10800e0032000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001036d0_14a059d6_v6.verification.json",
    "sha256": "63842fecfdd2eed9b6da88d65af48fbe82d4ea312d216ed9a12c1bc68e8ce312",
    "verification": {
      "source_sha256": "3ff3f3ad8fc6647441bbe62b377744d14e0af141217293d340f158042c5f7e1f",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_001036d0_14a059d6_v6.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "001036d0",
          "symbol": "_Z13func_001036d0Phi",
          "compiled_size": 120,
          "target_size": 120,
          "ghidra_body_size": 120,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "f0ffbd272d70a0000000b0ff0800bfff030080142d808000f101103c14801036f9ff0f3c2d2000020080ef352170cf0121800e025e18040c2d28c00133000f3c0600053c14bae2ad2d2000025e18040c0080a53433000f3c0000b0df18bae2ad01000e240800bfdf33000f3c30baeea10800e0031000bd27",
          "target_hex": "e0ffbd270000b0ff0800b1ff1000bfff03008014f9ff103cf2010f3c1480e4252d888000008010362180b0002d2800025e18040c2188300233000f3c0600053c14bae2ad2d2020025e18040c0080a53433000f3c0000b0df18bae2ad01000e240800b1df33000f3c1000bfdf30baeea10800e0032000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001036d0_14a059d6_v7.verification.json",
    "sha256": "7b991b0b2aad5aed635e90a2694506715cc1c2d11c37e570d216dd73cac57b89",
    "verification": {
      "source_sha256": "adfab95d07f23ae934b2276aee0e60bcc63d8dad108366139d2588319f20b93b",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_001036d0_14a059d6_v7.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "001036d0",
          "symbol": "_Z13func_001036d0Phi",
          "compiled_size": 124,
          "target_size": 120,
          "ghidra_body_size": 120,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "e0ffbd270000b0ff0800b1ff1000bfff030080142d788000f2010f3c1480ef25f9ff103c2d20e001008010362180b0002188f0015e18040c2d28000233000f3c0600053c14bae2ad2d2020025e18040c0080a53433000f3c0000b0df18bae2ad01000e240800b1df33000f3c1000bfdf30baeea10800e0032000bd27",
          "target_hex": "e0ffbd270000b0ff0800b1ff1000bfff03008014f9ff103cf2010f3c1480e4252d888000008010362180b0002d2800025e18040c2188300233000f3c0600053c14bae2ad2d2020025e18040c0080a53433000f3c0000b0df18bae2ad01000e240800b1df33000f3c1000bfdf30baeea10800e0032000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001036d0_14a059d6_v8.verification.json",
    "sha256": "598ff84c56595531c0086d96f39615cb199bae85042533acaf39ab04a0dcd543",
    "verification": {
      "source_sha256": "11f7e1cf653e1a49ba11115e2f255ca683a6d821270907466ed3d8d3dd10366f",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_001036d0_14a059d6_v8.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "001036d0",
          "symbol": "_Z13func_001036d0Phi",
          "compiled_size": 124,
          "target_size": 120,
          "ghidra_body_size": 120,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "e0ffbd270000b0ff0800b1ff1000bfff030080142d788000f2010f3c1480ef25f9ff103c2d20e001008010362180b0002188f0015e18040c2d28000233000f3c0600053c14bae2ad2d2020025e18040c0080a53433000f3c0000b0df18bae2ad01000e240800b1df33000f3c1000bfdf30baeea10800e0032000bd27",
          "target_hex": "e0ffbd270000b0ff0800b1ff1000bfff03008014f9ff103cf2010f3c1480e4252d888000008010362180b0002d2800025e18040c2188300233000f3c0600053c14bae2ad2d2020025e18040c0080a53433000f3c0000b0df18bae2ad01000e240800b1df33000f3c1000bfdf30baeea10800e0032000bd27"
        }
      ]
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001036d0_14a059d6_v9.verification.json",
    "sha256": "f5b98eaa3fc8dda3c4db884bfa2cc08be598cbef6a823272daa935775eab9882",
    "verification": {
      "source_sha256": "baf49ea555184d98c0187196c74bc29003e289be881ccbf3e2ae49677c6c55ae",
      "source": "analysis/final-mix/recovery-experiments/queue-run-20261009/recovery-c/recovery_c_001036d0_14a059d6_v9.cpp",
      "range_override": null,
      "rows": [
        {
          "address": "001036d0",
          "symbol": "_Z13func_001036d0Phi",
          "compiled_size": 116,
          "target_size": 120,
          "ghidra_body_size": 120,
          "boundary_agreement": true,
          "exact_match": false,
          "compiled_hex": "f0ffbd270000b0ff0800bfff030080142d788000f2010f3c1480ef25f9ff103c2d20e001008010362180b0002d2800025e18040c2180f00133000f3c0600053c14bae2ad2d2000025e18040c0080a53433000f3c0000b0df18bae2ad01000e240800bfdf33000f3c30baeea10800e0031000bd27",
          "target_hex": "e0ffbd270000b0ff0800b1ff1000bfff03008014f9ff103cf2010f3c1480e4252d888000008010362180b0002d2800025e18040c2188300233000f3c0600053c14bae2ad2d2020025e18040c0080a53433000f3c0000b0df18bae2ad01000e240800b1df33000f3c1000bfdf30baeea10800e0032000bd27"
        }
      ]
    }
  }
]
```
