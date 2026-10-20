# Target packet 001c5f38

- Range: `001c5f38`..`001c5f78`, **64 bytes = 16 instructions**. This size is the acceptance size.
- Layout name: `FUN_001c5f38`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001c5e88` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001c5f38: 27bdfff0  addiu	sp,sp,-16
001c5f3c: 3c0f0035  lui	t7,0x35
001c5f40: ffbf0000  sd	ra,0(sp)
001c5f44: 25ef1680  addiu	t7,t7,5760   ; = D_00351680
001c5f48: 908e0052  lbu	t6,82(a0)
001c5f4c: 000e7140  sll	t6,t6,0x5
001c5f50: 01cf7021  addu	t6,t6,t7
001c5f54: 8dcd0014  lw	t5,20(t6)
001c5f58: 19a00004  blez	t5,0x1c5f6c
001c5f5c: 0000102d  move	v0,zero
001c5f60: 0c0717a2  jal	0x1c5e88
001c5f64: 00000000  nop
001c5f68: 24020001  li	v0,1
001c5f6c: dfbf0000  ld	ra,0(sp)
001c5f70: 03e00008  jr	ra
001c5f74: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001c5f38(void)`

```c
bool FUN_001c5f38(int param_1)

{
  int iVar1;
  
  iVar1 = (&DAT_00351694)[(uint)*(byte *)(param_1 + 0x52) * 8];
  if (0 < iVar1) {
    FUN_001c5e88();
  }
  return 0 < iVar1;
}
```

## Earlier attempts (newest first)

- 7 differing words, 64/64 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round19_001c5f38_v02.verification.json`
- 7 differing words, 64/64 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round19_001c5f38_v01.verification.json`
