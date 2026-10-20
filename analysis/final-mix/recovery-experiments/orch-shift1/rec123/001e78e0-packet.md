# Target packet 001e78e0

- Range: `001e78e0`..`001e7948`, **104 bytes = 26 instructions**. This size is the acceptance size.
- Layout name: `FUN_001e78e0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001e78e0: 27bdffe0  addiu	sp,sp,-32
001e78e4: ffb00000  sd	s0,0(sp)
001e78e8: ffb10008  sd	s1,8(sp)
001e78ec: ffbf0010  sd	ra,16(sp)
001e78f0: 0000802d  move	s0,zero
001e78f4: 8c8c0064  lw	t4,100(a0)
001e78f8: 1980000e  blez	t4,0x1e7934
001e78fc: 0080882d  move	s1,a0
001e7900: 8e2f0078  lw	t7,120(s1)
001e7904: 00107080  sll	t6,s0,0x2
001e7908: 01cf7021  addu	t6,t6,t7
001e790c: 8dcd0000  lw	t5,0(t6)
001e7910: 8daf0018  lw	t7,24(t5)
001e7914: 11e00004  beqz	t7,0x1e7928
001e7918: 26100001  addiu	s0,s0,1
001e791c: 01e0f809  jalr	t7
001e7920: 0220202d  move	a0,s1
001e7924: 8e2c0064  lw	t4,100(s1)
001e7928: 020c782a  slt	t7,s0,t4
001e792c: 55e0fff5  bnezl	t7,0x1e7904
001e7930: 8e2f0078  lw	t7,120(s1)
001e7934: dfb00000  ld	s0,0(sp)
001e7938: dfb10008  ld	s1,8(sp)
001e793c: dfbf0010  ld	ra,16(sp)
001e7940: 03e00008  jr	ra
001e7944: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001e78e0(void)`

```c
void FUN_001e78e0(undefined8 param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  iVar2 = (int)param_1;
  iVar3 = *(int *)(iVar2 + 100);
  if (0 < iVar3) {
    iVar4 = *(int *)(iVar2 + 0x78);
    while( true ) {
      pcVar1 = *(code **)(*(int *)(iVar5 * 4 + iVar4) + 0x18);
      iVar5 = iVar5 + 1;
      if (pcVar1 != (code *)0x0) {
        (*pcVar1)(param_1);
        iVar3 = *(int *)(iVar2 + 100);
      }
      if (iVar3 <= iVar5) break;
      iVar4 = *(int *)(iVar2 + 0x78);
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
