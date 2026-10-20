# Target packet 00287ed8

- Range: `00287ed8`..`00287f2c`, **84 bytes = 21 instructions**. This size is the acceptance size.
- Layout name: `FUN_00287ed8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001063c0` registry: `Tz::LoadDataAlloc(unsigned int, unsigned int)`
- `00167658` registry: `_Z16wtarget_00167658jjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_orchaw_recovered_00167f38.cpp`, `fm_primary_queueeta_recovered_00167658.cpp`, `fm_primary_twowordfresh_recovered_00149ec0.cpp`, `fm_scalar_extra_recovered_01.cpp`
- `00288018` registry: `func_00288018`
  - accepted sources that already call it (copy their declaration): `fm_primary_queuenu_recovered_00288018.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00287ed8: 27bdffe0  addiu	sp,sp,-32
00287edc: 0080282d  move	a1,a0
00287ee0: ffb10008  sd	s1,8(sp)
00287ee4: ffb00000  sd	s0,0(sp)
00287ee8: ffbf0010  sd	ra,16(sp)
00287eec: 3c110036  lui	s1,0x36
00287ef0: 8e2ff324  lw	t7,-3292(s1)   ; = D_0035f324
00287ef4: 15e00008  bnez	t7,0x287f18
00287ef8: 24040050  li	a0,80
00287efc: 0c0418f0  jal	0x1063c0
00287f00: 00000000  nop
00287f04: 0040802d  move	s0,v0
00287f08: 0040202d  move	a0,v0
00287f0c: 0c059d96  jal	0x167658
00287f10: 0000282d  move	a1,zero
00287f14: ae30f324  sw	s0,-3292(s1)   ; = D_0035f324
00287f18: dfb00000  ld	s0,0(sp)
00287f1c: dfb10008  ld	s1,8(sp)
00287f20: dfbf0010  ld	ra,16(sp)
00287f24: 080a2006  j	0x288018
00287f28: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00287ed8(void)`

```c
void FUN_00287ed8(undefined8 param_1)

{
  undefined8 uVar1;
  
  if (DAT_0035f324 == 0) {
    uVar1 = FUN_001063c0(0x50,param_1);
    FUN_00167658(uVar1,0);
    DAT_0035f324 = (int)uVar1;
  }
  FUN_00288018();
  return;
}
```

## Earlier attempts (newest first)

- none found
