# Target packet 0029dd00

- Range: `0029dd00`..`0029dd60`, **96 bytes = 24 instructions**. This size is the acceptance size.
- Layout name: `FUN_0029dd00`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002931a8` registry: `func_002931a8`
- `00293cb8` registry: none
- `00293de8` registry: `Tz::JmAlbum::GetImageName(unsigned int)`
- `002ff2e8` registry: `Tz::LayFileBuildData(void*, unsigned int)`
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`, `fm_primary_oneword_recovered_0023f8c8.cpp`, `fm_primary_oneword_recovered_00246968.cpp`
- `002ff918` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0029dd00: 27bdff70  addiu	sp,sp,-144
0029dd04: 3c0f0036  lui	t7,0x36
0029dd08: ffbf0080  sd	ra,128(sp)
0029dd0c: 8deef5ac  lw	t6,-2644(t7)   ; = D_0035f5ac
0029dd10: 0c0a4f7a  jal	0x293de8
0029dd14: 81c40004  lb	a0,4(t6)
0029dd18: 0040302d  move	a2,v0
0029dd1c: 03a0202d  move	a0,sp
0029dd20: 0c0a4f2e  jal	0x293cb8
0029dd24: 24050004  li	a1,4
0029dd28: 3c0f0036  lui	t7,0x36
0029dd2c: 03a0202d  move	a0,sp
0029dd30: 0c0bfe46  jal	0x2ff918
0029dd34: 8de5f5c8  lw	a1,-2616(t7)   ; = D_0035f5c8
0029dd38: 10400004  beqz	v0,0x29dd4c
0029dd3c: 0040202d  move	a0,v0
0029dd40: 3c0f0036  lui	t7,0x36
0029dd44: 0c0bfcba  jal	0x2ff2e8
0029dd48: 8de5f5cc  lw	a1,-2612(t7)   ; = D_0035f5cc
0029dd4c: 0c0a4c6a  jal	0x2931a8
0029dd50: 03a0202d  move	a0,sp
0029dd54: dfbf0080  ld	ra,128(sp)
0029dd58: 03e00008  jr	ra
0029dd5c: 27bd0090  addiu	sp,sp,144
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0029dd00(void)`

```c
void FUN_0029dd00(void)

{
  undefined8 uVar1;
  long lVar2;
  undefined1 auStack_90 [128];
  
  uVar1 = FUN_00293de8(*(undefined1 *)(DAT_0035f5ac + 4));
  FUN_00293cb8(auStack_90,4,uVar1);
  lVar2 = FUN_002ff918(auStack_90,PTR_DAT_0035f5c8);
  if (lVar2 != 0) {
    FUN_002ff2e8(lVar2,PTR_DAT_0035f5cc);
  }
  FUN_002931a8(auStack_90);
  return;
}
```

## Earlier attempts (newest first)

- none found
