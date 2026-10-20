# Target packet 001c16a0

- Range: `001c16a0`..`001c16ec`, **76 bytes = 19 instructions**. This size is the acceptance size.
- Layout name: `FUN_001c16a0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001dca30` registry: `func_001dca30`
  - accepted sources that already call it (copy their declaration): `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_oneword_recovered_001c8710.cpp`, `fm_primary_oneword_recovered_001c8750.cpp`, `fm_primary_sixwordnext_recovered_001d7a50.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001c16a0: 27bdfff0  addiu	sp,sp,-16
001c16a4: 00a0682d  move	t5,a1
001c16a8: ffbf0000  sd	ra,0(sp)
001c16ac: 8c8e0004  lw	t6,4(a0)
001c16b0: 11c0000c  beqz	t6,0x1c16e4
001c16b4: 00a0302d  move	a2,a1
001c16b8: 240f0001  li	t7,1
001c16bc: 11cf0003  beq	t6,t7,0x1c16cc
001c16c0: dfbf0000  ld	ra,0(sp)
001c16c4: 03e00008  jr	ra
001c16c8: 27bd0010  addiu	sp,sp,16
001c16cc: 8c850030  lw	a1,48(a0)
001c16d0: 01a0302d  move	a2,t5
001c16d4: 8c840000  lw	a0,0(a0)
001c16d8: dfbf0000  ld	ra,0(sp)
001c16dc: 0807728c  j	0x1dca30
001c16e0: 27bd0010  addiu	sp,sp,16
001c16e4: 1000fffb  b	0x1c16d4
001c16e8: 8c850030  lw	a1,48(a0)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001c16a0(void)`

```c
void FUN_001c16a0(undefined4 *param_1,undefined8 param_2)

{
  undefined4 uVar1;
  
  if (param_1[1] == 0) {
    uVar1 = param_1[0xc];
  }
  else {
    if (param_1[1] != 1) {
      return;
    }
    uVar1 = param_1[0xc];
  }
  FUN_001dca30(*param_1,uVar1,param_2);
  return;
}
```

## Earlier attempts (newest first)

- 17 differing words, 68/76 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_07_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_07_0.cpp`)
