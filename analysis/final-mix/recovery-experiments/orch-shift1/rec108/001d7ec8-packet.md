# Target packet 001d7ec8

- Range: `001d7ec8`..`001d7f10`, **72 bytes = 18 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d7ec8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001d7f10` registry: `func_001d7f10`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d7ec8: 27bdfff0  addiu	sp,sp,-16
001d7ecc: ffb00000  sd	s0,0(sp)
001d7ed0: ffbf0008  sd	ra,8(sp)
001d7ed4: 0c075fc4  jal	0x1d7f10
001d7ed8: 0080802d  move	s0,a0
001d7edc: 00107080  sll	t6,s0,0x2
001d7ee0: 10400006  beqz	v0,0x1d7efc
001d7ee4: 0000682d  move	t5,zero
001d7ee8: 3c0f0035  lui	t7,0x35
001d7eec: 8ded28f8  lw	t5,10488(t7)   ; = D_003528f8
001d7ef0: 01cd7021  addu	t6,t6,t5
001d7ef4: 8dcf0008  lw	t7,8(t6)
001d7ef8: 01af6821  addu	t5,t5,t7
001d7efc: dfb00000  ld	s0,0(sp)
001d7f00: 01a0102d  move	v0,t5
001d7f04: dfbf0008  ld	ra,8(sp)
001d7f08: 03e00008  jr	ra
001d7f0c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d7ec8(void)`

```c
int FUN_001d7ec8(int param_1)

{
  long lVar1;
  int iVar2;
  
  lVar1 = FUN_001d7f10();
  iVar2 = 0;
  if (lVar1 != 0) {
    iVar2 = DAT_003528f8 + *(int *)(param_1 * 4 + DAT_003528f8 + 8);
  }
  return iVar2;
}
```

## Earlier attempts (newest first)

- 15 differing words, 72/72 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round22_001d7ec8_v02.verification.json`
- 16 differing words, 76/72 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round22_001d7ec8_v01.verification.json`
