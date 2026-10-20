# Target packet 0024eb50

- Range: `0024eb50`..`0024ebbc`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_0024eb50`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00139d78` registry: `_Z16u_call4_00139d78jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_close_recovered.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0024eb50: 27bdffe0  addiu	sp,sp,-32
0024eb54: 3c0f0036  lui	t7,0x36
0024eb58: ffb00000  sd	s0,0(sp)
0024eb5c: ffb10008  sd	s1,8(sp)
0024eb60: ffbf0010  sd	ra,16(sp)
0024eb64: 25f0ee18  addiu	s0,t7,-4584   ; = D_0035ee18
0024eb68: 24110004  li	s1,4
0024eb6c: 8e0f0000  lw	t7,0(s0)
0024eb70: 11e0000a  beqz	t7,0x24eb9c
0024eb74: 01e0202d  move	a0,t7
0024eb78: 0c04e75e  jal	0x139d78
0024eb7c: 00000000  nop
0024eb80: 50400006  beqzl	v0,0x24eb9c
0024eb84: ae000000  sw	zero,0(s0)
0024eb88: 8e0f0000  lw	t7,0(s0)
0024eb8c: 8dee0000  lw	t6,0(t7)
0024eb90: 8dcd0014  lw	t5,20(t6)
0024eb94: 01a0f809  jalr	t5
0024eb98: 01e0202d  move	a0,t7
0024eb9c: 2631ffff  addiu	s1,s1,-1
0024eba0: 0621fff2  bgez	s1,0x24eb6c
0024eba4: 26100004  addiu	s0,s0,4
0024eba8: dfb00000  ld	s0,0(sp)
0024ebac: dfb10008  ld	s1,8(sp)
0024ebb0: dfbf0010  ld	ra,16(sp)
0024ebb4: 03e00008  jr	ra
0024ebb8: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0024eb50(void)`

```c
void FUN_0024eb50(void)

{
  long lVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = &DAT_0035ee18;
  iVar3 = 4;
  do {
    if (*piVar2 != 0) {
      lVar1 = FUN_00139d78(*piVar2);
      if (lVar1 == 0) {
        *piVar2 = 0;
      }
      else {
        (**(code **)(*(int *)*piVar2 + 0x14))((int *)*piVar2);
      }
    }
    iVar3 = iVar3 + -1;
    piVar2 = piVar2 + 1;
  } while (-1 < iVar3);
  return;
}
```

## Earlier attempts (newest first)

- none found
