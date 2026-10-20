# Target packet 002a00f0

- Range: `002a00f0`..`002a0168`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_002a00f0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002943e8` registry: `_ZN2Tz6JmInfo11isHaveAnsemEPKNS_15JmAnsemDataInfoE`
- `002a01c8` registry: `func_002a01c8`
  - accepted sources that already call it (copy their declaration): `fm_primary_threeword_recovered_002a01c8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002a00f0: 27bdffe0  addiu	sp,sp,-32
002a00f4: ffb20010  sd	s2,16(sp)
002a00f8: ffb00000  sd	s0,0(sp)
002a00fc: 3c120036  lui	s2,0x36
002a0100: ffb10008  sd	s1,8(sp)
002a0104: ffbf0018  sd	ra,24(sp)
002a0108: 0000802d  move	s0,zero
002a010c: 8e4df5d0  lw	t5,-2608(s2)   ; = D_0035f5d0
002a0110: 81af0000  lb	t7,0(t5)
002a0114: 19e0000d  blez	t7,0x2a014c
002a0118: 0000882d  move	s1,zero
002a011c: 01b07821  addu	t7,t5,s0
002a0120: 81e40006  lb	a0,6(t7)
002a0124: 0c0a8072  jal	0x2a01c8
002a0128: 26100001  addiu	s0,s0,1
002a012c: 0c0a50fa  jal	0x2943e8
002a0130: 0040202d  move	a0,v0
002a0134: 8e4df5d0  lw	t5,-2608(s2)   ; = D_0035f5d0
002a0138: 262e0001  addiu	t6,s1,1
002a013c: 81af0000  lb	t7,0(t5)
002a0140: 020f782a  slt	t7,s0,t7
002a0144: 15e0fff5  bnez	t7,0x2a011c
002a0148: 01c2880b  movn	s1,t6,v0
002a014c: 0220102d  move	v0,s1
002a0150: dfb00000  ld	s0,0(sp)
002a0154: dfb10008  ld	s1,8(sp)
002a0158: dfb20010  ld	s2,16(sp)
002a015c: dfbf0018  ld	ra,24(sp)
002a0160: 03e00008  jr	ra
002a0164: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002a00f0(void)`

```c
int FUN_002a00f0(void)

{
  undefined8 uVar1;
  long lVar2;
  int iVar3;
  long lVar4;
  int iVar5;
  
  lVar4 = 0;
  iVar5 = 0;
  if ('\0' < *DAT_0035f5d0) {
    do {
      iVar3 = (int)lVar4;
      lVar4 = (long)(iVar3 + 1);
      uVar1 = FUN_002a01c8(DAT_0035f5d0[iVar3 + 6]);
      lVar2 = FUN_002943e8(uVar1);
      if (lVar2 != 0) {
        iVar5 = iVar5 + 1;
      }
    } while (lVar4 < *DAT_0035f5d0);
  }
  return iVar5;
}
```

## Earlier attempts (newest first)

- none found
