# Target packet 0013b9e0

- Range: `0013b9e0`..`0013ba4c`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_0013b9e0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0013ba50` registry: `func_0013ba50`
  - accepted sources that already call it (copy their declaration): `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`, `fm_primary_fourwordfresh_recovered_00140ce8.cpp`, `fm_primary_oneword_recovered_001344b8.cpp`, `fm_primary_order_recovered_00132130.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0013b9e0: 27bdffe0  addiu	sp,sp,-32
0013b9e4: ffb00000  sd	s0,0(sp)
0013b9e8: ffb10008  sd	s1,8(sp)
0013b9ec: ffbf0010  sd	ra,16(sp)
0013b9f0: 00a0802d  move	s0,a1
0013b9f4: 0c04ee94  jal	0x13ba50
0013b9f8: 0080882d  move	s1,a0
0013b9fc: 1440000d  bnez	v0,0x13ba34
0013ba00: 0000682d  move	t5,zero
0013ba04: 16000005  bnez	s0,0x13ba1c
0013ba08: 240f0006  li	t7,6
0013ba0c: 8e2e00ec  lw	t6,236(s1)
0013ba10: 11cf0008  beq	t6,t7,0x13ba34
0013ba14: 240d0001  li	t5,1
0013ba18: 240f0006  li	t7,6
0013ba1c: 160f0005  bne	s0,t7,0x13ba34
0013ba20: 0000682d  move	t5,zero
0013ba24: 8e2f00ec  lw	t7,236(s1)
0013ba28: 11e00002  beqz	t7,0x13ba34
0013ba2c: 240d0001  li	t5,1
0013ba30: 0000682d  move	t5,zero
0013ba34: dfb00000  ld	s0,0(sp)
0013ba38: 01a0102d  move	v0,t5
0013ba3c: dfb10008  ld	s1,8(sp)
0013ba40: dfbf0010  ld	ra,16(sp)
0013ba44: 03e00008  jr	ra
0013ba48: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0013b9e0(void)`

```c
undefined4 FUN_0013b9e0(int param_1,long param_2)

{
  long lVar1;
  undefined4 uVar2;
  
  lVar1 = FUN_0013ba50();
  uVar2 = 0;
  if (((lVar1 == 0) &&
      (((param_2 != 0 || (uVar2 = 1, *(int *)(param_1 + 0xec) != 6)) && (uVar2 = 0, param_2 == 6))))
     && (uVar2 = 1, *(int *)(param_1 + 0xec) != 0)) {
    uVar2 = 0;
  }
  return uVar2;
}
```

## Earlier attempts (newest first)

- none found
