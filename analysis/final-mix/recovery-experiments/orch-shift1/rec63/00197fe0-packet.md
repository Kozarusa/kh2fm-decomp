# Target packet 00197fe0

- Range: `00197fe0`..`0019803c`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_00197fe0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00169398` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00197fe0: 27bdfff0  addiu	sp,sp,-16
00197fe4: 00a0702d  move	t6,a1
00197fe8: ffb00000  sd	s0,0(sp)
00197fec: 00c0682d  move	t5,a2
00197ff0: ffbf0008  sd	ra,8(sp)
00197ff4: 00e0402d  move	t0,a3
00197ff8: 3c0f4000  lui	t7,0x4000
00197ffc: 0080802d  move	s0,a0
00198000: 8ca50000  lw	a1,0(a1)
00198004: 01c0302d  move	a2,t6
00198008: 01a0382d  move	a3,t5
0019800c: 0c05a4e6  jal	0x169398
00198010: 00af2825  or	a1,a1,t7
00198014: 8e0e0588  lw	t6,1416(s0)
00198018: 3c0f0035  lui	t7,0x35
0019801c: 25ef0388  addiu	t7,t7,904   ; = D_00350388
00198020: dfbf0008  ld	ra,8(sp)
00198024: 35ce0020  ori	t6,t6,0x20
00198028: ae0f0000  sw	t7,0(s0)
0019802c: ae0e0588  sw	t6,1416(s0)
00198030: dfb00000  ld	s0,0(sp)
00198034: 03e00008  jr	ra
00198038: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00197fe0(void)`

```c
void FUN_00197fe0(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4)

{
  undefined4 *puVar1;
  
  FUN_00169398(param_1,*(uint *)param_2 | 0x40000000,param_2,param_3,param_4);
  puVar1 = (undefined4 *)param_1;
  *puVar1 = &PTR_LAB_00350388;
  puVar1[0x162] = puVar1[0x162] | 0x20;
  return;
}
```

## Earlier attempts (newest first)

- none found
