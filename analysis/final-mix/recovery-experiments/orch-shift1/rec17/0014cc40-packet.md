# Target packet 0014cc40

- Range: `0014cc40`..`0014ccb4`, **116 bytes = 29 instructions**. This size is the acceptance size.
- Layout name: `FUN_0014cc40`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001058e8` registry: `_Z10getSaveRamv`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_00232510.cpp`
- `0014ca80` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_twowordfresh_recovered_00149ec0.cpp`, `fm_scalar_extra_recovered_00.cpp`, `fm_scalar_recovered_00.cpp`, `fm_width_recovered_01.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0014cc40: 27bdffd0  addiu	sp,sp,-48
0014cc44: ffb00000  sd	s0,0(sp)
0014cc48: ffb10008  sd	s1,8(sp)
0014cc4c: ffb20010  sd	s2,16(sp)
0014cc50: 0100802d  move	s0,t0
0014cc54: ffb30018  sd	s3,24(sp)
0014cc58: 0080882d  move	s1,a0
0014cc5c: ffb40020  sd	s4,32(sp)
0014cc60: 00a0902d  move	s2,a1
0014cc64: ffbf0028  sd	ra,40(sp)
0014cc68: 00c0982d  move	s3,a2
0014cc6c: 00e0a02d  move	s4,a3
0014cc70: 0c04163a  jal	0x1058e8
0014cc74: 00108080  sll	s0,s0,0x2
0014cc78: 24422444  addiu	v0,v0,9284
0014cc7c: dfbf0028  ld	ra,40(sp)
0014cc80: 02028021  addu	s0,s0,v0
0014cc84: 0220282d  move	a1,s1
0014cc88: 8e040008  lw	a0,8(s0)
0014cc8c: 0240302d  move	a2,s2
0014cc90: 0260382d  move	a3,s3
0014cc94: dfb10008  ld	s1,8(sp)
0014cc98: 0280402d  move	t0,s4
0014cc9c: dfb00000  ld	s0,0(sp)
0014cca0: dfb20010  ld	s2,16(sp)
0014cca4: dfb30018  ld	s3,24(sp)
0014cca8: dfb40020  ld	s4,32(sp)
0014ccac: 080532a0  j	0x14ca80
0014ccb0: 27bd0030  addiu	sp,sp,48
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0014cc40(void)`

```c
void FUN_0014cc40(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 int param_5)

{
  int iVar1;
  
  iVar1 = FUN_001058e8();
  FUN_0014ca80(*(undefined4 *)(param_5 * 4 + iVar1 + 0x244c),param_1,param_2,param_3,param_4);
  return;
}
```

## Earlier attempts (newest first)

- none found
