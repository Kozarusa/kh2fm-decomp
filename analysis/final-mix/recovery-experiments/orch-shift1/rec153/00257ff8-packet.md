# Target packet 00257ff8

- Range: `00257ff8`..`00258048`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_00257ff8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00257ff8: 3c0f0036  lui	t7,0x36
00257ffc: 2402ffff  li	v0,-1
00258000: 95edef70  lhu	t5,-4240(t7)   ; = D_0035ef70
00258004: 0000602d  move	t4,zero
00258008: 0000702d  move	t6,zero
0025800c: 01cd7807  srav	t7,t5,t6
00258010: 31ef0001  andi	t7,t7,0x1
00258014: 31ef00ff  andi	t7,t7,0xff
00258018: 51e00006  beqzl	t7,0x258034
0025801c: 25ce0001  addiu	t6,t6,1
00258020: 55c40003  bnel	t6,a0,0x258030
00258024: 258c0001  addiu	t4,t4,1
00258028: 03e00008  jr	ra
0025802c: 0180102d  move	v0,t4
00258030: 25ce0001  addiu	t6,t6,1
00258034: 29cf0008  slti	t7,t6,8
00258038: 55e0fff5  bnezl	t7,0x258010
0025803c: 01cd7807  srav	t7,t5,t6
00258040: 03e00008  jr	ra
00258044: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00257ff8(void)`

```c
int FUN_00257ff8(uint param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = 0;
  uVar2 = 0;
  uVar3 = (uint)DAT_0035ef70;
  while( true ) {
    if ((uVar3 & 1) != 0) {
      if (uVar2 == param_1) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
    }
    uVar2 = uVar2 + 1;
    if (7 < (int)uVar2) break;
    uVar3 = (int)(uint)DAT_0035ef70 >> (uVar2 & 0x1f);
  }
  return -1;
}
```

## Earlier attempts (newest first)

- 16 differing words, 80/80 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_03_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_03_0.cpp`)
