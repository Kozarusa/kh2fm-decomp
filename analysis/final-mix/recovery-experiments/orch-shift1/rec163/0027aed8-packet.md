# Target packet 0027aed8

- Range: `0027aed8`..`0027af54`, **124 bytes = 31 instructions**. This size is the acceptance size.
- Layout name: `FUN_0027aed8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0027ae20` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_002908f0.cpp`, `fm_primary_threeword_recovered_0026dcb8.cpp`, `fm_primary_threeword_recovered_0028e710.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0027aed8: 27bdffe0  addiu	sp,sp,-32
0027aedc: ffb00000  sd	s0,0(sp)
0027aee0: ffb10008  sd	s1,8(sp)
0027aee4: ffb20010  sd	s2,16(sp)
0027aee8: 0080802d  move	s0,a0
0027aeec: ffbf0018  sd	ra,24(sp)
0027aef0: 00a0882d  move	s1,a1
0027aef4: 14800009  bnez	a0,0x27af1c
0027aef8: 00c0902d  move	s2,a2
0027aefc: aca00000  sw	zero,0(a1)
0027af00: acc00000  sw	zero,0(a2)
0027af04: dfb00000  ld	s0,0(sp)
0027af08: dfb10008  ld	s1,8(sp)
0027af0c: dfb20010  ld	s2,16(sp)
0027af10: dfbf0018  ld	ra,24(sp)
0027af14: 03e00008  jr	ra
0027af18: 27bd0020  addiu	sp,sp,32
0027af1c: 0c09eb88  jal	0x27ae20
0027af20: 00000000  nop
0027af24: 244f0001  addiu	t7,v0,1
0027af28: 02027023  subu	t6,s0,v0
0027af2c: 10400007  beqz	v0,0x27af4c
0027af30: 020f782a  slt	t7,s0,t7
0027af34: 11e00005  beqz	t7,0x27af4c
0027af38: 240f0001  li	t7,1
0027af3c: 260effff  addiu	t6,s0,-1
0027af40: ae2f0000  sw	t7,0(s1)
0027af44: 1000ffef  b	0x27af04
0027af48: ae4e0000  sw	t6,0(s2)
0027af4c: 1000fffd  b	0x27af44
0027af50: ae200000  sw	zero,0(s1)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0027aed8(void)`

```c
void FUN_0027aed8(int param_1,undefined4 *param_2,int *param_3)

{
  long lVar1;
  int iVar2;
  
  if (param_1 == 0) {
    *param_2 = 0;
    *param_3 = 0;
  }
  else {
    lVar1 = FUN_0027ae20();
    iVar2 = param_1 - (int)lVar1;
    if ((lVar1 == 0) || ((int)lVar1 + 1 <= param_1)) {
      *param_2 = 0;
    }
    else {
      iVar2 = param_1 + -1;
      *param_2 = 1;
    }
    *param_3 = iVar2;
  }
  return;
}
```

## Earlier attempts (newest first)

- 8 differing words, 124/124 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_10_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_10_0.cpp`)
