# Target packet 001bba30

- Range: `001bba30`..`001bba88`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bba30`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001d5370` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_oneword_recovered_001bf0c8.cpp`, `fm_primary_twoword_recovered_001b2488.cpp`, `fm_primary_twoword_recovered_001ba310.cpp`
- `002534e0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_oneword_recovered_001bf0c8.cpp`, `fm_primary_twoword_recovered_001b2488.cpp`, `fm_primary_twoword_recovered_001ba310.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bba30: 27bdffe0  addiu	sp,sp,-32
001bba34: ffbf0010  sd	ra,16(sp)
001bba38: afa00000  sw	zero,0(sp)
001bba3c: afa00004  sw	zero,4(sp)
001bba40: 8c850048  lw	a1,72(a0)
001bba44: 10a00006  beqz	a1,0x1bba60
001bba48: 0000102d  move	v0,zero
001bba4c: 8c8f0008  lw	t7,8(a0)
001bba50: 91ee000c  lbu	t6,12(t7)
001bba54: 15c00005  bnez	t6,0x1bba6c
001bba58: 25c6ffff  addiu	a2,t6,-1
001bba5c: 0000102d  move	v0,zero
001bba60: dfbf0010  ld	ra,16(sp)
001bba64: 03e00008  jr	ra
001bba68: 27bd0020  addiu	sp,sp,32
001bba6c: 0c0754dc  jal	0x1d5370
001bba70: 03a0202d  move	a0,sp
001bba74: 8fa40004  lw	a0,4(sp)
001bba78: 0c094d38  jal	0x2534e0
001bba7c: 8fa50000  lw	a1,0(sp)
001bba80: 1000fff7  b	0x1bba60
001bba84: 24020001  li	v0,1
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bba30(void)`

```c
undefined4 FUN_001bba30(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  uStack_20 = 0;
  uStack_1c = 0;
  uVar2 = 0;
  if (*(int *)(param_1 + 0x48) != 0) {
    bVar1 = *(byte *)(*(int *)(param_1 + 8) + 0xc);
    if (bVar1 == 0) {
      uVar2 = 0;
    }
    else {
      FUN_001d5370(&uStack_20,*(int *)(param_1 + 0x48),bVar1 - 1);
      FUN_002534e0(uStack_1c,uStack_20);
      uVar2 = 1;
    }
  }
  return uVar2;
}
```

## Earlier attempts (newest first)

- 19 differing words, 80/88 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_06_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_06_0.cpp`)
