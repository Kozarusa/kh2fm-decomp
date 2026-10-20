# Target packet 001ac078

- Range: `001ac078`..`001ac0d0`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ac078`
- Registry names for this address: `_Z16wtarget_001ac078jjjj`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00239bf8` registry: `_Z16wtarget_00239bf8jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ac078: 00a0602d  move	t4,a1
001ac07c: 0080702d  move	t6,a0
001ac080: 00052880  sll	a1,a1,0x2
001ac084: a1cc0000  sb	t4,0(t6)
001ac088: 00a62821  addu	a1,a1,a2
001ac08c: a1c60001  sb	a2,1(t6)
001ac090: 00052840  sll	a1,a1,0x1
001ac094: a1c70002  sb	a3,2(t6)
001ac098: 24af0025  addiu	t7,a1,37
001ac09c: 27bdfff0  addiu	sp,sp,-16
001ac0a0: 28ed0004  slti	t5,a3,4
001ac0a4: ffbf0000  sd	ra,0(sp)
001ac0a8: 24a50021  addiu	a1,a1,33
001ac0ac: 24840004  addiu	a0,a0,4
001ac0b0: 11800004  beqz	t4,0x1ac0c4
001ac0b4: 01ed280b  movn	a1,t7,t5
001ac0b8: dfbf0000  ld	ra,0(sp)
001ac0bc: 0808e6fe  j	0x239bf8
001ac0c0: 27bd0010  addiu	sp,sp,16
001ac0c4: dfbf0000  ld	ra,0(sp)
001ac0c8: 03e00008  jr	ra
001ac0cc: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ac078(void)`

```c
void FUN_001ac078(undefined1 *param_1,long param_2,int param_3,long param_4)

{
  int iVar1;
  int iVar2;
  
  *param_1 = (char)param_2;
  param_1[1] = (char)param_3;
  iVar2 = ((int)param_2 * 4 + param_3) * 2;
  param_1[2] = (char)param_4;
  iVar1 = iVar2 + 0x21;
  if (param_4 < 4) {
    iVar1 = iVar2 + 0x25;
  }
  if (param_2 != 0) {
    FUN_00239bf8(param_1 + 4,iVar1);
    return;
  }
  return;
}
```

## Earlier attempts (newest first)

- 9 differing words, 88/88 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_05_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_05_0.cpp`)
