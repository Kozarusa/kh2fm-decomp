# Target packet 001b43e0

- Range: `001b43e0`..`001b4430`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_001b43e0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00105110` registry: `_ZN4AREA4FreeEPv`
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourwordfresh_recovered_002c14a8.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_oneword_recovered_001bf0c8.cpp`, `fm_primary_orchbu_recovered_001a4060.cpp`
- `001b4f40` registry: none
- `001b5460` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001b43e0: 27bdfff0  addiu	sp,sp,-16
001b43e4: ffb00000  sd	s0,0(sp)
001b43e8: ffbf0008  sd	ra,8(sp)
001b43ec: 3c1001d5  lui	s0,0x1d5
001b43f0: 8e0f8cb0  lw	t7,-29520(s0)   ; = D_01d48cb0
001b43f4: 11e0000a  beqz	t7,0x1b4420
001b43f8: 01e0202d  move	a0,t7
001b43fc: 0c06d518  jal	0x1b5460
001b4400: 00000000  nop
001b4404: 8e108cb0  lw	s0,-29520(s0)   ; = D_01d48cb0
001b4408: 12000005  beqz	s0,0x1b4420
001b440c: 0200202d  move	a0,s0
001b4410: 0c06d3d0  jal	0x1b4f40
001b4414: 00000000  nop
001b4418: 0c041444  jal	0x105110
001b441c: 0200202d  move	a0,s0
001b4420: dfb00000  ld	s0,0(sp)
001b4424: dfbf0008  ld	ra,8(sp)
001b4428: 03e00008  jr	ra
001b442c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001b43e0(void)`

```c
void FUN_001b43e0(void)

{
  int iVar1;
  
  if (DAT_01d48cb0 != 0) {
    FUN_001b5460(DAT_01d48cb0);
    iVar1 = DAT_01d48cb0;
    if (DAT_01d48cb0 != 0) {
      FUN_001b4f40(DAT_01d48cb0);
      FUN_00105110(iVar1);
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- 27 differing words, 108/80 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round25_001b43e0_v03.verification.json`
- 25 differing words, 104/80 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round25_001b43e0_v02.verification.json`
- 25 differing words, 104/80 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round25_001b43e0_v01.verification.json`
