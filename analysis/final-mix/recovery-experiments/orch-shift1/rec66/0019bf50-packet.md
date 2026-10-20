# Target packet 0019bf50

- Range: `0019bf50`..`0019bfd0`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_0019bf50`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00143928` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_oneword_recovered_001ac1d0.cpp`, `fm_primary_threewordnext_recovered_0019e6e8.cpp`, `fm_primary_twoword_recovered_001a6c38.cpp`
- `00185118` registry: `_ZN2YS3OBJ20prepare_bg_collisionEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_oneword_recovered_001ac1d0.cpp`, `fm_primary_threewordnext_recovered_0019e6e8.cpp`, `fm_primary_twoword_recovered_001a6c38.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0019bf50: 27bdffe0  addiu	sp,sp,-32
0019bf54: ffb00000  sd	s0,0(sp)
0019bf58: ffb10008  sd	s1,8(sp)
0019bf5c: ffbf0010  sd	ra,16(sp)
0019bf60: 0080802d  move	s0,a0
0019bf64: 0c061446  jal	0x185118
0019bf68: 00a0882d  move	s1,a1
0019bf6c: 26040590  addiu	a0,s0,1424
0019bf70: 260f0540  addiu	t7,s0,1344
0019bf74: 508f0004  beql	a0,t7,0x19bf88
0019bf78: 260f05a0  addiu	t7,s0,1440
0019bf7c: 79e80000  lq	t0,0(t7)
0019bf80: 7c880000  sq	t0,0(a0)
0019bf84: 260f05a0  addiu	t7,s0,1440
0019bf88: 51f10004  beql	t7,s1,0x19bf9c
0019bf8c: de0f0600  ld	t7,1536(s0)
0019bf90: 7a280000  lq	t0,0(s1)
0019bf94: 7de80000  sq	t0,0(t7)
0019bf98: de0f0600  ld	t7,1536(s0)
0019bf9c: 240efffe  li	t6,-2
0019bfa0: 01ee7824  and	t7,t7,t6
0019bfa4: 0c050e4a  jal	0x143928
0019bfa8: fe0f0600  sd	t7,1536(s0)
0019bfac: 9e020604  lwu	v0,1540(s0)
0019bfb0: dfb10008  ld	s1,8(sp)
0019bfb4: 0002103c  dsll32	v0,v0,0x0
0019bfb8: dfb00000  ld	s0,0(sp)
0019bfbc: 0002103f  dsra32	v0,v0,0x0
0019bfc0: dfbf0010  ld	ra,16(sp)
0019bfc4: 30420001  andi	v0,v0,0x1
0019bfc8: 03e00008  jr	ra
0019bfcc: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0019bf50(void)`

```c
uint FUN_0019bf50(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  ulong uVar4;
  
  FUN_00185118();
  if ((undefined4 *)(param_1 + 0x590) != (undefined4 *)(param_1 + 0x540)) {
    *(undefined4 *)(param_1 + 0x590) = *(undefined4 *)(param_1 + 0x540);
    *(undefined4 *)(param_1 + 0x594) = *(undefined4 *)(param_1 + 0x544);
    *(undefined4 *)(param_1 + 0x598) = *(undefined4 *)(param_1 + 0x548);
    *(undefined4 *)(param_1 + 0x59c) = *(undefined4 *)(param_1 + 0x54c);
  }
  if ((undefined4 *)(param_1 + 0x5a0) == param_2) {
    uVar4 = *(ulong *)(param_1 + 0x600);
  }
  else {
    uVar1 = param_2[1];
    uVar2 = param_2[2];
    uVar3 = param_2[3];
    *(undefined4 *)(param_1 + 0x5a0) = *param_2;
    *(undefined4 *)(param_1 + 0x5a4) = uVar1;
    *(undefined4 *)(param_1 + 0x5a8) = uVar2;
    *(undefined4 *)(param_1 + 0x5ac) = uVar3;
    uVar4 = *(ulong *)(param_1 + 0x600);
  }
  *(ulong *)(param_1 + 0x600) = uVar4 & 0xfffffffffffffffe;
  FUN_00143928();
  return *(uint *)(param_1 + 0x604) & 1;
}
```

## Earlier attempts (newest first)

- 32 differing words, 156/128 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_05_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_05_0.cpp`)
