# Target packet 00232db0

- Range: `00232db0`..`00232e14`, **100 bytes = 25 instructions**. This size is the acceptance size.
- Layout name: `FUN_00232db0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00232db0: 0000582d  move	t3,zero
00232db4: 3c090036  lui	t1,0x36
00232db8: 240affff  li	t2,-1
00232dbc: 8d2fdcf8  lw	t7,-8968(t1)   ; = D_0035dcf8
00232dc0: 000b6180  sll	t4,t3,0x6
00232dc4: 256b0001  addiu	t3,t3,1
00232dc8: 018f7021  addu	t6,t4,t7
00232dcc: 8dcf0000  lw	t7,0(t6)
00232dd0: 11ea000c  beq	t7,t2,0x232e04
00232dd4: 296d0040  slti	t5,t3,64
00232dd8: 8dcf0004  lw	t7,4(t6)
00232ddc: 15e40009  bne	t7,a0,0x232e04
00232de0: 00000000  nop
00232de4: adca0000  sw	t2,0(t6)
00232de8: 8d2fdcf8  lw	t7,-8968(t1)   ; = D_0035dcf8
00232dec: 018f7821  addu	t7,t4,t7
00232df0: adea0004  sw	t2,4(t7)
00232df4: 8d2edcf8  lw	t6,-8968(t1)   ; = D_0035dcf8
00232df8: 018e7021  addu	t6,t4,t6
00232dfc: 03e00008  jr	ra
00232e00: adc00008  sw	zero,8(t6)
00232e04: 15a0ffee  bnez	t5,0x232dc0
00232e08: 8d2fdcf8  lw	t7,-8968(t1)   ; = D_0035dcf8
00232e0c: 03e00008  jr	ra
00232e10: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00232db0(void)`

```c
void FUN_00232db0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = 0;
  while( true ) {
    iVar2 = iVar1 * 0x40;
    iVar1 = iVar1 + 1;
    piVar3 = (int *)(iVar2 + DAT_0035dcf8);
    if ((*piVar3 != -1) && (piVar3[1] == param_1)) break;
    if (0x3f < iVar1) {
      return;
    }
  }
  *piVar3 = -1;
  *(undefined4 *)(iVar2 + DAT_0035dcf8 + 4) = 0xffffffff;
  *(undefined4 *)(iVar2 + DAT_0035dcf8 + 8) = 0;
  return;
}
```

## Earlier attempts (newest first)

- 24 differing words, 104/100 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v2_02_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v2_02_0.cpp`)
