# Target packet 00288fd8

- Range: `00288fd8`..`00289034`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_00288fd8`
- Registry names for this address: none
- Queue: state `leased`, queue `abi-layout`, attempts 2, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\rec168\\00288fd8-BLOCKED.md", "sha256": "107f71bb720c8258d0e0c33b49a79ddbeafb7f6130010b6545b8730214b4ea97", "hypothesis": "ABI review of untouched entry-v0 contract"}`

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00288fd8: 000570c0  sll	t6,a1,0x3
00288fdc: 240d0003  li	t5,3
00288fe0: 00052880  sll	a1,a1,0x2
00288fe4: 8c8f002c  lw	t7,44(a0)
00288fe8: 25adffff  addiu	t5,t5,-1
00288fec: 01cf7821  addu	t7,t6,t7
00288ff0: a5e60000  sh	a2,0(t7)
00288ff4: 00000000  nop
00288ff8: 05a1fffa  bgez	t5,0x288fe4
00288ffc: 25ce0002  addiu	t6,t6,2
00289000: 00052840  sll	a1,a1,0x1
00289004: 240d0003  li	t5,3
00289008: 8c8f0030  lw	t7,48(a0)
0028900c: 00e0702d  move	t6,a3
00289010: 00af7821  addu	t7,a1,t7
00289014: 14e00002  bnez	a3,0x289020
00289018: 24a50002  addiu	a1,a1,2
0028901c: 00c0702d  move	t6,a2
00289020: 25adffff  addiu	t5,t5,-1
00289024: 05a1fff8  bgez	t5,0x289008
00289028: a5ee0000  sh	t6,0(t7)
0028902c: 03e00008  jr	ra
00289030: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00288fd8(void)`

```c
void FUN_00288fd8(int param_1,int param_2,ushort param_3,ulong param_4)

{
  int iVar1;
  int iVar2;
  ulong uVar3;
  undefined2 *puVar4;
  
  iVar2 = param_2 << 3;
  iVar1 = 3;
  do {
    iVar1 = iVar1 + -1;
    *(ushort *)(iVar2 + *(int *)(param_1 + 0x2c)) = param_3;
    iVar2 = iVar2 + 2;
  } while (-1 < iVar1);
  param_2 = param_2 << 3;
  iVar1 = 3;
  do {
    puVar4 = (undefined2 *)(param_2 + *(int *)(param_1 + 0x30));
    param_2 = param_2 + 2;
    uVar3 = param_4;
    if (param_4 == 0) {
      uVar3 = (ulong)param_3;
    }
    iVar1 = iVar1 + -1;
    *puVar4 = (short)uVar3;
  } while (-1 < iVar1);
  return;
}
```

## Earlier attempts (newest first)

- 25 differing words, 104/92 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_07.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_07.cpp`)
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec168/00288fd8-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec168/00288fd8-packet.md`
