# Target packet 001d7a08

- Range: `001d7a08`..`001d7a4c`, **68 bytes = 17 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d7a08`
- Registry names for this address: `_Z16wtarget_001d7a08jjjj`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001d7b10` registry: `func_001d7b10`
  - accepted sources that already call it (copy their declaration): `fm_primary_argument_recovered.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_oneword_recovered_001c8710.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d7a08: 27bdfff0  addiu	sp,sp,-16
001d7a0c: 0080702d  move	t6,a0
001d7a10: ffbf0000  sd	ra,0(sp)
001d7a14: 240d0003  li	t5,3
001d7a18: 8dcf0004  lw	t7,4(t6)
001d7a1c: 15e50006  bne	t7,a1,0x1d7a38
001d7a20: 25adffff  addiu	t5,t5,-1
001d7a24: adc00004  sw	zero,4(t6)
001d7a28: dfbf0000  ld	ra,0(sp)
001d7a2c: 08075ec4  j	0x1d7b10
001d7a30: 27bd0010  addiu	sp,sp,16
001d7a34: 00000000  nop
001d7a38: 05a1fff7  bgez	t5,0x1d7a18
001d7a3c: 25ce0008  addiu	t6,t6,8
001d7a40: dfbf0000  ld	ra,0(sp)
001d7a44: 03e00008  jr	ra
001d7a48: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d7a08(void)`

```c
void FUN_001d7a08(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 3;
  do {
    iVar1 = iVar1 + -1;
    if (*(int *)(param_1 + 4) == param_2) {
      *(undefined4 *)(param_1 + 4) = 0;
      FUN_001d7b10();
      return;
    }
    param_1 = param_1 + 8;
  } while (-1 < iVar1);
  return;
}
```

## Earlier attempts (newest first)

- none found
