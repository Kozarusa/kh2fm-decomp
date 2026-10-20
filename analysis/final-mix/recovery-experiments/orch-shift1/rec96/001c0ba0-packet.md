# Target packet 001c0ba0

- Range: `001c0ba0`..`001c0c14`, **116 bytes = 29 instructions**. This size is the acceptance size.
- Layout name: `FUN_001c0ba0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001c0ba0: 3c0f01d5  lui	t7,0x1d5
001c0ba4: 0000582d  move	t3,zero
001c0ba8: 8dee9360  lw	t6,-27808(t7)   ; = D_01d49360
001c0bac: 8dcf0004  lw	t7,4(t6)
001c0bb0: 19e00016  blez	t7,0x1c0c0c
001c0bb4: 25cc0008  addiu	t4,t6,8
001c0bb8: 3c0f0033  lui	t7,0x33
001c0bbc: 01c0502d  move	t2,t6
001c0bc0: 25e8f254  addiu	t0,t7,-3500   ; = D_0032f254
001c0bc4: 24090001  li	t1,1
001c0bc8: 8d8f0004  lw	t7,4(t4)
001c0bcc: 55e4000b  bnel	t7,a0,0x1c0bfc
001c0bd0: 8d4f0004  lw	t7,4(t2)
001c0bd4: 8d8f0000  lw	t7,0(t4)
001c0bd8: 000f6942  srl	t5,t7,0x5
001c0bdc: 000d6880  sll	t5,t5,0x2
001c0be0: 31ef001f  andi	t7,t7,0x1f
001c0be4: 01a86821  addu	t5,t5,t0
001c0be8: 01e97804  sllv	t7,t1,t7
001c0bec: 8dae0000  lw	t6,0(t5)
001c0bf0: 01cf7025  or	t6,t6,t7
001c0bf4: adae0000  sw	t6,0(t5)
001c0bf8: 8d4f0004  lw	t7,4(t2)
001c0bfc: 256b0001  addiu	t3,t3,1
001c0c00: 016f782a  slt	t7,t3,t7
001c0c04: 15e0fff0  bnez	t7,0x1c0bc8
001c0c08: 258c0020  addiu	t4,t4,32
001c0c0c: 03e00008  jr	ra
001c0c10: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001c0ba0(void)`

```c
void FUN_001c0ba0(uint param_1)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  
  iVar1 = DAT_01d49360;
  iVar2 = 0;
  puVar3 = (uint *)(DAT_01d49360 + 8);
  if (0 < *(int *)(DAT_01d49360 + 4)) {
    do {
      if (puVar3[1] == param_1) {
        *(uint *)(&DAT_0032f254 + (*puVar3 >> 5) * 4) =
             *(uint *)(&DAT_0032f254 + (*puVar3 >> 5) * 4) | 1 << (*puVar3 & 0x1f);
        iVar4 = *(int *)(iVar1 + 4);
      }
      else {
        iVar4 = *(int *)(iVar1 + 4);
      }
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 8;
    } while (iVar2 < iVar4);
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
