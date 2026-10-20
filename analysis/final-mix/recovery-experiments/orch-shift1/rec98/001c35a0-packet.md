# Target packet 001c35a0

- Range: `001c35a0`..`001c3614`, **116 bytes = 29 instructions**. This size is the acceptance size.
- Layout name: `FUN_001c35a0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001c35a0: 3c0f0037  lui	t7,0x37
001c35a4: 0000502d  move	t2,zero
001c35a8: 25ebdde8  addiu	t3,t7,-8728   ; = D_0036dde8
001c35ac: 24090001  li	t1,1
001c35b0: 240c0004  li	t4,4
001c35b4: 01444021  addu	t0,t2,a0
001c35b8: 016c7821  addu	t7,t3,t4
001c35bc: 91ed0000  lbu	t5,0(t7)
001c35c0: 000d7142  srl	t6,t5,0x5
001c35c4: 000e7080  sll	t6,t6,0x2
001c35c8: 31ad001f  andi	t5,t5,0x1f
001c35cc: 01c47021  addu	t6,t6,a0
001c35d0: 01a96804  sllv	t5,t1,t5
001c35d4: 8dcf0000  lw	t7,0(t6)
001c35d8: 01ed7824  and	t7,t7,t5
001c35dc: 11e00008  beqz	t7,0x1c3600
001c35e0: 258f0001  addiu	t7,t4,1
001c35e4: a10f0020  sb	t7,32(t0)
001c35e8: 254a0001  addiu	t2,t2,1
001c35ec: 294f0005  slti	t7,t2,5
001c35f0: 15e0ffef  bnez	t7,0x1c35b0
001c35f4: 256b0005  addiu	t3,t3,5
001c35f8: 03e00008  jr	ra
001c35fc: 00000000  nop
001c3600: 258cffff  addiu	t4,t4,-1
001c3604: 0581ffed  bgez	t4,0x1c35bc
001c3608: 016c7821  addu	t7,t3,t4
001c360c: 1000fff7  b	0x1c35ec
001c3610: 254a0001  addiu	t2,t2,1
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001c35a0(void)`

```c
void FUN_001c35a0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  
  iVar1 = 0;
  iVar2 = 0x36dde8;
  do {
    iVar3 = 4;
    pbVar4 = (byte *)(iVar2 + 4);
    do {
      if ((*(uint *)((uint)(*pbVar4 >> 5) * 4 + param_1) & 1 << (*pbVar4 & 0x1f)) != 0) {
        *(char *)(iVar1 + param_1 + 0x20) = (char)iVar3 + '\x01';
        break;
      }
      iVar3 = iVar3 + -1;
      pbVar4 = (byte *)(iVar2 + iVar3);
    } while (-1 < iVar3);
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 5;
    if (4 < iVar1) {
      return;
    }
  } while( true );
}
```

## Earlier attempts (newest first)

- 28 differing words, 124/116 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_04.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_04.cpp`)
