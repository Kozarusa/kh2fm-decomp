# Target packet 001b8d60

- Range: `001b8d60`..`001b8da0`, **64 bytes = 16 instructions**. This size is the acceptance size.
- Layout name: `FUN_001b8d60`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001b8d60: 3c0f0033  lui	t7,0x33
001b8d64: 0000602d  move	t4,zero
001b8d68: 25effb68  addiu	t7,t7,-1176   ; = D_0032fb68
001b8d6c: 91e2011f  lbu	v0,287(t7)
001b8d70: 10400009  beqz	v0,0x1b8d98
001b8d74: a1e0011f  sb	zero,287(t7)
001b8d78: 01e0582d  move	t3,t7
001b8d7c: 018b7821  addu	t7,t4,t3
001b8d80: 008c6821  addu	t5,a0,t4
001b8d84: 91ee0020  lbu	t6,32(t7)
001b8d88: 258c0001  addiu	t4,t4,1
001b8d8c: 0182782a  slt	t7,t4,v0
001b8d90: 15e0fffa  bnez	t7,0x1b8d7c
001b8d94: a1ae0000  sb	t6,0(t5)
001b8d98: 03e00008  jr	ra
001b8d9c: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001b8d60(void)`

```c
void FUN_001b8d60(int param_1)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  
  iVar3 = 0;
  uVar2 = (uint)DAT_0032fc87;
  DAT_0032fc87 = 0;
  if (uVar2 != 0) {
    do {
      puVar4 = (undefined1 *)(param_1 + iVar3);
      puVar1 = &DAT_0032fb88 + iVar3;
      iVar3 = iVar3 + 1;
      *puVar4 = *puVar1;
    } while (iVar3 < (int)uVar2);
  }
  return;
}
```

## Earlier attempts (newest first)

- 8 differing words, 64/64 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.cpp`)
