# Target packet 0027bf20

- Range: `0027bf20`..`0027bf64`, **68 bytes = 17 instructions**. This size is the acceptance size.
- Layout name: `FUN_0027bf20`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0027bf20: 3c0f0036  lui	t7,0x36
0027bf24: 000420c0  sll	a0,a0,0x3
0027bf28: 8deef230  lw	t6,-3536(t7)   ; = D_0035f230
0027bf2c: 24020001  li	v0,1
0027bf30: 85cc0002  lh	t4,2(t6)
0027bf34: 008e2021  addu	a0,a0,t6
0027bf38: 85cd0004  lh	t5,4(t6)
0027bf3c: 808b000e  lb	t3,14(a0)
0027bf40: 018d6023  subu	t4,t4,t5
0027bf44: 298f0000  slti	t7,t4,0
0027bf48: 15600004  bnez	t3,0x27bf5c
0027bf4c: 000f600b  movn	t4,zero,t7
0027bf50: 808f0011  lb	t7,17(a0)
0027bf54: 018f782a  slt	t7,t4,t7
0027bf58: 39e20001  xori	v0,t7,0x1
0027bf5c: 03e00008  jr	ra
0027bf60: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0027bf20(void)`

```c
bool FUN_0027bf20(int param_1)

{
  bool bVar1;
  int iVar2;
  long lVar3;
  
  bVar1 = true;
  iVar2 = param_1 * 8 + DAT_0035f230;
  lVar3 = (long)((int)*(short *)(DAT_0035f230 + 2) - (int)*(short *)(DAT_0035f230 + 4));
  if (lVar3 < 0) {
    lVar3 = 0;
  }
  if (*(char *)(iVar2 + 0xe) == '\0') {
    bVar1 = *(char *)(iVar2 + 0x11) <= lVar3;
  }
  return bVar1;
}
```

## Earlier attempts (newest first)

- 6 differing words, 68/68 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_03_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_03_1.cpp`)
