# Target packet 001c9c00

- Range: `001c9c00`..`001c9c78`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_001c9c00`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001c9d88` registry: `_ZN2YS9SACRIFICE6CanEndEv`
  - accepted sources that already call it (copy their declaration): `fm_width_recovered_09.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001c9c00: 27bdffe0  addiu	sp,sp,-32
001c9c04: 3c0e0035  lui	t6,0x35
001c9c08: ffb10008  sd	s1,8(sp)
001c9c0c: ffb00000  sd	s0,0(sp)
001c9c10: ffb20010  sd	s2,16(sp)
001c9c14: ffbf0018  sd	ra,24(sp)
001c9c18: 8dcf1f30  lw	t7,7984(t6)   ; = D_00351f30
001c9c1c: 19e0000e  blez	t7,0x1c9c58
001c9c20: 0000882d  move	s1,zero
001c9c24: 3c0f01d5  lui	t7,0x1d5
001c9c28: 01c0902d  move	s2,t6
001c9c2c: 25f09980  addiu	s0,t7,-26240   ; = D_01d49980
001c9c30: 0c072762  jal	0x1c9d88
001c9c34: 8e040000  lw	a0,0(s0)
001c9c38: 26100004  addiu	s0,s0,4
001c9c3c: 10400007  beqz	v0,0x1c9c5c
001c9c40: 0000782d  move	t7,zero
001c9c44: 8e4f1f30  lw	t7,7984(s2)
001c9c48: 26310001  addiu	s1,s1,1
001c9c4c: 022f782a  slt	t7,s1,t7
001c9c50: 15e0fff7  bnez	t7,0x1c9c30
001c9c54: 00000000  nop
001c9c58: 240f0001  li	t7,1
001c9c5c: dfb00000  ld	s0,0(sp)
001c9c60: 01e0102d  move	v0,t7
001c9c64: dfb10008  ld	s1,8(sp)
001c9c68: dfb20010  ld	s2,16(sp)
001c9c6c: dfbf0018  ld	ra,24(sp)
001c9c70: 03e00008  jr	ra
001c9c74: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001c9c00(void)`

```c
undefined4 FUN_001c9c00(void)

{
  long lVar1;
  undefined4 *puVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < DAT_00351f30) {
    puVar2 = &DAT_01d49980;
    do {
      lVar1 = FUN_001c9d88(*puVar2);
      puVar2 = puVar2 + 1;
      if (lVar1 == 0) {
        return 0;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_00351f30);
  }
  return 1;
}
```

## Earlier attempts (newest first)

- none found
