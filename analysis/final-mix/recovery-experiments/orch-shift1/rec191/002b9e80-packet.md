# Target packet 002b9e80

- Range: `002b9e80`..`002b9ecc`, **76 bytes = 19 instructions**. This size is the acceptance size.
- Layout name: `FUN_002b9e80`
- Registry names for this address: `func_002b9e80`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002b7fbc` registry: `func_002b7fbc`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_fourwordfresh_recovered_002c14a8.cpp`, `fm_primary_packetorder_recovered_002e8038.cpp`, `fm_primary_queuelambdaprime_recovered_002b7fbc.cpp`, `fm_primary_resume_recovered_01.cpp`
- `002b9b78` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_fourwordfresh_recovered_002c14a8.cpp`, `fm_primary_packetorder_recovered_002e8038.cpp`, `fm_primary_resume_recovered_01.cpp`, `fm_primary_sixword_recovered_002e7c78.cpp`
- `002b9ed0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_resume_recovered_01.cpp`, `fm_primary_storeorder_recovered_00281f90.cpp`, `fm_primary_width_recovered_02.cpp`
- `002ba390` registry: `_ZN5SOUND14seAlertPlayOffEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_fourwordfresh_recovered_002c14a8.cpp`, `fm_primary_packetorder_recovered_002e8038.cpp`, `fm_primary_resume_recovered_01.cpp`, `fm_primary_sixword_recovered_002e7c78.cpp`
- `002bce40` registry: `func_002bce40`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_resume_recovered_01.cpp`, `fm_primary_storeorder_recovered_00281f90.cpp`, `fm_primary_width_recovered_02.cpp`
- `002bce50` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_resume_recovered_01.cpp`, `fm_primary_storeorder_recovered_00281f90.cpp`, `fm_primary_width_recovered_02.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002b9e80: 27bdfff0  addiu	sp,sp,-16
002b9e84: 0000202d  move	a0,zero
002b9e88: ffb00000  sd	s0,0(sp)
002b9e8c: ffbf0008  sd	ra,8(sp)
002b9e90: 0c0adfef  jal	0x2b7fbc
002b9e94: 3c1001e3  lui	s0,0x1e3
002b9e98: 2610a410  addiu	s0,s0,-23536   ; = D_01e2a410
002b9e9c: 0c0af390  jal	0x2bce40
002b9ea0: 0200202d  move	a0,s0
002b9ea4: 0c0af394  jal	0x2bce50
002b9ea8: 0200202d  move	a0,s0
002b9eac: 0c0ae6de  jal	0x2b9b78
002b9eb0: 00000000  nop
002b9eb4: 0c0ae8e4  jal	0x2ba390
002b9eb8: 00000000  nop
002b9ebc: dfb00000  ld	s0,0(sp)
002b9ec0: dfbf0008  ld	ra,8(sp)
002b9ec4: 080ae7b4  j	0x2b9ed0
002b9ec8: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002b9e80(void)`

```c
void FUN_002b9e80(void)

{
  FUN_002b7fbc(0);
  FUN_002bce40(0x1e2a410);
  FUN_002bce50(0x1e2a410);
  FUN_002b9b78();
  FUN_002ba390();
  FUN_002b9ed0();
  return;
}
```

## Earlier attempts (newest first)

- 18 differing words, 68/76 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_primary_width_01_all.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_primary_width_01_all.cpp`)
