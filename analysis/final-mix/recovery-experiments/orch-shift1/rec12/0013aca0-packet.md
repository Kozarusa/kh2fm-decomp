# Target packet 0013aca0

- Range: `0013aca0`..`0013ad1c`, **124 bytes = 31 instructions**. This size is the acceptance size.
- Layout name: `FUN_0013aca0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0013aa78` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0013aca0: 27bdfff0  addiu	sp,sp,-16
0013aca4: 3c0f0035  lui	t7,0x35
0013aca8: ffbf0008  sd	ra,8(sp)
0013acac: 00c0682d  move	t5,a2
0013acb0: ffb00000  sd	s0,0(sp)
0013acb4: 00a0302d  move	a2,a1
0013acb8: 00e0602d  move	t4,a3
0013acbc: 0100582d  move	t3,t0
0013acc0: 8df08058  lw	s0,-32680(t7)   ; = D_00348058
0013acc4: 0120502d  move	t2,t1
0013acc8: 25ad0020  addiu	t5,t5,32
0013accc: 0080282d  move	a1,a0
0013acd0: 8e0e6ed0  lw	t6,28368(s0)
0013acd4: 01a0382d  move	a3,t5
0013acd8: 0180402d  move	t0,t4
0013acdc: 0160482d  move	t1,t3
0013ace0: 25ceffff  addiu	t6,t6,-1
0013ace4: ae0e6ed0  sw	t6,28368(s0)
0013ace8: 000e7880  sll	t7,t6,0x2
0013acec: 01f07821  addu	t7,t7,s0
0013acf0: 8dee6e40  lw	t6,28224(t7)
0013acf4: 240f0310  li	t7,784
0013acf8: 01cf7018  mult	t6,t6,t7
0013acfc: 020e8021  addu	s0,s0,t6
0013ad00: 0c04ea9e  jal	0x13aa78
0013ad04: 0200202d  move	a0,s0
0013ad08: 0200102d  move	v0,s0
0013ad0c: dfbf0008  ld	ra,8(sp)
0013ad10: dfb00000  ld	s0,0(sp)
0013ad14: 03e00008  jr	ra
0013ad18: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0013aca0(void)`

```c
int FUN_0013aca0(undefined8 param_1,undefined8 param_2,int param_3,undefined8 param_4,
                undefined8 param_5,undefined8 param_6)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00348058;
  iVar1 = *(int *)(DAT_00348058 + 0x6ed0) + -1;
  *(int *)(DAT_00348058 + 0x6ed0) = iVar1;
  iVar2 = iVar2 + *(int *)(iVar1 * 4 + iVar2 + 0x6e40) * 0x310;
  FUN_0013aa78(iVar2,param_1,param_2,param_3 + 0x20,param_4,param_5,param_6);
  return iVar2;
}
```

## Earlier attempts (newest first)

- none found
