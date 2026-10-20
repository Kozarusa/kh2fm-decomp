# Target packet 001ac5b8

- Range: `001ac5b8`..`001ac62c`, **116 bytes = 29 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ac5b8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ac5b8: 3c0f0035  lui	t7,0x35
001ac5bc: 3c0e01c7  lui	t6,0x1c7
001ac5c0: 25ef0c50  addiu	t7,t7,3152   ; = D_00350c50
001ac5c4: ac8f0000  sw	t7,0(a0)
001ac5c8: 8dcfced0  lw	t7,-12592(t6)   ; = D_01c6ced0
001ac5cc: 548f000b  bnel	a0,t7,0x1ac5fc
001ac5d0: 8dee007c  lw	t6,124(t7)
001ac5d4: 8c8f007c  lw	t7,124(a0)
001ac5d8: 0000682d  move	t5,zero
001ac5dc: adcfced0  sw	t7,-12592(t6)
001ac5e0: 3c0f01c7  lui	t7,0x1c7
001ac5e4: 25efced0  addiu	t7,t7,-12592   ; = D_01c6ced0
001ac5e8: 8dee0004  lw	t6,4(t7)
001ac5ec: 508e0001  beql	a0,t6,0x1ac5f4
001ac5f0: aded0004  sw	t5,4(t7)
001ac5f4: 03e00008  jr	ra
001ac5f8: ac80007c  sw	zero,124(a0)
001ac5fc: 11c40008  beq	t6,a0,0x1ac620
001ac600: 01e0682d  move	t5,t7
001ac604: 8dcf007c  lw	t7,124(t6)
001ac608: 01c0682d  move	t5,t6
001ac60c: 00000000  nop
001ac610: 00000000  nop
001ac614: 00000000  nop
001ac618: 15e4fffa  bne	t7,a0,0x1ac604
001ac61c: 01e0702d  move	t6,t7
001ac620: 8c8f007c  lw	t7,124(a0)
001ac624: 1000ffee  b	0x1ac5e0
001ac628: adaf007c  sw	t7,124(t5)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ac5b8(void)`

```c
void FUN_001ac5b8(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *param_1 = &PTR_LAB_00350c50;
  if (param_1 == DAT_01c6ced0) {
    DAT_01c6ced0 = (undefined4 *)param_1[0x1f];
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)DAT_01c6ced0[0x1f];
    puVar3 = DAT_01c6ced0;
    while (puVar1 = puVar2, puVar1 != param_1) {
      puVar3 = puVar1;
      puVar2 = (undefined4 *)puVar1[0x1f];
    }
    puVar3[0x1f] = param_1[0x1f];
  }
  if (param_1 == DAT_01c6ced4) {
    DAT_01c6ced4 = puVar3;
  }
  param_1[0x1f] = 0;
  return;
}
```

## Earlier attempts (newest first)

- none found
