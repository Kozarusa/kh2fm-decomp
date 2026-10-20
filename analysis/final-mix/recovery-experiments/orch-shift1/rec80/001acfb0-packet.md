# Target packet 001acfb0

- Range: `001acfb0`..`001ad020`, **112 bytes = 28 instructions**. This size is the acceptance size.
- Layout name: `FUN_001acfb0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00239bf8` registry: `_Z16wtarget_00239bf8jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001acfb0: 27bdfff0  addiu	sp,sp,-16
001acfb4: ffbf0000  sd	ra,0(sp)
001acfb8: 8c8f01dc  lw	t7,476(a0)
001acfbc: 10af0016  beq	a1,t7,0x1ad018
001acfc0: dfbf0000  ld	ra,0(sp)
001acfc4: ac8501dc  sw	a1,476(a0)
001acfc8: 8c8f0070  lw	t7,112(a0)
001acfcc: 15e0000a  bnez	t7,0x1acff8
001acfd0: 00057040  sll	t6,a1,0x1
001acfd4: dfbf0000  ld	ra,0(sp)
001acfd8: 3c0f0035  lui	t7,0x35
001acfdc: 01c57021  addu	t6,t6,a1
001acfe0: 25ef0a38  addiu	t7,t7,2616   ; = D_00350a38
001acfe4: 24840084  addiu	a0,a0,132
001acfe8: 01cf7021  addu	t6,t6,t7
001acfec: 91c50000  lbu	a1,0(t6)
001acff0: 0808e6fe  j	0x239bf8
001acff4: 27bd0010  addiu	sp,sp,16
001acff8: 3c0f0035  lui	t7,0x35
001acffc: 01c57021  addu	t6,t6,a1
001ad000: 25ef0a38  addiu	t7,t7,2616   ; = D_00350a38
001ad004: 01cf7021  addu	t6,t6,t7
001ad008: 24840084  addiu	a0,a0,132
001ad00c: 0c08e6fe  jal	0x239bf8
001ad010: 91c50001  lbu	a1,1(t6)
001ad014: dfbf0000  ld	ra,0(sp)
001ad018: 03e00008  jr	ra
001ad01c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001acfb0(void)`

```c
void FUN_001acfb0(int param_1,int param_2)

{
  if (param_2 != *(int *)(param_1 + 0x1dc)) {
    *(int *)(param_1 + 0x1dc) = param_2;
    if (*(int *)(param_1 + 0x70) == 0) {
      FUN_00239bf8(param_1 + 0x84,s_CDEFGHIJKLMNOPQRSTUVWXYZ_______00350a38[param_2 * 3]);
      return;
    }
    FUN_00239bf8(param_1 + 0x84,s_CDEFGHIJKLMNOPQRSTUVWXYZ_______00350a38[param_2 * 3 + 1]);
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
