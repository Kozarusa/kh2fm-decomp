# 001c2ce8 final-store ordering blocker

Live complete range is 001c2ce8-001c2d34, 76 bytes. Original best proposal already has every word exact except final two stores: target stores the vtable address at object offset zero before modified flags at 2748, while compiler reverses them.

Fourteen new complete isolated variants test memory barriers, volatile first/last/both stores, canonical reordered loads, empty input/read-write flag constraints, fixed flag register hints, and operand-specific final-pair assembly. None matches. Most produce broad upstream scheduling/register allocation changes, not range-size changes. The best fresh control v2 remains 76 bytes and differs only in the same final two words. Failures are preserved with logs; no shared registry, layout or stage was edited.

Next: use a canonical object/field alias description or a narrow pointer dependency before the final pair that preserves earlier load/register lifetimes. Evidence shows generic memory clobbers and grouped raw stores disturb the initial flag calculations, so avoid repeating those exact variants. Fixed flag register hints alone also failed. A different source alias/type description is an untested hypothesis, not a proven compiler limitation.

[
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001c2ce8_bfa33ef6_v0.verification.json",
    "sha256": "ab78468cb70857e624ce1bf5c377228a5d61a638b5a8c08960c993ff1a800489",
    "source_sha256": "1a4eeb6a063e031c0a3eaafdad8d73e1b17d2fd7b17c60dbc4820dd5b92dfb38",
    "compiled_size": 76,
    "different_words": [
      5,
      6,
      7,
      8,
      9,
      10,
      11,
      12,
      13,
      14,
      15
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001c2ce8_bfa33ef6_v1.verification.json",
    "sha256": "585541fc6f6e8f4ff2baeeb65ac96178b6bd340edf6e53b7d35261c75314e1fa",
    "source_sha256": "81e8339a9119e31b1044dd58a5bb66881883f4b24a93fd451b15033da1fec05c",
    "compiled_size": 76,
    "different_words": [
      5,
      6,
      7,
      8,
      9,
      10,
      11,
      12,
      13,
      14,
      15
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001c2ce8_bfa33ef6_v10.verification.json",
    "sha256": "a5a26c837b12073f23839a444ebadcf9d5c20c3dd4282ec157515ac244879c36",
    "source_sha256": "d4f211d571a7129817223eee929652085dd806d9d9800b7b673fc3a30ad05641",
    "compiled_size": 76,
    "different_words": [
      6,
      8,
      9,
      10,
      11,
      13,
      14,
      15
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001c2ce8_bfa33ef6_v11.verification.json",
    "sha256": "25411634e90dfd440956b2dc4cf0333324c0d535f1b8b6967b78a8b38735662d",
    "source_sha256": "857caf2dffa66384a2fb807a2e34e9b45c03ff88c297e0d31e12ccb48fc5daee",
    "compiled_size": 76,
    "different_words": [
      5,
      6,
      7,
      8,
      9,
      10,
      11,
      12,
      13,
      14
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001c2ce8_bfa33ef6_v12.verification.json",
    "sha256": "fa19094b8dcd49a5fbf934236c9fb05663a1761fbdfdb7d6b79bb968954143ea",
    "source_sha256": "373e1b52202754ff57ff47d708dc8e8da98981de55046e44f2f751fd4cf57891",
    "compiled_size": 76,
    "different_words": [
      5,
      6,
      7,
      8,
      9,
      10,
      11,
      12,
      13,
      14,
      15,
      16
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001c2ce8_bfa33ef6_v13.verification.json",
    "sha256": "e2b0fcd67defb819c091cce7b22ff1154edf5ba67b59a8dae109db2b88ec751b",
    "source_sha256": "fe8857a0f50488a57fd537a1b1d1a3334f259f983f39c5d7821628a9ae1d29cd",
    "compiled_size": 76,
    "different_words": [
      5,
      6,
      8,
      9,
      10,
      11,
      13,
      14,
      15,
      16
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001c2ce8_bfa33ef6_v2.verification.json",
    "sha256": "f164aa01d4bb1ef7766053d7dd33cb7095140e53185b880ffe2967530eb5eb0e",
    "source_sha256": "4fc5364ad686ebe6abc8de2e0fece0bb22c234de61b29f6942d6b80a21bec832",
    "compiled_size": 76,
    "different_words": [
      14,
      15
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001c2ce8_bfa33ef6_v3.verification.json",
    "sha256": "1a48a98357eb83bb0ad1eef0c4f485548bfc73da243c779a3f4579b39c61d369",
    "source_sha256": "ba251f3a7c85b47d602180e3f4740b49384a5e322f879d2d3da4b8a6f043dfa5",
    "compiled_size": 76,
    "different_words": [
      5,
      6,
      7,
      8,
      9,
      10,
      11,
      12,
      13,
      14,
      15
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001c2ce8_bfa33ef6_v4.verification.json",
    "sha256": "c88bf6a95bcbecea2c38c559397f2d800434bba7d137082b676732ac4951c70b",
    "source_sha256": "d9ef09145ef431b84117b094e347f3bc8b96cd09adc1adff842166fd45889ec9",
    "compiled_size": 76,
    "different_words": [
      5,
      6,
      7,
      8,
      9,
      10,
      11,
      12,
      13,
      14,
      15,
      16
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001c2ce8_bfa33ef6_v5.verification.json",
    "sha256": "f60518ca2a7a4fa4ae7561127d5ee3b593263df1c1462666912025c6c504c194",
    "source_sha256": "37500b1c3611b40a1ef2fe68a4db4c7ba73fc67c3b7bd213823ba505b1851fea",
    "compiled_size": 76,
    "different_words": [
      5,
      6,
      7,
      8,
      9,
      10,
      11,
      12,
      13,
      14,
      15,
      16
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001c2ce8_bfa33ef6_v6.verification.json",
    "sha256": "f3b2bb2fe5efed06cb654d37572c32c03acc74095a63c58dc377da9536aa901c",
    "source_sha256": "dd4ce4819c44b98be1b480257fdfa321034deaeb531b2b2974396777907f7206",
    "compiled_size": 76,
    "different_words": [
      5,
      7,
      8,
      11,
      12,
      14,
      15
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001c2ce8_bfa33ef6_v7.verification.json",
    "sha256": "9c2390e109a711c2d764448d6ab162f9e4021efde70a38aa8751ce56e7eccbd5",
    "source_sha256": "94396e1f103a2b2f41435860a6565c42565447d1ca29e922e2a571bbf4401dcb",
    "compiled_size": 76,
    "different_words": [
      5,
      6,
      7,
      8,
      9,
      10,
      11,
      12,
      13,
      14,
      15
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001c2ce8_bfa33ef6_v8.verification.json",
    "sha256": "a4c765bbf067d0a41f3ef125d8f07c31a03345b15abf3e0b3912661c920098bc",
    "source_sha256": "c53c98aa56a4bda781a1219e4443630d7fcbf1ff4e6d0b1d7d20fc83cb84a805",
    "compiled_size": 76,
    "different_words": [
      5,
      6,
      7,
      8,
      9,
      10,
      11,
      12,
      13,
      14,
      15
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001c2ce8_bfa33ef6_v9.verification.json",
    "sha256": "94ec343008f9ac4592c5572a1be7d33a93a5749c5c739146a3213f9f4c910867",
    "source_sha256": "2a581f64868ccadde0233993a8336b1a754abe37180406337081ba7de8b67198",
    "compiled_size": 76,
    "different_words": [
      5,
      6,
      7,
      8,
      9,
      10,
      11,
      12,
      13,
      14,
      15
    ]
  }
]