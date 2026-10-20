# Target packet 0019ae60

- Range: `0019ae60`..`0019aebc`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_0019ae60`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0019aec0` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0019ae60: 27bdfff0  addiu	sp,sp,-16
0019ae64: ffbf0000  sd	ra,0(sp)
0019ae68: 908f0020  lbu	t7,32(a0)
0019ae6c: 25ed0001  addiu	t5,t7,1
0019ae70: 31ef00ff  andi	t7,t7,0xff
0019ae74: 2def00c8  sltiu	t7,t7,200
0019ae78: 51e0000e  beqzl	t7,0x19aeb4
0019ae7c: dfbf0000  ld	ra,0(sp)
0019ae80: a08d0020  sb	t5,32(a0)
0019ae84: 8c8c0008  lw	t4,8(a0)
0019ae88: 918e0023  lbu	t6,35(t4)
0019ae8c: 11c00008  beqz	t6,0x19aeb0
0019ae90: 31af00ff  andi	t7,t5,0xff
0019ae94: 01ee782b  sltu	t7,t7,t6
0019ae98: 15e00006  bnez	t7,0x19aeb4
0019ae9c: dfbf0000  ld	ra,0(sp)
0019aea0: 91850024  lbu	a1,36(t4)
0019aea4: 08066bb0  j	0x19aec0
0019aea8: 27bd0010  addiu	sp,sp,16
0019aeac: 00000000  nop
0019aeb0: dfbf0000  ld	ra,0(sp)
0019aeb4: 03e00008  jr	ra
0019aeb8: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0019ae60(void)`

```c
void FUN_0019ae60(int param_1)

{
  byte bVar1;
  byte bVar2;
  
  bVar2 = *(byte *)(param_1 + 0x20) + 1;
  if (*(byte *)(param_1 + 0x20) < 200) {
    *(byte *)(param_1 + 0x20) = bVar2;
    bVar1 = *(byte *)(*(int *)(param_1 + 8) + 0x23);
    if ((bVar1 != 0) && (bVar1 <= bVar2)) {
      FUN_0019aec0(param_1,*(undefined1 *)(*(int *)(param_1 + 8) + 0x24));
      return;
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
