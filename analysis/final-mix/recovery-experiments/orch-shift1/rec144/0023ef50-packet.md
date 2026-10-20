# Target packet 0023ef50

- Range: `0023ef50`..`0023efb4`, **100 bytes = 25 instructions**. This size is the acceptance size.
- Layout name: `FUN_0023ef50`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00236ca8` registry: `_ZN2YI12IMAGE_FREEZE8GetImageEi`
  - accepted sources that already call it (copy their declaration): `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`, `fm_primary_oneword_recovered_0023f8c8.cpp`, `fm_primary_oneword_recovered_00246968.cpp`, `fm_primary_oneword_recovered_00253538.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0023ef50: 27bdffd0  addiu	sp,sp,-48
0023ef54: ffb00000  sd	s0,0(sp)
0023ef58: ffb10008  sd	s1,8(sp)
0023ef5c: ffb20010  sd	s2,16(sp)
0023ef60: ffb30018  sd	s3,24(sp)
0023ef64: ffbf0020  sd	ra,32(sp)
0023ef68: 8c910028  lw	s1,40(a0)
0023ef6c: 1a20000a  blez	s1,0x23ef98
0023ef70: 0000802d  move	s0,zero
0023ef74: 24920030  addiu	s2,a0,48
0023ef78: 24130001  li	s3,1
0023ef7c: 8e440028  lw	a0,40(s2)
0023ef80: 0200282d  move	a1,s0
0023ef84: 0c08db2a  jal	0x236ca8
0023ef88: 26100001  addiu	s0,s0,1
0023ef8c: 0211782a  slt	t7,s0,s1
0023ef90: 15e0fffa  bnez	t7,0x23ef7c
0023ef94: a0530190  sb	s3,400(v0)
0023ef98: dfb00000  ld	s0,0(sp)
0023ef9c: dfb10008  ld	s1,8(sp)
0023efa0: dfb20010  ld	s2,16(sp)
0023efa4: dfb30018  ld	s3,24(sp)
0023efa8: dfbf0020  ld	ra,32(sp)
0023efac: 03e00008  jr	ra
0023efb0: 27bd0030  addiu	sp,sp,48
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0023ef50(void)`

```c
void FUN_0023ef50(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x28);
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      iVar3 = iVar2 + 1;
      iVar2 = FUN_00236ca8(*(undefined4 *)(param_1 + 0x58),iVar2);
      *(undefined1 *)(iVar2 + 400) = 1;
      iVar2 = iVar3;
    } while (iVar3 < iVar1);
  }
  return;
}
```

## Earlier attempts (newest first)

- 23 differing words, 104/100 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_09_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_09_0.cpp`)
