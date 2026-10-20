# Target packet 001de590

- Range: `001de590`..`001de610`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_001de590`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001dc9e0` registry: `_ZN3ryj6EFFECT9is_activeEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_fiveword_recovered_0017a8f8.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`
- `001dfa38` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001de590: 27bdffe0  addiu	sp,sp,-32
001de594: ffb00000  sd	s0,0(sp)
001de598: ffb10008  sd	s1,8(sp)
001de59c: ffb20010  sd	s2,16(sp)
001de5a0: ffbf0018  sd	ra,24(sp)
001de5a4: 8c90000c  lw	s0,12(a0)
001de5a8: 12000013  beqz	s0,0x1de5f8
001de5ac: 3c120035  lui	s2,0x35
001de5b0: 8e040040  lw	a0,64(s0)
001de5b4: 0c077278  jal	0x1dc9e0
001de5b8: 8e110060  lw	s1,96(s0)
001de5bc: 1040000c  beqz	v0,0x1de5f0
001de5c0: 00000000  nop
001de5c4: 8e0e0040  lw	t6,64(s0)
001de5c8: 8dcf0008  lw	t7,8(t6)
001de5cc: 000f7e83  sra	t7,t7,0x1a
001de5d0: 31ef0001  andi	t7,t7,0x1
001de5d4: 31ef00ff  andi	t7,t7,0xff
001de5d8: 15e00005  bnez	t7,0x1de5f0
001de5dc: 00000000  nop
001de5e0: ae502b58  sw	s0,11096(s2)   ; = D_00352b58
001de5e4: 0c077e8e  jal	0x1dfa38
001de5e8: 0200202d  move	a0,s0
001de5ec: ae402b58  sw	zero,11096(s2)   ; = D_00352b58
001de5f0: 1620ffef  bnez	s1,0x1de5b0
001de5f4: 0220802d  move	s0,s1
001de5f8: dfb00000  ld	s0,0(sp)
001de5fc: dfb10008  ld	s1,8(sp)
001de600: dfb20010  ld	s2,16(sp)
001de604: dfbf0018  ld	ra,24(sp)
001de608: 03e00008  jr	ra
001de60c: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001de590(void)`

```c
void FUN_001de590(int param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  
  iVar1 = *(int *)(param_1 + 0xc);
  while (iVar2 = iVar1, iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x60);
    lVar3 = FUN_001dc9e0(*(undefined4 *)(iVar2 + 0x40));
    if ((lVar3 != 0) && ((*(int *)(*(int *)(iVar2 + 0x40) + 8) >> 0x1a & 1U) == 0)) {
      DAT_00352b58 = iVar2;
      FUN_001dfa38(iVar2);
      DAT_00352b58 = 0;
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
