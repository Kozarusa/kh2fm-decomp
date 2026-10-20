# Target packet 0014eda8

- Range: `0014eda8`..`0014ee28`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_0014eda8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `002bc358` registry: `Tz::MenuSound::StopBgSeHandle(...)`
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_twoword_recovered_001b2488.cpp`, `fm_primary_twowordfresh_recovered_001b3330.cpp`, `fm_scalar_extra_recovered_04.cpp`, `fm_scalar_recovered_04.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0014eda8: 27bdffd0  addiu	sp,sp,-48
0014edac: 3c0e0035  lui	t6,0x35
0014edb0: ffb10008  sd	s1,8(sp)
0014edb4: ffb00000  sd	s0,0(sp)
0014edb8: ffb20010  sd	s2,16(sp)
0014edbc: ffb30018  sd	s3,24(sp)
0014edc0: ffbf0020  sd	ra,32(sp)
0014edc4: 8dcfa400  lw	t7,-23552(t6)   ; = D_0034a400
0014edc8: 19e00010  blez	t7,0x14ee0c
0014edcc: 0000882d  move	s1,zero
0014edd0: 3c0f0035  lui	t7,0x35
0014edd4: 01c0982d  move	s3,t6
0014edd8: 25f0a408  addiu	s0,t7,-23544   ; = D_0034a408
0014eddc: 2412ffff  li	s2,-1
0014ede0: 8e0f0000  lw	t7,0(s0)
0014ede4: 26100004  addiu	s0,s0,4
0014ede8: 11f20003  beq	t7,s2,0x14edf8
0014edec: 01e0202d  move	a0,t7
0014edf0: 0c0af0d6  jal	0x2bc358
0014edf4: 24050001  li	a1,1
0014edf8: 8e6fa400  lw	t7,-23552(s3)
0014edfc: 26310001  addiu	s1,s1,1
0014ee00: 022f782a  slt	t7,s1,t7
0014ee04: 55e0fff7  bnezl	t7,0x14ede4
0014ee08: 8e0f0000  lw	t7,0(s0)
0014ee0c: dfb00000  ld	s0,0(sp)
0014ee10: dfb10008  ld	s1,8(sp)
0014ee14: dfb20010  ld	s2,16(sp)
0014ee18: dfb30018  ld	s3,24(sp)
0014ee1c: dfbf0020  ld	ra,32(sp)
0014ee20: 03e00008  jr	ra
0014ee24: 27bd0030  addiu	sp,sp,48
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0014eda8(void)`

```c
void FUN_0014eda8(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < DAT_0034a400) {
    piVar2 = &DAT_0034a408;
    iVar1 = DAT_0034a408;
    while( true ) {
      piVar2 = piVar2 + 1;
      if (iVar1 != -1) {
        FUN_002bc358(iVar1,1);
      }
      iVar3 = iVar3 + 1;
      if (DAT_0034a400 <= iVar3) break;
      iVar1 = *piVar2;
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
