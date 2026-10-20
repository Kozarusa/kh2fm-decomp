# Target packet 001bb958

- Range: `001bb958`..`001bb9b0`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bb958`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0014f578` registry: `func_0014f578`
  - accepted sources that already call it (copy their declaration): `fm_primary_globalargument_recovered_0014f578.cpp`
- `00192048` registry: `_Z16u_tail4_00192048jjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_00232510.cpp`
- `001bb4a0` registry: `_ZN2YS7MISSION6IsExecEv`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bb958: 27bdfff0  addiu	sp,sp,-16
001bb95c: ffbf0000  sd	ra,0(sp)
001bb960: 14800008  bnez	a0,0x1bb984
001bb964: 00000000  nop
001bb968: 0c06ed28  jal	0x1bb4a0
001bb96c: 00000000  nop
001bb970: 1040000c  beqz	v0,0x1bb9a4
001bb974: 3c0f01d5  lui	t7,0x1d5
001bb978: 8dee9320  lw	t6,-27872(t7)   ; = D_01d49320
001bb97c: 8dcd0008  lw	t5,8(t6)
001bb980: 95a40006  lhu	a0,6(t5)
001bb984: 18800008  blez	a0,0x1bb9a8
001bb988: dfbf0000  ld	ra,0(sp)
001bb98c: 0c064812  jal	0x192048
001bb990: 00000000  nop
001bb994: dfbf0000  ld	ra,0(sp)
001bb998: 0040202d  move	a0,v0
001bb99c: 08053d5e  j	0x14f578
001bb9a0: 27bd0010  addiu	sp,sp,16
001bb9a4: dfbf0000  ld	ra,0(sp)
001bb9a8: 03e00008  jr	ra
001bb9ac: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bb958(void)`

```c
void FUN_001bb958(ulong param_1)

{
  long lVar1;
  undefined8 uVar2;
  
  if (param_1 == 0) {
    lVar1 = FUN_001bb4a0();
    if (lVar1 == 0) {
      return;
    }
    param_1 = (ulong)*(ushort *)(*(int *)(DAT_01d49320 + 8) + 6);
  }
  if ((long)param_1 < 1) {
    return;
  }
  uVar2 = FUN_00192048();
  FUN_0014f578(uVar2);
  return;
}
```

## Earlier attempts (newest first)

- none found
