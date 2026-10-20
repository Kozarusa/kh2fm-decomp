# Target packet 0014cde0

- Range: `0014cde0`..`0014ce1c`, **60 bytes = 15 instructions**. This size is the acceptance size.
- Layout name: `FUN_0014cde0`
- Registry names for this address: `_ZN2dk5Vsync12setGameSpeedEfff`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00102788` registry: `_ZN12TASK_MANAGER11create_taskEiiPFvP4TASKE`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`, `fm_primary_fourwordfresh_recovered_00140ce8.cpp`, `fm_primary_oneword_recovered_001344b8.cpp`
- `0014f030` registry: `func_0014f030`
  - accepted sources that already call it (copy their declaration): `fm_primary_queueetaprime_recovered_0014f030.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0014cde0: 27bdfff0  addiu	sp,sp,-16
0014cde4: 3c040045  lui	a0,0x45
0014cde8: ffbf0000  sd	ra,0(sp)
0014cdec: 0c053c0c  jal	0x14f030
0014cdf0: 248474b8  addiu	a0,a0,29880   ; = D_004574b8
0014cdf4: 3c0f0033  lui	t7,0x33
0014cdf8: dfbf0000  ld	ra,0(sp)
0014cdfc: 8de4b91c  lw	a0,-18148(t7)   ; = D_0032b91c
0014ce00: 3c06000c  lui	a2,0xc
0014ce04: 3c070015  lui	a3,0x15
0014ce08: 0000282d  move	a1,zero
0014ce0c: 24e7cd98  addiu	a3,a3,-12904   ; = D_0014cd98
0014ce10: 34c63500  ori	a2,a2,0x3500
0014ce14: 080409e2  j	0x102788
0014ce18: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0014cde0(void)`

```c
void FUN_0014cde0(void)

{
  FUN_0014f030(0x4574b8);
  FUN_00102788(DAT_0032b91c,0,800000,0x14cd98);
  return;
}
```

## Earlier attempts (newest first)

- none found
