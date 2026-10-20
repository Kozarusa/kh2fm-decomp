# Target packet 001a8c78

- Range: `001a8c78`..`001a8ccc`, **84 bytes = 21 instructions**. This size is the acceptance size.
- Layout name: `FUN_001a8c78`
- Registry names for this address: none
- Queue: state `leased`, queue `register-allocation`, attempts 2, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\rec76\\001a8c78-BLOCKED.md", "sha256": "0ed439f05d5e31b180fe6a8a76e4dcb4106a4c82d69ad68145e93466d01b6541", "hypothesis": "only andi order/registers differ: reorder kind computation before 0x80 test or bind kind to register 14"}`

## Callees

- `001c9db0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_oneword_recovered_001ac1d0.cpp`, `fm_primary_threewordnext_recovered_0019e6e8.cpp`, `fm_primary_twoword_recovered_001a6c38.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001a8c78: 27bdfff0  addiu	sp,sp,-16
001a8c7c: 00852021  addu	a0,a0,a1
001a8c80: ffb00000  sd	s0,0(sp)
001a8c84: ffbf0008  sd	ra,8(sp)
001a8c88: 10a0000a  beqz	a1,0x1a8cb4
001a8c8c: 0000802d  move	s0,zero
001a8c90: 908f0000  lbu	t7,0(a0)
001a8c94: 31ee001f  andi	t6,t7,0x1f
001a8c98: 31ef0080  andi	t7,t7,0x80
001a8c9c: 15e00005  bnez	t7,0x1a8cb4
001a8ca0: 31c400ff  andi	a0,t6,0xff
001a8ca4: 0c07276c  jal	0x1c9db0
001a8ca8: 00000000  nop
001a8cac: 10400003  beqz	v0,0x1a8cbc
001a8cb0: 0200102d  move	v0,s0
001a8cb4: 24100001  li	s0,1
001a8cb8: 0200102d  move	v0,s0
001a8cbc: dfbf0008  ld	ra,8(sp)
001a8cc0: dfb00000  ld	s0,0(sp)
001a8cc4: 03e00008  jr	ra
001a8cc8: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001a8c78(void)`

```c
undefined4 FUN_001a8c78(int param_1,long param_2)

{
  byte bVar1;
  long lVar2;
  
  if (((param_2 != 0) && (bVar1 = *(byte *)(param_1 + (int)param_2), (bVar1 & 0x80) == 0)) &&
     (lVar2 = FUN_001c9db0(bVar1 & 0x1f), lVar2 == 0)) {
    return 0;
  }
  return 1;
}
```

## Earlier attempts (newest first)

- 18 differing words, 84/84 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_03.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_03.cpp`)
- 4 differing words, 84/84 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec76/orch1_rec76_001a8c78_v8.verification.json`
- 16 differing words, 80/84 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec76/orch1_rec76_001a8c78_v7.verification.json`
- 18 differing words, 88/84 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec76/orch1_rec76_001a8c78_v6.verification.json`
- 20 differing words, 68/84 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec76/orch1_rec76_001a8c78_v5.verification.json`
- 17 differing words, 80/84 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec76/orch1_rec76_001a8c78_v4.verification.json`
- 20 differing words, 72/84 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec76/orch1_rec76_001a8c78_v3.verification.json`
- 19 differing words, 76/84 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec76/orch1_rec76_001a8c78_v2.verification.json`
- 19 differing words, 80/84 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec76/orch1_rec76_001a8c78_v1.verification.json`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec76/001a8c78-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec76/001a8c78-packet.md`
