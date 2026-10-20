# Target packet 001aeb80

- Range: `001aeb80`..`001aebf0`, **112 bytes = 28 instructions**. This size is the acceptance size.
- Layout name: `FUN_001aeb80`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00168b38` registry: `func_00168b38`
  - accepted sources that already call it (copy their declaration): `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_fiveword_recovered_0017a8f8.cpp`
- `001b1490` registry: `func_001b1490`
  - accepted sources that already call it (copy their declaration): `fm_primary_orchbk_recovered_00192320.cpp`, `fm_scalar_recovered_04.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001aeb80: 27bdffe0  addiu	sp,sp,-32
001aeb84: 3c0f0035  lui	t7,0x35
001aeb88: ffb00000  sd	s0,0(sp)
001aeb8c: ffb10008  sd	s1,8(sp)
001aeb90: ffb20010  sd	s2,16(sp)
001aeb94: ffbf0018  sd	ra,24(sp)
001aeb98: 0000882d  move	s1,zero
001aeb9c: 0c06c524  jal	0x1b1490
001aeba0: 8de40de8  lw	a0,3560(t7)   ; = D_00350de8
001aeba4: 3c0f01c9  lui	t7,0x1c9
001aeba8: 0040902d  move	s2,v0
001aebac: 25f04040  addiu	s0,t7,16448   ; = D_01c94040
001aebb0: 0220302d  move	a2,s1
001aebb4: 0240202d  move	a0,s2
001aebb8: 24050002  li	a1,2
001aebbc: 0c05a2ce  jal	0x168b38
001aebc0: 26310001  addiu	s1,s1,1
001aebc4: 8c4f0008  lw	t7,8(v0)
001aebc8: 2a2e0013  slti	t6,s1,19
001aebcc: ae0f0000  sw	t7,0(s0)
001aebd0: 15c0fff7  bnez	t6,0x1aebb0
001aebd4: 26100004  addiu	s0,s0,4
001aebd8: dfb00000  ld	s0,0(sp)
001aebdc: dfb10008  ld	s1,8(sp)
001aebe0: dfb20010  ld	s2,16(sp)
001aebe4: dfbf0018  ld	ra,24(sp)
001aebe8: 03e00008  jr	ra
001aebec: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001aeb80(void)`

```c
void FUN_001aeb80(void)

{
  undefined8 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  uVar1 = FUN_001b1490(PTR_s_12soundinfo_bar_0036d85f_1_00350de8);
  puVar3 = &DAT_01c94040;
  iVar2 = 0;
  do {
    iVar4 = iVar2 + 1;
    iVar2 = FUN_00168b38(uVar1,2,iVar2);
    *puVar3 = *(undefined4 *)(iVar2 + 8);
    puVar3 = puVar3 + 1;
    iVar2 = iVar4;
  } while (iVar4 < 0x13);
  return;
}
```

## Earlier attempts (newest first)

- none found
