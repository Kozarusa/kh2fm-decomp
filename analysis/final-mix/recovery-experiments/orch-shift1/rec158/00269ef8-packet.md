# Target packet 00269ef8

- Range: `00269ef8`..`00269f58`, **96 bytes = 24 instructions**. This size is the acceptance size.
- Layout name: `FUN_00269ef8`
- Registry names for this address: `func_00269ef8`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002579e0` registry: `func_002579e0`
- `0028abe0` registry: `Tz::Select::Destroy(...)`
- `0028acc8` registry: `Tz::Select::isCreated(...)`
  - accepted sources that already call it (copy their declaration): `fm_primary_orcheb_recovered_002519d0.cpp`, `fm_primary_orchec_recovered_002576d0.cpp`, `fm_primary_orchee_recovered_00262290.cpp`, `fm_primary_orchef_recovered_002656c0.cpp`
- `0028be18` registry: `_ZN2Tz9ScrollBar5LeaveEv`
- `0028be58` registry: `Tz::LeadDataIsActive(unsigned int)`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_002908f0.cpp`, `fm_primary_orchee_recovered_00262290.cpp`, `fm_primary_threeword_recovered_0026dcb8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00269ef8: 27bdfff0  addiu	sp,sp,-16
00269efc: ffb00000  sd	s0,0(sp)
00269f00: ffbf0008  sd	ra,8(sp)
00269f04: 0c095e78  jal	0x2579e0
00269f08: 3c100036  lui	s0,0x36
00269f0c: 0c0a2f96  jal	0x28be58
00269f10: 8e04f04c  lw	a0,-4020(s0)   ; = D_0035f04c
00269f14: 50400004  beqzl	v0,0x269f28
00269f18: 3c100036  lui	s0,0x36
00269f1c: 0c0a2f86  jal	0x28be18
00269f20: 8e04f04c  lw	a0,-4020(s0)   ; = D_0035f04c
00269f24: 3c100036  lui	s0,0x36
00269f28: 0c0a2b32  jal	0x28acc8
00269f2c: 8e04f01c  lw	a0,-4068(s0)   ; = D_0035f01c
00269f30: 50400006  beqzl	v0,0x269f4c
00269f34: dfb00000  ld	s0,0(sp)
00269f38: 8e04f01c  lw	a0,-4068(s0)
00269f3c: dfbf0008  ld	ra,8(sp)
00269f40: dfb00000  ld	s0,0(sp)
00269f44: 080a2af8  j	0x28abe0
00269f48: 27bd0010  addiu	sp,sp,16
00269f4c: dfbf0008  ld	ra,8(sp)
00269f50: 03e00008  jr	ra
00269f54: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00269ef8(void)`

```c
void FUN_00269ef8(void)

{
  long lVar1;
  
  FUN_002579e0();
  lVar1 = FUN_0028be58(DAT_0035f04c);
  if (lVar1 != 0) {
    FUN_0028be18(DAT_0035f04c);
  }
  lVar1 = FUN_0028acc8(DAT_0035f01c);
  if (lVar1 != 0) {
    FUN_0028abe0(DAT_0035f01c);
    return;
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
