# Target packet 00261ce8

- Range: `00261ce8`..`00261d44`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_00261ce8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00257130` registry: `_ZN2Tz5CmTop11GetItemInfoEv`
- `00281198` registry: `_ZN2Tz9PartyInfo8GetPartyEi`
- `00282240` registry: none
- `002827f0` registry: `func_002827f0`
  - accepted sources that already call it (copy their declaration): `fm_scalar_extra_recovered_07.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00261ce8: 27bdfff0  addiu	sp,sp,-16
00261cec: 3c0f0036  lui	t7,0x36
00261cf0: 0080282d  move	a1,a0
00261cf4: ffbf0008  sd	ra,8(sp)
00261cf8: 8de4f010  lw	a0,-4080(t7)   ; = D_0035f010
00261cfc: ffb00000  sd	s0,0(sp)
00261d00: 0c0a0466  jal	0x281198
00261d04: 00000000  nop
00261d08: 0c095c4c  jal	0x257130
00261d0c: 24500005  addiu	s0,v0,5
00261d10: 0200282d  move	a1,s0
00261d14: 0040202d  move	a0,v0
00261d18: 0c0a0890  jal	0x282240
00261d1c: 0000302d  move	a2,zero
00261d20: 0c095c4c  jal	0x257130
00261d24: 00000000  nop
00261d28: dfb00000  ld	s0,0(sp)
00261d2c: 0040202d  move	a0,v0
00261d30: dfbf0008  ld	ra,8(sp)
00261d34: 0000282d  move	a1,zero
00261d38: 0000302d  move	a2,zero
00261d3c: 080a09fc  j	0x2827f0
00261d40: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00261ce8(void)`

```c
void FUN_00261ce8(undefined8 param_1)

{
  undefined8 uVar1;
  int iVar2;
  
  iVar2 = FUN_00281198(DAT_0035f010,param_1);
  uVar1 = FUN_00257130();
  FUN_00282240(uVar1,iVar2 + 5,0);
  uVar1 = FUN_00257130();
  FUN_002827f0(uVar1,0,0);
  return;
}
```

## Earlier attempts (newest first)

- none found
