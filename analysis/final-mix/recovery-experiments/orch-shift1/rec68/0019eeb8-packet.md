# Target packet 0019eeb8

- Range: `0019eeb8`..`0019ef30`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_0019eeb8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00194878` registry: `func_00194878`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0019eeb8: 27bdffe0  addiu	sp,sp,-32
0019eebc: ffb00000  sd	s0,0(sp)
0019eec0: ffb10008  sd	s1,8(sp)
0019eec4: 0080802d  move	s0,a0
0019eec8: ffbf0010  sd	ra,16(sp)
0019eecc: 00a0882d  move	s1,a1
0019eed0: 00a0202d  move	a0,a1
0019eed4: 0c06521e  jal	0x194878
0019eed8: 0200282d  move	a1,s0
0019eedc: 001080c0  sll	s0,s0,0x3
0019eee0: 3c0f0033  lui	t7,0x33
0019eee4: 00117142  srl	t6,s1,0x5
0019eee8: 25efde28  addiu	t7,t7,-8664   ; = D_0032de28
0019eeec: 000e7080  sll	t6,t6,0x2
0019eef0: 020f8021  addu	s0,s0,t7
0019eef4: 3231001f  andi	s1,s1,0x1f
0019eef8: 01d06021  addu	t4,t6,s0
0019eefc: 240f0001  li	t7,1
0019ef00: 240d0001  li	t5,1
0019ef04: 14400004  bnez	v0,0x19ef18
0019ef08: 022f7004  sllv	t6,t7,s1
0019ef0c: 8d8f0000  lw	t7,0(t4)
0019ef10: 01ee7824  and	t7,t7,t6
0019ef14: 000f682b  sltu	t5,zero,t7
0019ef18: dfb00000  ld	s0,0(sp)
0019ef1c: 01a0102d  move	v0,t5
0019ef20: dfb10008  ld	s1,8(sp)
0019ef24: dfbf0010  ld	ra,16(sp)
0019ef28: 03e00008  jr	ra
0019ef2c: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0019eeb8(void)`

```c
bool FUN_0019eeb8(undefined8 param_1,undefined8 param_2)

{
  long lVar1;
  bool bVar2;
  
  lVar1 = FUN_00194878(param_2,param_1);
  bVar2 = true;
  if (lVar1 == 0) {
    bVar2 = ((&DAT_0032de28)[(int)param_1 * 2 + ((uint)param_2 >> 5)] & 1 << ((uint)param_2 & 0x1f))
            != 0;
  }
  return bVar2;
}
```

## Earlier attempts (newest first)

- none found
