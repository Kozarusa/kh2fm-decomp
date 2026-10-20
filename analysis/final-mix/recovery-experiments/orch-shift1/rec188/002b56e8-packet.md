# Target packet 002b56e8

- Range: `002b56e8`..`002b5764`, **124 bytes = 31 instructions**. This size is the acceptance size.
- Layout name: `FUN_002b56e8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00139d78` registry: `_Z16u_call4_00139d78jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_close_recovered.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002b56e8: 27bdffe0  addiu	sp,sp,-32
002b56ec: 3c0f0036  lui	t7,0x36
002b56f0: ffb00000  sd	s0,0(sp)
002b56f4: ffb10008  sd	s1,8(sp)
002b56f8: ffb20010  sd	s2,16(sp)
002b56fc: 0000802d  move	s0,zero
002b5700: ffbf0018  sd	ra,24(sp)
002b5704: 25f1f680  addiu	s1,t7,-2432   ; = D_0035f680
002b5708: 0000902d  move	s2,zero
002b570c: 8e2f0000  lw	t7,0(s1)
002b5710: 26310004  addiu	s1,s1,4
002b5714: 11e0000d  beqz	t7,0x2b574c
002b5718: 01e0202d  move	a0,t7
002b571c: 0c04e75e  jal	0x139d78
002b5720: 00000000  nop
002b5724: 1040000a  beqz	v0,0x2b5750
002b5728: 26100001  addiu	s0,s0,1
002b572c: 24120001  li	s2,1
002b5730: 0240102d  move	v0,s2
002b5734: dfb00000  ld	s0,0(sp)
002b5738: dfb10008  ld	s1,8(sp)
002b573c: dfb20010  ld	s2,16(sp)
002b5740: dfbf0018  ld	ra,24(sp)
002b5744: 03e00008  jr	ra
002b5748: 27bd0020  addiu	sp,sp,32
002b574c: 26100001  addiu	s0,s0,1
002b5750: 2a0f0004  slti	t7,s0,4
002b5754: 55e0ffee  bnezl	t7,0x2b5710
002b5758: 8e2f0000  lw	t7,0(s1)
002b575c: 1000fff5  b	0x2b5734
002b5760: 0240102d  move	v0,s2
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002b56e8(void)`

```c
undefined4 FUN_002b56e8(void)

{
  int iVar1;
  long lVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = 0;
  piVar4 = &DAT_0035f680;
  iVar1 = DAT_0035f680;
  while ((piVar4 = piVar4 + 1, iVar1 == 0 || (lVar2 = FUN_00139d78(iVar1), lVar2 == 0))) {
    iVar3 = iVar3 + 1;
    if (3 < iVar3) {
      return 0;
    }
    iVar1 = *piVar4;
  }
  return 1;
}
```

## Earlier attempts (newest first)

- none found
