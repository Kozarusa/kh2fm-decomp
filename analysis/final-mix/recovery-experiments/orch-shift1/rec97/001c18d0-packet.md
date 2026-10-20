# Target packet 001c18d0

- Range: `001c18d0`..`001c1938`, **104 bytes = 26 instructions**. This size is the acceptance size.
- Layout name: `FUN_001c18d0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001c18d0: 27bdfff0  addiu	sp,sp,-16
001c18d4: ffb00000  sd	s0,0(sp)
001c18d8: ffbf0008  sd	ra,8(sp)
001c18dc: 8c820010  lw	v0,16(a0)
001c18e0: 0040f809  jalr	v0
001c18e4: 0080802d  move	s0,a0
001c18e8: 1040000e  beqz	v0,0x1c1924
001c18ec: 0000782d  move	t7,zero
001c18f0: 8e0e0020  lw	t6,32(s0)
001c18f4: 11c0000b  beqz	t6,0x1c1924
001c18f8: 240f0001  li	t7,1
001c18fc: 8e0f001c  lw	t7,28(s0)
001c1900: 8ded0004  lw	t5,4(t7)
001c1904: 51a00005  beqzl	t5,0x1c191c
001c1908: 91cf000f  lbu	t7,15(t6)
001c190c: 240f0001  li	t7,1
001c1910: 51af0002  beql	t5,t7,0x1c191c
001c1914: 91cf000d  lbu	t7,13(t6)
001c1918: 0000782d  move	t7,zero
001c191c: a20f0017  sb	t7,23(s0)
001c1920: 240f0001  li	t7,1
001c1924: dfb00000  ld	s0,0(sp)
001c1928: 01e0102d  move	v0,t7
001c192c: dfbf0008  ld	ra,8(sp)
001c1930: 03e00008  jr	ra
001c1934: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001c18d0(void)`

```c
undefined4 FUN_001c18d0(int param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  
  lVar3 = (**(code **)(param_1 + 0x10))();
  uVar5 = 0;
  if (lVar3 != 0) {
    iVar1 = *(int *)(param_1 + 0x20);
    uVar5 = 1;
    if (iVar1 != 0) {
      iVar2 = *(int *)(*(int *)(param_1 + 0x1c) + 4);
      if (iVar2 == 0) {
        uVar4 = *(undefined1 *)(iVar1 + 0xf);
      }
      else if (iVar2 == 1) {
        uVar4 = *(undefined1 *)(iVar1 + 0xd);
      }
      else {
        uVar4 = 0;
      }
      *(undefined1 *)(param_1 + 0x17) = uVar4;
      uVar5 = 1;
    }
  }
  return uVar5;
}
```

## Earlier attempts (newest first)

- none found
