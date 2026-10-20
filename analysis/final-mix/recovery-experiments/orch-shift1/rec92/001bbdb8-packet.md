# Target packet 001bbdb8

- Range: `001bbdb8`..`001bbe14`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bbdb8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001bb4a0` registry: `_ZN2YS7MISSION6IsExecEv`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`
- `001bbcb0` registry: `_ZN2YS7MISSION10GetCurrentEv`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`
- `001d4fa8` registry: `func_001d4fa8`
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_oneword_recovered_001bf0c8.cpp`, `fm_primary_twoword_recovered_001b2488.cpp`, `fm_primary_twoword_recovered_001ba310.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bbdb8: 27bdfff0  addiu	sp,sp,-16
001bbdbc: ffb00000  sd	s0,0(sp)
001bbdc0: ffbf0008  sd	ra,8(sp)
001bbdc4: 0c06ed28  jal	0x1bb4a0
001bbdc8: 0080802d  move	s0,a0
001bbdcc: 1040000d  beqz	v0,0x1bbe04
001bbdd0: 0000102d  move	v0,zero
001bbdd4: 0c06ef2c  jal	0x1bbcb0
001bbdd8: 00000000  nop
001bbddc: 8c4f02f0  lw	t7,752(v0)
001bbde0: 31ef0004  andi	t7,t7,0x4
001bbde4: 11e00007  beqz	t7,0x1bbe04
001bbde8: 0000102d  move	v0,zero
001bbdec: 0c06ef2c  jal	0x1bbcb0
001bbdf0: 00000000  nop
001bbdf4: 244402e4  addiu	a0,v0,740
001bbdf8: 0c0753ea  jal	0x1d4fa8
001bbdfc: 0200282d  move	a1,s0
001bbe00: 24020001  li	v0,1
001bbe04: dfb00000  ld	s0,0(sp)
001bbe08: dfbf0008  ld	ra,8(sp)
001bbe0c: 03e00008  jr	ra
001bbe10: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bbdb8(void)`

```c
undefined4 FUN_001bbdb8(undefined8 param_1)

{
  int iVar1;
  undefined4 uVar2;
  long lVar3;
  
  lVar3 = FUN_001bb4a0();
  uVar2 = 0;
  if (lVar3 != 0) {
    iVar1 = FUN_001bbcb0();
    uVar2 = 0;
    if ((*(uint *)(iVar1 + 0x2f0) & 4) != 0) {
      iVar1 = FUN_001bbcb0();
      FUN_001d4fa8(iVar1 + 0x2e4,param_1);
      uVar2 = 1;
    }
  }
  return uVar2;
}
```

## Earlier attempts (newest first)

- 25 differing words, 104/92 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_06_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_06_0.cpp`)
