# Target packet 00272ae0

- Range: `00272ae0`..`00272b60`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_00272ae0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00272b60` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`
- `00273140` registry: `_ZN2Tz8CmCustom10GetItemTblEi`
- `00286068` registry: none
- `00286280` registry: `func_00286280`
- `00287bc0` registry: `_ZN2Tz8MenuBase7GetModeEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`
- `0028b040` registry: `Tz::JmReport::GetData(unsigned int)`
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_twoword_recovered_0026ec70.cpp`, `fm_primary_twoword_recovered_00276410.cpp`, `fm_primary_twoword_recovered_002806c8.cpp`, `fm_scalar_extra_recovered_07.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00272ae0: 27bdfff0  addiu	sp,sp,-16
00272ae4: ffbf0008  sd	ra,8(sp)
00272ae8: ffb00000  sd	s0,0(sp)
00272aec: 0c0a1ef0  jal	0x287bc0
00272af0: 00000000  nop
00272af4: 3c0f0036  lui	t7,0x36
00272af8: 0c0a2c10  jal	0x28b040
00272afc: 8de4f01c  lw	a0,-4068(t7)   ; = D_0035f01c
00272b00: 0040802d  move	s0,v0
00272b04: 0c09cad8  jal	0x272b60
00272b08: 0040202d  move	a0,v0
00272b0c: 2c420002  sltiu	v0,v0,2
00272b10: 1040000f  beqz	v0,0x272b50
00272b14: 0200202d  move	a0,s0
00272b18: 0c09cc50  jal	0x273140
00272b1c: 00000000  nop
00272b20: 1040000c  beqz	v0,0x272b54
00272b24: dfb00000  ld	s0,0(sp)
00272b28: 94500000  lhu	s0,0(v0)
00272b2c: 0c0a181a  jal	0x286068
00272b30: 0200202d  move	a0,s0
00272b34: 10400006  beqz	v0,0x272b50
00272b38: 0200202d  move	a0,s0
00272b3c: dfb00000  ld	s0,0(sp)
00272b40: dfbf0008  ld	ra,8(sp)
00272b44: 080a18a0  j	0x286280
00272b48: 27bd0010  addiu	sp,sp,16
00272b4c: 00000000  nop
00272b50: dfb00000  ld	s0,0(sp)
00272b54: dfbf0008  ld	ra,8(sp)
00272b58: 03e00008  jr	ra
00272b5c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00272ae0(void)`

```c
void FUN_00272ae0(void)

{
  undefined2 uVar1;
  undefined8 uVar2;
  ulong uVar3;
  long lVar4;
  
  FUN_00287bc0();
  uVar2 = FUN_0028b040(DAT_0035f01c);
  uVar3 = FUN_00272b60(uVar2);
  if ((uVar3 < 2) && (lVar4 = FUN_00273140(uVar2), lVar4 != 0)) {
    uVar1 = *(undefined2 *)lVar4;
    lVar4 = FUN_00286068(uVar1);
    if (lVar4 != 0) {
      FUN_00286280(uVar1);
      return;
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
