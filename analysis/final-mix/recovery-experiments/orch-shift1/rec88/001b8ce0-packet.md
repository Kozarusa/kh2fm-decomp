# Target packet 001b8ce0

- Range: `001b8ce0`..`001b8d60`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_001b8ce0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001b8838` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001b8ce0: 27bdffd0  addiu	sp,sp,-48
001b8ce4: 3c0d01d5  lui	t5,0x1d5
001b8ce8: ffb00000  sd	s0,0(sp)
001b8cec: ffb10008  sd	s1,8(sp)
001b8cf0: ffb20010  sd	s2,16(sp)
001b8cf4: 8daf8d90  lw	t7,-29296(t5)   ; = D_01d48d90
001b8cf8: 0000882d  move	s1,zero
001b8cfc: ffb30018  sd	s3,24(sp)
001b8d00: 0080902d  move	s2,a0
001b8d04: ffbf0020  sd	ra,32(sp)
001b8d08: 8dee0004  lw	t6,4(t7)
001b8d0c: 19c0000d  blez	t6,0x1b8d44
001b8d10: 25f00008  addiu	s0,t7,8
001b8d14: 01a0982d  move	s3,t5
001b8d18: 8e0f0004  lw	t7,4(s0)
001b8d1c: 15f20004  bne	t7,s2,0x1b8d30
001b8d20: 8e6e8d90  lw	t6,-29296(s3)
001b8d24: 0c06e20e  jal	0x1b8838
001b8d28: 92040000  lbu	a0,0(s0)
001b8d2c: 8e6e8d90  lw	t6,-29296(s3)
001b8d30: 26310001  addiu	s1,s1,1
001b8d34: 8dcf0004  lw	t7,4(t6)
001b8d38: 022f782a  slt	t7,s1,t7
001b8d3c: 15e0fff6  bnez	t7,0x1b8d18
001b8d40: 26100010  addiu	s0,s0,16
001b8d44: dfb00000  ld	s0,0(sp)
001b8d48: dfb10008  ld	s1,8(sp)
001b8d4c: dfb20010  ld	s2,16(sp)
001b8d50: dfb30018  ld	s3,24(sp)
001b8d54: dfbf0020  ld	ra,32(sp)
001b8d58: 03e00008  jr	ra
001b8d5c: 27bd0030  addiu	sp,sp,48
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001b8ce0(void)`

```c
void FUN_001b8ce0(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = (undefined1 *)(DAT_01d48d90 + 8);
  if (0 < *(int *)(DAT_01d48d90 + 4)) {
    do {
      if (*(int *)(puVar1 + 4) == param_1) {
        FUN_001b8838(*puVar1);
      }
      iVar2 = iVar2 + 1;
      puVar1 = puVar1 + 0x10;
    } while (iVar2 < *(int *)(DAT_01d48d90 + 4));
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
