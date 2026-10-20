# Target packet 0021f5d8

- Range: `0021f5d8`..`0021f620`, **72 bytes = 18 instructions**. This size is the acceptance size.
- Layout name: `FUN_0021f5d8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002f4000` registry: `func_002f4000`
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_orchdf_recovered_001eb0c8.cpp`, `fm_primary_orchdf_recovered_001eb140.cpp`, `fm_primary_orchdf_recovered_001eb1b0.cpp`, `fm_primary_orchdf_recovered_001eb228.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0021f5d8: 27bdfff0  addiu	sp,sp,-16
0021f5dc: 3c0f01da  lui	t7,0x1da
0021f5e0: ffb00000  sd	s0,0(sp)
0021f5e4: ffbf0008  sd	ra,8(sp)
0021f5e8: 0080802d  move	s0,a0
0021f5ec: 8deee6e0  lw	t6,-6432(t7)   ; = D_01d9e6e0
0021f5f0: 24840040  addiu	a0,a0,64
0021f5f4: 240f0002  li	t7,2
0021f5f8: 0c0bd000  jal	0x2f4000
0021f5fc: a1cf00a8  sb	t7,168(t6)
0021f600: 3c0f0037  lui	t7,0x37
0021f604: dfbf0008  ld	ra,8(sp)
0021f608: 25ef0b6c  addiu	t7,t7,2924   ; = D_00370b6c
0021f60c: c5e00000  lwc1	$f0,0(t7)
0021f610: e60000ac  swc1	$f0,172(s0)
0021f614: dfb00000  ld	s0,0(sp)
0021f618: 03e00008  jr	ra
0021f61c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0021f5d8(void)`

```c
void FUN_0021f5d8(int param_1)

{
  *(undefined1 *)(DAT_01d9e6e0 + 0xa8) = 2;
  FUN_002f4000(param_1 + 0x40);
  *(undefined4 *)(param_1 + 0xac) = DAT_00370b6c;
  return;
}
```

## Earlier attempts (newest first)

- none found
