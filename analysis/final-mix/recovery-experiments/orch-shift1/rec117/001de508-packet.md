# Target packet 001de508

- Range: `001de508`..`001de564`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_001de508`
- Registry names for this address: `_ZN3ryj3PAX6unbindEPNS_6EFFECTE`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001dc700` registry: `func_001dc700`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001de508: 27bdfff0  addiu	sp,sp,-16
001de50c: ffbf0000  sd	ra,0(sp)
001de510: 8c8d000c  lw	t5,12(a0)
001de514: 11a00011  beqz	t5,0x1de55c
001de518: dfbf0000  ld	ra,0(sp)
001de51c: 8daf0040  lw	t7,64(t5)
001de520: 15e5000b  bne	t7,a1,0x1de550
001de524: 8dae0060  lw	t6,96(t5)
001de528: 8dae005c  lw	t6,92(t5)
001de52c: 240ffffe  li	t7,-2
001de530: 00a0202d  move	a0,a1
001de534: ada00048  sw	zero,72(t5)
001de538: 01cf7024  and	t6,t6,t7
001de53c: dfbf0000  ld	ra,0(sp)
001de540: adae005c  sw	t6,92(t5)
001de544: 0000282d  move	a1,zero
001de548: 080771c0  j	0x1dc700
001de54c: 27bd0010  addiu	sp,sp,16
001de550: 15c0fff2  bnez	t6,0x1de51c
001de554: 01c0682d  move	t5,t6
001de558: dfbf0000  ld	ra,0(sp)
001de55c: 03e00008  jr	ra
001de560: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001de508(void)`

```c
void FUN_001de508(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0xc);
  do {
    iVar1 = iVar2;
    if (iVar1 == 0) {
      return;
    }
    iVar2 = *(int *)(iVar1 + 0x60);
  } while (*(int *)(iVar1 + 0x40) != param_2);
  *(undefined4 *)(iVar1 + 0x48) = 0;
  *(uint *)(iVar1 + 0x5c) = *(uint *)(iVar1 + 0x5c) & 0xfffffffe;
  FUN_001dc700(param_2,0);
  return;
}
```

## Earlier attempts (newest first)

- 10 differing words, 84/92 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_08_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_08_0.cpp`)
