# Target packet 0010ce78

- Range: `0010ce78`..`0010cef0`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_0010ce78`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00190140` registry: `_ZNK2YS6TARGET8is_existEv`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_fiveword_recovered_0017a8f8.cpp`, `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0010ce78: 27bdffe0  addiu	sp,sp,-32
0010ce7c: ffb00000  sd	s0,0(sp)
0010ce80: ffb20010  sd	s2,16(sp)
0010ce84: ffb10008  sd	s1,8(sp)
0010ce88: 3c100034  lui	s0,0x34
0010ce8c: ffbf0018  sd	ra,24(sp)
0010ce90: 0080902d  move	s2,a0
0010ce94: 260417b0  addiu	a0,s0,6064   ; = D_003417b0
0010ce98: 0c064050  jal	0x190140
0010ce9c: 0000882d  move	s1,zero
0010cea0: 10400003  beqz	v0,0x10ceb0
0010cea4: 0000702d  move	t6,zero
0010cea8: 8e0f17b0  lw	t7,6064(s0)   ; = D_003417b0
0010ceac: 000f882b  sltu	s1,zero,t7
0010ceb0: 322f00ff  andi	t7,s1,0xff
0010ceb4: 11e00007  beqz	t7,0x10ced4
0010ceb8: 8e0417b0  lw	a0,6064(s0)   ; = D_003417b0
0010cebc: 10800005  beqz	a0,0x10ced4
0010cec0: 240e0001  li	t6,1
0010cec4: 8e4f09f4  lw	t7,2548(s2)
0010cec8: 11e40002  beq	t7,a0,0x10ced4
0010cecc: 0000702d  move	t6,zero
0010ced0: 240e0001  li	t6,1
0010ced4: dfb00000  ld	s0,0(sp)
0010ced8: 01c0102d  move	v0,t6
0010cedc: dfb10008  ld	s1,8(sp)
0010cee0: dfb20010  ld	s2,16(sp)
0010cee4: dfbf0018  ld	ra,24(sp)
0010cee8: 03e00008  jr	ra
0010ceec: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0010ce78(void)`

```c
undefined4 FUN_0010ce78(int param_1)

{
  long lVar1;
  undefined4 uVar2;
  
  lVar1 = FUN_00190140(0x3417b0);
  uVar2 = 0;
  if (((lVar1 != 0 && DAT_003417b0 != 0) && (uVar2 = 1, DAT_003417b0 != 0)) &&
     (uVar2 = 0, *(int *)(param_1 + 0x9f4) != DAT_003417b0)) {
    uVar2 = 1;
  }
  return uVar2;
}
```

## Earlier attempts (newest first)

- none found
