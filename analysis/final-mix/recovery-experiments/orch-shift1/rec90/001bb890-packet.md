# Target packet 001bb890

- Range: `001bb890`..`001bb8f0`, **96 bytes = 24 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bb890`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0014ca20` registry: `func_0014ca20`
  - accepted sources that already call it (copy their declaration): `fm_fallback_small.cpp`
- `001af9f8` registry: `func_001af9f8`
- `001c1130` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_orchbk_recovered_00191938.cpp`, `fm_primary_queuegammaprime_recovered_001ad5a8.cpp`, `fm_primary_queuegammaprime_recovered_001ad5f0.cpp`
- `001c11a8` registry: `_ZN2YS8SELECTOR14ResetPauseModeEi`
  - accepted sources that already call it (copy their declaration): `fm_primary_orchbk_recovered_00191938.cpp`
- `001d6c58` registry: `_ZN2YS10INDICATION7DisableEv`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bb890: 27bdfff0  addiu	sp,sp,-16
001bb894: 3c0c01d5  lui	t4,0x1d5
001bb898: 8d8e9320  lw	t6,-27872(t4)   ; = D_01d49320
001bb89c: ffbf0000  sd	ra,0(sp)
001bb8a0: 8dcf0004  lw	t7,4(t6)
001bb8a4: 35ef0004  ori	t7,t7,0x4
001bb8a8: adcf0004  sw	t7,4(t6)
001bb8ac: 8d8d9320  lw	t5,-27872(t4)   ; = D_01d49320
001bb8b0: 8daf0004  lw	t7,4(t5)
001bb8b4: 35ef0010  ori	t7,t7,0x10
001bb8b8: 0c053288  jal	0x14ca20
001bb8bc: adaf0004  sw	t7,4(t5)
001bb8c0: 3c0e0035  lui	t6,0x35
001bb8c4: 8dcff240  lw	t7,-3520(t6)   ; = D_0034f240
001bb8c8: 35ef0002  ori	t7,t7,0x2
001bb8cc: 0c075b16  jal	0x1d6c58
001bb8d0: adcff240  sw	t7,-3520(t6)   ; = D_0034f240
001bb8d4: 0c07046a  jal	0x1c11a8
001bb8d8: 24040008  li	a0,8
001bb8dc: 0c07044c  jal	0x1c1130
001bb8e0: 24040005  li	a0,5
001bb8e4: dfbf0000  ld	ra,0(sp)
001bb8e8: 0806be7e  j	0x1af9f8
001bb8ec: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bb890(void)`

```c
void FUN_001bb890(void)

{
  *(uint *)(DAT_01d49320 + 4) = *(uint *)(DAT_01d49320 + 4) | 4;
  *(uint *)(DAT_01d49320 + 4) = *(uint *)(DAT_01d49320 + 4) | 0x10;
  FUN_0014ca20();
  DAT_0034f240 = DAT_0034f240 | 2;
  FUN_001d6c58();
  FUN_001c11a8(8);
  FUN_001c1130(5);
  FUN_001af9f8();
  return;
}
```

## Earlier attempts (newest first)

- none found
