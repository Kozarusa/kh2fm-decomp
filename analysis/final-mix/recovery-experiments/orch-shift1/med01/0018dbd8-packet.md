# Target packet 0018dbd8

- Range: `0018dbd8`..`0018dc28`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_0018dbd8`
- Registry names for this address: `_ZN2YS6ATTACK6is_hitEv`
- Queue: state `leased`, queue `medium-register-and-branch`, attempts 3, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\eight-hour-20261011\\0018dbd8-medium-blocker.md", "sha256": "2563419d9ad9cb4baa5a3f6636578a1eba29a201d1a18e9186648613a1bb5db2", "hypothesis": "Focused source family still differs in native scheduling, register allocation or branch layout; see immutable probe census."}`

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0018dbd8: 8c8e0004  lw	t6,4(a0)
0018dbdc: 0000102d  move	v0,zero
0018dbe0: 31cf0002  andi	t7,t6,0x2
0018dbe4: 15e0000d  bnez	t7,0x18dc1c
0018dbe8: 31cd0008  andi	t5,t6,0x8
0018dbec: 15a00004  bnez	t5,0x18dc00
0018dbf0: 0000602d  move	t4,zero
0018dbf4: 31cf0010  andi	t7,t6,0x10
0018dbf8: 11e00003  beqz	t7,0x18dc08
0018dbfc: 318f00ff  andi	t7,t4,0xff
0018dc00: 240c0001  li	t4,1
0018dc04: 318f00ff  andi	t7,t4,0xff
0018dc08: 55e00005  bnezl	t7,0x18dc20
0018dc0c: 24020001  li	v0,1
0018dc10: 31cf0200  andi	t7,t6,0x200
0018dc14: 11e00002  beqz	t7,0x18dc20
0018dc18: 00000000  nop
0018dc1c: 24020001  li	v0,1
0018dc20: 03e00008  jr	ra
0018dc24: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0018dbd8(void)`

```c
undefined4 FUN_0018dbd8(int param_1)

{
  uint uVar1;
  bool bVar2;
  
  uVar1 = *(uint *)(param_1 + 4);
  if ((uVar1 & 2) == 0) {
    if (((uVar1 & 8) != 0) || (bVar2 = false, (uVar1 & 0x10) != 0)) {
      bVar2 = true;
    }
    if (bVar2) {
      return 1;
    }
    if ((uVar1 & 0x200) == 0) {
      return 0;
    }
  }
  return 1;
}
```

## Earlier attempts (newest first)

- 11 differing words, 80/80 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_0018dbd8_byte_boolean_result_v3_3.verification.json`
- 11 differing words, 80/80 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_0018dbd8_byte_boolean_result_v3_2.verification.json`
- 11 differing words, 80/80 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_0018dbd8_byte_boolean_result_v3_1.verification.json`
- 11 differing words, 80/80 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_0018dbd8_byte_boolean_result_v3_0.verification.json`
- 19 differing words, 76/80 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_0018dbd8_byte_boolean_lifetime_v2_3.verification.json`
- 19 differing words, 76/80 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_0018dbd8_byte_boolean_lifetime_v2_2.verification.json`
- 18 differing words, 64/80 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_0018dbd8_byte_boolean_lifetime_v2_1.verification.json`
- 18 differing words, 64/80 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_0018dbd8_byte_boolean_lifetime_v2_0.verification.json`
- 18 differing words, 64/80 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_0018dbd8_medium_scalar_v1_1.verification.json`
- 19 differing words, 48/80 bytes: `analysis/final-mix/recovery-experiments/eight-hour-20261011/eight_hour_0018dbd8_medium_scalar_v1_0.verification.json`
- report: `analysis/final-mix/recovery-experiments/eight-hour-20261011/0018dbd8-medium-blocker.md`
