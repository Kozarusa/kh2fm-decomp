# Target packet 001db250

- Range: `001db250`..`001db294`, **68 bytes = 17 instructions**. This size is the acceptance size.
- Layout name: `FUN_001db250`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0017d0e8` registry: `_ZN2YS4MATH8RotToDirEf`
  - accepted sources that already call it (copy their declaration): `fm_more_recovered.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_loadorder_recovered.cpp`, `fm_primary_packetnext_recovered.cpp`
- `0019c778` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001db250: 27bdffe0  addiu	sp,sp,-32
001db254: ffbf0010  sd	ra,16(sp)
001db258: 8c8f006c  lw	t7,108(a0)
001db25c: c5e00020  lwc1	$f0,32(t7)
001db260: 03a0202d  move	a0,sp
001db264: 3c0f0037  lui	t7,0x37
001db268: 25efe7a0  addiu	t7,t7,-6240   ; = D_0036e7a0
001db26c: c5ec0000  lwc1	$f12,0(t7)
001db270: 0c05f43a  jal	0x17d0e8
001db274: 46006301  sub.s	$f12,$f12,$f0
001db278: 3c0f0035  lui	t7,0x35
001db27c: 03a0282d  move	a1,sp
001db280: 0c0671de  jal	0x19c778
001db284: 8de4e948  lw	a0,-5816(t7)   ; = D_0034e948
001db288: dfbf0010  ld	ra,16(sp)
001db28c: 03e00008  jr	ra
001db290: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001db250(void)`

```c
void FUN_001db250(int param_1)

{
  undefined1 auStack_20 [16];
  
  FUN_0017d0e8((float)PTR_DAT_0036e7a0 - *(float *)(*(int *)(param_1 + 0x6c) + 0x20),auStack_20);
  FUN_0019c778(DAT_0034e948,auStack_20);
  return;
}
```

## Earlier attempts (newest first)

- none found
