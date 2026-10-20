# Target packet 001cbeb8

- Range: `001cbeb8`..`001cbf1c`, **100 bytes = 25 instructions**. This size is the acceptance size.
- Layout name: `FUN_001cbeb8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001cbc50` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001cbeb8: 27bdfff0  addiu	sp,sp,-16
001cbebc: 3c0f0035  lui	t7,0x35
001cbec0: ffbf0000  sd	ra,0(sp)
001cbec4: 0080302d  move	a2,a0
001cbec8: 0000682d  move	t5,zero
001cbecc: 8dee1fe4  lw	t6,8164(t7)   ; = D_00351fe4
001cbed0: 00057900  sll	t7,a1,0x4
001cbed4: 11c0000d  beqz	t6,0x1cbf0c
001cbed8: 01c0202d  move	a0,t6
001cbedc: 3c050037  lui	a1,0x37
001cbee0: 0000382d  move	a3,zero
001cbee4: 24a5e180  addiu	a1,a1,-7808   ; = D_0036e180
001cbee8: 0c072f14  jal	0x1cbc50
001cbeec: 01e52821  addu	a1,t7,a1
001cbef0: 8c4e0028  lw	t6,40(v0)
001cbef4: 3c0f001d  lui	t7,0x1d
001cbef8: 25efba90  addiu	t7,t7,-17776   ; = D_001cba90
001cbefc: 0040682d  move	t5,v0
001cbf00: 35ce0003  ori	t6,t6,0x3
001cbf04: ac4f0010  sw	t7,16(v0)
001cbf08: ac4e0028  sw	t6,40(v0)
001cbf0c: dfbf0000  ld	ra,0(sp)
001cbf10: 01a0102d  move	v0,t5
001cbf14: 03e00008  jr	ra
001cbf18: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001cbeb8(void)`

```c
undefined8 FUN_001cbeb8(undefined8 param_1,int param_2)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = 0;
  if (DAT_00351fe4 != 0) {
    uVar2 = FUN_001cbc50(DAT_00351fe4,param_2 * 0x10 + 0x36e180,param_1,0);
    iVar1 = (int)uVar2;
    *(undefined1 **)(iVar1 + 0x10) = &LAB_001cba90;
    *(uint *)(iVar1 + 0x28) = *(uint *)(iVar1 + 0x28) | 3;
  }
  return uVar2;
}
```

## Earlier attempts (newest first)

- none found
