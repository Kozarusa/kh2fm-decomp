# Target packet 00257fa8

- Range: `00257fa8`..`00257ff8`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_00257fa8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00257fa8: 3c0f0036  lui	t7,0x36
00257fac: 2402ffff  li	v0,-1
00257fb0: 95ecef70  lhu	t4,-4240(t7)   ; = D_0035ef70
00257fb4: 0000682d  move	t5,zero
00257fb8: 0000702d  move	t6,zero
00257fbc: 01cc7807  srav	t7,t4,t6
00257fc0: 31ef0001  andi	t7,t7,0x1
00257fc4: 31ef00ff  andi	t7,t7,0xff
00257fc8: 51e00006  beqzl	t7,0x257fe4
00257fcc: 25ce0001  addiu	t6,t6,1
00257fd0: 55a40003  bnel	t5,a0,0x257fe0
00257fd4: 25ad0001  addiu	t5,t5,1
00257fd8: 03e00008  jr	ra
00257fdc: 01c0102d  move	v0,t6
00257fe0: 25ce0001  addiu	t6,t6,1
00257fe4: 29cf0008  slti	t7,t6,8
00257fe8: 55e0fff5  bnezl	t7,0x257fc0
00257fec: 01cc7807  srav	t7,t4,t6
00257ff0: 03e00008  jr	ra
00257ff4: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00257fa8(void)`

```c
uint FUN_00257fa8(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = 0;
  uVar2 = 0;
  uVar3 = (uint)DAT_0035ef70;
  while( true ) {
    if ((uVar3 & 1) != 0) {
      if (iVar1 == param_1) {
        return uVar2;
      }
      iVar1 = iVar1 + 1;
    }
    uVar2 = uVar2 + 1;
    if (7 < (int)uVar2) break;
    uVar3 = (int)(uint)DAT_0035ef70 >> (uVar2 & 0x1f);
  }
  return 0xffffffff;
}
```

## Earlier attempts (newest first)

- 16 differing words, 80/80 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_03_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_03_0.cpp`)
