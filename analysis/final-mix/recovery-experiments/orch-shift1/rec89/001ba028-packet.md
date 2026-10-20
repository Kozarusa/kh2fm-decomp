# Target packet 001ba028

- Range: `001ba028`..`001ba060`, **56 bytes = 14 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ba028`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ba028: 0000702d  move	t6,zero
001ba02c: 3c0d01d5  lui	t5,0x1d5
001ba030: 55c00002  bnezl	t6,0x1ba03c
001ba034: 8dcf08b4  lw	t7,2228(t6)
001ba038: 8daf8da0  lw	t7,-29280(t5)   ; = D_01d48da0
001ba03c: 15e00004  bnez	t7,0x1ba050
001ba040: 01e0702d  move	t6,t7
001ba044: 0000102d  move	v0,zero
001ba048: 03e00008  jr	ra
001ba04c: 304200ff  andi	v0,v0,0xff
001ba050: 11e4fffd  beq	t7,a0,0x1ba048
001ba054: 24020001  li	v0,1
001ba058: 1000fff5  b	0x1ba030
001ba05c: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ba028(void)`

```c
undefined4 FUN_001ba028(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  while( true ) {
    iVar2 = DAT_01d48da0;
    if (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 0x8b4);
    }
    if (iVar2 == 0) break;
    iVar1 = iVar2;
    if (iVar2 == param_1) {
      return 1;
    }
  }
  return 0;
}
```

## Earlier attempts (newest first)

- 12 differing words, 48/56 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.cpp`)
