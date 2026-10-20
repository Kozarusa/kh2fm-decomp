# Target packet 0019ad00

- Range: `0019ad00`..`0019ad58`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_0019ad00`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0019ad00: 8c8e0008  lw	t6,8(a0)
0019ad04: 0000602d  move	t4,zero
0019ad08: 95cf0004  lhu	t7,4(t6)
0019ad0c: 11e0000f  beqz	t7,0x19ad4c
0019ad10: 01c0582d  move	t3,t6
0019ad14: 240a0002  li	t2,2
0019ad18: 000c7980  sll	t7,t4,0x6
0019ad1c: 01ee6821  addu	t5,t7,t6
0019ad20: 258c0001  addiu	t4,t4,1
0019ad24: 91af0048  lbu	t7,72(t5)
0019ad28: 15ea0004  bne	t7,t2,0x19ad3c
0019ad2c: 0160702d  move	t6,t3
0019ad30: 91af005c  lbu	t7,92(t5)
0019ad34: 11e50006  beq	t7,a1,0x19ad50
0019ad38: 24020001  li	v0,1
0019ad3c: 95cf0004  lhu	t7,4(t6)
0019ad40: 018f782a  slt	t7,t4,t7
0019ad44: 15e0fff5  bnez	t7,0x19ad1c
0019ad48: 000c7980  sll	t7,t4,0x6
0019ad4c: 0000102d  move	v0,zero
0019ad50: 03e00008  jr	ra
0019ad54: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0019ad00(void)`

```c
undefined4 FUN_0019ad00(int param_1,ulong param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 8);
  iVar2 = 0;
  if (*(short *)(iVar1 + 4) != 0) {
    iVar3 = 0;
    do {
      iVar2 = iVar2 + 1;
      if ((*(char *)(iVar3 + iVar1 + 0x48) == '\x02') &&
         (*(byte *)(iVar3 + iVar1 + 0x5c) == param_2)) {
        return 1;
      }
      iVar3 = iVar2 * 0x40;
    } while (iVar2 < (int)(uint)*(ushort *)(iVar1 + 4));
  }
  return 0;
}
```

## Earlier attempts (newest first)

- 23 differing words, 92/88 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_primary_width_00_all.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_primary_width_00_all.cpp`)
