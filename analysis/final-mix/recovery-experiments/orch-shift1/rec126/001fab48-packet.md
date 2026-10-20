# Target packet 001fab48

- Range: `001fab48`..`001fabc8`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_001fab48`
- Registry names for this address: `func_001fab48(void*)`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0021fe08` registry: `func_0021fe08`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001fab48: 27bdfff0  addiu	sp,sp,-16
001fab4c: 8ccb000c  lw	t3,12(a2)
001fab50: ffbf0000  sd	ra,0(sp)
001fab54: 8d6f0000  lw	t7,0(t3)
001fab58: 8cad0000  lw	t5,0(a1)
001fab5c: 008f6021  addu	t4,a0,t7
001fab60: 8c8e000c  lw	t6,12(a0)
001fab64: 15ae000a  bne	t5,t6,0x1fab90
001fab68: 258a00a0  addiu	t2,t4,160
001fab6c: 8d6f0004  lw	t7,4(t3)
001fab70: 008f7821  addu	t7,a0,t7
001fab74: 25ef00a0  addiu	t7,t7,160
001fab78: ad8f00a0  sw	t7,160(t4)
001fab7c: 8cae0004  lw	t6,4(a1)
001fab80: 340fffff  li	t7,0xffff
001fab84: 15cf0005  bne	t6,t7,0x1fab9c
001fab88: 000e58c0  sll	t3,t6,0x3
001fab8c: ad400004  sw	zero,4(t2)
001fab90: dfbf0000  ld	ra,0(sp)
001fab94: 03e00008  jr	ra
001fab98: 27bd0010  addiu	sp,sp,16
001fab9c: 3c0e01da  lui	t6,0x1da
001faba0: 8d4c0004  lw	t4,4(t2)
001faba4: 8dcde6e4  lw	t5,-6428(t6)   ; = D_01d9e6e4
001faba8: 8daf0014  lw	t7,20(t5)
001fabac: 01eb7821  addu	t7,t7,t3
001fabb0: 11ecfff7  beq	t7,t4,0x1fab90
001fabb4: 01e0282d  move	a1,t7
001fabb8: dfbf0000  ld	ra,0(sp)
001fabbc: 0140202d  move	a0,t2
001fabc0: 08087f82  j	0x21fe08
001fabc4: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001fab48(void)`

```c
void FUN_001fab48(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1 + **(int **)(param_3 + 0xc);
  if (*param_2 == *(int *)(param_1 + 0xc)) {
    *(int *)(iVar1 + 0xa0) = param_1 + (*(int **)(param_3 + 0xc))[1] + 0xa0;
    if (param_2[1] == 0xffff) {
      *(undefined4 *)(iVar1 + 0xa4) = 0;
    }
    else {
      iVar2 = *(int *)(DAT_01d9e6e4 + 0x14) + param_2[1] * 8;
      if (iVar2 != *(int *)(iVar1 + 0xa4)) {
        FUN_0021fe08(iVar1 + 0xa0,iVar2);
        return;
      }
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
