# Target packet 0018ca48

- Range: `0018ca48`..`0018ca80`, **56 bytes = 14 instructions**. This size is the acceptance size.
- Layout name: `FUN_0018ca48`
- Registry names for this address: `_ZN2YS6DAMAGE15GetReactionTypeEi`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0018ca48: 2c8f0013  sltiu	t7,a0,19
0018ca4c: 11e0000a  beqz	t7,0x18ca78
0018ca50: 0080102d  move	v0,a0
0018ca54: 3c0e0037  lui	t6,0x37
0018ca58: 00047880  sll	t7,a0,0x2
0018ca5c: 25cecc28  addiu	t6,t6,-13272   ; = D_0036cc28
0018ca60: 01ee7821  addu	t7,t7,t6
0018ca64: 8ded0000  lw	t5,0(t7)
0018ca68: 01a00008  jr	t5
0018ca6c: 00000000  nop
0018ca70: 03e00008  jr	ra
0018ca74: 24020001  li	v0,1
0018ca78: 03e00008  jr	ra
0018ca7c: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0018ca48(void)`

```c
ulong FUN_0018ca48(ulong param_1)

{
  if (param_1 < 0x13) {
                    /* WARNING: Switch is manually overridden */
    switch((int)param_1) {
    case 1:
      return 1;
    case 3:
      return 3;
    case 4:
      return 4;
    }
  }
  return param_1;
}
```

## Earlier attempts (newest first)

- none found
