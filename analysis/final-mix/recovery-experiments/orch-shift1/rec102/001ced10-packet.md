# Target packet 001ced10

- Range: `001ced10`..`001ced68`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ced10`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00177dc8` registry: none
- `001d56f0` registry: `func_001d56f0`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ced10: 27bdfff0  addiu	sp,sp,-16
001ced14: 00e0402d  move	t0,a3
001ced18: ffb00000  sd	s0,0(sp)
001ced1c: 00c0382d  move	a3,a2
001ced20: ffbf0008  sd	ra,8(sp)
001ced24: 0000302d  move	a2,zero
001ced28: 0c05df72  jal	0x177dc8
001ced2c: 0080802d  move	s0,a0
001ced30: 3c0f0035  lui	t7,0x35
001ced34: ae000b68  sw	zero,2920(s0)
001ced38: 25ef21e0  addiu	t7,t7,8672   ; = D_003521e0
001ced3c: ae000b70  sw	zero,2928(s0)
001ced40: ae0f0000  sw	t7,0(s0)
001ced44: 0c0755bc  jal	0x1d56f0
001ced48: 26040b74  addiu	a0,s0,2932
001ced4c: 8e0f058c  lw	t7,1420(s0)
001ced50: dfbf0008  ld	ra,8(sp)
001ced54: 35ef0004  ori	t7,t7,0x4
001ced58: ae0f058c  sw	t7,1420(s0)
001ced5c: dfb00000  ld	s0,0(sp)
001ced60: 03e00008  jr	ra
001ced64: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ced10(void)`

```c
void FUN_001ced10(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 *puVar1;
  
  FUN_00177dc8(param_1,param_2,0,param_3,param_4);
  puVar1 = (undefined4 *)param_1;
  puVar1[0x2da] = 0;
  puVar1[0x2dc] = 0;
  *puVar1 = &PTR_LAB_003521e0;
  FUN_001d56f0(puVar1 + 0x2dd);
  puVar1[0x163] = puVar1[0x163] | 4;
  return;
}
```

## Earlier attempts (newest first)

- none found
