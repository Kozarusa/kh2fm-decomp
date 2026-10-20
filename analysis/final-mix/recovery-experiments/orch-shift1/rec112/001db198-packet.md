# Target packet 001db198

- Range: `001db198`..`001db200`, **104 bytes = 26 instructions**. This size is the acceptance size.
- Layout name: `FUN_001db198`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001db200` registry: `func_001db200`
  - accepted sources that already call it (copy their declaration): `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_oneword_recovered_001c8710.cpp`, `fm_primary_oneword_recovered_001c8750.cpp`
- `001db250` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_oneword_recovered_001c8710.cpp`, `fm_primary_oneword_recovered_001c8750.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001db198: 27bdffe0  addiu	sp,sp,-32
001db19c: 24020001  li	v0,1
001db1a0: ffb00000  sd	s0,0(sp)
001db1a4: ffb10008  sd	s1,8(sp)
001db1a8: ffbf0010  sd	ra,16(sp)
001db1ac: 10a0000d  beqz	a1,0x1db1e4
001db1b0: 0080802d  move	s0,a0
001db1b4: 04a00010  bltz	a1,0x1db1f8
001db1b8: 28af0003  slti	t7,a1,3
001db1bc: 11e00009  beqz	t7,0x1db1e4
001db1c0: 0000102d  move	v0,zero
001db1c4: 0c076c80  jal	0x1db200
001db1c8: 0000882d  move	s1,zero
001db1cc: 10400004  beqz	v0,0x1db1e0
001db1d0: 0200202d  move	a0,s0
001db1d4: 0c076c94  jal	0x1db250
001db1d8: 00000000  nop
001db1dc: 0002882b  sltu	s1,zero,v0
001db1e0: 0220102d  move	v0,s1
001db1e4: dfb00000  ld	s0,0(sp)
001db1e8: dfb10008  ld	s1,8(sp)
001db1ec: dfbf0010  ld	ra,16(sp)
001db1f0: 03e00008  jr	ra
001db1f4: 27bd0020  addiu	sp,sp,32
001db1f8: 1000fffa  b	0x1db1e4
001db1fc: 0000102d  move	v0,zero
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001db198(void)`

```c
bool FUN_001db198(undefined8 param_1,long param_2)

{
  bool bVar1;
  long lVar2;
  
  bVar1 = true;
  if (param_2 != 0) {
    if (param_2 < 0) {
      bVar1 = false;
    }
    else {
      bVar1 = false;
      if (param_2 < 3) {
        bVar1 = false;
        lVar2 = FUN_001db200();
        if (lVar2 != 0) {
          lVar2 = FUN_001db250(param_1);
          bVar1 = lVar2 != 0;
        }
      }
    }
  }
  return bVar1;
}
```

## Earlier attempts (newest first)

- 25 differing words, 104/104 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_parameters_07_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_width_parameters_07_0.cpp`)
