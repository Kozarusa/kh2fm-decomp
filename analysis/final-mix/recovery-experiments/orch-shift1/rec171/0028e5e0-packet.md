# Target packet 0028e5e0

- Range: `0028e5e0`..`0028e650`, **112 bytes = 28 instructions**. This size is the acceptance size.
- Layout name: `FUN_0028e5e0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00139d78` registry: `_Z16u_call4_00139d78jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_close_recovered.cpp`
- `0028e510` registry: `func_0028e510`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_002908f0.cpp`, `fm_primary_threeword_recovered_0026dcb8.cpp`, `fm_primary_threeword_recovered_0028e710.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0028e5e0: 27bdffd0  addiu	sp,sp,-48
0028e5e4: ffb00000  sd	s0,0(sp)
0028e5e8: ffb10008  sd	s1,8(sp)
0028e5ec: ffb20010  sd	s2,16(sp)
0028e5f0: 00a0802d  move	s0,a1
0028e5f4: ffb30018  sd	s3,24(sp)
0028e5f8: 0000882d  move	s1,zero
0028e5fc: ffbf0020  sd	ra,32(sp)
0028e600: 00c0902d  move	s2,a2
0028e604: 0c04e75e  jal	0x139d78
0028e608: 0080982d  move	s3,a0
0028e60c: 5a40000a  blezl	s2,0x28e638
0028e610: dfb00000  ld	s0,0(sp)
0028e614: 86060000  lh	a2,0(s0)
0028e618: 0220282d  move	a1,s1
0028e61c: 0260202d  move	a0,s3
0028e620: 0c0a3944  jal	0x28e510
0028e624: 26310001  addiu	s1,s1,1
0028e628: 0232782a  slt	t7,s1,s2
0028e62c: 15e0fff9  bnez	t7,0x28e614
0028e630: 26100002  addiu	s0,s0,2
0028e634: dfb00000  ld	s0,0(sp)
0028e638: dfb10008  ld	s1,8(sp)
0028e63c: dfb20010  ld	s2,16(sp)
0028e640: dfb30018  ld	s3,24(sp)
0028e644: dfbf0020  ld	ra,32(sp)
0028e648: 03e00008  jr	ra
0028e64c: 27bd0030  addiu	sp,sp,48
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0028e5e0(void)`

```c
void FUN_0028e5e0(undefined8 param_1,undefined2 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  FUN_00139d78();
  iVar1 = 0;
  if (0 < param_3) {
    do {
      iVar2 = iVar1 + 1;
      FUN_0028e510(param_1,iVar1,*param_2);
      param_2 = param_2 + 1;
      iVar1 = iVar2;
    } while (iVar2 < param_3);
  }
  return;
}
```

## Earlier attempts (newest first)

- 13 differing words, 112/112 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_10_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_10_0.cpp`)
