# Target packet 0018a1b8

- Range: `0018a1b8`..`0018a218`, **96 bytes = 24 instructions**. This size is the acceptance size.
- Layout name: `FUN_0018a1b8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0018a1b8: 8c8e0000  lw	t6,0(a0)
0018a1bc: 240f0014  li	t7,20
0018a1c0: 248c0040  addiu	t4,a0,64
0018a1c4: 24cd0014  addiu	t5,a2,20
0018a1c8: 01cf7018  mult	t6,t6,t7
0018a1cc: 01a6600b  movn	t4,t5,a2
0018a1d0: 008e2021  addu	a0,a0,t6
0018a1d4: 24840040  addiu	a0,a0,64
0018a1d8: 0184782b  sltu	t7,t4,a0
0018a1dc: 11e0000b  beqz	t7,0x18a20c
0018a1e0: 0180302d  move	a2,t4
0018a1e4: 240d0001  li	t5,1
0018a1e8: 90cf0004  lbu	t7,4(a2)
0018a1ec: 00c0102d  move	v0,a2
0018a1f0: 24c60014  addiu	a2,a2,20
0018a1f4: 01ed7804  sllv	t7,t5,t7
0018a1f8: 00af7824  and	t7,a1,t7
0018a1fc: 15e00004  bnez	t7,0x18a210
0018a200: 00c4702b  sltu	t6,a2,a0
0018a204: 55c0fff9  bnezl	t6,0x18a1ec
0018a208: 90cf0004  lbu	t7,4(a2)
0018a20c: 0000102d  move	v0,zero
0018a210: 03e00008  jr	ra
0018a214: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0018a1b8(void)`

```c
int * FUN_0018a1b8(int *param_1,uint param_2,long param_3)

{
  byte bVar1;
  int *piVar2;
  
  piVar2 = param_1 + 0x10;
  if (param_3 != 0) {
    piVar2 = (int *)((int)param_3 + 0x14);
  }
  if (piVar2 < param_1 + *param_1 * 5 + 0x10) {
    bVar1 = *(byte *)(piVar2 + 1);
    while( true ) {
      if ((param_2 & 1 << (bVar1 & 0x1f)) != 0) break;
      if (param_1 + *param_1 * 5 + 0x10 <= piVar2 + 5) goto LAB_0018a20c;
      bVar1 = *(byte *)(piVar2 + 6);
      piVar2 = piVar2 + 5;
    }
  }
  else {
LAB_0018a20c:
    piVar2 = (int *)0x0;
  }
  return piVar2;
}
```

## Earlier attempts (newest first)

- none found
