# Target packet 0017cb78

- Range: `0017cb78`..`0017cbf4`, **124 bytes = 31 instructions**. This size is the acceptance size.
- Layout name: `FUN_0017cb78`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0017f488` registry: `func_0017f488(int,int,float,float)`
  - accepted sources that already call it (copy their declaration): `fm_primary_animation_recovered.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`
- `00180c88` registry: `func_00180c88`
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_002e8c28.cpp`, `fm_primary_floatpacket_recovered_002e8c58.cpp`, `fm_primary_oneword_recovered_002ef1b8.cpp`, `fm_primary_order_recovered_002ffc08.cpp`, `fm_primary_sixword_recovered_002f0948.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0017cb78: 27bdfff0  addiu	sp,sp,-16
0017cb7c: 24a40140  addiu	a0,a1,320
0017cb80: ffb00000  sd	s0,0(sp)
0017cb84: 240f0004  li	t7,4
0017cb88: ffbf0008  sd	ra,8(sp)
0017cb8c: 00a0802d  move	s0,a1
0017cb90: 8cae0100  lw	t6,256(a1)
0017cb94: 15cf000e  bne	t6,t7,0x17cbd0
0017cb98: 24050004  li	a1,4
0017cb9c: 3c0f0037  lui	t7,0x37
0017cba0: 44806800  mtc1	zero,$f13
0017cba4: 25efc540  addiu	t7,t7,-15040   ; = D_0036c540
0017cba8: 0c05fd22  jal	0x17f488
0017cbac: c5ec0000  lwc1	$f12,0(t7)
0017cbb0: 8e0f010c  lw	t7,268(s0)
0017cbb4: 240efffe  li	t6,-2
0017cbb8: dfbf0008  ld	ra,8(sp)
0017cbbc: 01ee7824  and	t7,t7,t6
0017cbc0: ae0f010c  sw	t7,268(s0)
0017cbc4: dfb00000  ld	s0,0(sp)
0017cbc8: 03e00008  jr	ra
0017cbcc: 27bd0010  addiu	sp,sp,16
0017cbd0: 05c0fff7  bltz	t6,0x17cbb0
0017cbd4: 3c0f0037  lui	t7,0x37
0017cbd8: 26040140  addiu	a0,s0,320
0017cbdc: 25efc540  addiu	t7,t7,-15040   ; = D_0036c540
0017cbe0: 01c0282d  move	a1,t6
0017cbe4: 0c060322  jal	0x180c88
0017cbe8: c5ec0000  lwc1	$f12,0(t7)
0017cbec: 1000fff1  b	0x17cbb4
0017cbf0: 8e0f010c  lw	t7,268(s0)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0017cb78(void)`

```c
void FUN_0017cb78(undefined8 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(param_2 + 0x100);
  if (iVar1 == 4) {
    FUN_0017f488(DAT_0036c540,0,param_2 + 0x140,4);
  }
  else if (-1 < iVar1) {
    FUN_00180c88(DAT_0036c540,param_2 + 0x140,iVar1);
    uVar2 = *(uint *)(param_2 + 0x10c);
    goto LAB_0017cbb4;
  }
  uVar2 = *(uint *)(param_2 + 0x10c);
LAB_0017cbb4:
  *(uint *)(param_2 + 0x10c) = uVar2 & 0xfffffffe;
  return;
}
```

## Earlier attempts (newest first)

- none found
