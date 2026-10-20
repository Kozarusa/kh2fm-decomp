# Target packet 001e0fe8

- Range: `001e0fe8`..`001e1064`, **124 bytes = 31 instructions**. This size is the acceptance size.
- Layout name: `FUN_001e0fe8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001e2760` registry: `func_001e2760`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001e0fe8: 27bdfff0  addiu	sp,sp,-16
001e0fec: 3c0f0035  lui	t7,0x35
001e0ff0: ffb00000  sd	s0,0(sp)
001e0ff4: ffbf0008  sd	ra,8(sp)
001e0ff8: 0080802d  move	s0,a0
001e0ffc: 8de42bd0  lw	a0,11216(t7)   ; = D_00352bd0
001e1000: 0c0789d8  jal	0x1e2760
001e1004: 8e050020  lw	a1,32(s0)
001e1008: 904f0000  lbu	t7,0(v0)
001e100c: 25ee000a  addiu	t6,t7,10
001e1010: 000f7e00  sll	t7,t7,0x18
001e1014: 000e6e00  sll	t5,t6,0x18
001e1018: 000f7e03  sra	t7,t7,0x18
001e101c: 01c0602d  move	t4,t6
001e1020: 05e10007  bgez	t7,0x1e1040
001e1024: 000d6e03  sra	t5,t5,0x18
001e1028: 240f0002  li	t7,2
001e102c: ae0f0024  sw	t7,36(s0)
001e1030: dfb00000  ld	s0,0(sp)
001e1034: dfbf0008  ld	ra,8(sp)
001e1038: 03e00008  jr	ra
001e103c: 27bd0010  addiu	sp,sp,16
001e1040: 05a10002  bgez	t5,0x1e104c
001e1044: a04e0000  sb	t6,0(v0)
001e1048: 240cff80  li	t4,-128
001e104c: 240f000a  li	t7,10
001e1050: a04c0000  sb	t4,0(v0)
001e1054: a04f0003  sb	t7,3(v0)
001e1058: a0400001  sb	zero,1(v0)
001e105c: 1000fff4  b	0x1e1030
001e1060: a0400002  sb	zero,2(v0)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001e0fe8(void)`

```c
void FUN_001e0fe8(int param_1)

{
  char *pcVar1;
  char cVar2;
  
  pcVar1 = (char *)FUN_001e2760(DAT_00352bd0,*(undefined4 *)(param_1 + 0x20));
  cVar2 = *pcVar1 + '\n';
  if (*pcVar1 < '\0') {
    *(undefined4 *)(param_1 + 0x24) = 2;
  }
  else {
    *pcVar1 = cVar2;
    if (cVar2 < '\0') {
      cVar2 = -0x80;
    }
    *pcVar1 = cVar2;
    pcVar1[3] = '\n';
    pcVar1[1] = '\0';
    pcVar1[2] = '\0';
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
