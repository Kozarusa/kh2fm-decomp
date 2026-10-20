# Target packet 001fb928

- Range: `001fb928`..`001fb9a4`, **124 bytes = 31 instructions**. This size is the acceptance size.
- Layout name: `FUN_001fb928`
- Registry names for this address: none
- Queue: state `leased`, queue `branch-layout`, attempts 2, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\rec125\\001fb928-BLOCKED.md", "sha256": "9ea5ab91f5dae2c79cc656d950ead8714d20572fc86a162ebdc9c722a9f4cec5", "hypothesis": "try early return instead of if block and separate compare variables so ld s0 fills bne delay slot once"}`

## Callees

- `001fab48` registry: `func_001fab48(void*)`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001fb928: 27bdffe0  addiu	sp,sp,-32
001fb92c: ffb00000  sd	s0,0(sp)
001fb930: ffb10008  sd	s1,8(sp)
001fb934: ffb20010  sd	s2,16(sp)
001fb938: 0080802d  move	s0,a0
001fb93c: ffbf0018  sd	ra,24(sp)
001fb940: 00a0882d  move	s1,a1
001fb944: 8cce000c  lw	t6,12(a2)
001fb948: 8dcf0000  lw	t7,0(t6)
001fb94c: 008f7821  addu	t7,a0,t7
001fb950: 0c07ead2  jal	0x1fab48
001fb954: 25f200a0  addiu	s2,t7,160
001fb958: 8e0e000c  lw	t6,12(s0)
001fb95c: 8e2f0000  lw	t7,0(s1)
001fb960: 15ee000b  bne	t7,t6,0x1fb990
001fb964: dfb00000  ld	s0,0(sp)
001fb968: c620000c  lwc1	$f0,12(s1)
001fb96c: e6400020  swc1	$f0,32(s2)
001fb970: 962f0010  lhu	t7,16(s1)
001fb974: 448f0000  mtc1	t7,$f0
001fb978: 46800020  cvt.s.w	$f0,$f0
001fb97c: e6400028  swc1	$f0,40(s2)
001fb980: 962f0012  lhu	t7,18(s1)
001fb984: 448f0000  mtc1	t7,$f0
001fb988: 46800020  cvt.s.w	$f0,$f0
001fb98c: e640002c  swc1	$f0,44(s2)
001fb990: dfb10008  ld	s1,8(sp)
001fb994: dfb20010  ld	s2,16(sp)
001fb998: dfbf0018  ld	ra,24(sp)
001fb99c: 03e00008  jr	ra
001fb9a0: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001fb928(void)`

```c
void FUN_001fb928(int param_1,int *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_1 + **(int **)(param_3 + 0xc);
  FUN_001fab48();
  if (*param_2 == *(int *)(param_1 + 0xc)) {
    *(int *)(iVar1 + 0xc0) = param_2[3];
    *(float *)(iVar1 + 200) = (float)*(ushort *)(param_2 + 4);
    *(float *)(iVar1 + 0xcc) = (float)*(ushort *)((int)param_2 + 0x12);
  }
  return;
}
```

## Earlier attempts (newest first)

- 22 differing words, 120/124 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_08_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_08_0.cpp`)
- 14 differing words, 128/124 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec125/orch1_rec125_001fb928_v7.verification.json`
- 20 differing words, 128/124 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec125/orch1_rec125_001fb928_v6.verification.json`
- 14 differing words, 128/124 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec125/orch1_rec125_001fb928_v5.verification.json`
- 14 differing words, 128/124 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec125/orch1_rec125_001fb928_v4.verification.json`
- 25 differing words, 136/124 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec125/orch1_rec125_001fb928_v3.verification.json`
- 16 differing words, 124/124 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec125/orch1_rec125_001fb928_v2.verification.json`
- 24 differing words, 124/124 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec125/orch1_rec125_001fb928_v1.verification.json`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec125/001fb928-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec125/001fb928-packet.md`
