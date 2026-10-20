# Target packet 00187ab8

- Range: `00187ab8`..`00187b2c`, **116 bytes = 29 instructions**. This size is the acceptance size.
- Layout name: `FUN_00187ab8`
- Registry names for this address: `_Z16ctarget_00187ab8jjjj`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002ff1a4` registry: `func_002ff1a4`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00187ab8: 27bdffe0  addiu	sp,sp,-32
00187abc: 0000782d  move	t7,zero
00187ac0: ffb20010  sd	s2,16(sp)
00187ac4: ffb00000  sd	s0,0(sp)
00187ac8: ffb10008  sd	s1,8(sp)
00187acc: ffbf0018  sd	ra,24(sp)
00187ad0: 1080000f  beqz	a0,0x187b10
00187ad4: 00a0902d  move	s2,a1
00187ad8: 0080802d  move	s0,a0
00187adc: 0000882d  move	s1,zero
00187ae0: 8e0f0000  lw	t7,0(s0)
00187ae4: 11e00005  beqz	t7,0x187afc
00187ae8: 01e0282d  move	a1,t7
00187aec: 0c0bfc69  jal	0x2ff1a4
00187af0: 0240202d  move	a0,s2
00187af4: 10400006  beqz	v0,0x187b10
00187af8: 0200782d  move	t7,s0
00187afc: 26310001  addiu	s1,s1,1
00187b00: 2a2f0080  slti	t7,s1,128
00187b04: 15e0fff6  bnez	t7,0x187ae0
00187b08: 26100020  addiu	s0,s0,32
00187b0c: 0000782d  move	t7,zero
00187b10: dfb00000  ld	s0,0(sp)
00187b14: 01e0102d  move	v0,t7
00187b18: dfb10008  ld	s1,8(sp)
00187b1c: dfb20010  ld	s2,16(sp)
00187b20: dfbf0018  ld	ra,24(sp)
00187b24: 03e00008  jr	ra
00187b28: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00187ab8(void)`

```c
int * FUN_00187ab8(int *param_1,undefined8 param_2)

{
  long lVar1;
  int iVar2;
  
  if (param_1 != (int *)0x0) {
    iVar2 = 0;
    do {
      if ((*param_1 != 0) && (lVar1 = FUN_002ff1a4(param_2,*param_1), lVar1 == 0)) {
        return param_1;
      }
      iVar2 = iVar2 + 1;
      param_1 = param_1 + 8;
    } while (iVar2 < 0x80);
  }
  return (int *)0x0;
}
```

## Earlier attempts (newest first)

- none found
