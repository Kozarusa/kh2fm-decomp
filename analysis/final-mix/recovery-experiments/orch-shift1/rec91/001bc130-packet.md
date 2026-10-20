# Target packet 001bc130

- Range: `001bc130`..`001bc188`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_001bc130`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001bb4a0` registry: `_ZN2YS7MISSION6IsExecEv`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`
- `001bbcb0` registry: `_ZN2YS7MISSION10GetCurrentEv`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001bc130: 27bdfff0  addiu	sp,sp,-16
001bc134: ffb00000  sd	s0,0(sp)
001bc138: ffbf0008  sd	ra,8(sp)
001bc13c: 0c06ed28  jal	0x1bb4a0
001bc140: 0000802d  move	s0,zero
001bc144: 5040000b  beqzl	v0,0x1bc174
001bc148: 24100001  li	s0,1
001bc14c: 0c06ef2c  jal	0x1bbcb0
001bc150: 00000000  nop
001bc154: 8c4e0008  lw	t6,8(v0)
001bc158: 95cf0004  lhu	t7,4(t6)
001bc15c: 000f7882  srl	t7,t7,0x2
001bc160: 31ef0001  andi	t7,t7,0x1
001bc164: 31ef00ff  andi	t7,t7,0xff
001bc168: 11e00003  beqz	t7,0x1bc178
001bc16c: 0200102d  move	v0,s0
001bc170: 24100001  li	s0,1
001bc174: 0200102d  move	v0,s0
001bc178: dfbf0008  ld	ra,8(sp)
001bc17c: dfb00000  ld	s0,0(sp)
001bc180: 03e00008  jr	ra
001bc184: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001bc130(void)`

```c
undefined4 FUN_001bc130(void)

{
  int iVar1;
  long lVar2;
  
  lVar2 = FUN_001bb4a0();
  if ((lVar2 != 0) && (iVar1 = FUN_001bbcb0(), (*(ushort *)(*(int *)(iVar1 + 8) + 4) >> 2 & 1) == 0)
     ) {
    return 0;
  }
  return 1;
}
```

## Earlier attempts (newest first)

- 19 differing words, 88/88 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_04.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_04.cpp`)
