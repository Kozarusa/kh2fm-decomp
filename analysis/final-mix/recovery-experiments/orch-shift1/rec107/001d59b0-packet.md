# Target packet 001d59b0

- Range: `001d59b0`..`001d5a1c`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d59b0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001d5960` registry: `func_001d5960`
  - accepted sources that already call it (copy their declaration): `fm_primary_width_recovered_02.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d59b0: 27bdffe0  addiu	sp,sp,-32
001d59b4: ffb20010  sd	s2,16(sp)
001d59b8: ffb10008  sd	s1,8(sp)
001d59bc: 3c1201d6  lui	s2,0x1d6
001d59c0: ffb00000  sd	s0,0(sp)
001d59c4: ffbf0018  sd	ra,24(sp)
001d59c8: 8e44ba6c  lw	a0,-17812(s2)   ; = D_01d5ba6c
001d59cc: 8c8f0004  lw	t7,4(a0)
001d59d0: 19e0000c  blez	t7,0x1d5a04
001d59d4: 0000882d  move	s1,zero
001d59d8: 0000802d  move	s0,zero
001d59dc: 00902021  addu	a0,a0,s0
001d59e0: 26310001  addiu	s1,s1,1
001d59e4: 24840008  addiu	a0,a0,8
001d59e8: 0c075658  jal	0x1d5960
001d59ec: 2610003c  addiu	s0,s0,60
001d59f0: 8e44ba6c  lw	a0,-17812(s2)   ; = D_01d5ba6c
001d59f4: 8c8f0004  lw	t7,4(a0)
001d59f8: 022f782a  slt	t7,s1,t7
001d59fc: 55e0fff8  bnezl	t7,0x1d59e0
001d5a00: 00902021  addu	a0,a0,s0
001d5a04: dfb00000  ld	s0,0(sp)
001d5a08: dfb10008  ld	s1,8(sp)
001d5a0c: dfb20010  ld	s2,16(sp)
001d5a10: dfbf0018  ld	ra,24(sp)
001d5a14: 03e00008  jr	ra
001d5a18: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d59b0(void)`

```c
void FUN_001d59b0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(DAT_01d5ba6c + 4)) {
    iVar2 = 0;
    iVar1 = DAT_01d5ba6c;
    while( true ) {
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 0x3c;
      FUN_001d5960(iVar1 + 8);
      if (*(int *)(DAT_01d5ba6c + 4) <= iVar3) break;
      iVar1 = DAT_01d5ba6c + iVar2;
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
