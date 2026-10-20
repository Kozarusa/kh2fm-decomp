# Target packet 001bbac0

- Range: `001bbac0`..`001bbb04`, **68 bytes = 17 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bbac0`
- Registry names for this address: `_ZN2YS7MISSION10Activate2dEv`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001bb4a0` registry: `_ZN2YS7MISSION6IsExecEv`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`
- `001c11a8` registry: `_ZN2YS8SELECTOR14ResetPauseModeEi`
  - accepted sources that already call it (copy their declaration): `fm_primary_orchbk_recovered_00191938.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bbac0: 27bdfff0  addiu	sp,sp,-16
001bbac4: ffbf0000  sd	ra,0(sp)
001bbac8: 0c06ed28  jal	0x1bb4a0
001bbacc: 00000000  nop
001bbad0: 10400009  beqz	v0,0x1bbaf8
001bbad4: 3c0f01d5  lui	t7,0x1d5
001bbad8: 8dee9320  lw	t6,-27872(t7)   ; = D_01d49320
001bbadc: 8dcd0008  lw	t5,8(t6)
001bbae0: 91af0008  lbu	t7,8(t5)
001bbae4: 11e00004  beqz	t7,0x1bbaf8
001bbae8: 01e0202d  move	a0,t7
001bbaec: dfbf0000  ld	ra,0(sp)
001bbaf0: 0807046a  j	0x1c11a8
001bbaf4: 27bd0010  addiu	sp,sp,16
001bbaf8: dfbf0000  ld	ra,0(sp)
001bbafc: 03e00008  jr	ra
001bbb00: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bbac0(void)`

```c
void FUN_001bbac0(void)

{
  char cVar1;
  long lVar2;
  
  lVar2 = FUN_001bb4a0();
  if ((lVar2 != 0) && (cVar1 = *(char *)(*(int *)(DAT_01d49320 + 8) + 8), cVar1 != '\0')) {
    FUN_001c11a8(cVar1);
    return;
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
