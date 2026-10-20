# Target packet 001ddc48

- Range: `001ddc48`..`001ddc88`, **64 bytes = 16 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ddc48`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ddc48: 3c0f0035  lui	t7,0x35
001ddc4c: 8dee2ae0  lw	t6,10976(t7)   ; = D_00352ae0
001ddc50: 11c0000b  beqz	t6,0x1ddc80
001ddc54: 00000000  nop
001ddc58: 3c0dfbff  lui	t5,0xfbff
001ddc5c: 35adffff  ori	t5,t5,0xffff
001ddc60: 8dcf0008  lw	t7,8(t6)
001ddc64: 01ed7824  and	t7,t7,t5
001ddc68: adcf0008  sw	t7,8(t6)
001ddc6c: 8dce0028  lw	t6,40(t6)
001ddc70: 00000000  nop
001ddc74: 00000000  nop
001ddc78: 55c0fffa  bnezl	t6,0x1ddc64
001ddc7c: 8dcf0008  lw	t7,8(t6)
001ddc80: 03e00008  jr	ra
001ddc84: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ddc48(void)`

```c
void FUN_001ddc48(void)

{
  int iVar1;
  uint uVar2;
  
  if (DAT_00352ae0 != 0) {
    uVar2 = *(uint *)(DAT_00352ae0 + 8);
    iVar1 = DAT_00352ae0;
    while( true ) {
      *(uint *)(iVar1 + 8) = uVar2 & 0xfbffffff;
      iVar1 = *(int *)(iVar1 + 0x28);
      if (iVar1 == 0) break;
      uVar2 = *(uint *)(iVar1 + 8);
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- 12 differing words, 60/64 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v2_02_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v2_02_0.cpp`)
