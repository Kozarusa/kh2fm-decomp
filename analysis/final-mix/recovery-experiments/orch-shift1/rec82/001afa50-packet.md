# Target packet 001afa50

- Range: `001afa50`..`001afa88`, **56 bytes = 14 instructions**. This size is the acceptance size.
- Layout name: `FUN_001afa50`
- Registry names for this address: `_Z16wtarget_001afa50jjjj`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001afa50: 3c0f01c9  lui	t7,0x1c9
001afa54: 240dffff  li	t5,-1
001afa58: 25ee4090  addiu	t6,t7,16528   ; = D_01c94090
001afa5c: 25cc0024  addiu	t4,t6,36
001afa60: adc00000  sw	zero,0(t6)
001afa64: adcd0004  sw	t5,4(t6)
001afa68: adcd0008  sw	t5,8(t6)
001afa6c: 25ce000c  addiu	t6,t6,12
001afa70: 01cc782a  slt	t7,t6,t4
001afa74: 00000000  nop
001afa78: 55e0fffa  bnezl	t7,0x1afa64
001afa7c: adc00000  sw	zero,0(t6)
001afa80: 03e00008  jr	ra
001afa84: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001afa50(void)`

```c
void FUN_001afa50(void)

{
  undefined4 *puVar1;
  
  puVar1 = &DAT_01c94090;
  DAT_01c94090 = 0;
  while( true ) {
    puVar1[1] = 0xffffffff;
    puVar1[2] = 0xffffffff;
    puVar1 = puVar1 + 3;
    if (0x1c940b3 < (int)puVar1) break;
    *puVar1 = 0;
  }
  return;
}
```

## Earlier attempts (newest first)

- 15 differing words, 64/56 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.cpp`)
