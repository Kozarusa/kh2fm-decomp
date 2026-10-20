# Target packet 00171fa8

- Range: `00171fa8`..`00172008`, **96 bytes = 24 instructions**. This size is the acceptance size.
- Layout name: `FUN_00171fa8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0016cf00` registry: `_ZN2YS2VM3dupEiiP8BD_VALUEi`
  - accepted sources that already call it (copy their declaration): `fm_scalar_extra_recovered_12.cpp`
- `00177460` registry: `_ZN2YS5PARTY4hookEPNS_2VME`
  - accepted sources that already call it (copy their declaration): `fm_primary_threeword_recovered_00177460.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00171fa8: 27bdffe0  addiu	sp,sp,-32
00171fac: 24080001  li	t0,1
00171fb0: ffb00010  sd	s0,16(sp)
00171fb4: ffbf0018  sd	ra,24(sp)
00171fb8: 8c8f0000  lw	t7,0(a0)
00171fbc: 8c8e0008  lw	t6,8(a0)
00171fc0: 8df00004  lw	s0,4(t7)
00171fc4: 11c00003  beqz	t6,0x171fd4
00171fc8: afb00000  sw	s0,0(sp)
00171fcc: afae0004  sw	t6,4(sp)
00171fd0: 24080002  li	t0,2
00171fd4: 8c860004  lw	a2,4(a0)
00171fd8: 3c0f0035  lui	t7,0x35
00171fdc: 03a0382d  move	a3,sp
00171fe0: 0000282d  move	a1,zero
00171fe4: 0c05b3c0  jal	0x16cf00
00171fe8: 8de4d8a0  lw	a0,-10080(t7)   ; = D_0034d8a0
00171fec: 0200202d  move	a0,s0
00171ff0: 0c05dd18  jal	0x177460
00171ff4: 0040282d  move	a1,v0
00171ff8: dfb00010  ld	s0,16(sp)
00171ffc: dfbf0018  ld	ra,24(sp)
00172000: 03e00008  jr	ra
00172004: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00171fa8(void)`

```c
void FUN_00171fa8(int *param_1)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  undefined4 uStack_20;
  int iStack_1c;
  
  uVar3 = 1;
  uVar1 = *(undefined4 *)(*param_1 + 4);
  if (param_1[2] != 0) {
    uVar3 = 2;
    iStack_1c = param_1[2];
  }
  uStack_20 = uVar1;
  uVar2 = FUN_0016cf00(DAT_0034d8a0,0,param_1[1],&uStack_20,uVar3);
  FUN_00177460(uVar1,uVar2);
  return;
}
```

## Earlier attempts (newest first)

- none found
