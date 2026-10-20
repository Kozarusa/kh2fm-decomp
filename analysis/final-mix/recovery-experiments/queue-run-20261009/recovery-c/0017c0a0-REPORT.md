# 0017c0a0 initial stack-argument scheduling

Live layout is 0017c0a0-0017c108, 104 bytes. The queue label described a historical final-store residual. The nominated v5_1 best proposal already matches both final stores exactly; its only differences are initial argument placement at words 3 and 5. The target moves sp to a0, saves ra, then computes a2=sp+32. The best proposal computes a2 first and moves sp to a0 after the save.

Eighteen new isolated variants test explicit extra-address constraints, pointer input dependencies, narrow ABI widths, local aggregate/declaration order, explicit move-address transport, memory operands, and a genuine hidden aggregate-return/by-value-callee hypothesis. None matches. Several retain 104 bytes and only the original two differing words. Explicit moves and volatile constraints disturb prologue order. Native aggregate-return/by-value transport also yields 104 bytes in v16 but uses an 80-byte rather than 64-byte frame and a return temporary at sp+48, with different quadword registers. Thus the ABI hypothesis is plausible but not a recovery; no impossible-compiler claim is made.

Next: inspect the complete 0017c030/0017c4c8 callees for their actual aggregate ABI and pointer roles, then model the original local lifetime/output-buffer reuse rather than repeat the tested pointer constraints. The by-value control proves the compiler can produce an equal-size quadword transport call but does not prove the inferred ABI is correct. Failures, source versions and logs remain preserved; no shared registry, layout, source stage or checkpoint was modified.

[
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_0017c0a0_e7816918_v0.verification.json",
    "sha256": "9686e3a7571b84878c78900d1b0fb26f6ea3b3d11f4d5d95f56011c8520952c7",
    "source_sha256": "ad9737ccd2296e65e1e98b7fb4757675602f7e5c9b852df4439606c11891ec66",
    "compiled_size": 104,
    "different_words": [
      3,
      5
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_0017c0a0_e7816918_v1.verification.json",
    "sha256": "70b08eef13b70d991fc6889c0847d40e5a19221eb0b413816aa9efbc49db2977",
    "source_sha256": "4eeff0bdb30be6d6b6143ad318114f3f3e5f5371f27ebf9c08e5ce4dab26bd87",
    "compiled_size": 108,
    "different_words": [
      1,
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
      16,
      17,
      18,
      19,
      20,
      21,
      22,
      23,
      24,
      25
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_0017c0a0_e7816918_v10.verification.json",
    "sha256": "e06156bb0c2d8d1423a95909576920b0432d4aa1c090dbf6519f67e8f0826a54",
    "source_sha256": "686a486f1036a4ff2be186e190befd26c8557456ea6402898dacee9dfe99441b",
    "compiled_size": 104,
    "different_words": [
      3,
      5,
      7
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_0017c0a0_e7816918_v11.verification.json",
    "sha256": "6db8a298dae40b2876c069de88630180720e7708cb4e18b7f2d23f551820d610",
    "source_sha256": "301df4b01faa820de3bcbb292971e39defb05c79434ac1c55074d7bfe41b5a57",
    "compiled_size": 104,
    "different_words": [
      1,
      2,
      3,
      4,
      5,
      7
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_0017c0a0_e7816918_v12.verification.json",
    "sha256": "22e55ee6b0937b0c9eec1c64551d631753c6792c8a9562b9710c55043327bae0",
    "source_sha256": "3b01fd967eb0329f6b6456f74540f52961c2518105f4ef316c201313a93714b0",
    "compiled_size": 104,
    "different_words": [
      3,
      5
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_0017c0a0_e7816918_v13.verification.json",
    "sha256": "e0b8e9a93eaacb8368782412075ecc66f4e34c56821555c380a15da7a20b6783",
    "source_sha256": "db3d6fa7053d338d1461fb05d6cfea24a6f300bd100526e04d9801adbb292e73",
    "compiled_size": 104,
    "different_words": [
      3,
      5
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_0017c0a0_e7816918_v14.verification.json",
    "sha256": "77ea7a2421d1cc855479fd8dea8e1a3f81e427109232440265a816bb82c5b4e6",
    "source_sha256": "5fe1e2811bf853b487ad5d2012bfbc40ad34cacd0b1e459e6d3cb8c7ae2e5e72",
    "compiled_size": 112,
    "different_words": [
      0,
      2,
      3,
      4,
      8,
      9,
      10,
      11,
      12,
      13,
      14,
      15,
      16,
      17,
      18,
      19,
      20,
      21,
      22,
      23,
      24,
      25
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_0017c0a0_e7816918_v15.verification.json",
    "sha256": "aed0b1cf112eb9fb25439f8d4be12e8cfe01dadbb64e25614b46fce66cb10a28",
    "source_sha256": "4e0008d0ccb20fcf4605351934954cc67a5dec1ac2fc7879df91f12a83facee3",
    "compiled_size": 116,
    "different_words": [
      0,
      3,
      4,
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
      16,
      17,
      18,
      19,
      20,
      21,
      22,
      23,
      24,
      25
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_0017c0a0_e7816918_v16.verification.json",
    "sha256": "f630334c947a3b232040a61f471df8a565f77fb0eda08b27f1520d9c59cb5ddf",
    "source_sha256": "97cfce7c8a8d971ce1b40d2cc9921a8482bd473ea6e33437f7d389a534de916c",
    "compiled_size": 104,
    "different_words": [
      0,
      2,
      3,
      4,
      5,
      8,
      9,
      10,
      12,
      19,
      23,
      25
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_0017c0a0_e7816918_v17.verification.json",
    "sha256": "34680063ee11c6588bf324ef1ad6dc023eca68477b4e8e80e8989260fc78d30b",
    "source_sha256": "7447d2c5377b6703aa9e4bf543060dd1e387d2c286b8189cc64e212c059f0e2e",
    "compiled_size": 108,
    "different_words": [
      2,
      3,
      4,
      5,
      6,
      8,
      9,
      10,
      12,
      15,
      19,
      23,
      24,
      25
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_0017c0a0_e7816918_v2.verification.json",
    "sha256": "36fe5bd43fa86ad3b84a12cf2cf0823f2a806102c07186d0d6ccfa0c64526530",
    "source_sha256": "a8f1fda592ed0a994b86912e3bad26314f75fae216179600d56b2e03983e26e9",
    "compiled_size": 108,
    "different_words": [
      1,
      3,
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
      16,
      17,
      18,
      19,
      20,
      21,
      22,
      23,
      24,
      25
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_0017c0a0_e7816918_v3.verification.json",
    "sha256": "86279a4238b54a6d731e17c3b0ae64eba9b69460ecd09d97234e7568af176e78",
    "source_sha256": "874afa4412aaf57c5b7f567bfdf9b2cde20e40ea4730be88b4b0aa9eced34135",
    "compiled_size": 104,
    "different_words": [
      3,
      5
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_0017c0a0_e7816918_v4.verification.json",
    "sha256": "73920c1cbab3c9512101b17ac57514572f5ae335bac961f5c21dc241065af077",
    "source_sha256": "7de1474d6e97f03af6ac62420e8d59ff5dcd2ca1dd5cd1e08b327c976544a60d",
    "compiled_size": 104,
    "different_words": [
      3,
      5
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_0017c0a0_e7816918_v5.verification.json",
    "sha256": "c07510dd0883a20cc5c59998aaf0ff96d9b10eb0228db18bb5ada366da031104",
    "source_sha256": "3bd241067cb90c31d1b39071c6cd9c1d7452a2b96950a23ce255f9cede4d649c",
    "compiled_size": 104,
    "different_words": [
      3,
      5
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_0017c0a0_e7816918_v6.verification.json",
    "sha256": "03fc4a7e282c26db266a49ee773d23762cc6755a8a89862b3db07fef2aa499ec",
    "source_sha256": "975e99519c0376bb91a17271d24548932f4d07432d5a02ef2d8698c3e8086efa",
    "compiled_size": 112,
    "different_words": [
      3,
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
      16,
      17,
      18,
      19,
      20,
      21,
      22,
      23,
      24,
      25
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_0017c0a0_e7816918_v7.verification.json",
    "sha256": "1e8abbcff0acb46cae8a3d0376967c131f9245a0fb564e6c971cc148ddf828ea",
    "source_sha256": "c66ae841224e5e7365ab34c32d2380f00634d0f7012b968ec881ea16c562fcd8",
    "compiled_size": 152,
    "different_words": [
      0,
      3,
      4,
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
      16,
      17,
      18,
      19,
      20,
      21,
      22,
      23,
      24,
      25
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_0017c0a0_e7816918_v8.verification.json",
    "sha256": "2d66e694179079475bd9e74baf965bf3f1b24cf72ebd0a2c48bc920e1f2582bd",
    "source_sha256": "215da54157a89b5795acfe2e26fda71ddc385fcbe25fc68246f74e0d18de9f81",
    "compiled_size": 116,
    "different_words": [
      0,
      3,
      4,
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
      16,
      17,
      18,
      19,
      20,
      21,
      22,
      23,
      24,
      25
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_0017c0a0_e7816918_v9.verification.json",
    "sha256": "8f761a324c60a54e0b57c2cc18f3f6635479eaff4f7c2dfa1dd788e336aae156",
    "source_sha256": "9ebe94f6f45c07d9a08887cc6d33d632d860835fc94b63e1d62af7eb7799378a",
    "compiled_size": 104,
    "different_words": [
      3,
      5
    ]
  }
]