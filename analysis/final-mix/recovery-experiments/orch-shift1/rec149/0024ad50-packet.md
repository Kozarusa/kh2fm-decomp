# Target packet 0024ad50

- Range: `0024ad50`..`0024ada0`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_0024ad50`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001d56c8` registry: `_ZN2YS8MINIGAME8GetScoreEi`
  - accepted sources that already call it (copy their declaration): `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`, `fm_primary_oneword_recovered_0023f8c8.cpp`, `fm_primary_oneword_recovered_00246968.cpp`, `fm_primary_oneword_recovered_00253538.cpp`
- `00276c18` registry: `_ZN2Tz6Jiminy10isFullOpenEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_oneword_recovered_00232510.cpp`, `fm_primary_oneword_recovered_0023a9c0.cpp`, `fm_primary_oneword_recovered_0023f8c8.cpp`, `fm_primary_oneword_recovered_00246968.cpp`, `fm_primary_oneword_recovered_00253538.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0024ad50: 27bdfff0  addiu	sp,sp,-16
0024ad54: 2404000a  li	a0,10
0024ad58: ffb00000  sd	s0,0(sp)
0024ad5c: ffbf0008  sd	ra,8(sp)
0024ad60: 0c0755b2  jal	0x1d56c8
0024ad64: 0000802d  move	s0,zero
0024ad68: 904f0000  lbu	t7,0(v0)
0024ad6c: 2def0002  sltiu	t7,t7,2
0024ad70: 51e00006  beqzl	t7,0x24ad8c
0024ad74: 24100001  li	s0,1
0024ad78: 0c09db06  jal	0x276c18
0024ad7c: 00000000  nop
0024ad80: 10400003  beqz	v0,0x24ad90
0024ad84: 0200102d  move	v0,s0
0024ad88: 24100001  li	s0,1
0024ad8c: 0200102d  move	v0,s0
0024ad90: dfbf0008  ld	ra,8(sp)
0024ad94: dfb00000  ld	s0,0(sp)
0024ad98: 03e00008  jr	ra
0024ad9c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0024ad50(void)`

```c
undefined4 FUN_0024ad50(void)

{
  byte *pbVar1;
  long lVar2;
  
  pbVar1 = (byte *)FUN_001d56c8(10);
  if ((*pbVar1 < 2) && (lVar2 = FUN_00276c18(), lVar2 == 0)) {
    return 0;
  }
  return 1;
}
```

## Earlier attempts (newest first)

- 15 differing words, 76/80 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_06.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_06.cpp`)
- 9 differing words, 72/80 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round26_0024ad50_v01.verification.json`
