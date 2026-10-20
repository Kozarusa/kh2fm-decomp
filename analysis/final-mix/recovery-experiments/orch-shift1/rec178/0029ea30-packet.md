# Target packet 0029ea30

- Range: `0029ea30`..`0029eaa4`, **116 bytes = 29 instructions**. This size is the acceptance size.
- Layout name: `FUN_0029ea30`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00276c50` registry: `Tz::JmReport::DrawMessage(unsigned int, unsigned int)`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_resume_recovered_01.cpp`, `fm_primary_storeorder_recovered_00281f90.cpp`, `fm_primary_width_recovered_02.cpp`, `fm_scalar_recovered_07.cpp`
- `00287bc0` registry: `_ZN2Tz8MenuBase7GetModeEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0029ea30: 27bdfff0  addiu	sp,sp,-16
0029ea34: ffbf0000  sd	ra,0(sp)
0029ea38: 0c0a1ef0  jal	0x287bc0
0029ea3c: 00000000  nop
0029ea40: 2442fff2  addiu	v0,v0,-14
0029ea44: 2c4f0009  sltiu	t7,v0,9
0029ea48: 11e00010  beqz	t7,0x29ea8c
0029ea4c: 3c0e0037  lui	t6,0x37
0029ea50: 00027880  sll	t7,v0,0x2
0029ea54: 25ce4a58  addiu	t6,t6,19032   ; = D_00374a58
0029ea58: 01ee7821  addu	t7,t7,t6
0029ea5c: 8ded0000  lw	t5,0(t7)
0029ea60: 01a00008  jr	t5
0029ea64: 00000000  nop
0029ea68: 240448ee  li	a0,18670
0029ea6c: dfbf0000  ld	ra,0(sp)
0029ea70: 0000282d  move	a1,zero
0029ea74: 0809db14  j	0x276c50
0029ea78: 27bd0010  addiu	sp,sp,16
0029ea7c: 1000fffb  b	0x29ea6c
0029ea80: 240448ef  li	a0,18671
0029ea84: 1000fff9  b	0x29ea6c
0029ea88: 240448f0  li	a0,18672
0029ea8c: 1000fff7  b	0x29ea6c
0029ea90: 240448f3  li	a0,18675
0029ea94: 1000fff5  b	0x29ea6c
0029ea98: 240448f1  li	a0,18673
0029ea9c: 1000fff3  b	0x29ea6c
0029eaa0: 240448f2  li	a0,18674
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0029ea30(void)`

```c
void FUN_0029ea30(void)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar1 = FUN_00287bc0();
  switch(uVar1) {
  case 0xe:
    uVar2 = 0x48ee;
    break;
  case 0xf:
    uVar2 = 0x48ef;
    break;
  case 0x10:
  case 0x13:
  case 0x16:
    uVar2 = 0x48f2;
    break;
  default:
    uVar2 = 0x48f3;
    break;
  case 0x12:
    uVar2 = 0x48f0;
    break;
  case 0x15:
    uVar2 = 0x48f1;
  }
  FUN_00276c50(uVar2,0);
  return;
}
```

## Earlier attempts (newest first)

- none found
