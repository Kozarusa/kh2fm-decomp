# Target packet 00135bd0

- Range: `00135bd0`..`00135c50`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_00135bd0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00135ad0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_more_recovered.cpp`, `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`, `fm_primary_fourwordfresh_recovered_00140ce8.cpp`, `fm_primary_oneword_recovered_001344b8.cpp`
- `00135c50` registry: `func_00135c50`
  - accepted sources that already call it (copy their declaration): `fm_more_recovered.cpp`, `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`, `fm_primary_fourwordfresh_recovered_00140ce8.cpp`, `fm_primary_oneword_recovered_001344b8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00135bd0: 27bdffe0  addiu	sp,sp,-32
00135bd4: ffb00000  sd	s0,0(sp)
00135bd8: ffb20010  sd	s2,16(sp)
00135bdc: ffb10008  sd	s1,8(sp)
00135be0: 0080802d  move	s0,a0
00135be4: ffbf0018  sd	ra,24(sp)
00135be8: 0c04d714  jal	0x135c50
00135bec: 00a0902d  move	s2,a1
00135bf0: 8e0e000c  lw	t6,12(s0)
00135bf4: 0200202d  move	a0,s0
00135bf8: 240f0020  li	t7,32
00135bfc: 15cf0009  bne	t6,t7,0x135c24
00135c00: 01c0882d  move	s1,t6
00135c04: 0c04d6b4  jal	0x135ad0
00135c08: 00000000  nop
00135c0c: 8e0e000c  lw	t6,12(s0)
00135c10: 15d10004  bne	t6,s1,0x135c24
00135c14: 0200202d  move	a0,s0
00135c18: 0c04d714  jal	0x135c50
00135c1c: 8e050010  lw	a1,16(s0)
00135c20: 8e0e000c  lw	t6,12(s0)
00135c24: 000e7880  sll	t7,t6,0x2
00135c28: dfb10008  ld	s1,8(sp)
00135c2c: 01f07821  addu	t7,t7,s0
00135c30: dfbf0018  ld	ra,24(sp)
00135c34: 25ce0001  addiu	t6,t6,1
00135c38: adf20010  sw	s2,16(t7)
00135c3c: ae0e000c  sw	t6,12(s0)
00135c40: dfb20010  ld	s2,16(sp)
00135c44: dfb00000  ld	s0,0(sp)
00135c48: 03e00008  jr	ra
00135c4c: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00135bd0(void)`

```c
void FUN_00135bd0(undefined8 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  FUN_00135c50();
  iVar2 = (int)param_1;
  iVar1 = *(int *)(iVar2 + 0xc);
  if (iVar1 == 0x20) {
    FUN_00135ad0(param_1);
    iVar1 = *(int *)(iVar2 + 0xc);
    if (iVar1 == 0x20) {
      FUN_00135c50(param_1,*(undefined4 *)(iVar2 + 0x10));
      iVar1 = *(int *)(iVar2 + 0xc);
    }
  }
  *(undefined4 *)(iVar1 * 4 + iVar2 + 0x10) = param_2;
  *(int *)(iVar2 + 0xc) = iVar1 + 1;
  return;
}
```

## Earlier attempts (newest first)

- none found
