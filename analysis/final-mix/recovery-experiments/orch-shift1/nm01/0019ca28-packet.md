# Target packet 0019ca28

- Range: `0019ca28`..`0019ca90`, **104 bytes = 26 instructions**. This size is the acceptance size.
- Layout name: `FUN_0019ca28`
- Registry names for this address: none
- Queue: state `leased`, queue `store-order`, attempts 2, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\rec69\\0019ca28-BLOCKED.md", "sha256": "d160c3b16a24fa6aa23f0432aea762c14fd75ec33bb98548bcedb65b025e82c7", "hypothesis": "C10d asm volatile memory barrier or different local layout so the zero store follows lw+addiu"}`

## Callees

- `001902a8` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_floatarguments_recovered_0018f9b8.cpp`, `fm_primary_fourword_recovered_001a93b0.cpp`, `fm_primary_fourwordfresh_recovered_00195558.cpp`, `fm_primary_fourwordfresh_recovered_00197390.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0019ca28: 27bdffd0  addiu	sp,sp,-48
0019ca2c: 00a0682d  move	t5,a1
0019ca30: ffb00020  sd	s0,32(sp)
0019ca34: ffbf0028  sd	ra,40(sp)
0019ca38: 0080802d  move	s0,a0
0019ca3c: 8caf0000  lw	t7,0(a1)
0019ca40: 24840004  addiu	a0,a0,4
0019ca44: afa0000c  sw	zero,12(sp)
0019ca48: 03a0282d  move	a1,sp
0019ca4c: ae0f0004  sw	t7,4(s0)
0019ca50: 8daf0004  lw	t7,4(t5)
0019ca54: ae0f0008  sw	t7,8(s0)
0019ca58: 8dae0008  lw	t6,8(t5)
0019ca5c: ae0e000c  sw	t6,12(s0)
0019ca60: 8daf000c  lw	t7,12(t5)
0019ca64: ae0f0010  sw	t7,16(s0)
0019ca68: 8dae0010  lw	t6,16(t5)
0019ca6c: 0c0640aa  jal	0x1902a8
0019ca70: ae0e0014  sw	t6,20(s0)
0019ca74: 8faf000c  lw	t7,12(sp)
0019ca78: dfbf0028  ld	ra,40(sp)
0019ca7c: 91ee0001  lbu	t6,1(t7)
0019ca80: ae0e0024  sw	t6,36(s0)
0019ca84: dfb00020  ld	s0,32(sp)
0019ca88: 03e00008  jr	ra
0019ca8c: 27bd0030  addiu	sp,sp,48
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0019ca28(void)`

```c
void FUN_0019ca28(int param_1,undefined4 *param_2)

{
  undefined1 auStack_30 [12];
  int iStack_24;
  
  iStack_24 = 0;
  *(undefined4 *)(param_1 + 4) = *param_2;
  *(undefined4 *)(param_1 + 8) = param_2[1];
  *(undefined4 *)(param_1 + 0xc) = param_2[2];
  *(undefined4 *)(param_1 + 0x10) = param_2[3];
  *(undefined4 *)(param_1 + 0x14) = param_2[4];
  FUN_001902a8(param_1 + 4,auStack_30);
  *(uint *)(param_1 + 0x24) = (uint)*(byte *)(iStack_24 + 1);
  return;
}
```

## Earlier attempts (newest first)

- 21 differing words, 96/104 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_05_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_05_0.cpp`)
- 5 differing words, 104/104 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec69/orch1_rec69_0019ca28_v5.verification.json`
- 5 differing words, 104/104 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec69/orch1_rec69_0019ca28_v4.verification.json`
- 5 differing words, 104/104 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec69/orch1_rec69_0019ca28_v3.verification.json`
- 5 differing words, 104/104 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec69/orch1_rec69_0019ca28_v2.verification.json`
- 11 differing words, 104/104 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec69/orch1_rec69_0019ca28_v1.verification.json`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec69/0019ca28-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec69/0019ca28-packet.md`
