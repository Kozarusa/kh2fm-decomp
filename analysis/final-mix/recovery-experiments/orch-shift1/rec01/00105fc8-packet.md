# Target packet 00105fc8

- Range: `00105fc8`..`00106044`, **124 bytes = 31 instructions**. This size is the acceptance size.
- Layout name: `FUN_00105fc8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00102c80` registry: `_Z12getFieldModev`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_more_recovered.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`
- `001058e8` registry: `_Z10getSaveRamv`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_00232510.cpp`
- `00105f98` registry: `func_00105f98`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00105fc8: 27bdffe0  addiu	sp,sp,-32
00105fcc: 340fffff  li	t7,0xffff
00105fd0: ffbf0018  sd	ra,24(sp)
00105fd4: ffb00010  sd	s0,16(sp)
00105fd8: a7af0008  sh	t7,8(sp)
00105fdc: a3af0000  sb	t7,0(sp)
00105fe0: a3af0001  sb	t7,1(sp)
00105fe4: a3af0002  sb	t7,2(sp)
00105fe8: a7af0004  sh	t7,4(sp)
00105fec: 0c04163a  jal	0x1058e8
00105ff0: a7af0006  sh	t7,6(sp)
00105ff4: 240f000f  li	t7,15
00105ff8: a04f000c  sb	t7,12(v0)
00105ffc: 0c04163a  jal	0x1058e8
00106000: a3af0000  sb	t7,0(sp)
00106004: a040000d  sb	zero,13(v0)
00106008: 0c04163a  jal	0x1058e8
0010600c: a3a00001  sb	zero,1(sp)
00106010: 0c0417e6  jal	0x105f98
00106014: 0040802d  move	s0,v0
00106018: a202000e  sb	v0,14(s0)
0010601c: 0c040b20  jal	0x102c80
00106020: a3a20002  sb	v0,2(sp)
00106024: 8c4e0000  lw	t6,0(v0)
00106028: 8dcf0000  lw	t7,0(t6)
0010602c: 01e0f809  jalr	t7
00106030: 0040202d  move	a0,v0
00106034: dfb00010  ld	s0,16(sp)
00106038: dfbf0018  ld	ra,24(sp)
0010603c: 03e00008  jr	ra
00106040: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00105fc8(void)`

```c
void FUN_00105fc8(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined8 uVar3;
  
  iVar2 = FUN_001058e8();
  *(undefined1 *)(iVar2 + 0xc) = 0xf;
  iVar2 = FUN_001058e8();
  *(undefined1 *)(iVar2 + 0xd) = 0;
  iVar2 = FUN_001058e8();
  uVar1 = FUN_00105f98();
  *(undefined1 *)(iVar2 + 0xe) = uVar1;
  uVar3 = FUN_00102c80();
  (**(code **)*(undefined4 *)uVar3)(uVar3);
  return;
}
```

## Earlier attempts (newest first)

- none found
