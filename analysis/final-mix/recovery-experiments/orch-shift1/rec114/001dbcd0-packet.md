# Target packet 001dbcd0

- Range: `001dbcd0`..`001dbd38`, **104 bytes = 26 instructions**. This size is the acceptance size.
- Layout name: `FUN_001dbcd0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0016c028` registry: `func_0016c028`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`
- `0019ba60` registry: `_Z16ctarget_0019ba60jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001dbcd0: 27bdfff0  addiu	sp,sp,-16
001dbcd4: ffb00000  sd	s0,0(sp)
001dbcd8: ffbf0008  sd	ra,8(sp)
001dbcdc: 3c100035  lui	s0,0x35
001dbce0: 0c066e98  jal	0x19ba60
001dbce4: 8e04e948  lw	a0,-5816(s0)   ; = D_0034e948
001dbce8: 1040000a  beqz	v0,0x1dbd14
001dbcec: 3c0e0035  lui	t6,0x35
001dbcf0: 0c05b00a  jal	0x16c028
001dbcf4: 8e04e948  lw	a0,-5816(s0)   ; = D_0034e948
001dbcf8: 3c0f01d6  lui	t7,0x1d6
001dbcfc: 25efbab0  addiu	t7,t7,-17744   ; = D_01d5bab0
001dbd00: 104f0004  beq	v0,t7,0x1dbd14
001dbd04: 3c0e0035  lui	t6,0x35
001dbd08: 78480000  lq	t0,0(v0)
001dbd0c: 7de80000  sq	t0,0(t7)
001dbd10: 3c0e0035  lui	t6,0x35
001dbd14: dfb00000  ld	s0,0(sp)
001dbd18: 3c0f0035  lui	t7,0x35
001dbd1c: c5c02ad0  lwc1	$f0,10960(t6)   ; = D_00352ad0
001dbd20: c5e19e10  lwc1	$f1,-25072(t7)   ; = D_00349e10
001dbd24: dfbf0008  ld	ra,8(sp)
001dbd28: 46010001  sub.s	$f0,$f0,$f1
001dbd2c: e5c02ad0  swc1	$f0,10960(t6)   ; = D_00352ad0
001dbd30: 03e00008  jr	ra
001dbd34: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001dbcd0(void)`

```c
void FUN_001dbcd0(void)

{
  undefined4 *puVar1;
  long lVar2;
  
  lVar2 = FUN_0019ba60(DAT_0034e948);
  if ((lVar2 != 0) &&
     (lVar2 = FUN_0016c028(DAT_0034e948), puVar1 = (undefined4 *)lVar2, lVar2 != 0x1d5bab0)) {
    DAT_01d5bab0 = *puVar1;
    DAT_01d5bab4 = puVar1[1];
    DAT_01d5bab8 = puVar1[2];
    DAT_01d5babc = puVar1[3];
  }
  DAT_00352ad0 = DAT_00352ad0 - DAT_00349e10;
  return;
}
```

## Earlier attempts (newest first)

- none found
