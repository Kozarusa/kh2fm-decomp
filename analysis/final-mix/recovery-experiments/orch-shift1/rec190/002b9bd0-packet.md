# Target packet 002b9bd0

- Range: `002b9bd0`..`002b9c30`, **96 bytes = 24 instructions**. This size is the acceptance size.
- Layout name: `FUN_002b9bd0`
- Registry names for this address: `_Z16wtarget_002b9bd0jjjj`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00102788` registry: `_ZN12TASK_MANAGER11create_taskEiiPFvP4TASKE`
  - accepted sources that already call it (copy their declaration): `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`, `fm_primary_fourwordfresh_recovered_00140ce8.cpp`, `fm_primary_oneword_recovered_001344b8.cpp`
- `002b691c` registry: `_Z16u_call4_002b691cjjjj`
- `002b9ad0` registry: `_Z16u_tail0_002b9ad0v`
- `002b9c80` registry: none
- `002bacc0` registry: none
- `002bbde0` registry: none
- `002bd538` registry: `func_002bd538`
  - accepted sources that already call it (copy their declaration): `fm_primary_workerbacklog_recovered_002bd538.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002b9bd0: 27bdfff0  addiu	sp,sp,-16
002b9bd4: ffbf0000  sd	ra,0(sp)
002b9bd8: 0c0ada47  jal	0x2b691c
002b9bdc: 0000202d  move	a0,zero
002b9be0: 0c0aef78  jal	0x2bbde0
002b9be4: 00000000  nop
002b9be8: 0c0aeb30  jal	0x2bacc0
002b9bec: 00000000  nop
002b9bf0: 0c0ae6b4  jal	0x2b9ad0
002b9bf4: 00000000  nop
002b9bf8: 0c0ae720  jal	0x2b9c80
002b9bfc: 00000000  nop
002b9c00: 0c0af54e  jal	0x2bd538
002b9c04: 00000000  nop
002b9c08: 3c0f0033  lui	t7,0x33
002b9c0c: dfbf0000  ld	ra,0(sp)
002b9c10: 8de4b91c  lw	a0,-18148(t7)   ; = D_0032b91c
002b9c14: 3c060007  lui	a2,0x7
002b9c18: 3c07002c  lui	a3,0x2c
002b9c1c: 0000282d  move	a1,zero
002b9c20: 24e79c60  addiu	a3,a3,-25504   ; = D_002b9c60
002b9c24: 34c6a12a  ori	a2,a2,0xa12a
002b9c28: 080409e2  j	0x102788
002b9c2c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002b9bd0(void)`

```c
void FUN_002b9bd0(void)

{
  FUN_002b691c(0);
  FUN_002bbde0();
  FUN_002bacc0();
  FUN_002b9ad0();
  FUN_002b9c80();
  FUN_002bd538();
  FUN_00102788(DAT_0032b91c,0,0x7a12a,0x2b9c60);
  return;
}
```

## Earlier attempts (newest first)

- none found
