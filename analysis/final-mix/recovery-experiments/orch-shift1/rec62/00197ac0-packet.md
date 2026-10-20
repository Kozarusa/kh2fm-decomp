# Target packet 00197ac0

- Range: `00197ac0`..`00197af4`, **52 bytes = 13 instructions**. This size is the acceptance size.
- Layout name: `FUN_00197ac0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001024a8` registry: `printf(void*)`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_more_recovered.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_flagguard_recovered_00157160.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`
- `001d3148` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00197ac0: 27bdfff0  addiu	sp,sp,-16
00197ac4: 3c0f0035  lui	t7,0x35
00197ac8: ffbf0000  sd	ra,0(sp)
00197acc: 8dee037c  lw	t6,892(t7)   ; = D_0035037c
00197ad0: 11c00005  beqz	t6,0x197ae8
00197ad4: 25cf0040  addiu	t7,t6,64
00197ad8: dfbf0000  ld	ra,0(sp)
00197adc: 01e0202d  move	a0,t7
00197ae0: 08074c52  j	0x1d3148
00197ae4: 27bd0010  addiu	sp,sp,16
00197ae8: dfbf0000  ld	ra,0(sp)
00197aec: 0804092a  j	0x1024a8
00197af0: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00197ac0(void)`

```c
void FUN_00197ac0(void)

{
  if (DAT_0035037c != 0) {
    FUN_001d3148(DAT_0035037c + 0x40);
    return;
  }
  FUN_001024a8();
  return;
}
```

## Earlier attempts (newest first)

- none found
