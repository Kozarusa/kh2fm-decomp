# Target packet 001d87b8

- Range: `001d87b8`..`001d881c`, **100 bytes = 25 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d87b8`
- Registry names for this address: `_ZN2YS7MISSION8GetCountEi`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001bb4a0` registry: `_ZN2YS7MISSION6IsExecEv`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`
- `001bbcb0` registry: `_ZN2YS7MISSION10GetCurrentEv`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d87b8: 27bdfff0  addiu	sp,sp,-16
001d87bc: ffb00000  sd	s0,0(sp)
001d87c0: ffbf0008  sd	ra,8(sp)
001d87c4: 0c06ed28  jal	0x1bb4a0
001d87c8: 0080802d  move	s0,a0
001d87cc: 1040000f  beqz	v0,0x1d880c
001d87d0: 0000102d  move	v0,zero
001d87d4: 0c06ef2c  jal	0x1bbcb0
001d87d8: 00000000  nop
001d87dc: 240f0038  li	t7,56
001d87e0: 020f8018  mult	s0,s0,t7
001d87e4: 00501021  addu	v0,v0,s0
001d87e8: 8c4f00f4  lw	t7,244(v0)
001d87ec: 31ef0001  andi	t7,t7,0x1
001d87f0: 31ef00ff  andi	t7,t7,0xff
001d87f4: 11e00005  beqz	t7,0x1d880c
001d87f8: 0000102d  move	v0,zero
001d87fc: 0c06ef2c  jal	0x1bbcb0
001d8800: 00000000  nop
001d8804: 02021021  addu	v0,s0,v0
001d8808: 8c420114  lw	v0,276(v0)
001d880c: dfb00000  ld	s0,0(sp)
001d8810: dfbf0008  ld	ra,8(sp)
001d8814: 03e00008  jr	ra
001d8818: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d87b8(void)`

```c
undefined4 FUN_001d87b8(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = FUN_001bb4a0();
  uVar2 = 0;
  if (lVar3 != 0) {
    iVar1 = FUN_001bbcb0();
    uVar2 = 0;
    if ((*(uint *)(iVar1 + param_1 * 0x38 + 0xf4) & 1) != 0) {
      iVar1 = FUN_001bbcb0();
      uVar2 = *(undefined4 *)(param_1 * 0x38 + iVar1 + 0x114);
    }
  }
  return uVar2;
}
```

## Earlier attempts (newest first)

- 27 differing words, 112/100 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_08_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_08_1.cpp`)
