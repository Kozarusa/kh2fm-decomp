# Target packet 002b3ae8

- Range: `002b3ae8`..`002b3b60`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_002b3ae8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001d9d48` registry: `func_001d9d48`
  - accepted sources that already call it (copy their declaration): `fm_primary_orchcv_recovered_001d9d48.cpp`
- `001d9e30` registry: `func_001d9e30`
  - accepted sources that already call it (copy their declaration): `fm_primary_orchcu_recovered_001d9e30.cpp`
- `00276c18` registry: `_ZN2Tz6Jiminy10isFullOpenEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`, `fm_primary_oneword_recovered_0023f8c8.cpp`, `fm_primary_oneword_recovered_00246968.cpp`, `fm_primary_oneword_recovered_00253538.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002b3ae8: 27bdffe0  addiu	sp,sp,-32
002b3aec: ffb00000  sd	s0,0(sp)
002b3af0: ffb10008  sd	s1,8(sp)
002b3af4: ffbf0010  sd	ra,16(sp)
002b3af8: 0000802d  move	s0,zero
002b3afc: 0000882d  move	s1,zero
002b3b00: 0c07678c  jal	0x1d9e30
002b3b04: 0200202d  move	a0,s0
002b3b08: 0040802d  move	s0,v0
002b3b0c: 1440000e  bnez	v0,0x2b3b48
002b3b10: 0040202d  move	a0,v0
002b3b14: 16200005  bnez	s1,0x2b3b2c
002b3b18: 0000802d  move	s0,zero
002b3b1c: 0c09db06  jal	0x276c18
002b3b20: 00000000  nop
002b3b24: 10400003  beqz	v0,0x2b3b34
002b3b28: 0200102d  move	v0,s0
002b3b2c: 24100001  li	s0,1
002b3b30: 0200102d  move	v0,s0
002b3b34: dfb10008  ld	s1,8(sp)
002b3b38: dfb00000  ld	s0,0(sp)
002b3b3c: dfbf0010  ld	ra,16(sp)
002b3b40: 03e00008  jr	ra
002b3b44: 27bd0020  addiu	sp,sp,32
002b3b48: 0c076752  jal	0x1d9d48
002b3b4c: 00000000  nop
002b3b50: 1040ffeb  beqz	v0,0x2b3b00
002b3b54: 00000000  nop
002b3b58: 1000ffee  b	0x2b3b14
002b3b5c: 24110001  li	s1,1
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002b3ae8(void)`

```c
undefined4 FUN_002b3ae8(void)

{
  bool bVar1;
  long lVar2;
  long lVar3;
  
  lVar3 = 0;
  bVar1 = false;
  do {
    lVar3 = FUN_001d9e30(lVar3);
    if (lVar3 == 0) goto LAB_002b3b14;
    lVar2 = FUN_001d9d48(lVar3);
  } while (lVar2 == 0);
  bVar1 = true;
LAB_002b3b14:
  if ((!bVar1) && (lVar3 = FUN_00276c18(), lVar3 == 0)) {
    return 0;
  }
  return 1;
}
```

## Earlier attempts (newest first)

- none found
