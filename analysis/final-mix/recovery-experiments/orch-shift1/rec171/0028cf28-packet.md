# Target packet 0028cf28

- Range: `0028cf28`..`0028cf98`, **112 bytes = 28 instructions**. This size is the acceptance size.
- Layout name: `FUN_0028cf28`
- Registry names for this address: `func_0028cf28`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001396b0` registry: `Tz::Select::BeginLeave(...)`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`
- `0031a260` registry: `Tz::Select::SetFlag(...)`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0028cf28: 240f0198  li	t7,408
0028cf2c: 27bdfff0  addiu	sp,sp,-16
0028cf30: 008f2018  mult	a0,a0,t7
0028cf34: ffb00000  sd	s0,0(sp)
0028cf38: 3c0e0036  lui	t6,0x36
0028cf3c: ffbf0008  sd	ra,8(sp)
0028cf40: 8dcff3fc  lw	t7,-3076(t6)   ; = D_0035f3fc
0028cf44: 01e48021  addu	s0,t7,a0
0028cf48: ae05018c  sw	a1,396(s0)
0028cf4c: 0c04e5ac  jal	0x1396b0
0028cf50: 0200202d  move	a0,s0
0028cf54: 8e0f018c  lw	t7,396(s0)
0028cf58: 11e0000b  beqz	t7,0x28cf88
0028cf5c: 0200202d  move	a0,s0
0028cf60: 0c04e5ac  jal	0x1396b0
0028cf64: ae000190  sw	zero,400(s0)
0028cf68: 8e0f0190  lw	t7,400(s0)
0028cf6c: 0200202d  move	a0,s0
0028cf70: 11e00005  beqz	t7,0x28cf88
0028cf74: 0000282d  move	a1,zero
0028cf78: dfb00000  ld	s0,0(sp)
0028cf7c: dfbf0008  ld	ra,8(sp)
0028cf80: 080c6898  j	0x31a260
0028cf84: 27bd0010  addiu	sp,sp,16
0028cf88: dfb00000  ld	s0,0(sp)
0028cf8c: dfbf0008  ld	ra,8(sp)
0028cf90: 03e00008  jr	ra
0028cf94: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0028cf28(void)`

```c
void FUN_0028cf28(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = DAT_0035f3fc + param_1 * 0x198;
  *(undefined4 *)(iVar1 + 0x18c) = param_2;
  FUN_001396b0(iVar1);
  if (*(int *)(iVar1 + 0x18c) != 0) {
    *(undefined4 *)(iVar1 + 400) = 0;
    FUN_001396b0(iVar1);
    if (*(int *)(iVar1 + 400) != 0) {
      FUN_0031a260(iVar1,0);
      return;
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
