# Target packet 00132ec0

- Range: `00132ec0`..`00132f34`, **116 bytes = 29 instructions**. This size is the acceptance size.
- Layout name: `FUN_00132ec0`
- Registry names for this address: `func_00132ec0`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001325c8` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`, `fm_primary_fourwordfresh_recovered_00140ce8.cpp`, `fm_primary_oneword_recovered_001344b8.cpp`, `fm_primary_order_recovered_00132130.cpp`
- `00132c68` registry: `func_00132c68`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`, `fm_primary_fourwordfresh_recovered_00140ce8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00132ec0: 27bdffe0  addiu	sp,sp,-32
00132ec4: ffb00000  sd	s0,0(sp)
00132ec8: ffb20010  sd	s2,16(sp)
00132ecc: ffb10008  sd	s1,8(sp)
00132ed0: 00a0802d  move	s0,a1
00132ed4: ffbf0018  sd	ra,24(sp)
00132ed8: 0c04cb1a  jal	0x132c68
00132edc: 0080902d  move	s2,a0
00132ee0: 0040882d  move	s1,v0
00132ee4: 0200302d  move	a2,s0
00132ee8: 0240202d  move	a0,s2
00132eec: 1040000b  beqz	v0,0x132f1c
00132ef0: 3405ffff  li	a1,0xffff
00132ef4: 0c04c972  jal	0x1325c8
00132ef8: 00000000  nop
00132efc: 04400007  bltz	v0,0x132f1c
00132f00: 00027080  sll	t6,v0,0x2
00132f04: 8e2f001c  lw	t7,28(s1)
00132f08: 022f7821  addu	t7,s1,t7
00132f0c: 01cf7821  addu	t7,t6,t7
00132f10: 8dee0000  lw	t6,0(t7)
00132f14: 022e7021  addu	t6,s1,t6
00132f18: ae4e0274  sw	t6,628(s2)
00132f1c: dfb00000  ld	s0,0(sp)
00132f20: dfb10008  ld	s1,8(sp)
00132f24: dfb20010  ld	s2,16(sp)
00132f28: dfbf0018  ld	ra,24(sp)
00132f2c: 03e00008  jr	ra
00132f30: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00132ec0(void)`

```c
void FUN_00132ec0(undefined8 param_1,undefined8 param_2)

{
  int iVar1;
  long lVar2;
  
  lVar2 = FUN_00132c68();
  iVar1 = (int)lVar2;
  if (lVar2 != 0) {
    lVar2 = FUN_001325c8(param_1,0xffff,param_2);
    if (-1 < lVar2) {
      *(int *)((int)param_1 + 0x274) =
           iVar1 + *(int *)((int)lVar2 * 4 + iVar1 + *(int *)(iVar1 + 0x1c));
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
