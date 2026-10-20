# Target packet 00199cd0

- Range: `00199cd0`..`00199d34`, **100 bytes = 25 instructions**. This size is the acceptance size.
- Layout name: `FUN_00199cd0`
- Registry names for this address: `func_00199cd0`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00199cd0: 27bdffe0  addiu	sp,sp,-32
00199cd4: ffb10008  sd	s1,8(sp)
00199cd8: ffb00000  sd	s0,0(sp)
00199cdc: ffbf0010  sd	ra,16(sp)
00199ce0: 0080882d  move	s1,a0
00199ce4: 8c8f0004  lw	t7,4(a0)
00199ce8: 8c84000c  lw	a0,12(a0)
00199cec: 35ef0001  ori	t7,t7,0x1
00199cf0: 10800009  beqz	a0,0x199d18
00199cf4: ae2f0004  sw	t7,4(s1)
00199cf8: 10800005  beqz	a0,0x199d10
00199cfc: 8c900060  lw	s0,96(a0)
00199d00: 8c8e0000  lw	t6,0(a0)
00199d04: 8dcf0004  lw	t7,4(t6)
00199d08: 01e0f809  jalr	t7
00199d0c: 00000000  nop
00199d10: 1600fff9  bnez	s0,0x199cf8
00199d14: 0200202d  move	a0,s0
00199d18: ae20000c  sw	zero,12(s1)
00199d1c: ae200010  sw	zero,16(s1)
00199d20: dfb00000  ld	s0,0(sp)
00199d24: dfb10008  ld	s1,8(sp)
00199d28: dfbf0010  ld	ra,16(sp)
00199d2c: 03e00008  jr	ra
00199d30: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00199cd0(void)`

```c
void FUN_00199cd0(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 1;
  piVar1 = *(int **)(param_1 + 0xc);
  while (piVar2 = piVar1, piVar2 != (int *)0x0) {
    piVar1 = (int *)piVar2[0x18];
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 4))();
    }
  }
  *(undefined4 *)(param_1 + 0xc) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return;
}
```

## Earlier attempts (newest first)

- none found
