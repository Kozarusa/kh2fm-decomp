# Target packet 0016f6f8

- Range: `0016f6f8`..`0016f770`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_0016f6f8`
- Registry names for this address: `func_0016f6f8`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0016e920` registry: `Tz::JmInfo::GetCharaData(unsigned int)`
  - accepted sources that already call it (copy their declaration): `fm_fallback_helpers.cpp`, `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fiveword_recovered_0017a8f8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0016f6f8: 3c0e4000  lui	t6,0x4000
0016f6fc: 27bdfff0  addiu	sp,sp,-16
0016f700: 008e7824  and	t7,a0,t6
0016f704: ffbf0000  sd	ra,0(sp)
0016f708: 11e0000e  beqz	t7,0x16f744
0016f70c: 0000702d  move	t6,zero
0016f710: 0c05ba48  jal	0x16e920
0016f714: 00000000  nop
0016f718: 1040000a  beqz	v0,0x16f744
0016f71c: 0000702d  move	t6,zero
0016f720: 90420004  lbu	v0,4(v0)
0016f724: 240f0016  li	t7,22
0016f728: 104f000a  beq	v0,t7,0x16f754
0016f72c: 284e0017  slti	t6,v0,23
0016f730: 11c0000a  beqz	t6,0x16f75c
0016f734: 240f0007  li	t7,7
0016f738: 104f0002  beq	v0,t7,0x16f744
0016f73c: 0000702d  move	t6,zero
0016f740: 240e0001  li	t6,1
0016f744: dfbf0000  ld	ra,0(sp)
0016f748: 01c0102d  move	v0,t6
0016f74c: 03e00008  jr	ra
0016f750: 27bd0010  addiu	sp,sp,16
0016f754: 1000fffb  b	0x16f744
0016f758: 0000702d  move	t6,zero
0016f75c: 240f0018  li	t7,24
0016f760: 544ffff8  bnel	v0,t7,0x16f744
0016f764: 240e0001  li	t6,1
0016f768: 1000fff6  b	0x16f744
0016f76c: 0000702d  move	t6,zero
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0016f6f8(void)`

```c
undefined4 FUN_0016f6f8(ulong param_1)

{
  byte bVar1;
  long lVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if ((param_1 & 0x40000000) != 0) {
    lVar2 = FUN_0016e920();
    uVar3 = 0;
    if (lVar2 != 0) {
      bVar1 = *(byte *)((int)lVar2 + 4);
      if (bVar1 == 0x16) {
        uVar3 = 0;
      }
      else if (bVar1 < 0x17) {
        uVar3 = 0;
        if (bVar1 != 7) {
          uVar3 = 1;
        }
      }
      else if (bVar1 == 0x18) {
        uVar3 = 0;
      }
      else {
        uVar3 = 1;
      }
    }
  }
  return uVar3;
}
```

## Earlier attempts (newest first)

- none found
