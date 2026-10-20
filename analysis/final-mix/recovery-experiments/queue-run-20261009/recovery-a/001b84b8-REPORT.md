# Conditional cached-result reload residual 001b84b8

Live range is 100 bytes. Symbolic callback func_001b8520 fixes ori/addiu and high half. Barrier after member[4] store fixes initial store/load order, but compiler caches member[2] call result and loads it into v0 instead of original t7 before bnel. Original code reloads member[2] after helper result store. Applying a memory barrier to both reload branches changes branch layout and yields 112 bytes. v4 is prepared but unprobed: add barrier only after helper-result store, preserving untouched else reload. Primary pause arrived before this fresh probe.

Next: probe v4 and test volatile member[2] read only after the helper-result store if needed. The original reload evidence supports this narrower barrier.

```json
[
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_001b84b8_50c8e3c3_v1.verification.json",
    "sha256": "8deb5041582a28bbe8d1a2322e663d1b4c30ce681e790dee67f7cf50b30ff434",
    "source_sha256": "ca2849035d61b1f6f39ad1f6f0e9e34781ed7d0716228e1467381b1388db8547",
    "row": {
      "address": "001b84b8",
      "symbol": "_Z13func_001b84b8jj",
      "compiled_size": 100,
      "target_size": 100,
      "ghidra_body_size": 100,
      "boundary_agreement": true,
      "exact_match": false,
      "compiled_hex": "f0ffbd272d1000000000b0ff0800bfff04008f8c0f00e0112d80800008008f8c100085ac0400e0152d10e00108e1060c0000848c080002ae1c00053c2d2040002d300002846d070c2085a524080002ae2b1002000000b0df0800bfdf0800e0031000bd27",
      "target_hex": "f0ffbd272d1000000000b0ff0800bfff04008f8c0f00e0112d808000100085ac08008f8c0500e0550800048e08e1060c0000848c080002ae0800048e1c00053c2d300002846d070c2085a524080002ae2b1002000000b0df0800bfdf0800e0031000bd27"
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_001b84b8_50c8e3c3_v2.verification.json",
    "sha256": "365ec67f90a914827e002ed503da81fabea21b721733b89e526a17d23558b84e",
    "source_sha256": "bd0f513eb313881b312bc0e7bb23d91d3401a8f35d5f8ef7556042ce072a1cfa",
    "row": {
      "address": "001b84b8",
      "symbol": "_Z13func_001b84b8jj",
      "compiled_size": 100,
      "target_size": 100,
      "ghidra_body_size": 100,
      "boundary_agreement": true,
      "exact_match": false,
      "compiled_hex": "f0ffbd272d1000000000b0ff0800bfff04008f8c0f00e0112d808000100085ac0800828c050040541c00053c08e1060c0000848c080002ae1c00053c2d2040002d300002846d070c2085a524080002ae2b1002000000b0df0800bfdf0800e0031000bd27",
      "target_hex": "f0ffbd272d1000000000b0ff0800bfff04008f8c0f00e0112d808000100085ac08008f8c0500e0550800048e08e1060c0000848c080002ae0800048e1c00053c2d300002846d070c2085a524080002ae2b1002000000b0df0800bfdf0800e0031000bd27"
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_001b84b8_50c8e3c3_v3.verification.json",
    "sha256": "7e163c8d5bc7a582a05e94ece4367b6e43c1ca9bbfec597bfa5663876de1db10",
    "source_sha256": "f588cf898d83451b1d514334e68c7ddec344a44e705b1d6cdf42f5b3119c2751",
    "row": {
      "address": "001b84b8",
      "symbol": "_Z13func_001b84b8jj",
      "compiled_size": 112,
      "target_size": 100,
      "ghidra_body_size": 100,
      "boundary_agreement": true,
      "exact_match": false,
      "compiled_hex": "f0ffbd272d1000000000b0ff0800bfff04008f8c1000e0112d808000100085ac08008f8c1000e0150000000008e1060c0000848c080002ae0800028e1c00053c2d3000022085a524846d070c2d204000080002ae2b1002000000b0df0800bfdf0800e0031000bd27f4ff00100800028e",
      "target_hex": "f0ffbd272d1000000000b0ff0800bfff04008f8c0f00e0112d808000100085ac08008f8c0500e0550800048e08e1060c0000848c080002ae0800048e1c00053c2d300002846d070c2085a524080002ae2b1002000000b0df0800bfdf0800e0031000bd27"
    }
  }
]
```
