# Target packet 001e7cc0

- Range: `001e7cc0`..`001e7d20`, **96 bytes = 24 instructions**. This size is the acceptance size.
- Layout name: `FUN_001e7cc0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001e7798` registry: `func_001e7798`
  - accepted sources that already call it (copy their declaration): `fm_primary_orchde_recovered_001e7798.cpp`, `fm_primary_workerbacklog_recovered_001e6c00.cpp`, `fm_primary_workerbacklog_recovered_001ea928.cpp`
- `001e7be0` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001e7cc0: 27bdffe0  addiu	sp,sp,-32
001e7cc4: ffb10008  sd	s1,8(sp)
001e7cc8: ffb00000  sd	s0,0(sp)
001e7ccc: ffbf0010  sd	ra,16(sp)
001e7cd0: 0080882d  move	s1,a0
001e7cd4: 8c840074  lw	a0,116(a0)
001e7cd8: 50800006  beqzl	a0,0x1e7cf4
001e7cdc: ae200074  sw	zero,116(s1)
001e7ce0: 0c079ef8  jal	0x1e7be0
001e7ce4: 8c900000  lw	s0,0(a0)
001e7ce8: 1600fffd  bnez	s0,0x1e7ce0
001e7cec: 0200202d  move	a0,s0
001e7cf0: ae200074  sw	zero,116(s1)
001e7cf4: 8e250080  lw	a1,128(s1)
001e7cf8: 10a00004  beqz	a1,0x1e7d0c
001e7cfc: 3c0f01da  lui	t7,0x1da
001e7d00: 0c079de6  jal	0x1e7798
001e7d04: 8de4e6e4  lw	a0,-6428(t7)   ; = D_01d9e6e4
001e7d08: ae200080  sw	zero,128(s1)
001e7d0c: dfb00000  ld	s0,0(sp)
001e7d10: dfb10008  ld	s1,8(sp)
001e7d14: dfbf0010  ld	ra,16(sp)
001e7d18: 03e00008  jr	ra
001e7d1c: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001e7cc0(void)`

```c
void FUN_001e7cc0(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x74);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(param_1 + 0x74) = 0;
  }
  else {
    do {
      piVar1 = (int *)*piVar1;
      FUN_001e7be0();
    } while (piVar1 != (int *)0x0);
    *(undefined4 *)(param_1 + 0x74) = 0;
  }
  if (*(int *)(param_1 + 0x80) != 0) {
    FUN_001e7798(DAT_01d9e6e4);
    *(undefined4 *)(param_1 + 0x80) = 0;
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
