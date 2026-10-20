# Target packet 00159ef8

- Range: `00159ef8`..`00159f50`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_00159ef8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0016c028` registry: `func_0016c028`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00159ef8: 27bdfff0  addiu	sp,sp,-16
00159efc: 0080782d  move	t7,a0
00159f00: ffb00000  sd	s0,0(sp)
00159f04: ffbf0008  sd	ra,8(sp)
00159f08: 25f00080  addiu	s0,t7,128
00159f0c: 0c05b00a  jal	0x16c028
00159f10: 8c840044  lw	a0,68(a0)
00159f14: 3c0f0035  lui	t7,0x35
00159f18: 25efaa50  addiu	t7,t7,-21936   ; = D_0034aa50
00159f1c: 520f0004  beql	s0,t7,0x159f30
00159f20: 25ef0010  addiu	t7,t7,16
00159f24: 7a080000  lq	t0,0(s0)
00159f28: 7de80000  sq	t0,0(t7)
00159f2c: 25ef0010  addiu	t7,t7,16
00159f30: 104f0004  beq	v0,t7,0x159f44
00159f34: dfb00000  ld	s0,0(sp)
00159f38: 78480000  lq	t0,0(v0)
00159f3c: 7de80000  sq	t0,0(t7)
00159f40: dfb00000  ld	s0,0(sp)
00159f44: dfbf0008  ld	ra,8(sp)
00159f48: 03e00008  jr	ra
00159f4c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00159ef8(void)`

```c
void FUN_00159ef8(int param_1)

{
  undefined4 *puVar1;
  long lVar2;
  
  lVar2 = FUN_0016c028(*(undefined4 *)(param_1 + 0x44));
  puVar1 = (undefined4 *)lVar2;
  if ((undefined4 *)(param_1 + 0x80) != &DAT_0034aa50) {
    DAT_0034aa50 = *(undefined4 *)(param_1 + 0x80);
    DAT_0034aa54 = *(undefined4 *)(param_1 + 0x84);
    DAT_0034aa58 = *(undefined4 *)(param_1 + 0x88);
    DAT_0034aa5c = *(undefined4 *)(param_1 + 0x8c);
  }
  if (lVar2 != 0x34aa60) {
    DAT_0034aa60 = *puVar1;
    DAT_0034aa64 = puVar1[1];
    DAT_0034aa68 = puVar1[2];
    DAT_0034aa6c = puVar1[3];
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
