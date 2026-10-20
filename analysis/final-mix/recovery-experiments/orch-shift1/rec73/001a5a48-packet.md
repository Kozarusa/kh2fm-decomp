# Target packet 001a5a48

- Range: `001a5a48`..`001a5ac4`, **124 bytes = 31 instructions**. This size is the acceptance size.
- Layout name: `FUN_001a5a48`
- Registry names for this address: `_Z17ctarget0_001a5a48v`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001a53d0` registry: `func_001a53d0`
  - accepted sources that already call it (copy their declaration): `fm_scalar_recovered_03.cpp`
- `001c16f0` registry: `_ZN2YS10MASSEFFECT7MANAGER4eachEPS0_`
  - accepted sources that already call it (copy their declaration): `fm_primary_resume_recovered_00.cpp`, `fm_primary_width_recovered_00.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001a5a48: 27bdffe0  addiu	sp,sp,-32
001a5a4c: ffb00000  sd	s0,0(sp)
001a5a50: ffb10008  sd	s1,8(sp)
001a5a54: ffb20010  sd	s2,16(sp)
001a5a58: 0000802d  move	s0,zero
001a5a5c: ffbf0018  sd	ra,24(sp)
001a5a60: 3c110035  lui	s1,0x35
001a5a64: 3c120035  lui	s2,0x35
001a5a68: 8e2f0790  lw	t7,1936(s1)   ; = D_00350790
001a5a6c: 0200282d  move	a1,s0
001a5a70: 0c0705bc  jal	0x1c16f0
001a5a74: 8de409f4  lw	a0,2548(t7)
001a5a78: 0040302d  move	a2,v0
001a5a7c: 14400008  bnez	v0,0x1a5aa0
001a5a80: 0040802d  move	s0,v0
001a5a84: dfb00000  ld	s0,0(sp)
001a5a88: dfb10008  ld	s1,8(sp)
001a5a8c: dfb20010  ld	s2,16(sp)
001a5a90: dfbf0018  ld	ra,24(sp)
001a5a94: 03e00008  jr	ra
001a5a98: 27bd0020  addiu	sp,sp,32
001a5a9c: 00000000  nop
001a5aa0: 8c4f0028  lw	t7,40(v0)
001a5aa4: 31ef0001  andi	t7,t7,0x1
001a5aa8: 51e0fff0  beqzl	t7,0x1a5a6c
001a5aac: 8e2f0790  lw	t7,1936(s1)
001a5ab0: 8e45e948  lw	a1,-5816(s2)
001a5ab4: 0c0694f4  jal	0x1a53d0
001a5ab8: 8e240790  lw	a0,1936(s1)
001a5abc: 1000ffeb  b	0x1a5a6c
001a5ac0: 8e2f0790  lw	t7,1936(s1)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001a5a48(void)`

```c
void FUN_001a5a48(void)

{
  long lVar1;
  
  lVar1 = 0;
  while( true ) {
    lVar1 = FUN_001c16f0(*(undefined4 *)(DAT_00350790 + 0x9f4),lVar1);
    if (lVar1 == 0) break;
    if ((*(uint *)((int)lVar1 + 0x28) & 1) != 0) {
      FUN_001a53d0(DAT_00350790,DAT_0034e948,lVar1);
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
