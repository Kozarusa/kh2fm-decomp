# Target packet 0010f9f0

- Range: `0010f9f0`..`0010fa24`, **52 bytes = 13 instructions**. This size is the acceptance size.
- Layout name: `FUN_0010f9f0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0010f9f0: 248f0c00  addiu	t7,a0,3072
0010f9f4: 11e50003  beq	t7,a1,0x10fa04
0010f9f8: 30c600ff  andi	a2,a2,0xff
0010f9fc: 78a80000  lq	t0,0(a1)
0010fa00: 7de80000  sq	t0,0(t7)
0010fa04: 10c00004  beqz	a2,0x10fa18
0010fa08: 8c8f0b7c  lw	t7,2940(a0)
0010fa0c: 35ef0080  ori	t7,t7,0x80
0010fa10: 03e00008  jr	ra
0010fa14: ac8f0b7c  sw	t7,2940(a0)
0010fa18: 240eff7f  li	t6,-129
0010fa1c: 1000fffc  b	0x10fa10
0010fa20: 01ee7824  and	t7,t7,t6
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0010f9f0(void)`

```c
void FUN_0010f9f0(int param_1,undefined4 *param_2,char param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if ((undefined4 *)(param_1 + 0xc00) != param_2) {
    uVar1 = param_2[1];
    uVar2 = param_2[2];
    uVar3 = param_2[3];
    *(undefined4 *)(param_1 + 0xc00) = *param_2;
    *(undefined4 *)(param_1 + 0xc04) = uVar1;
    *(undefined4 *)(param_1 + 0xc08) = uVar2;
    *(undefined4 *)(param_1 + 0xc0c) = uVar3;
  }
  if (param_3 == '\0') {
    uVar4 = *(uint *)(param_1 + 0xb7c) & 0xffffff7f;
  }
  else {
    uVar4 = *(uint *)(param_1 + 0xb7c) | 0x80;
  }
  *(uint *)(param_1 + 0xb7c) = uVar4;
  return;
}
```

## Earlier attempts (newest first)

- none found
