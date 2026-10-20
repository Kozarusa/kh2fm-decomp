# Target packet 001bbb50

- Range: `001bbb50`..`001bbba8`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bbb50`
- Registry names for this address: `func_001bbb50`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bbb50: 3c0f01d5  lui	t7,0x1d5
001bbb54: 8def9320  lw	t7,-27872(t7)   ; = D_01d49320
001bbb58: 11e0000a  beqz	t7,0x1bbb84
001bbb5c: 0000102d  move	v0,zero
001bbb60: 8def0008  lw	t7,8(t7)
001bbb64: 91ee0008  lbu	t6,8(t7)
001bbb68: 240f0019  li	t7,25
001bbb6c: 11cf0007  beq	t6,t7,0x1bbb8c
001bbb70: 29cd001a  slti	t5,t6,26
001bbb74: 11a00007  beqz	t5,0x1bbb94
001bbb78: 240f0002  li	t7,2
001bbb7c: 11cf0003  beq	t6,t7,0x1bbb8c
001bbb80: 00000000  nop
001bbb84: 03e00008  jr	ra
001bbb88: 00000000  nop
001bbb8c: 03e00008  jr	ra
001bbb90: 24020001  li	v0,1
001bbb94: 240f0020  li	t7,32
001bbb98: 55cffffa  bnel	t6,t7,0x1bbb84
001bbb9c: 0000102d  move	v0,zero
001bbba0: 1000fffa  b	0x1bbb8c
001bbba4: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bbb50(void)`

```c
undefined4 FUN_001bbb50(void)

{
  byte bVar1;
  
  if (DAT_01d49320 == 0) {
    return 0;
  }
  bVar1 = *(byte *)(*(int *)(DAT_01d49320 + 8) + 8);
  if (bVar1 != 0x19) {
    if (bVar1 < 0x1a) {
      if (bVar1 != 2) {
        return 0;
      }
    }
    else if (bVar1 != 0x20) {
      return 0;
    }
  }
  return 1;
}
```

## Earlier attempts (newest first)

- 13 differing words, 72/88 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.cpp`)
