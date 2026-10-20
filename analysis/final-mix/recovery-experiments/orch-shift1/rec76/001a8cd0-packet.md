# Target packet 001a8cd0

- Range: `001a8cd0`..`001a8d3c`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_001a8cd0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001a8bf8` registry: `func_001a8bf8`
  - accepted sources that already call it (copy their declaration): `fm_fallback_small.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001a8cd0: 27bdffe0  addiu	sp,sp,-32
001a8cd4: 2402ffff  li	v0,-1
001a8cd8: ffb10008  sd	s1,8(sp)
001a8cdc: 240f0012  li	t7,18
001a8ce0: ffb20010  sd	s2,16(sp)
001a8ce4: ffb00000  sd	s0,0(sp)
001a8ce8: 30b1001f  andi	s1,a1,0x1f
001a8cec: ffbf0018  sd	ra,24(sp)
001a8cf0: 122f000c  beq	s1,t7,0x1a8d24
001a8cf4: 0080902d  move	s2,a0
001a8cf8: 0000802d  move	s0,zero
001a8cfc: 0200282d  move	a1,s0
001a8d00: 0c06a2fe  jal	0x1a8bf8
001a8d04: 0240202d  move	a0,s2
001a8d08: 10510006  beq	v0,s1,0x1a8d24
001a8d0c: 0200102d  move	v0,s0
001a8d10: 26100001  addiu	s0,s0,1
001a8d14: 2a0f0004  slti	t7,s0,4
001a8d18: 15e0fff9  bnez	t7,0x1a8d00
001a8d1c: 0200282d  move	a1,s0
001a8d20: 2402ffff  li	v0,-1
001a8d24: dfb00000  ld	s0,0(sp)
001a8d28: dfb10008  ld	s1,8(sp)
001a8d2c: dfb20010  ld	s2,16(sp)
001a8d30: dfbf0018  ld	ra,24(sp)
001a8d34: 03e00008  jr	ra
001a8d38: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001a8cd0(void)`

```c
int FUN_001a8cd0(undefined8 param_1,ulong param_2)

{
  ulong uVar1;
  int iVar2;
  
  if ((param_2 & 0x1f) != 0x12) {
    iVar2 = 0;
    do {
      uVar1 = FUN_001a8bf8(param_1,iVar2);
      if (uVar1 == (param_2 & 0x1f)) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 4);
  }
  return -1;
}
```

## Earlier attempts (newest first)

- 20 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_05_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_all_05_0.cpp`)
