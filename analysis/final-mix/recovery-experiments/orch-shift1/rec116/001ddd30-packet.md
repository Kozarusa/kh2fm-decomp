# Target packet 001ddd30

- Range: `001ddd30`..`001ddd84`, **84 bytes = 21 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ddd30`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001dde40` registry: none
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ddd30: 27bdfff0  addiu	sp,sp,-16
001ddd34: 0000682d  move	t5,zero
001ddd38: ffbf0000  sd	ra,0(sp)
001ddd3c: 3c0c01da  lui	t4,0x1da
001ddd40: 55a00002  bnezl	t5,0x1ddd4c
001ddd44: 8dae0014  lw	t6,20(t5)
001ddd48: 8d8ee348  lw	t6,-7352(t4)   ; = D_01d9e348
001ddd4c: 15c00009  bnez	t6,0x1ddd74
001ddd50: 01c0682d  move	t5,t6
001ddd54: 0000782d  move	t7,zero
001ddd58: 31ef00ff  andi	t7,t7,0xff
001ddd5c: 11e00003  beqz	t7,0x1ddd6c
001ddd60: dfbf0000  ld	ra,0(sp)
001ddd64: 08077790  j	0x1dde40
001ddd68: 27bd0010  addiu	sp,sp,16
001ddd6c: 03e00008  jr	ra
001ddd70: 27bd0010  addiu	sp,sp,16
001ddd74: 11c4fff8  beq	t6,a0,0x1ddd58
001ddd78: 240f0001  li	t7,1
001ddd7c: 1000fff0  b	0x1ddd40
001ddd80: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ddd30(void)`

```c
void FUN_001ddd30(int param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    iVar1 = DAT_01d9e348;
    if (iVar3 != 0) {
      iVar1 = *(int *)(iVar3 + 0x14);
    }
    if (iVar1 == 0) break;
    bVar2 = true;
    iVar3 = iVar1;
    if (iVar1 == param_1) {
LAB_001ddd58:
      if (!bVar2) {
        return;
      }
      FUN_001dde40();
      return;
    }
  }
  bVar2 = false;
  goto LAB_001ddd58;
}
```

## Earlier attempts (newest first)

- none found
