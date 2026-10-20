# Target packet 001dc018

- Range: `001dc018`..`001dc06c`, **84 bytes = 21 instructions**. This size is the acceptance size.
- Layout name: `FUN_001dc018`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001dc018: 8c8f0000  lw	t7,0(a0)
001dc01c: 0000602d  move	t4,zero
001dc020: 0000102d  move	v0,zero
001dc024: 8deb000c  lw	t3,12(t7)
001dc028: 19600009  blez	t3,0x1dc050
001dc02c: 25ed0010  addiu	t5,t7,16
001dc030: 8daf0008  lw	t7,8(t5)
001dc034: 55e50008  bnel	t7,a1,0x1dc058
001dc038: 258c0001  addiu	t4,t4,1
001dc03c: 8dae0000  lw	t6,0(t5)
001dc040: 24020001  li	v0,1
001dc044: acce0000  sw	t6,0(a2)
001dc048: 8daf0004  lw	t7,4(t5)
001dc04c: acef0000  sw	t7,0(a3)
001dc050: 03e00008  jr	ra
001dc054: 0002102b  sltu	v0,zero,v0
001dc058: 018b782a  slt	t7,t4,t3
001dc05c: 15e0fff4  bnez	t7,0x1dc030
001dc060: 25ad0020  addiu	t5,t5,32
001dc064: 1000fffa  b	0x1dc050
001dc068: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001dc018(void)`

```c
undefined1 FUN_001dc018(int *param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar2 = 0;
  iVar1 = *(int *)(*param_1 + 0xc);
  puVar3 = (undefined4 *)(*param_1 + 0x10);
  if (0 < iVar1) {
    do {
      if (puVar3[2] == param_2) {
        *param_3 = *puVar3;
        *param_4 = puVar3[1];
        return 1;
      }
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 8;
    } while (iVar2 < iVar1);
  }
  return 0;
}
```

## Earlier attempts (newest first)

- 18 differing words, 76/84 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_05.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_05.cpp`)
