# Target packet 00198bd0

- Range: `00198bd0`..`00198c28`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_00198bd0`
- Registry names for this address: `_Z16ctarget_00198bd0jjjj`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00198bd0: 3c0f01c6  lui	t7,0x1c6
00198bd4: 0000602d  move	t4,zero
00198bd8: 25ee1b48  addiu	t6,t7,6984   ; = D_01c61b48
00198bdc: 25cd0580  addiu	t5,t6,1408
00198be0: 8dcf0000  lw	t7,0(t6)
00198be4: 55e4000a  bnel	t7,a0,0x198c10
00198be8: 25ce0058  addiu	t6,t6,88
00198bec: 8dcf0004  lw	t7,4(t6)
00198bf0: 11e5000b  beq	t7,a1,0x198c20
00198bf4: 01c0102d  move	v0,t6
00198bf8: 04a20004  bltzl	a1,0x198c0c
00198bfc: 01c0602d  move	t4,t6
00198c00: 05e30003  bgezl	t7,0x198c10
00198c04: 25ce0058  addiu	t6,t6,88
00198c08: 01c0602d  move	t4,t6
00198c0c: 25ce0058  addiu	t6,t6,88
00198c10: 01cd782a  slt	t7,t6,t5
00198c14: 55e0fff3  bnezl	t7,0x198be4
00198c18: 8dcf0000  lw	t7,0(t6)
00198c1c: 0180102d  move	v0,t4
00198c20: 03e00008  jr	ra
00198c24: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00198bd0(void)`

```c
int * FUN_00198bd0(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = (int *)0x0;
  piVar2 = &DAT_01c61b48;
  iVar3 = DAT_01c61b48;
  while( true ) {
    if (iVar3 == param_1) {
      if (piVar2[1] == param_2) {
        return piVar2;
      }
      if ((param_2 < 0) || (piVar2[1] < 0)) {
        piVar1 = piVar2;
      }
    }
    piVar2 = piVar2 + 0x16;
    if (0x1c620c7 < (int)piVar2) break;
    iVar3 = *piVar2;
  }
  return piVar1;
}
```

## Earlier attempts (newest first)

- 23 differing words, 96/88 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.cpp`)
