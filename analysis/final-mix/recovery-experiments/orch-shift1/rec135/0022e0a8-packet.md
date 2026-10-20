# Target packet 0022e0a8

- Range: `0022e0a8`..`0022e10c`, **100 bytes = 25 instructions**. This size is the acceptance size.
- Layout name: `FUN_0022e0a8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001de4b0` registry: `func_001de4b0`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`, `fm_primary_oneword_recovered_0022d1d8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0022e0a8: 27bdffe0  addiu	sp,sp,-32
0022e0ac: 0000102d  move	v0,zero
0022e0b0: ffb00000  sd	s0,0(sp)
0022e0b4: ffb10008  sd	s1,8(sp)
0022e0b8: ffbf0010  sd	ra,16(sp)
0022e0bc: 24900010  addiu	s0,a0,16
0022e0c0: 0080882d  move	s1,a0
0022e0c4: 0040302d  move	a2,v0
0022e0c8: 0200202d  move	a0,s0
0022e0cc: 0c07792c  jal	0x1de4b0
0022e0d0: 0000282d  move	a1,zero
0022e0d4: 14400008  bnez	v0,0x22e0f8
0022e0d8: 240e0001  li	t6,1
0022e0dc: 0000702d  move	t6,zero
0022e0e0: dfb00000  ld	s0,0(sp)
0022e0e4: 01c0102d  move	v0,t6
0022e0e8: dfb10008  ld	s1,8(sp)
0022e0ec: dfbf0010  ld	ra,16(sp)
0022e0f0: 03e00008  jr	ra
0022e0f4: 27bd0020  addiu	sp,sp,32
0022e0f8: 8e2f000c  lw	t7,12(s1)
0022e0fc: 11e2fff8  beq	t7,v0,0x22e0e0
0022e100: 0040302d  move	a2,v0
0022e104: 1000fff1  b	0x22e0cc
0022e108: 0200202d  move	a0,s0
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0022e0a8(void)`

```c
undefined4 FUN_0022e0a8(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    iVar1 = FUN_001de4b0(param_1 + 0x10,0,iVar1);
    if (iVar1 == 0) {
      return 0;
    }
  } while (*(int *)(param_1 + 0xc) != iVar1);
  return 1;
}
```

## Earlier attempts (newest first)

- 14 differing words, 92/100 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_08_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_08_0.cpp`)
