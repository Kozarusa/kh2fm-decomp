# Target packet 001e65d0

- Range: `001e65d0`..`001e6630`, **96 bytes = 24 instructions**. This size is the acceptance size.
- Layout name: `FUN_001e65d0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001e5610` registry: none
- `001e5898` registry: none
- `001e5990` registry: `func_001e5990`
- `002f25a0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_002e8c28.cpp`, `fm_primary_floatpacket_recovered_002e8c58.cpp`, `fm_primary_globalcall_recovered_0020f118.cpp`, `fm_primary_globalcall_recovered_0020f150.cpp`, `fm_primary_oneword_recovered_002ef1b8.cpp`
- `002f3918` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_globalcall_recovered_0020f118.cpp`, `fm_primary_globalcall_recovered_0020f150.cpp`, `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`, `fm_primary_oneword_recovered_0023f8c8.cpp`
- `003058a0` registry: `FlushCache`
  - accepted sources that already call it (copy their declaration): `fm_boundary_initializers.cpp`, `fm_primary_orchal_recovered_0014d8d0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001e65d0: 27bdfff0  addiu	sp,sp,-16
001e65d4: 3c040035  lui	a0,0x35
001e65d8: ffbf0008  sd	ra,8(sp)
001e65dc: ffb00000  sd	s0,0(sp)
001e65e0: 0c079664  jal	0x1e5990
001e65e4: 24844698  addiu	a0,a0,18072   ; = D_00354698
001e65e8: 3c100035  lui	s0,0x35
001e65ec: 0c079584  jal	0x1e5610
001e65f0: 8e044648  lw	a0,17992(s0)   ; = D_00354648
001e65f4: 0c079626  jal	0x1e5898
001e65f8: 8e044648  lw	a0,17992(s0)   ; = D_00354648
001e65fc: 0000282d  move	a1,zero
001e6600: 0c0bc968  jal	0x2f25a0
001e6604: 0000202d  move	a0,zero
001e6608: 0c0c1628  jal	0x3058a0
001e660c: 0000202d  move	a0,zero
001e6610: 3c0f0036  lui	t7,0x36
001e6614: dfb00000  ld	s0,0(sp)
001e6618: 8de491c8  lw	a0,-28216(t7)   ; = D_003591c8
001e661c: 3c050035  lui	a1,0x35
001e6620: dfbf0008  ld	ra,8(sp)
001e6624: 24a54650  addiu	a1,a1,18000   ; = D_00354650
001e6628: 080bce46  j	0x2f3918
001e662c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001e65d0(void)`

```c
void FUN_001e65d0(void)

{
  FUN_001e5990(0x354698);
  FUN_001e5610(DAT_00354648);
  FUN_001e5898(DAT_00354648);
  FUN_002f25a0(0,0);
  FlushCache(0);
  FUN_002f3918(DAT_003591c8,0x354650);
  return;
}
```

## Earlier attempts (newest first)

- none found
