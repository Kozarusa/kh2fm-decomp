# Target packet 0018fe80

- Range: `0018fe80`..`0018fee8`, **104 bytes = 26 instructions**. This size is the acceptance size.
- Layout name: `FUN_0018fe80`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001b58f0` registry: `func_001b58f0`
  - accepted sources that already call it (copy their declaration): `fm_primary_floatarguments_recovered_0018f9b8.cpp`, `fm_primary_fourwordfresh_recovered_00195558.cpp`, `fm_primary_fourwordfresh_recovered_00197390.cpp`, `fm_primary_sixword_recovered_0018f2a8.cpp`, `fm_primary_sixword_recovered_0018f2d0.cpp`
- `001dc5f8` registry: `_ZN3ryj6EFFECT3posEv`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_floatarguments_recovered_0018f9b8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0018fe80: 27bdffe0  addiu	sp,sp,-32
0018fe84: 0000382d  move	a3,zero
0018fe88: ffb10008  sd	s1,8(sp)
0018fe8c: ffb00000  sd	s0,0(sp)
0018fe90: ffbf0010  sd	ra,16(sp)
0018fe94: 0080882d  move	s1,a0
0018fe98: 8c840000  lw	a0,0(a0)
0018fe9c: 8e250004  lw	a1,4(s1)
0018fea0: 0c06d63c  jal	0x1b58f0
0018fea4: 8e26000c  lw	a2,12(s1)
0018fea8: 0040802d  move	s0,v0
0018feac: 10400008  beqz	v0,0x18fed0
0018feb0: 0040202d  move	a0,v0
0018feb4: 0c07717e  jal	0x1dc5f8
0018feb8: 00000000  nop
0018febc: 8e2f0008  lw	t7,8(s1)
0018fec0: 504f0004  beql	v0,t7,0x18fed4
0018fec4: ae300000  sw	s0,0(s1)
0018fec8: 79e80000  lq	t0,0(t7)
0018fecc: 7c480000  sq	t0,0(v0)
0018fed0: ae300000  sw	s0,0(s1)
0018fed4: dfbf0010  ld	ra,16(sp)
0018fed8: dfb00000  ld	s0,0(sp)
0018fedc: dfb10008  ld	s1,8(sp)
0018fee0: 03e00008  jr	ra
0018fee4: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0018fe80(void)`

```c
void FUN_0018fe80(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  long lVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  lVar3 = FUN_001b58f0(*param_1,param_1[1],param_1[3],0);
  if (lVar3 != 0) {
    puVar2 = (undefined4 *)FUN_001dc5f8(lVar3);
    puVar1 = (undefined4 *)param_1[2];
    if (puVar2 == puVar1) {
      *param_1 = (int)lVar3;
      return;
    }
    uVar4 = puVar1[1];
    uVar5 = puVar1[2];
    uVar6 = puVar1[3];
    *puVar2 = *puVar1;
    puVar2[1] = uVar4;
    puVar2[2] = uVar5;
    puVar2[3] = uVar6;
  }
  *param_1 = (int)lVar3;
  return;
}
```

## Earlier attempts (newest first)

- 21 differing words, 128/104 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_04_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_04_0.cpp`)
