# Target packet 001c11e0

- Range: `001c11e0`..`001c1218`, **56 bytes = 14 instructions**. This size is the acceptance size.
- Layout name: `FUN_001c11e0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001c11e0: 3c0f01d5  lui	t7,0x1d5
001c11e4: 240d0005  li	t5,5
001c11e8: 25ef9388  addiu	t7,t7,-27768   ; = D_01d49388
001c11ec: 25ee0140  addiu	t6,t7,320
001c11f0: 95cf0000  lhu	t7,0(t6)
001c11f4: 01c0102d  move	v0,t6
001c11f8: 15e00005  bnez	t7,0x1c1210
001c11fc: 25ceffc0  addiu	t6,t6,-64
001c1200: 25adffff  addiu	t5,t5,-1
001c1204: 5da0fffb  bgtzl	t5,0x1c11f4
001c1208: 95cf0000  lhu	t7,0(t6)
001c120c: 0000102d  move	v0,zero
001c1210: 03e00008  jr	ra
001c1214: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001c11e0(void)`

```c
short * FUN_001c11e0(void)

{
  short sVar1;
  int iVar2;
  short *psVar3;
  
  iVar2 = 5;
  psVar3 = &DAT_01d494c8;
  sVar1 = DAT_01d494c8;
  while( true ) {
    if (sVar1 != 0) {
      return psVar3;
    }
    iVar2 = iVar2 + -1;
    if (iVar2 < 1) break;
    sVar1 = psVar3[-0x20];
    psVar3 = psVar3 + -0x20;
  }
  return (short *)0x0;
}
```

## Earlier attempts (newest first)

- none found
