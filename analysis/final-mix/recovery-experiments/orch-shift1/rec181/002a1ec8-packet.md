# Target packet 002a1ec8

- Range: `002a1ec8`..`002a1f40`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_002a1ec8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002766d0` registry: `_ZN2Tz6Jiminy9GetSeqTblEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_oneword_recovered_00293b70.cpp`, `fm_primary_queuekappaprime_recovered_0029e258.cpp`, `fm_primary_queuekappaprime_recovered_0029e3a0.cpp`, `fm_primary_resume_recovered_01.cpp`
- `0028dac8` registry: `Tz::Select::FadeOut(...)`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_002908f0.cpp`, `fm_primary_oneword_recovered_00293b70.cpp`, `fm_primary_orcheb_recovered_00252618.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002a1ec8: 27bdffe0  addiu	sp,sp,-32
002a1ecc: ffb00000  sd	s0,0(sp)
002a1ed0: ffb10008  sd	s1,8(sp)
002a1ed4: ffb20010  sd	s2,16(sp)
002a1ed8: ffbf0018  sd	ra,24(sp)
002a1edc: 0c09d9b4  jal	0x2766d0
002a1ee0: 2411001f  li	s1,31
002a1ee4: 3c0f0036  lui	t7,0x36
002a1ee8: 24504398  addiu	s0,v0,17304
002a1eec: 8dedf5d4  lw	t5,-2604(t7)   ; = D_0035f5d4
002a1ef0: 81ae0002  lb	t6,2(t5)
002a1ef4: 3c0f0037  lui	t7,0x37
002a1ef8: 25ef4b60  addiu	t7,t7,19296   ; = D_00374b60
002a1efc: 39ce0010  xori	t6,t6,0x10
002a1f00: 240d0006  li	t5,6
002a1f04: 000e680b  movn	t5,zero,t6
002a1f08: 01af9021  addu	s2,t5,t7
002a1f0c: 0200202d  move	a0,s0
002a1f10: 86450002  lh	a1,2(s2)
002a1f14: 2631ffff  addiu	s1,s1,-1
002a1f18: 0c0a36b2  jal	0x28dac8
002a1f1c: 26100198  addiu	s0,s0,408
002a1f20: 0621fffb  bgez	s1,0x2a1f10
002a1f24: 0200202d  move	a0,s0
002a1f28: dfb00000  ld	s0,0(sp)
002a1f2c: dfb10008  ld	s1,8(sp)
002a1f30: dfb20010  ld	s2,16(sp)
002a1f34: dfbf0018  ld	ra,24(sp)
002a1f38: 03e00008  jr	ra
002a1f3c: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002a1ec8(void)`

```c
void FUN_002a1ec8(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0x1f;
  iVar1 = FUN_002766d0();
  iVar1 = iVar1 + 0x4398;
  iVar2 = 6;
  if (*(char *)(DAT_0035f5d4 + 2) != '\x10') {
    iVar2 = 0;
  }
  do {
    iVar3 = iVar3 + -1;
    FUN_0028dac8(iVar1,*(undefined2 *)(iVar2 + 0x374b62));
    iVar1 = iVar1 + 0x198;
  } while (-1 < iVar3);
  return;
}
```

## Earlier attempts (newest first)

- none found
