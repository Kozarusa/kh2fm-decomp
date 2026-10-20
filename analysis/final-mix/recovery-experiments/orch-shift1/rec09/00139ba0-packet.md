# Target packet 00139ba0

- Range: `00139ba0`..`00139c14`, **116 bytes = 29 instructions**. This size is the acceptance size.
- Layout name: `FUN_00139ba0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00139718` registry: `func_00139718`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00139ba0: 27bdffe0  addiu	sp,sp,-32
00139ba4: ffb00000  sd	s0,0(sp)
00139ba8: ffb10008  sd	s1,8(sp)
00139bac: ffb20010  sd	s2,16(sp)
00139bb0: 0000802d  move	s0,zero
00139bb4: ffbf0018  sd	ra,24(sp)
00139bb8: 0080882d  move	s1,a0
00139bbc: 3c120034  lui	s2,0x34
00139bc0: 16000012  bnez	s0,0x139c0c
00139bc4: 8e447f80  lw	a0,32640(s2)   ; = D_00347f80
00139bc8: 8c840004  lw	a0,4(a0)
00139bcc: 14800008  bnez	a0,0x139bf0
00139bd0: 0080802d  move	s0,a0
00139bd4: dfb00000  ld	s0,0(sp)
00139bd8: dfb10008  ld	s1,8(sp)
00139bdc: dfb20010  ld	s2,16(sp)
00139be0: dfbf0018  ld	ra,24(sp)
00139be4: 03e00008  jr	ra
00139be8: 27bd0020  addiu	sp,sp,32
00139bec: 00000000  nop
00139bf0: 8c8f0010  lw	t7,16(a0)
00139bf4: 15f1fff2  bne	t7,s1,0x139bc0
00139bf8: 00000000  nop
00139bfc: 0c04e5c6  jal	0x139718
00139c00: 00000000  nop
00139c04: 1000ffee  b	0x139bc0
00139c08: 00000000  nop
00139c0c: 1000ffef  b	0x139bcc
00139c10: 8e040004  lw	a0,4(s0)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00139ba0(void)`

```c
void FUN_00139ba0(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (iVar1 == 0) {
      iVar1 = *(int *)(DAT_00347f80 + 4);
    }
    else {
      iVar1 = *(int *)(iVar1 + 4);
    }
    if (iVar1 == 0) break;
    if (*(int *)(iVar1 + 0x10) == param_1) {
      FUN_00139718();
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
