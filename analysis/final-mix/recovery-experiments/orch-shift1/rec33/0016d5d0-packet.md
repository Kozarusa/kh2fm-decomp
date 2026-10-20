# Target packet 0016d5d0

- Range: `0016d5d0`..`0016d63c`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_0016d5d0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0017d538` registry: none
- `002fd188` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_orchah_recovered_00142208.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0016d5d0: 27bdffe0  addiu	sp,sp,-32
0016d5d4: 3c0e004f  lui	t6,0x4f
0016d5d8: ffb00010  sd	s0,16(sp)
0016d5dc: ffbf0018  sd	ra,24(sp)
0016d5e0: 81cf6330  lb	t7,25392(t6)   ; = D_004f6330
0016d5e4: 15e00006  bnez	t7,0x16d600
0016d5e8: 0080802d  move	s0,a0
0016d5ec: 240f0001  li	t7,1
0016d5f0: 3c040017  lui	a0,0x17
0016d5f4: a1cf6330  sb	t7,25392(t6)   ; = D_004f6330
0016d5f8: 0c0bf462  jal	0x2fd188
0016d5fc: 2484e898  addiu	a0,a0,-5992   ; = D_0016e898
0016d600: 8e050000  lw	a1,0(s0)
0016d604: 03a0202d  move	a0,sp
0016d608: 0c05f54e  jal	0x17d538
0016d60c: c60c0004  lwc1	$f12,4(s0)
0016d610: 3c0f004f  lui	t7,0x4f
0016d614: 25ef6340  addiu	t7,t7,25408   ; = D_004f6340
0016d618: 53af0004  beql	sp,t7,0x16d62c
0016d61c: ae0f0000  sw	t7,0(s0)
0016d620: 7ba80000  lq	t0,0(sp)
0016d624: 7de80000  sq	t0,0(t7)
0016d628: ae0f0000  sw	t7,0(s0)
0016d62c: dfbf0018  ld	ra,24(sp)
0016d630: dfb00010  ld	s0,16(sp)
0016d634: 03e00008  jr	ra
0016d638: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0016d5d0(void)`

```c
void FUN_0016d5d0(undefined4 *param_1)

{
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if (DAT_004f6330 == '\0') {
    DAT_004f6330 = '\x01';
    FUN_002fd188(0x16e898);
  }
  FUN_0017d538(param_1[1],&uStack_20,*param_1);
  if (&stack0x00000000 == (undefined1 *)0x4f6360) {
    *param_1 = &DAT_004f6340;
  }
  else {
    DAT_004f6340 = uStack_20;
    DAT_004f6344 = uStack_1c;
    DAT_004f6348 = uStack_18;
    DAT_004f634c = uStack_14;
    *param_1 = &DAT_004f6340;
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
