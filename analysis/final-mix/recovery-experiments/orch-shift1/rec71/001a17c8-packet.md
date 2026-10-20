# Target packet 001a17c8

- Range: `001a17c8`..`001a1840`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_001a17c8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001a1840` registry: `_Z16wtarget_001a1840jjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_threewordnext_recovered_0019e6e8.cpp`, `fm_scalar_extra_recovered_03.cpp`, `fm_scalar_extra_recovered_12.cpp`, `fm_scalar_recovered_03.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001a17c8: 27bdfff0  addiu	sp,sp,-16
001a17cc: ffb00000  sd	s0,0(sp)
001a17d0: ffbf0008  sd	ra,8(sp)
001a17d4: 0c068610  jal	0x1a1840
001a17d8: 0080802d  move	s0,a0
001a17dc: 3c0f01c6  lui	t7,0x1c6
001a17e0: 3c0d3f2b  lui	t5,0x3f2b
001a17e4: 25ec2fb8  addiu	t4,t7,12216   ; = D_01c62fb8
001a17e8: 35ad3885  ori	t5,t5,0x3885
001a17ec: 340f8000  li	t7,0x8000
001a17f0: 020c7023  subu	t6,s0,t4
001a17f4: 018f5021  addu	t2,t4,t7
001a17f8: 000e70c3  sra	t6,t6,0x3
001a17fc: 8e0f0258  lw	t7,600(s0)
001a1800: 01cd5818  mult	t3,t6,t5
001a1804: 25efffff  addiu	t7,t7,-1
001a1808: 1de00009  bgtz	t7,0x1a1830
001a180c: ae0f0258  sw	t7,600(s0)
001a1810: 8d4d1b00  lw	t5,6912(t2)
001a1814: 340f9a00  li	t7,0x9a00
001a1818: 000d7080  sll	t6,t5,0x2
001a181c: 01cc7021  addu	t6,t6,t4
001a1820: 25ad0001  addiu	t5,t5,1
001a1824: 01cf7021  addu	t6,t6,t7
001a1828: ad4d1b00  sw	t5,6912(t2)
001a182c: adcb0000  sw	t3,0(t6)
001a1830: dfb00000  ld	s0,0(sp)
001a1834: dfbf0008  ld	ra,8(sp)
001a1838: 03e00008  jr	ra
001a183c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001a17c8(void)`

```c
void FUN_001a17c8(int param_1)

{
  int *piVar1;
  int iVar2;
  
  FUN_001a1840();
  iVar2 = *(int *)(param_1 + 600) + -1;
  *(int *)(param_1 + 600) = iVar2;
  if (iVar2 < 1) {
    piVar1 = &DAT_01c6c9b8 + DAT_01c6cab8;
    DAT_01c6cab8 = DAT_01c6cab8 + 1;
    *piVar1 = (param_1 + -0x1c62fb8 >> 3) * 0x3f2b3885;
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
