# Target packet 0019ac80

- Range: `0019ac80`..`0019acfc`, **124 bytes = 31 instructions**. This size is the acceptance size.
- Layout name: `FUN_0019ac80`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0019ad00` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_floatarguments_recovered_0018f9b8.cpp`, `fm_primary_fourwordfresh_recovered_00195558.cpp`, `fm_primary_fourwordfresh_recovered_00197390.cpp`, `fm_primary_sixword_recovered_0018f2a8.cpp`, `fm_primary_sixword_recovered_0018f2d0.cpp`
- `0019ad58` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_floatarguments_recovered_0018f9b8.cpp`, `fm_primary_fourwordfresh_recovered_00195558.cpp`, `fm_primary_fourwordfresh_recovered_00197390.cpp`, `fm_primary_sixword_recovered_0018f2a8.cpp`, `fm_primary_sixword_recovered_0018f2d0.cpp`
- `0019ae60` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_floatarguments_recovered_0018f9b8.cpp`, `fm_primary_fourwordfresh_recovered_00195558.cpp`, `fm_primary_fourwordfresh_recovered_00197390.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0019ac80: 27bdfff0  addiu	sp,sp,-16
0019ac84: 0000682d  move	t5,zero
0019ac88: ffb00000  sd	s0,0(sp)
0019ac8c: ffbf0008  sd	ra,8(sp)
0019ac90: 908f0020  lbu	t7,32(a0)
0019ac94: 2def00c8  sltiu	t7,t7,200
0019ac98: 11e00013  beqz	t7,0x19ace8
0019ac9c: 0080802d  move	s0,a0
0019aca0: 0c066b56  jal	0x19ad58
0019aca4: 00000000  nop
0019aca8: 8e0e0008  lw	t6,8(s0)
0019acac: 91cf0022  lbu	t7,34(t6)
0019acb0: 01e2782a  slt	t7,t7,v0
0019acb4: 15e0000c  bnez	t7,0x19ace8
0019acb8: 0000682d  move	t5,zero
0019acbc: 0c066b98  jal	0x19ae60
0019acc0: 0200202d  move	a0,s0
0019acc4: 92050020  lbu	a1,32(s0)
0019acc8: 0c066b40  jal	0x19ad00
0019accc: 0200202d  move	a0,s0
0019acd0: 14400005  bnez	v0,0x19ace8
0019acd4: 240d0001  li	t5,1
0019acd8: 920f0020  lbu	t7,32(s0)
0019acdc: 2def00c8  sltiu	t7,t7,200
0019ace0: 15e0fff6  bnez	t7,0x19acbc
0019ace4: 0000682d  move	t5,zero
0019ace8: dfb00000  ld	s0,0(sp)
0019acec: 01a0102d  move	v0,t5
0019acf0: dfbf0008  ld	ra,8(sp)
0019acf4: 03e00008  jr	ra
0019acf8: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0019ac80(void)`

```c
undefined4 FUN_0019ac80(undefined8 param_1)

{
  long lVar1;
  int iVar2;
  
  iVar2 = (int)param_1;
  if ((*(byte *)(iVar2 + 0x20) < 200) &&
     (lVar1 = FUN_0019ad58(), lVar1 <= (long)(ulong)*(byte *)(*(int *)(iVar2 + 8) + 0x22))) {
    do {
      FUN_0019ae60(param_1);
      lVar1 = FUN_0019ad00(param_1,*(undefined1 *)(iVar2 + 0x20));
      if (lVar1 != 0) {
        return 1;
      }
    } while (*(byte *)(iVar2 + 0x20) < 200);
  }
  return 0;
}
```

## Earlier attempts (newest first)

- 26 differing words, 124/124 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_04_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_04_0.cpp`)
