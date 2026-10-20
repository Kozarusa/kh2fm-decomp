# Target packet 00203ae8

- Range: `00203ae8`..`00203b44`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_00203ae8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00203ae8: 8c8f0050  lw	t7,80(a0)
00203aec: 11e00013  beqz	t7,0x203b3c
00203af0: 0000102d  move	v0,zero
00203af4: 90ae00cc  lbu	t6,204(a1)
00203af8: 240f0001  li	t7,1
00203afc: 11cf0005  beq	t6,t7,0x203b14
00203b00: 240f0003  li	t7,3
00203b04: 11cf0003  beq	t6,t7,0x203b14
00203b08: 240f0002  li	t7,2
00203b0c: 55cf0005  bnel	t6,t7,0x203b24
00203b10: 90af00c9  lbu	t7,201(a1)
00203b14: 8c8f0054  lw	t7,84(a0)
00203b18: 11e00008  beqz	t7,0x203b3c
00203b1c: 0000102d  move	v0,zero
00203b20: 90af00c9  lbu	t7,201(a1)
00203b24: 11e00005  beqz	t7,0x203b3c
00203b28: 24020001  li	v0,1
00203b2c: 8c8f0058  lw	t7,88(a0)
00203b30: 11e00002  beqz	t7,0x203b3c
00203b34: 0000102d  move	v0,zero
00203b38: 24020001  li	v0,1
00203b3c: 03e00008  jr	ra
00203b40: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00203ae8(void)`

```c
undefined4 FUN_00203ae8(int param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 0x50) != 0) {
    cVar1 = *(char *)(param_2 + 0xcc);
    if (((cVar1 == '\x01') || (cVar1 == '\x03')) || (cVar1 == '\x02')) {
      if (*(int *)(param_1 + 0x54) == 0) {
        return 0;
      }
      cVar1 = *(char *)(param_2 + 0xc9);
    }
    else {
      cVar1 = *(char *)(param_2 + 0xc9);
    }
    uVar2 = 1;
    if ((cVar1 != '\0') && (uVar2 = 0, *(int *)(param_1 + 0x58) != 0)) {
      uVar2 = 1;
    }
  }
  return uVar2;
}
```

## Earlier attempts (newest first)

- 11 differing words, 84/92 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_05.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_05.cpp`)
