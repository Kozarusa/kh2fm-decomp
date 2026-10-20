# Target packet 001d6e60

- Range: `001d6e60`..`001d6ec4`, **100 bytes = 25 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d6e60`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001d6da8` registry: `func_001d6da8`
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_oneword_recovered_001bf0c8.cpp`, `fm_primary_twoword_recovered_001b2488.cpp`, `fm_primary_twoword_recovered_001ba310.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d6e60: 27bdffc0  addiu	sp,sp,-64
001d6e64: 3c0e01d6  lui	t6,0x1d6
001d6e68: ffb00020  sd	s0,32(sp)
001d6e6c: ffbe0028  sd	s8,40(sp)
001d6e70: ffbf0030  sd	ra,48(sp)
001d6e74: 03a0802d  move	s0,sp
001d6e78: 03a0f02d  move	s8,sp
001d6e7c: 8dcdba98  lw	t5,-17768(t6)   ; = D_01d5ba98
001d6e80: 8daf0004  lw	t7,4(t5)
001d6e84: 000f7840  sll	t7,t7,0x1
001d6e88: 25ef0011  addiu	t7,t7,17
001d6e8c: 000f7902  srl	t7,t7,0x4
001d6e90: 000f7900  sll	t7,t7,0x4
001d6e94: 03afe823  subu	sp,sp,t7
001d6e98: 0c075b6a  jal	0x1d6da8
001d6e9c: 03a0202d  move	a0,sp
001d6ea0: 97a20000  lhu	v0,0(sp)
001d6ea4: 0200e82d  move	sp,s0
001d6ea8: 0002102b  sltu	v0,zero,v0
001d6eac: 03c0e82d  move	sp,s8
001d6eb0: dfb00020  ld	s0,32(sp)
001d6eb4: dfbe0028  ld	s8,40(sp)
001d6eb8: dfbf0030  ld	ra,48(sp)
001d6ebc: 03e00008  jr	ra
001d6ec0: 27bd0040  addiu	sp,sp,64
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d6e60(void)`

```c
bool FUN_001d6e60(void)

{
  uint uVar1;
  short asStack_40 [16];
  
  uVar1 = *(int *)(DAT_01d5ba98 + 4) * 2 + 0x11U >> 4;
  FUN_001d6da8(asStack_40 + uVar1 * -8);
  return asStack_40[uVar1 * -8] != 0;
}
```

## Earlier attempts (newest first)

- none found
