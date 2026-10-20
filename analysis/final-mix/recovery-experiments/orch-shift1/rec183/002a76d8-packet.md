# Target packet 002a76d8

- Range: `002a76d8`..`002a7758`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_002a76d8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00106420` registry: `Tz::LoadDataFree(...)`
  - accepted sources that already call it (copy their declaration): `fm_primary_orchac_recovered_00123c98.cpp`, `fm_primary_orchac_recovered_00315678.cpp`, `fm_primary_orchac_recovered_00315700.cpp`, `fm_primary_orchac_recovered_00316890.cpp`, `fm_primary_orchcv_recovered_001db808.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002a76d8: 27bdffe0  addiu	sp,sp,-32
002a76dc: ffb00000  sd	s0,0(sp)
002a76e0: ffb10008  sd	s1,8(sp)
002a76e4: ffbf0010  sd	ra,16(sp)
002a76e8: 3c100036  lui	s0,0x36
002a76ec: 8e04f600  lw	a0,-2560(s0)   ; = D_0035f600
002a76f0: 10800005  beqz	a0,0x2a7708
002a76f4: 3c0f0036  lui	t7,0x36
002a76f8: 0c041908  jal	0x106420
002a76fc: 00000000  nop
002a7700: ae00f600  sw	zero,-2560(s0)   ; = D_0035f600
002a7704: 3c0f0036  lui	t7,0x36
002a7708: 8df1f604  lw	s1,-2556(t7)   ; = D_0035f604
002a770c: 1220000d  beqz	s1,0x2a7744
002a7710: 26302210  addiu	s0,s1,8720
002a7714: 12300007  beq	s1,s0,0x2a7734
002a7718: 2610fe4c  addiu	s0,s0,-436
002a771c: 8e0e0000  lw	t6,0(s0)
002a7720: 8dcf000c  lw	t7,12(t6)
002a7724: 01e0f809  jalr	t7
002a7728: 0200202d  move	a0,s0
002a772c: 1000fff9  b	0x2a7714
002a7730: 00000000  nop
002a7734: 0c041908  jal	0x106420
002a7738: 0220202d  move	a0,s1
002a773c: 3c0f0036  lui	t7,0x36
002a7740: ade0f604  sw	zero,-2556(t7)   ; = D_0035f604
002a7744: dfb00000  ld	s0,0(sp)
002a7748: dfb10008  ld	s1,8(sp)
002a774c: dfbf0010  ld	ra,16(sp)
002a7750: 03e00008  jr	ra
002a7754: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002a76d8(void)`

```c
void FUN_002a76d8(void)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  
  if (DAT_0035f600 != 0) {
    FUN_00106420();
    DAT_0035f600 = 0;
  }
  piVar2 = DAT_0035f604;
  piVar3 = DAT_0035f604 + 0x884;
  if (DAT_0035f604 != (int *)0x0) {
    while( true ) {
      bVar1 = piVar2 == piVar3;
      piVar3 = piVar3 + -0x6d;
      if (bVar1) break;
      (**(code **)(*piVar3 + 0xc))(piVar3);
    }
    FUN_00106420(piVar2);
    DAT_0035f604 = (int *)0x0;
  }
  return;
}
```

## Earlier attempts (newest first)

- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec183/002a76d8-packet.md`
