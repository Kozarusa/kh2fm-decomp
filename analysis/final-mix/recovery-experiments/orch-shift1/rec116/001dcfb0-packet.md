# Target packet 001dcfb0

- Range: `001dcfb0`..`001dcfec`, **60 bytes = 15 instructions**. This size is the acceptance size.
- Layout name: `FUN_001dcfb0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001dc878` registry: `_ZN3ryj6EFFECT4freeEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_threewordnext_recovered_0019e6e8.cpp`, `fm_scalar_extra_recovered_03.cpp`, `fm_scalar_recovered_03.cpp`, `fm_scalar_recovered_05.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001dcfb0: 27bdfff0  addiu	sp,sp,-16
001dcfb4: 3c0f0035  lui	t7,0x35
001dcfb8: ffb00000  sd	s0,0(sp)
001dcfbc: ffbf0008  sd	ra,8(sp)
001dcfc0: 8de42ae0  lw	a0,10976(t7)   ; = D_00352ae0
001dcfc4: 10800006  beqz	a0,0x1dcfe0
001dcfc8: dfb00000  ld	s0,0(sp)
001dcfcc: 0c07721e  jal	0x1dc878
001dcfd0: 8c900028  lw	s0,40(a0)
001dcfd4: 1600fffd  bnez	s0,0x1dcfcc
001dcfd8: 0200202d  move	a0,s0
001dcfdc: dfb00000  ld	s0,0(sp)
001dcfe0: dfbf0008  ld	ra,8(sp)
001dcfe4: 03e00008  jr	ra
001dcfe8: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001dcfb0(void)`

```c
void FUN_001dcfb0(void)

{
  int iVar1;
  
  iVar1 = DAT_00352ae0;
  while (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 0x28);
    FUN_001dc878();
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
