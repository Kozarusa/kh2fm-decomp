# Target packet 001d8fa8

- Range: `001d8fa8`..`001d9024`, **124 bytes = 31 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d8fa8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001bb4a0` registry: `_ZN2YS7MISSION6IsExecEv`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`
- `001bbcb0` registry: `_ZN2YS7MISSION10GetCurrentEv`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d8fa8: 27bdffe0  addiu	sp,sp,-32
001d8fac: ffb00000  sd	s0,0(sp)
001d8fb0: ffb10008  sd	s1,8(sp)
001d8fb4: ffbf0010  sd	ra,16(sp)
001d8fb8: 00a0802d  move	s0,a1
001d8fbc: 0c06ed28  jal	0x1bb4a0
001d8fc0: 309100ff  andi	s1,a0,0xff
001d8fc4: 50400011  beqzl	v0,0x1d900c
001d8fc8: dfb00000  ld	s0,0(sp)
001d8fcc: 0c06ef2c  jal	0x1bbcb0
001d8fd0: 00000000  nop
001d8fd4: 240f0034  li	t7,52
001d8fd8: 020f7818  mult	t7,s0,t7
001d8fdc: 004f1021  addu	v0,v0,t7
001d8fe0: 8c4e019c  lw	t6,412(v0)
001d8fe4: 31ce0001  andi	t6,t6,0x1
001d8fe8: 31ce00ff  andi	t6,t6,0xff
001d8fec: 11c00006  beqz	t6,0x1d9008
001d8ff0: 24440190  addiu	a0,v0,400
001d8ff4: 12200009  beqz	s1,0x1d901c
001d8ff8: 8c4e0190  lw	t6,400(v0)
001d8ffc: 8dcf000c  lw	t7,12(t6)
001d9000: 01e0f809  jalr	t7
001d9004: 00000000  nop
001d9008: dfb00000  ld	s0,0(sp)
001d900c: dfb10008  ld	s1,8(sp)
001d9010: dfbf0010  ld	ra,16(sp)
001d9014: 03e00008  jr	ra
001d9018: 27bd0020  addiu	sp,sp,32
001d901c: 1000fff8  b	0x1d9000
001d9020: 8dcf0010  lw	t7,16(t6)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d8fa8(void)`

```c
void FUN_001d8fa8(char param_1,int param_2)

{
  int iVar1;
  long lVar2;
  code *pcVar3;
  
  lVar2 = FUN_001bb4a0();
  if (lVar2 != 0) {
    iVar1 = FUN_001bbcb0();
    iVar1 = iVar1 + param_2 * 0x34;
    if ((*(uint *)(iVar1 + 0x19c) & 1) != 0) {
      if (param_1 == '\0') {
        pcVar3 = *(code **)(*(int *)(iVar1 + 400) + 0x10);
      }
      else {
        pcVar3 = *(code **)(*(int *)(iVar1 + 400) + 0xc);
      }
      (*pcVar3)(iVar1 + 400);
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
