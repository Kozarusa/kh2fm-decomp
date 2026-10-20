# Target packet 002a94f8

- Range: `002a94f8`..`002a956c`, **116 bytes = 29 instructions**. This size is the acceptance size.
- Layout name: `FUN_002a94f8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00139d78` registry: `_Z16u_call4_00139d78jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_argument_recovered.cpp`, `fm_primary_argumentfinish_recovered.cpp`, `fm_primary_close_recovered.cpp`
- `00276a18` registry: `func_00276a18`
- `00276b10` registry: `func_00276b10`
  - accepted sources that already call it (copy their declaration): `fm_primary_orcheh_recovered_00276b10.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002a94f8: 27bdffe0  addiu	sp,sp,-32
002a94fc: ffb00000  sd	s0,0(sp)
002a9500: ffb10008  sd	s1,8(sp)
002a9504: ffb20010  sd	s2,16(sp)
002a9508: 0000802d  move	s0,zero
002a950c: ffbf0018  sd	ra,24(sp)
002a9510: 24110009  li	s1,9
002a9514: 3c120036  lui	s2,0x36
002a9518: 8e44f60c  lw	a0,-2548(s2)   ; = D_0035f60c
002a951c: 0c04e75e  jal	0x139d78
002a9520: 00902021  addu	a0,a0,s0
002a9524: 10400006  beqz	v0,0x2a9540
002a9528: 8e44f60c  lw	a0,-2548(s2)   ; = D_0035f60c
002a952c: 02042021  addu	a0,s0,a0
002a9530: 8c8e0000  lw	t6,0(a0)
002a9534: 8dcf0014  lw	t7,20(t6)
002a9538: 01e0f809  jalr	t7
002a953c: 00000000  nop
002a9540: 2631ffff  addiu	s1,s1,-1
002a9544: 0621fff4  bgez	s1,0x2a9518
002a9548: 261001b4  addiu	s0,s0,436
002a954c: 0c09da86  jal	0x276a18
002a9550: 00000000  nop
002a9554: dfb00000  ld	s0,0(sp)
002a9558: dfb10008  ld	s1,8(sp)
002a955c: dfb20010  ld	s2,16(sp)
002a9560: dfbf0018  ld	ra,24(sp)
002a9564: 0809dac4  j	0x276b10
002a9568: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002a94f8(void)`

```c
void FUN_002a94f8(void)

{
  long lVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 9;
  do {
    lVar1 = FUN_00139d78(DAT_0035f60c + iVar2);
    if (lVar1 != 0) {
      (**(code **)(*(int *)(iVar2 + DAT_0035f60c) + 0x14))();
    }
    iVar3 = iVar3 + -1;
    iVar2 = iVar2 + 0x1b4;
  } while (-1 < iVar3);
  FUN_00276a18();
  FUN_00276b10();
  return;
}
```

## Earlier attempts (newest first)

- none found
