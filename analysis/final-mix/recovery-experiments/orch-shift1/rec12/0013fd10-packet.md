# Target packet 0013fd10

- Range: `0013fd10`..`0013fd74`, **100 bytes = 25 instructions**. This size is the acceptance size.
- Layout name: `FUN_0013fd10`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0013fcd8` registry: `_ZN2YS19trap_vector_atan_xzEP8BD_VALUE`
  - accepted sources that already call it (copy their declaration): `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`, `fm_primary_fourwordfresh_recovered_00140ce8.cpp`, `fm_primary_oneword_recovered_001344b8.cpp`, `fm_primary_order_recovered_00132130.cpp`
- `0016af58` registry: none
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`, `fm_primary_fourwordfresh_recovered_00140ce8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0013fd10: 27bdffc0  addiu	sp,sp,-64
0013fd14: ffb00020  sd	s0,32(sp)
0013fd18: ffb10028  sd	s1,40(sp)
0013fd1c: ffb20030  sd	s2,48(sp)
0013fd20: 27b00010  addiu	s0,sp,16
0013fd24: ffbf0038  sd	ra,56(sp)
0013fd28: 0080882d  move	s1,a0
0013fd2c: 8c850044  lw	a1,68(a0)
0013fd30: 0c05abd6  jal	0x16af58
0013fd34: 0200202d  move	a0,s0
0013fd38: 13b00003  beq	sp,s0,0x13fd48
0013fd3c: 00000000  nop
0013fd40: 7a080000  lq	t0,0(s0)
0013fd44: 7fa80000  sq	t0,0(sp)
0013fd48: 7ba80000  lq	t0,0(sp)
0013fd4c: 7e080000  sq	t0,0(s0)
0013fd50: 0220202d  move	a0,s1
0013fd54: 0c04ff36  jal	0x13fcd8
0013fd58: 0200282d  move	a1,s0
0013fd5c: dfb00020  ld	s0,32(sp)
0013fd60: dfb10028  ld	s1,40(sp)
0013fd64: dfb20030  ld	s2,48(sp)
0013fd68: dfbf0038  ld	ra,56(sp)
0013fd6c: 03e00008  jr	ra
0013fd70: 27bd0040  addiu	sp,sp,64
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0013fd10(void)`

```c
void FUN_0013fd10(undefined8 param_1)

{
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  FUN_0016af58(&uStack_30,*(undefined4 *)((int)param_1 + 0x44));
  if (&uStack_40 != &uStack_30) {
    uStack_40 = uStack_30;
    uStack_3c = uStack_2c;
    uStack_38 = uStack_28;
    uStack_34 = uStack_24;
  }
  uStack_30 = uStack_40;
  uStack_2c = uStack_3c;
  uStack_28 = uStack_38;
  uStack_24 = uStack_34;
  FUN_0013fcd8(param_1,&uStack_30);
  return;
}
```

## Earlier attempts (newest first)

- none found
