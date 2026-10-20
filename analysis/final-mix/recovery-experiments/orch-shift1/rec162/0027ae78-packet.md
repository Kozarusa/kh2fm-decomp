# Target packet 0027ae78

- Range: `0027ae78`..`0027aed4`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_0027ae78`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0027ae78: 3c0f0036  lui	t7,0x36
0027ae7c: 0000702d  move	t6,zero
0027ae80: 8dedf230  lw	t5,-3536(t7)   ; = D_0035f230
0027ae84: 0000102d  move	v0,zero
0027ae88: 240c0006  li	t4,6
0027ae8c: 504c000c  beql	v0,t4,0x27aec0
0027ae90: 24420001  addiu	v0,v0,1
0027ae94: 85af0000  lh	t7,0(t5)
0027ae98: 004f7807  srav	t7,t7,v0
0027ae9c: 39ef0001  xori	t7,t7,0x1
0027aea0: 31ef0001  andi	t7,t7,0x1
0027aea4: 31ef00ff  andi	t7,t7,0xff
0027aea8: 55e00005  bnezl	t7,0x27aec0
0027aeac: 24420001  addiu	v0,v0,1
0027aeb0: 108e0006  beq	a0,t6,0x27aecc
0027aeb4: 00000000  nop
0027aeb8: 25ce0001  addiu	t6,t6,1
0027aebc: 24420001  addiu	v0,v0,1
0027aec0: 284f0008  slti	t7,v0,8
0027aec4: 15e0fff1  bnez	t7,0x27ae8c
0027aec8: 00000000  nop
0027aecc: 03e00008  jr	ra
0027aed0: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0027ae78(void)`

```c
void FUN_0027ae78(int param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  uVar1 = 0;
  do {
    if ((uVar1 != 6) && ((((int)*DAT_0035f230 >> (uVar1 & 0x1f) ^ 1U) & 1) == 0)) {
      if (param_1 == iVar2) {
        return;
      }
      iVar2 = iVar2 + 1;
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 8);
  return;
}
```

## Earlier attempts (newest first)

- 20 differing words, 88/92 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v2_04_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v2_04_0.cpp`)
