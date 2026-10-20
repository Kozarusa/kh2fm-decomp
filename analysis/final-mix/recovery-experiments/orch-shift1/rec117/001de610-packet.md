# Target packet 001de610

- Range: `001de610`..`001de690`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_001de610`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001dca20` registry: `func_001dca20`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`
- `001e0058` registry: `func_001e0058`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`
- `00321ce8` registry: `func_00321ce8`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001de610: 27bdffe0  addiu	sp,sp,-32
001de614: ffb20010  sd	s2,16(sp)
001de618: ffb00000  sd	s0,0(sp)
001de61c: ffb10008  sd	s1,8(sp)
001de620: ffbf0018  sd	ra,24(sp)
001de624: 8c90000c  lw	s0,12(a0)
001de628: 12000013  beqz	s0,0x1de678
001de62c: 0080902d  move	s2,a0
001de630: 8e040040  lw	a0,64(s0)
001de634: 8c8f0008  lw	t7,8(a0)
001de638: 000f7e83  sra	t7,t7,0x1a
001de63c: 31ef0001  andi	t7,t7,0x1
001de640: 31ef00ff  andi	t7,t7,0xff
001de644: 15e0000a  bnez	t7,0x1de670
001de648: 8e110060  lw	s1,96(s0)
001de64c: 0c077288  jal	0x1dca20
001de650: 00000000  nop
001de654: 0200282d  move	a1,s0
001de658: 10400005  beqz	v0,0x1de670
001de65c: 2644000c  addiu	a0,s2,12
001de660: 0c0c873a  jal	0x321ce8
001de664: 00000000  nop
001de668: 0c078016  jal	0x1e0058
001de66c: 0200202d  move	a0,s0
001de670: 1620ffef  bnez	s1,0x1de630
001de674: 0220802d  move	s0,s1
001de678: dfb00000  ld	s0,0(sp)
001de67c: dfb10008  ld	s1,8(sp)
001de680: dfb20010  ld	s2,16(sp)
001de684: dfbf0018  ld	ra,24(sp)
001de688: 03e00008  jr	ra
001de68c: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001de610(void)`

```c
void FUN_001de610(int param_1)

{
  int iVar1;
  int iVar2;
  long lVar3;
  
  iVar1 = *(int *)(param_1 + 0xc);
  while (iVar2 = iVar1, iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 0x60);
    if ((*(int *)(*(int *)(iVar2 + 0x40) + 8) >> 0x1a & 1U) == 0) {
      lVar3 = FUN_001dca20();
      if (lVar3 != 0) {
        FUN_00321ce8(param_1 + 0xc,iVar2);
        FUN_001e0058(iVar2);
      }
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- 23 differing words, 124/128 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_08_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_08_0.cpp`)
