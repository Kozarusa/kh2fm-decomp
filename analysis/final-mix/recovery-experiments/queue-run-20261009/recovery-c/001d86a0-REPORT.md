# 001d86a0 returned-pointer/index register blocker

Live range 001d86a0-001d8718 is 120 bytes. Original best proposal computes the final indexed pointer in t6; target adds index t6 into returned pointer v0 and loads through v0. New variant v1 fixes pointer v0 via an explicit register variable and assigning the summed pointer, retaining 120 bytes. It differs only in index register t7 instead of original t6 at words 11, 13 and 14. This is new evidence beyond the original two-word mismatch.

Four controls tested direct fixed pointer, fixed pointer assignment, read/write pointer capture and fixed index capture. The latter two add an inline asm expression and lose the original branch-likely arrangement, producing116 bytes. v4 is prepared but UNPROBED because primary paused integration. It retains v1 pointer assignment and forces the explicit offset variable to t6 without the inline asm expression, testing whether native register hints retain the original branch-likely while fixing index register allocation. This source must be reprobed under a fresh claim before submission. All failed sources/proofs/logs are preserved; no shared registry, layout, stage or checkpoint was changed.

[
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001d86a0_c6c14d13_v0.verification.json",
    "sha256": "b36909ded1ce8c7c3d88e32ad2843cd0d5a032c6ad841dbecb15b97848ffad49",
    "source_sha256": "2c318ad03916322130a9689ad409531d9cc5a2baf6731b5e29d164ae0df410d6",
    "compiled_size": 120,
    "different_words": [
      11,
      13,
      14,
      15,
      16,
      17,
      18
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001d86a0_c6c14d13_v1.verification.json",
    "sha256": "0fa380ee849110bc6148bf20c9b61afc3f52fee55082314e5c45460c0aa7b329",
    "source_sha256": "43b59fc40bd3565df33fa1aa05da87a6fee3dd8e17c91741f2edaded655e2a61",
    "compiled_size": 120,
    "different_words": [
      11,
      13,
      14
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001d86a0_c6c14d13_v2.verification.json",
    "sha256": "dbea6208dc731bb44907d2e81588d3e0a546d32b3076a06c5b65fd87d467499c",
    "source_sha256": "36d08774821a22b90c76c616a220f6635ece075490bdbb9ca8441931208b93b1",
    "compiled_size": 116,
    "different_words": [
      7,
      11,
      13,
      14,
      15,
      16,
      17,
      18,
      19,
      25,
      26,
      27,
      28
    ]
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-c\\recovery_c_001d86a0_c6c14d13_v3.verification.json",
    "sha256": "db6fa8becec694a867e8fbf58330c2dc97ee4d7da861019f6075f5d15b3379c0",
    "source_sha256": "fc56fc5a0fb9e46a294103656ba71219ccb44b5d776baa3de8923ebdd4570894",
    "compiled_size": 116,
    "different_words": [
      7,
      14,
      15,
      16,
      17,
      18,
      19,
      25,
      26,
      27,
      28
    ]
  }
]