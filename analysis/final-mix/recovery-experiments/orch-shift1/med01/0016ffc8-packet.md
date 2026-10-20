# Target packet 0016ffc8

- Range: `0016ffc8`..`00170018`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_0016ffc8`
- Registry names for this address: none
- Queue: state `leased`, queue `medium-register-and-branch`, attempts 3, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\eight-hour-20261011\\0016ffc8-medium-blocker.md", "sha256": "bcb3fca6160aa8de337ce62e5f80537ea68a03e47cffb20802738cf045fa9faf", "hypothesis": "Focused source family still differs in native scheduling, register allocation or branch layout; see immutable probe census."}`

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0016ffc8: 8c8d0028  lw	t5,40(a0)
0016ffcc: 05a10010  bgez	t5,0x170010
0016ffd0: 01a0102d  move	v0,t5
0016ffd4: 908f0000  lbu	t7,0(a0)
0016ffd8: 15e0000d  bnez	t7,0x170010
0016ffdc: 00000000  nop
0016ffe0: 8c840038  lw	a0,56(a0)
0016ffe4: 248ff704  addiu	t7,a0,-2300
0016ffe8: 248ef696  addiu	t6,a0,-2410
0016ffec: 2def0064  sltiu	t7,t7,100
0016fff0: 0080102d  move	v0,a0
0016fff4: 15e00006  bnez	t7,0x170010
0016fff8: 2dce000a  sltiu	t6,t6,10
0016fffc: 15c00004  bnez	t6,0x170010
00170000: 248ff68c  addiu	t7,a0,-2420
00170004: 2def000a  sltiu	t7,t7,10
00170008: 51e00001  beqzl	t7,0x170010
0017000c: 01a0102d  move	v0,t5
00170010: 03e00008  jr	ra
00170014: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0016ffc8(void)`

```c
int FUN_0016ffc8(char *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x28);
  iVar2 = iVar1;
  if ((iVar1 < 0) && (*param_1 == '\0')) {
    iVar2 = *(int *)(param_1 + 0x38);
    if ((99 < iVar2 - 0x8fcU) && ((9 < iVar2 - 0x96aU && (9 < iVar2 - 0x974U)))) {
      iVar2 = iVar1;
    }
  }
  return iVar2;
}
```

## Earlier attempts (newest first)

- 17 differing words, 72/80 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_0016ffc8_medium_scalar_v1_1.verification.json`
- 13 differing words, 84/80 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_0016ffc8_medium_scalar_v1_0.verification.json`
- report: `analysis/final-mix/recovery-experiments/eight-hour-20261011/0016ffc8-medium-blocker.md`
