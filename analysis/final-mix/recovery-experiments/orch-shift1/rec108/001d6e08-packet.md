# Target packet 001d6e08

- Range: `001d6e08`..`001d6e5c`, **84 bytes = 21 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d6e08`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0016ed50` registry: `_Z16wtarget_0016ed50jjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_floatarguments_recovered_0018f9b8.cpp`, `fm_primary_fourwordfresh_recovered_00195558.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d6e08: 27bdffe0  addiu	sp,sp,-32
001d6e0c: ffb00000  sd	s0,0(sp)
001d6e10: ffb10008  sd	s1,8(sp)
001d6e14: ffbf0010  sd	ra,16(sp)
001d6e18: 24900004  addiu	s0,a0,4
001d6e1c: 24110001  li	s1,1
001d6e20: 8e0f0000  lw	t7,0(s0)
001d6e24: 26100004  addiu	s0,s0,4
001d6e28: 11e00004  beqz	t7,0x1d6e3c
001d6e2c: 01e0202d  move	a0,t7
001d6e30: 2405ffff  li	a1,-1
001d6e34: 0c05bb54  jal	0x16ed50
001d6e38: 2406001e  li	a2,30
001d6e3c: 2631ffff  addiu	s1,s1,-1
001d6e40: 0623fff8  bgezl	s1,0x1d6e24
001d6e44: 8e0f0000  lw	t7,0(s0)
001d6e48: dfb00000  ld	s0,0(sp)
001d6e4c: dfb10008  ld	s1,8(sp)
001d6e50: dfbf0010  ld	ra,16(sp)
001d6e54: 03e00008  jr	ra
001d6e58: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d6e08(void)`

```c
void FUN_001d6e08(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)(param_1 + 4);
  iVar3 = 1;
  iVar1 = *piVar2;
  while( true ) {
    piVar2 = piVar2 + 1;
    if (iVar1 != 0) {
      FUN_0016ed50(iVar1,0xffffffffffffffff,0x1e);
    }
    iVar3 = iVar3 + -1;
    if (iVar3 < 0) break;
    iVar1 = *piVar2;
  }
  return;
}
```

## Earlier attempts (newest first)

- 11 differing words, 88/84 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_07_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_07_0.cpp`)
