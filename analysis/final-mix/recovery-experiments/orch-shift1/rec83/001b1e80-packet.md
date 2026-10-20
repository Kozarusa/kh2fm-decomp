# Target packet 001b1e80

- Range: `001b1e80`..`001b1ee4`, **100 bytes = 25 instructions**. This size is the acceptance size.
- Layout name: `FUN_001b1e80`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00102818` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001b1e80: 27bdfff0  addiu	sp,sp,-16
001b1e84: 240fffff  li	t7,-1
001b1e88: ffb00000  sd	s0,0(sp)
001b1e8c: ffbf0008  sd	ra,8(sp)
001b1e90: 108f0010  beq	a0,t7,0x1b1ed4
001b1e94: 0080802d  move	s0,a0
001b1e98: 3c0f0035  lui	t7,0x35
001b1e9c: 8dee0f1c  lw	t6,3868(t7)   ; = D_00350f1c
001b1ea0: 108e000c  beq	a0,t6,0x1b1ed4
001b1ea4: 3c0f0033  lui	t7,0x33
001b1ea8: 3c060005  lui	a2,0x5
001b1eac: 8de4b91c  lw	a0,-18148(t7)   ; = D_0032b91c
001b1eb0: 3c07001b  lui	a3,0x1b
001b1eb4: 24e71ee8  addiu	a3,a3,7912   ; = D_001b1ee8
001b1eb8: 0000282d  move	a1,zero
001b1ebc: 34c65730  ori	a2,a2,0x5730
001b1ec0: 0c040a06  jal	0x102818
001b1ec4: 24081000  li	t0,4096
001b1ec8: 3c0f01d5  lui	t7,0x1d5
001b1ecc: ade28c44  sw	v0,-29628(t7)   ; = D_01d48c44
001b1ed0: ac500004  sw	s0,4(v0)
001b1ed4: dfb00000  ld	s0,0(sp)
001b1ed8: dfbf0008  ld	ra,8(sp)
001b1edc: 03e00008  jr	ra
001b1ee0: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001b1e80(void)`

```c
void FUN_001b1e80(int param_1)

{
  if ((param_1 != -1) && (param_1 != DAT_00350f1c)) {
    DAT_01d48c44 = FUN_00102818(DAT_0032b91c,0,350000,0x1b1ee8,0x1000);
    *(int *)(DAT_01d48c44 + 4) = param_1;
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
