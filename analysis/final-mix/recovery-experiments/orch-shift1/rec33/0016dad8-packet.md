# Target packet 0016dad8

- Range: `0016dad8`..`0016db20`, **72 bytes = 18 instructions**. This size is the acceptance size.
- Layout name: `FUN_0016dad8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0017d050` registry: none
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_loadorder_recovered.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0016dad8: 27bdffe0  addiu	sp,sp,-32
0016dadc: ffb00010  sd	s0,16(sp)
0016dae0: ffbf0018  sd	ra,24(sp)
0016dae4: 0080802d  move	s0,a0
0016dae8: 8c850000  lw	a1,0(a0)
0016daec: 0c05f414  jal	0x17d050
0016daf0: 03a0202d  move	a0,sp
0016daf4: 3c0f004f  lui	t7,0x4f
0016daf8: 25ef62a0  addiu	t7,t7,25248   ; = D_004f62a0
0016dafc: 53af0004  beql	sp,t7,0x16db10
0016db00: ae0f0000  sw	t7,0(s0)
0016db04: 7ba80000  lq	t0,0(sp)
0016db08: 7de80000  sq	t0,0(t7)
0016db0c: ae0f0000  sw	t7,0(s0)
0016db10: dfbf0018  ld	ra,24(sp)
0016db14: dfb00010  ld	s0,16(sp)
0016db18: 03e00008  jr	ra
0016db1c: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0016dad8(void)`

```c
void FUN_0016dad8(undefined4 *param_1)

{
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  FUN_0017d050(&uStack_20,*param_1);
  if ((undefined4 *)&stack0x00000000 == &DAT_004f62c0) {
    *param_1 = &DAT_004f62a0;
  }
  else {
    DAT_004f62a0 = uStack_20;
    DAT_004f62a4 = uStack_1c;
    DAT_004f62a8 = uStack_18;
    DAT_004f62ac = uStack_14;
    *param_1 = &DAT_004f62a0;
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
