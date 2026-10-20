# Target packet 0022f4f0

- Range: `0022f4f0`..`0022f528`, **56 bytes = 14 instructions**. This size is the acceptance size.
- Layout name: `FUN_0022f4f0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0022f4f0: 3c0f0036  lui	t7,0x36
0022f4f4: 0000682d  move	t5,zero
0022f4f8: 8deedcfc  lw	t6,-8964(t7)   ; = D_0035dcfc
0022f4fc: 8dcf0000  lw	t7,0(t6)
0022f500: 25c20017  addiu	v0,t6,23
0022f504: 11e40006  beq	t7,a0,0x22f520
0022f508: 25ce0028  addiu	t6,t6,40
0022f50c: 25ad0001  addiu	t5,t5,1
0022f510: 29af0060  slti	t7,t5,96
0022f514: 55e0fffa  bnezl	t7,0x22f500
0022f518: 8dcf0000  lw	t7,0(t6)
0022f51c: 0000102d  move	v0,zero
0022f520: 03e00008  jr	ra
0022f524: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0022f4f0(void)`

```c
int FUN_0022f4f0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = 0;
  iVar4 = *DAT_0035dcfc;
  piVar3 = DAT_0035dcfc;
  while( true ) {
    iVar1 = (int)piVar3 + 0x17;
    piVar3 = piVar3 + 10;
    if (iVar4 == param_1) {
      return iVar1;
    }
    iVar2 = iVar2 + 1;
    if (0x5f < iVar2) break;
    iVar4 = *piVar3;
  }
  return 0;
}
```

## Earlier attempts (newest first)

- 9 differing words, 56/56 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_03_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_03_0.cpp`)
