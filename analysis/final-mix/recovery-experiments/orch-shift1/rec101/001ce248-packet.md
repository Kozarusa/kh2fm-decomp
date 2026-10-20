# Target packet 001ce248

- Range: `001ce248`..`001ce2a0`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ce248`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00168b88` registry: `func_00168b88`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_floatarguments_recovered_0018f9b8.cpp`, `fm_primary_fourwordfresh_recovered_00195558.cpp`, `fm_primary_fourwordfresh_recovered_00197390.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ce248: 27bdfff0  addiu	sp,sp,-16
001ce24c: 00a0782d  move	t7,a1
001ce250: ffbf0000  sd	ra,0(sp)
001ce254: 0000382d  move	a3,zero
001ce258: 80ac0001  lb	t4,1(a1)
001ce25c: 81ed0003  lb	t5,3(t7)
001ce260: 81ee0002  lb	t6,2(t7)
001ce264: 0080282d  move	a1,a0
001ce268: 81e60000  lb	a2,0(t7)
001ce26c: 000c6200  sll	t4,t4,0x8
001ce270: 000d6e00  sll	t5,t5,0x18
001ce274: 000e7400  sll	t6,t6,0x10
001ce278: 3c0f0035  lui	t7,0x35
001ce27c: 00cd3025  or	a2,a2,t5
001ce280: 01cc7025  or	t6,t6,t4
001ce284: 8de42134  lw	a0,8500(t7)   ; = D_00352134
001ce288: 0c05a2e2  jal	0x168b88
001ce28c: 00ce3025  or	a2,a2,t6
001ce290: 8c420008  lw	v0,8(v0)
001ce294: dfbf0000  ld	ra,0(sp)
001ce298: 03e00008  jr	ra
001ce29c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ce248(void)`

```c
undefined4 FUN_001ce248(undefined8 param_1,char *param_2)

{
  int iVar1;
  
  iVar1 = FUN_00168b88(DAT_00352134,param_1,
                       (long)*param_2 | (long)((int)param_2[3] << 0x18) |
                       (long)((int)param_2[2] << 0x10 | (int)param_2[1] << 8),0);
  return *(undefined4 *)(iVar1 + 8);
}
```

## Earlier attempts (newest first)

- none found
