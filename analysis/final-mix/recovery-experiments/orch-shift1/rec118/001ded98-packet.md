# Target packet 001ded98

- Range: `001ded98`..`001dee10`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ded98`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001e0158` registry: `func_001e0158`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`
- `001e01b8` registry: `func_001e01b8`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ded98: 27bdfff0  addiu	sp,sp,-16
001ded9c: ffbf0000  sd	ra,0(sp)
001deda0: 8c8e005c  lw	t6,92(a0)
001deda4: 31cf0004  andi	t7,t6,0x4
001deda8: 11e00013  beqz	t7,0x1dedf8
001dedac: 31cf0008  andi	t7,t6,0x8
001dedb0: 8c840058  lw	a0,88(a0)
001dedb4: 1080000d  beqz	a0,0x1dedec
001dedb8: 240fffe0  li	t7,-32
001dedbc: 108f0009  beq	a0,t7,0x1dede4
001dedc0: 248f0040  addiu	t7,a0,64
001dedc4: 248e0020  addiu	t6,a0,32
001dedc8: 00000000  nop
001dedcc: 00000000  nop
001dedd0: 00000000  nop
001dedd4: 00000000  nop
001dedd8: 00000000  nop
001deddc: 15cffffa  bne	t6,t7,0x1dedc8
001dede0: 25effff0  addiu	t7,t7,-16
001dede4: 0c078056  jal	0x1e0158
001dede8: 00000000  nop
001dedec: dfbf0000  ld	ra,0(sp)
001dedf0: 03e00008  jr	ra
001dedf4: 27bd0010  addiu	sp,sp,16
001dedf8: 51e0fffd  beqzl	t7,0x1dedf0
001dedfc: dfbf0000  ld	ra,0(sp)
001dee00: 0c07806e  jal	0x1e01b8
001dee04: 8c840058  lw	a0,88(a0)
001dee08: 1000fff9  b	0x1dedf0
001dee0c: dfbf0000  ld	ra,0(sp)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ded98(void)`

```c
void FUN_001ded98(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if ((*(uint *)(param_1 + 0x5c) & 4) == 0) {
    if ((*(uint *)(param_1 + 0x5c) & 8) != 0) {
      FUN_001e01b8(*(undefined4 *)(param_1 + 0x58));
    }
  }
  else {
    iVar2 = *(int *)(param_1 + 0x58);
    if (iVar2 != 0) {
      iVar3 = iVar2 + 0x40;
      if (iVar2 != -0x20) {
        do {
          bVar1 = iVar2 + 0x20 != iVar3;
          iVar3 = iVar3 + -0x10;
        } while (bVar1);
      }
      FUN_001e0158();
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- 24 differing words, 120/120 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_08_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_08_1.cpp`)
