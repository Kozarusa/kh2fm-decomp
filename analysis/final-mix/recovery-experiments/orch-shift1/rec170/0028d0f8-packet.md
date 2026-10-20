# Target packet 0028d0f8

- Range: `0028d0f8`..`0028d140`, **72 bytes = 18 instructions**. This size is the acceptance size.
- Layout name: `FUN_0028d0f8`
- Registry names for this address: `func_0028d0f8`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00239700` registry: `func_00239700`
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_queuebeta_recovered_0015d730.cpp`, `fm_primary_resume_recovered_00.cpp`, `fm_primary_threewordnext_recovered_0019e6e8.cpp`, `fm_primary_width_recovered_00.cpp`
- `0028d188` registry: `func_0028d188`
  - accepted sources that already call it (copy their declaration): `fm_float_memory_recovered.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0028d0f8: 27bdfff0  addiu	sp,sp,-16
0028d0fc: ac80000c  sw	zero,12(a0)
0028d100: 3c0f0034  lui	t7,0x34
0028d104: ffb00000  sd	s0,0(sp)
0028d108: 25ef7e60  addiu	t7,t7,32352   ; = D_00347e60
0028d10c: ffbf0008  sd	ra,8(sp)
0028d110: ac8f0000  sw	t7,0(a0)
0028d114: 0080802d  move	s0,a0
0028d118: 0c08e5c0  jal	0x239700
0028d11c: 24840018  addiu	a0,a0,24
0028d120: 3c0f0036  lui	t7,0x36
0028d124: dfbf0008  ld	ra,8(sp)
0028d128: 25eff420  addiu	t7,t7,-3040   ; = D_0035f420
0028d12c: 0200202d  move	a0,s0
0028d130: ae0f0000  sw	t7,0(s0)
0028d134: dfb00000  ld	s0,0(sp)
0028d138: 080a3462  j	0x28d188
0028d13c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0028d0f8(void)`

```c
void FUN_0028d0f8(undefined8 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1;
  puVar1[3] = 0;
  *puVar1 = &PTR_FUN_00347e60;
  FUN_00239700(puVar1 + 6);
  *puVar1 = &PTR_FUN_0035f420;
  FUN_0028d188(param_1);
  return;
}
```

## Earlier attempts (newest first)

- none found
