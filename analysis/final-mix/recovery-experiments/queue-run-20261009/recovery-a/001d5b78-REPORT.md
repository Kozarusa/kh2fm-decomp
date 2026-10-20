# Signed-low global and prologue scheduling 001d5b78

Live range is 64 bytes. Original lui 0x1d6 and signed lw low 0xba70 establishes D_01d5ba70; the archived DAT_01d6ba60 declaration had the wrong global. Symbolic D_003217a0 fixes ori/addiu and a trailing memory barrier prevents tail-call optimization. v1 now differs only by swapped lw t6 and sd ra at offsets 8/16. Volatile global did not fix it. Entry memory or ra/register barriers alter argument allocation and the full schedule. s64 parameters add width transport instructions. Seven failed variants preserved.

Next: constrain the global loaded value through an empty t6 register output after sll, without any barrier at function entry; preserve early lui and original argument allocation.

```json
[
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_001d5b78_fc79ca3d_v1.verification.json",
    "proof_sha256": "ced4fdb7395810972fc77815083fbce0b88cc2dd8a427b49d6a96c60324f4ac4",
    "source_sha256": "d9a39898fda5f81a4e88ea24f32538b3a6f90a8666bba31e080b77b1318bdcdf",
    "row": {
      "address": "001d5b78",
      "symbol": "_Z13func_001d5b78jj",
      "compiled_size": 64,
      "target_size": 64,
      "ghidra_body_size": 64,
      "boundary_agreement": true,
      "exact_match": false,
      "compiled_hex": "f0ffbd27d6010f3c70baee8d002104000000bfff252085003200083c080007240400c68da01708250800ce2592f40b0c2d28c0010000bfdf0800e0031000bd27",
      "target_hex": "f0ffbd27d6010f3c0000bfff0021040070baee8d252085003200083c080007240400c68da01708250800ce2592f40b0c2d28c0010000bfdf0800e0031000bd27"
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_001d5b78_fc79ca3d_v2.verification.json",
    "proof_sha256": "64de7a83ed9cf3a66a29a75f2ce41a6ea70f4b3663826fce718cb9d4e123df95",
    "source_sha256": "b1242ee05da23e0d3a5762d449729900d751f7b949e664df6fe0cae22c14fb3b",
    "row": {
      "address": "001d5b78",
      "symbol": "_Z13func_001d5b78jj",
      "compiled_size": 64,
      "target_size": 64,
      "ghidra_body_size": 64,
      "boundary_agreement": true,
      "exact_match": false,
      "compiled_hex": "f0ffbd27d6010f3c70baee8d002104000000bfff252085003200083c080007240400c68da01708250800ce2592f40b0c2d28c0010000bfdf0800e0031000bd27",
      "target_hex": "f0ffbd27d6010f3c0000bfff0021040070baee8d252085003200083c080007240400c68da01708250800ce2592f40b0c2d28c0010000bfdf0800e0031000bd27"
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_001d5b78_fc79ca3d_v3.verification.json",
    "proof_sha256": "09ebadae404ca06b3fec557dfbcd56fd72ac508676c6135f454320cdade585ac",
    "source_sha256": "b872c180eb30a6c29d54524c5628a88cd08dffb6360d4c8b4d51c9957a68931e",
    "row": {
      "address": "001d5b78",
      "symbol": "_Z13func_001d5b78jj",
      "compiled_size": 64,
      "target_size": 64,
      "ghidra_body_size": 64,
      "boundary_agreement": true,
      "exact_match": false,
      "compiled_hex": "f0ffbd272d70a0000000bfffd6010f3c0021040070bae58d3200083c25208e00a01708250400a68c0800072492f40b0c0800a5240000bfdf0800e0031000bd27",
      "target_hex": "f0ffbd27d6010f3c0000bfff0021040070baee8d252085003200083c080007240400c68da01708250800ce2592f40b0c2d28c0010000bfdf0800e0031000bd27"
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_001d5b78_fc79ca3d_v4.verification.json",
    "proof_sha256": "21b70b08d5e0d644ac54142cbf933610a649f657d592b71bd0de3f435dafb09b",
    "source_sha256": "50b9a6a0399e2b6f7b1d9bcaefe4bcefe4c007d26db20d52ac9af9ffe660bfda",
    "row": {
      "address": "001d5b78",
      "symbol": "_Z13func_001d5b78xx",
      "compiled_size": 72,
      "target_size": 64,
      "ghidra_body_size": 64,
      "boundary_agreement": true,
      "exact_match": false,
      "compiled_hex": "f0ffbd27d6010f3c70baee8d382104000000bfff252085003c2004003200083c0400c68d3f200400a0170825080007240800ce2592f40b0c2d28c0010000bfdf0800e0031000bd27",
      "target_hex": "f0ffbd27d6010f3c0000bfff0021040070baee8d252085003200083c080007240400c68da01708250800ce2592f40b0c2d28c0010000bfdf0800e0031000bd27"
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_001d5b78_fc79ca3d_v5.verification.json",
    "proof_sha256": "a0a2ec087f60585e8395028684bd873b21129535724174f3f0f1ab20079ffd87",
    "source_sha256": "84250770a29afd6467b46360532e1b0b902aac7dd51fdc6664cc2ed1dd3eed2a",
    "row": {
      "address": "001d5b78",
      "symbol": "_Z13func_001d5b78jj",
      "compiled_size": 64,
      "target_size": 64,
      "ghidra_body_size": 64,
      "boundary_agreement": true,
      "exact_match": false,
      "compiled_hex": "f0ffbd272d70a0000000bfffd6010f3c0021040070bae58d3200083c25208e00a01708250400a68c0800072492f40b0c0800a5240000bfdf0800e0031000bd27",
      "target_hex": "f0ffbd27d6010f3c0000bfff0021040070baee8d252085003200083c080007240400c68da01708250800ce2592f40b0c2d28c0010000bfdf0800e0031000bd27"
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_001d5b78_fc79ca3d_v6.verification.json",
    "proof_sha256": "c771e7683ea07d8a89bd0686e79b265869334f6b51701658fdabf472b7cc9422",
    "source_sha256": "9300a8fc4568feef918556380e1a4871160b7368f315031ac0d13b47a779a4b1",
    "row": {
      "address": "001d5b78",
      "symbol": "_Z13func_001d5b78jj",
      "compiled_size": 64,
      "target_size": 64,
      "ghidra_body_size": 64,
      "boundary_agreement": true,
      "exact_match": false,
      "compiled_hex": "f0ffbd272d70a0000000bfffd6010f3c0021040070bae58d3200083c25208e00a01708250400a68c0800072492f40b0c0800a5240000bfdf0800e0031000bd27",
      "target_hex": "f0ffbd27d6010f3c0000bfff0021040070baee8d252085003200083c080007240400c68da01708250800ce2592f40b0c2d28c0010000bfdf0800e0031000bd27"
    }
  },
  {
    "proof": "Codex\\analysis\\final-mix\\recovery-experiments\\queue-run-20261009\\recovery-a\\recovery_a_001d5b78_fc79ca3d_v7.verification.json",
    "proof_sha256": "2594e2bca8b8954b6c1d93e2783eb2886659635bb2436366ec077a0eb55e2acb",
    "source_sha256": "96aef7c71138c681fee5a081540cfc6f9ed440a28656ef319955eb9165281ff2",
    "row": {
      "address": "001d5b78",
      "symbol": "_Z13func_001d5b78jj",
      "compiled_size": 64,
      "target_size": 64,
      "ghidra_body_size": 64,
      "boundary_agreement": true,
      "exact_match": false,
      "compiled_hex": "f0ffbd272d70a0000000bfff00210400d6010f3c3200083c70bae58d25208e00a0170825080007240400a68c92f40b0c0800a5240000bfdf0800e0031000bd27",
      "target_hex": "f0ffbd27d6010f3c0000bfff0021040070baee8d252085003200083c080007240400c68da01708250800ce2592f40b0c2d28c0010000bfdf0800e0031000bd27"
    }
  }
]
```
