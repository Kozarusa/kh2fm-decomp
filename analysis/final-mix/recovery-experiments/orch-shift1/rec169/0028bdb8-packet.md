# Target packet 0028bdb8

- Range: `0028bdb8`..`0028be14`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_0028bdb8`
- Registry names for this address: `Tz::LeadDataLeave(unsigned int)`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0028be58` registry: `Tz::LeadDataIsActive(unsigned int)`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_002908f0.cpp`, `fm_primary_orchee_recovered_00262290.cpp`, `fm_primary_orcheg_recovered_00269ef8.cpp`
- `0028e4c8` registry: `func_0028e4c8`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_002908f0.cpp`, `fm_primary_threeword_recovered_0026dcb8.cpp`, `fm_primary_threeword_recovered_0028e710.cpp`
- `0028e560` registry: `func_0028e560`
  - accepted sources that already call it (copy their declaration): `fm_primary_argument_recovered.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_002908f0.cpp`, `fm_primary_threeword_recovered_0026dcb8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0028bdb8: 27bdfff0  addiu	sp,sp,-16
0028bdbc: ffb00000  sd	s0,0(sp)
0028bdc0: ffbf0008  sd	ra,8(sp)
0028bdc4: 0c0a2f96  jal	0x28be58
0028bdc8: 0080802d  move	s0,a0
0028bdcc: 1040000d  beqz	v0,0x28be04
0028bdd0: 0000282d  move	a1,zero
0028bdd4: 0c0a3932  jal	0x28e4c8
0028bdd8: 8e040000  lw	a0,0(s0)
0028bddc: 860f0010  lh	t7,16(s0)
0028bde0: 26050010  addiu	a1,s0,16
0028bde4: 24060004  li	a2,4
0028bde8: 104f0006  beq	v0,t7,0x28be04
0028bdec: 2407ffff  li	a3,-1
0028bdf0: 8e040000  lw	a0,0(s0)
0028bdf4: dfbf0008  ld	ra,8(sp)
0028bdf8: dfb00000  ld	s0,0(sp)
0028bdfc: 080a3958  j	0x28e560
0028be00: 27bd0010  addiu	sp,sp,16
0028be04: dfb00000  ld	s0,0(sp)
0028be08: dfbf0008  ld	ra,8(sp)
0028be0c: 03e00008  jr	ra
0028be10: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0028bdb8(void)`

```c
void FUN_0028bdb8(undefined4 *param_1)

{
  short sVar1;
  long lVar2;
  
  lVar2 = FUN_0028be58();
  if (lVar2 != 0) {
    sVar1 = FUN_0028e4c8(*param_1,0);
    if (sVar1 != *(short *)(param_1 + 4)) {
      FUN_0028e560(*param_1,param_1 + 4,4,0xffffffffffffffff);
      return;
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- 15 differing words, 88/92 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_10_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_10_1.cpp`)
