# Target packet 001dffd8

- Range: `001dffd8`..`001e0054`, **124 bytes = 31 instructions**. This size is the acceptance size.
- Layout name: `FUN_001dffd8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0019ba60` registry: `_Z16ctarget_0019ba60jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001dffd8: 27bdffe0  addiu	sp,sp,-32
001dffdc: 3c0f0035  lui	t7,0x35
001dffe0: ffb00000  sd	s0,0(sp)
001dffe4: 0000102d  move	v0,zero
001dffe8: ffb10008  sd	s1,8(sp)
001dffec: ffbf0010  sd	ra,16(sp)
001dfff0: 8dee2b50  lw	t6,11088(t7)   ; = D_00352b50
001dfff4: 240f0001  li	t7,1
001dfff8: 15cf0011  bne	t6,t7,0x1e0040
001dfffc: 0080802d  move	s0,a0
001e0000: 8c840048  lw	a0,72(a0)
001e0004: 0c066e98  jal	0x19ba60
001e0008: 0000882d  move	s1,zero
001e000c: 1040000a  beqz	v0,0x1e0038
001e0010: 3c0f2000  lui	t7,0x2000
001e0014: 8e040048  lw	a0,72(s0)
001e0018: 8c8e0160  lw	t6,352(a0)
001e001c: 01cf7024  and	t6,t6,t7
001e0020: 55c00006  bnezl	t6,0x1e003c
001e0024: 24110001  li	s1,1
001e0028: 8c8f010c  lw	t7,268(a0)
001e002c: 31ef0400  andi	t7,t7,0x400
001e0030: 11e00003  beqz	t7,0x1e0040
001e0034: 0220102d  move	v0,s1
001e0038: 24110001  li	s1,1
001e003c: 0220102d  move	v0,s1
001e0040: dfb00000  ld	s0,0(sp)
001e0044: dfb10008  ld	s1,8(sp)
001e0048: dfbf0010  ld	ra,16(sp)
001e004c: 03e00008  jr	ra
001e0050: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001dffd8(void)`

```c
undefined4 FUN_001dffd8(int param_1)

{
  undefined4 uVar1;
  long lVar2;
  
  uVar1 = 0;
  if ((DAT_00352b50 == 1) &&
     (((lVar2 = FUN_0019ba60(*(undefined4 *)(param_1 + 0x48)), lVar2 == 0 ||
       ((*(uint *)(*(int *)(param_1 + 0x48) + 0x160) & 0x20000000) != 0)) ||
      (uVar1 = 0, (*(uint *)(*(int *)(param_1 + 0x48) + 0x10c) & 0x400) != 0)))) {
    uVar1 = 1;
  }
  return uVar1;
}
```

## Earlier attempts (newest first)

- none found
