# Target packet 00157aa0

- Range: `00157aa0`..`00157adc`, **60 bytes = 15 instructions**. This size is the acceptance size.
- Layout name: `FUN_00157aa0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00138c10` registry: `_ZN2dk6Sprite6setNumEi`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_capacity_recovered_00303c48.cpp`
- `001a1de0` registry: `_Z16u_call4_001a1de0jjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_twowordfresh_recovered_00149ec0.cpp`, `fm_scalar_extra_recovered_01.cpp`, `fm_scalar_recovered_01.cpp`, `fm_width_recovered_01.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00157aa0: 27bdfff0  addiu	sp,sp,-16
00157aa4: ffb00000  sd	s0,0(sp)
00157aa8: ffbf0008  sd	ra,8(sp)
00157aac: 0080802d  move	s0,a0
00157ab0: 8c8f0034  lw	t7,52(a0)
00157ab4: 0c068778  jal	0x1a1de0
00157ab8: 8de4048c  lw	a0,1164(t7)
00157abc: 26042710  addiu	a0,s0,10000
00157ac0: 10400002  beqz	v0,0x157acc
00157ac4: 24050075  li	a1,117
00157ac8: 2405006f  li	a1,111
00157acc: dfb00000  ld	s0,0(sp)
00157ad0: dfbf0008  ld	ra,8(sp)
00157ad4: 0804e304  j	0x138c10
00157ad8: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00157aa0(void)`

```c
void FUN_00157aa0(int param_1)

{
  long lVar1;
  undefined4 uVar2;
  
  lVar1 = FUN_001a1de0(*(undefined4 *)(*(int *)(param_1 + 0x34) + 0x48c));
  uVar2 = 0x75;
  if (lVar1 != 0) {
    uVar2 = 0x6f;
  }
  FUN_00138c10(param_1 + 10000,uVar2);
  return;
}
```

## Earlier attempts (newest first)

- none found
