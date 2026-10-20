# Target packet 001ddc08

- Range: `001ddc08`..`001ddc44`, **60 bytes = 15 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ddc08`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ddc08: 3c0f0035  lui	t7,0x35
001ddc0c: 8dee2ae0  lw	t6,10976(t7)   ; = D_00352ae0
001ddc10: 11c0000a  beqz	t6,0x1ddc3c
001ddc14: 00000000  nop
001ddc18: 3c0d0400  lui	t5,0x400
001ddc1c: 8dcf0008  lw	t7,8(t6)
001ddc20: 01ed7825  or	t7,t7,t5
001ddc24: adcf0008  sw	t7,8(t6)
001ddc28: 8dce0028  lw	t6,40(t6)
001ddc2c: 00000000  nop
001ddc30: 00000000  nop
001ddc34: 55c0fffa  bnezl	t6,0x1ddc20
001ddc38: 8dcf0008  lw	t7,8(t6)
001ddc3c: 03e00008  jr	ra
001ddc40: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ddc08(void)`

```c
void FUN_001ddc08(void)

{
  int iVar1;
  uint uVar2;
  
  if (DAT_00352ae0 != 0) {
    uVar2 = *(uint *)(DAT_00352ae0 + 8);
    iVar1 = DAT_00352ae0;
    while( true ) {
      *(uint *)(iVar1 + 8) = uVar2 | 0x4000000;
      iVar1 = *(int *)(iVar1 + 0x28);
      if (iVar1 == 0) break;
      uVar2 = *(uint *)(iVar1 + 8);
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- 12 differing words, 56/60 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v2_02_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v2_02_0.cpp`)
