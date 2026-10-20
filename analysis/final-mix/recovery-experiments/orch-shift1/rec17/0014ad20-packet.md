# Target packet 0014ad20

- Range: `0014ad20`..`0014ad58`, **56 bytes = 14 instructions**. This size is the acceptance size.
- Layout name: `FUN_0014ad20`
- Registry names for this address: `func_0014ad20`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00102788` registry: `_ZN12TASK_MANAGER11create_taskEiiPFvP4TASKE`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`, `fm_primary_fourwordfresh_recovered_00140ce8.cpp`, `fm_primary_oneword_recovered_001344b8.cpp`
- `0014acf8` registry: `func_0014acf8`
  - accepted sources that already call it (copy their declaration): `fm_more_recovered.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0014ad20: 27bdfff0  addiu	sp,sp,-16
0014ad24: ffbf0000  sd	ra,0(sp)
0014ad28: 0c052b3e  jal	0x14acf8
0014ad2c: 00000000  nop
0014ad30: 3c0f0033  lui	t7,0x33
0014ad34: dfbf0000  ld	ra,0(sp)
0014ad38: 8de4b91c  lw	a0,-18148(t7)   ; = D_0032b91c
0014ad3c: 3c060005  lui	a2,0x5
0014ad40: 3c070015  lui	a3,0x15
0014ad44: 0000282d  move	a1,zero
0014ad48: 24e7ac18  addiu	a3,a3,-21480   ; = D_0014ac18
0014ad4c: 34c60910  ori	a2,a2,0x910
0014ad50: 080409e2  j	0x102788
0014ad54: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0014ad20(void)`

```c
void FUN_0014ad20(void)

{
  FUN_0014acf8();
  FUN_00102788(DAT_0032b91c,0,330000,0x14ac18);
  return;
}
```

## Earlier attempts (newest first)

- none found
