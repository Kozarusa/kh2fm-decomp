# Target packet 00180dc0

- Range: `00180dc0`..`00180df4`, **52 bytes = 13 instructions**. This size is the acceptance size.
- Layout name: `FUN_00180dc0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00180dc0: 2484014c  addiu	a0,a0,332
00180dc4: 0000702d  move	t6,zero
00180dc8: 8c8f0000  lw	t7,0(a0)
00180dcc: 24020001  li	v0,1
00180dd0: 11e50006  beq	t7,a1,0x180dec
00180dd4: 24840004  addiu	a0,a0,4
00180dd8: 25ce0001  addiu	t6,t6,1
00180ddc: 29cf0010  slti	t7,t6,16
00180de0: 55e0fffb  bnezl	t7,0x180dd0
00180de4: 8c8f0000  lw	t7,0(a0)
00180de8: 0000102d  move	v0,zero
00180dec: 03e00008  jr	ra
00180df0: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00180dc0(void)`

```c
undefined4 FUN_00180dc0(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)(param_1 + 0x14c);
  iVar2 = 0;
  iVar3 = *piVar1;
  while( true ) {
    piVar1 = piVar1 + 1;
    if (iVar3 == param_2) {
      return 1;
    }
    iVar2 = iVar2 + 1;
    if (0xf < iVar2) break;
    iVar3 = *piVar1;
  }
  return 0;
}
```

## Earlier attempts (newest first)

- 11 differing words, 56/52 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_02.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_02.cpp`)
