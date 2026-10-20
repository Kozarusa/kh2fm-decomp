# Target packet 001dba18

- Range: `001dba18`..`001dba84`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_001dba18`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001b9bc8` registry: `_Z16ctarget_001b9bc8jjjj`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_fiveword_recovered_0017a8f8.cpp`, `fm_primary_floatarguments_recovered_0018f9b8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001dba18: 27bdffe0  addiu	sp,sp,-32
001dba1c: 0000102d  move	v0,zero
001dba20: ffb00000  sd	s0,0(sp)
001dba24: ffb10008  sd	s1,8(sp)
001dba28: ffbf0010  sd	ra,16(sp)
001dba2c: 3c101000  lui	s0,0x1000
001dba30: 0080882d  move	s1,a0
001dba34: 0c06e6f2  jal	0x1b9bc8
001dba38: 0040202d  move	a0,v0
001dba3c: 14400008  bnez	v0,0x1dba60
001dba40: 0040702d  move	t6,v0
001dba44: 0000702d  move	t6,zero
001dba48: dfb00000  ld	s0,0(sp)
001dba4c: 01c0102d  move	v0,t6
001dba50: dfb10008  ld	s1,8(sp)
001dba54: dfbf0010  ld	ra,16(sp)
001dba58: 03e00008  jr	ra
001dba5c: 27bd0020  addiu	sp,sp,32
001dba60: 8c4f0588  lw	t7,1416(v0)
001dba64: 01f07824  and	t7,t7,s0
001dba68: 11e0fff2  beqz	t7,0x1dba34
001dba6c: 00000000  nop
001dba70: 8c4f0008  lw	t7,8(v0)
001dba74: 51f1fff5  beql	t7,s1,0x1dba4c
001dba78: dfb00000  ld	s0,0(sp)
001dba7c: 1000ffed  b	0x1dba34
001dba80: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001dba18(void)`

```c
long FUN_001dba18(int param_1)

{
  long lVar1;
  
  lVar1 = 0;
  do {
    lVar1 = FUN_001b9bc8(lVar1);
    if (lVar1 == 0) {
      return 0;
    }
  } while (((*(uint *)((int)lVar1 + 0x588) & 0x10000000) == 0) ||
          (*(int *)((int)lVar1 + 8) != param_1));
  return lVar1;
}
```

## Earlier attempts (newest first)

- 23 differing words, 104/108 bytes: `analysis/final-mix/recovery-experiments/fm_primary_resume_01.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_primary_resume_01.cpp`)
