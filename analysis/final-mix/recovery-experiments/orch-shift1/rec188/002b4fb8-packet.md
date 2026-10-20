# Target packet 002b4fb8

- Range: `002b4fb8`..`002b4ff8`, **64 bytes = 16 instructions**. This size is the acceptance size.
- Layout name: `FUN_002b4fb8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00139d78` registry: `_Z16u_call4_00139d78jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_close_recovered.cpp`
- `0028acc8` registry: `Tz::Select::isCreated(...)`
  - accepted sources that already call it (copy their declaration): `fm_primary_orcheb_recovered_002519d0.cpp`, `fm_primary_orchec_recovered_002576d0.cpp`, `fm_primary_orchee_recovered_00262290.cpp`, `fm_primary_orchef_recovered_002656c0.cpp`, `fm_primary_orcheg_recovered_00269ef8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002b4fb8: 27bdfff0  addiu	sp,sp,-16
002b4fbc: 3c0f0036  lui	t7,0x36
002b4fc0: ffbf0000  sd	ra,0(sp)
002b4fc4: 0000102d  move	v0,zero
002b4fc8: 8deef654  lw	t6,-2476(t7)   ; = D_0035f654
002b4fcc: 11c00003  beqz	t6,0x2b4fdc
002b4fd0: 01c0202d  move	a0,t6
002b4fd4: 0c04e75e  jal	0x139d78
002b4fd8: 00000000  nop
002b4fdc: 10400003  beqz	v0,0x2b4fec
002b4fe0: 3c0f0036  lui	t7,0x36
002b4fe4: 0c0a2b32  jal	0x28acc8
002b4fe8: 8de4f650  lw	a0,-2480(t7)   ; = D_0035f650
002b4fec: dfbf0000  ld	ra,0(sp)
002b4ff0: 03e00008  jr	ra
002b4ff4: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002b4fb8(void)`

```c
void FUN_002b4fb8(void)

{
  long lVar1;
  
  lVar1 = 0;
  if (DAT_0035f654 != 0) {
    lVar1 = FUN_00139d78(DAT_0035f654);
  }
  if (lVar1 != 0) {
    FUN_0028acc8(DAT_0035f650);
  }
  return;
}
```

## Earlier attempts (newest first)

- 9 differing words, 64/64 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round20_002b4fb8_v02.verification.json`
- 13 differing words, 68/64 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round20_002b4fb8_v01.verification.json`
