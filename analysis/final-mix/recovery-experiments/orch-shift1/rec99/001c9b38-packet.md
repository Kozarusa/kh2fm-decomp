# Target packet 001c9b38

- Range: `001c9b38`..`001c9b90`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_001c9b38`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001c99b0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_oneword_recovered_001c8710.cpp`, `fm_primary_oneword_recovered_001c8750.cpp`, `fm_primary_sixwordnext_recovered_001d7a50.cpp`
- `001c9ab8` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_oneword_recovered_001c8710.cpp`, `fm_primary_oneword_recovered_001c8750.cpp`, `fm_primary_sixwordnext_recovered_001d7a50.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001c9b38: 27bdfff0  addiu	sp,sp,-16
001c9b3c: 240f0004  li	t7,4
001c9b40: ffbf0000  sd	ra,0(sp)
001c9b44: 948e0002  lhu	t6,2(a0)
001c9b48: 11cf000d  beq	t6,t7,0x1c9b80
001c9b4c: 240f0048  li	t7,72
001c9b50: 11cf0005  beq	t6,t7,0x1c9b68
001c9b54: 0000782d  move	t7,zero
001c9b58: dfbf0000  ld	ra,0(sp)
001c9b5c: 01e0102d  move	v0,t7
001c9b60: 03e00008  jr	ra
001c9b64: 27bd0010  addiu	sp,sp,16
001c9b68: 0c0726ae  jal	0x1c9ab8
001c9b6c: 00000000  nop
001c9b70: 1040fff9  beqz	v0,0x1c9b58
001c9b74: 240f0002  li	t7,2
001c9b78: 1000fff7  b	0x1c9b58
001c9b7c: 0000782d  move	t7,zero
001c9b80: 84840004  lh	a0,4(a0)
001c9b84: dfbf0000  ld	ra,0(sp)
001c9b88: 0807266c  j	0x1c99b0
001c9b8c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001c9b38(void)`

```c
undefined8 FUN_001c9b38(int param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  if (*(short *)(param_1 + 2) != 4) {
    uVar2 = 0;
    if (*(short *)(param_1 + 2) == 0x48) {
      lVar1 = FUN_001c9ab8();
      uVar2 = 2;
      if (lVar1 != 0) {
        uVar2 = 0;
      }
    }
    return uVar2;
  }
  uVar2 = FUN_001c99b0(*(undefined2 *)(param_1 + 4));
  return uVar2;
}
```

## Earlier attempts (newest first)

- 18 differing words, 84/88 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_07_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_07_0.cpp`)
