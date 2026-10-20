# Target packet 001ca950

- Range: `001ca950`..`001ca988`, **56 bytes = 14 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ca950`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001c6fa8` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_workerbacklog_recovered_001ca988.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ca950: 27bdffe0  addiu	sp,sp,-32
001ca954: ffb00000  sd	s0,0(sp)
001ca958: ffb10008  sd	s1,8(sp)
001ca95c: ffbf0010  sd	ra,16(sp)
001ca960: 0080802d  move	s0,a0
001ca964: 0c071bea  jal	0x1c6fa8
001ca968: 0120882d  move	s1,t1
001ca96c: ae110054  sw	s1,84(s0)
001ca970: ae000058  sw	zero,88(s0)
001ca974: dfb10008  ld	s1,8(sp)
001ca978: dfb00000  ld	s0,0(sp)
001ca97c: dfbf0010  ld	ra,16(sp)
001ca980: 03e00008  jr	ra
001ca984: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ca950(void)`

```c
void FUN_001ca950(int param_1)

{
  undefined4 in_t1_lo;
  
  FUN_001c6fa8();
  *(undefined4 *)(param_1 + 0x54) = in_t1_lo;
  *(undefined4 *)(param_1 + 0x58) = 0;
  return;
}
```

## Earlier attempts (newest first)

- none found
