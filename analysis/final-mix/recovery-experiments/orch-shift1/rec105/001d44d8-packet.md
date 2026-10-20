# Target packet 001d44d8

- Range: `001d44d8`..`001d4528`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d44d8`
- Registry names for this address: `Tz::JmInfo::GetLimitEntry(...)`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d44d8: 3c0b01d6  lui	t3,0x1d6
001d44dc: 8d6eba28  lw	t6,-17880(t3)   ; = D_01d5ba28
001d44e0: 8dcf0004  lw	t7,4(t6)
001d44e4: 19e0000d  blez	t7,0x1d451c
001d44e8: 0000602d  move	t4,zero
001d44ec: 8d6dba28  lw	t5,-17880(t3)   ; = D_01d5ba28
001d44f0: 000c7980  sll	t7,t4,0x6
001d44f4: 258c0001  addiu	t4,t4,1
001d44f8: 01ed7821  addu	t7,t7,t5
001d44fc: 3c0b01d6  lui	t3,0x1d6
001d4500: 95ee0030  lhu	t6,48(t7)
001d4504: 11c40006  beq	t6,a0,0x1d4520
001d4508: 25e20008  addiu	v0,t7,8
001d450c: 8daf0004  lw	t7,4(t5)
001d4510: 018f782a  slt	t7,t4,t7
001d4514: 15e0fff6  bnez	t7,0x1d44f0
001d4518: 8d6dba28  lw	t5,-17880(t3)   ; = D_01d5ba28
001d451c: 0000102d  move	v0,zero
001d4520: 03e00008  jr	ra
001d4524: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d44d8(void)`

```c
int FUN_001d44d8(ulong param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(DAT_01d5ba28 + 4)) {
    do {
      iVar2 = iVar1 * 0x40;
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + DAT_01d5ba28;
      if (*(ushort *)(iVar2 + 0x30) == param_1) {
        return iVar2 + 8;
      }
    } while (iVar1 < *(int *)(DAT_01d5ba28 + 4));
  }
  return 0;
}
```

## Earlier attempts (newest first)

- 19 differing words, 76/80 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.cpp`)
