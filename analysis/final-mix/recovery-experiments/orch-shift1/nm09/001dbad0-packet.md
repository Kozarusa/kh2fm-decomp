# Target packet 001dbad0

- Range: `001dbad0`..`001dbb38`, **104 bytes = 26 instructions**. This size is the acceptance size.
- Layout name: `FUN_001dbad0`
- Registry names for this address: none
- Queue: state `leased`, queue `register-allocation`, attempts 2, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\rec114\\001dbad0-BLOCKED.md", "sha256": "396bf971a7bb6e63c8a883c9d68adc92a2f95c2e42c2f8daad5273a853f5696a", "hypothesis": "C11(c) bind destination to $15 and the quad temp to $8 with why comments"}`

## Callees

- `0016c028` registry: `func_0016c028`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`
- `0019ba60` registry: `_Z16ctarget_0019ba60jjjj`
  - accepted sources that already call it (copy their declaration): `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`
- `001c2578` registry: `_ZN2YS7MASSOBJ9_OVR_execEv`
  - accepted sources that already call it (copy their declaration): `fm_scalar_recovered_04.cpp`
- `001dbcd0` registry: `func_001dbcd0`
  - accepted sources that already call it (copy their declaration): `fm_primary_orchcw_recovered_001dbcd0.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001dbad0: 27bdffe0  addiu	sp,sp,-32
001dbad4: ffb00000  sd	s0,0(sp)
001dbad8: ffb10008  sd	s1,8(sp)
001dbadc: ffbf0010  sd	ra,16(sp)
001dbae0: 3c100035  lui	s0,0x35
001dbae4: 0080882d  move	s1,a0
001dbae8: 0c066e98  jal	0x19ba60
001dbaec: 8e04e948  lw	a0,-5816(s0)   ; = D_0034e948
001dbaf0: 10400009  beqz	v0,0x1dbb18
001dbaf4: 00000000  nop
001dbaf8: 0c05b00a  jal	0x16c028
001dbafc: 8e04e948  lw	a0,-5816(s0)   ; = D_0034e948
001dbb00: 3c0f0035  lui	t7,0x35
001dbb04: 25ef2a60  addiu	t7,t7,10848   ; = D_00352a60
001dbb08: 104f0003  beq	v0,t7,0x1dbb18
001dbb0c: 00000000  nop
001dbb10: 78480000  lq	t0,0(v0)
001dbb14: 7de80000  sq	t0,0(t7)
001dbb18: 0c076f34  jal	0x1dbcd0
001dbb1c: 00000000  nop
001dbb20: 0220202d  move	a0,s1
001dbb24: dfb00000  ld	s0,0(sp)
001dbb28: dfb10008  ld	s1,8(sp)
001dbb2c: dfbf0010  ld	ra,16(sp)
001dbb30: 0807095e  j	0x1c2578
001dbb34: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001dbad0(void)`

```c
void FUN_001dbad0(undefined8 param_1)

{
  undefined4 *puVar1;
  long lVar2;
  
  lVar2 = FUN_0019ba60(DAT_0034e948);
  if ((lVar2 != 0) &&
     (lVar2 = FUN_0016c028(DAT_0034e948), puVar1 = (undefined4 *)lVar2, lVar2 != 0x352a60)) {
    DAT_00352a60 = *puVar1;
    DAT_00352a64 = puVar1[1];
    DAT_00352a68 = puVar1[2];
    DAT_00352a6c = puVar1[3];
  }
  FUN_001dbcd0();
  FUN_001c2578(param_1);
  return;
}
```

## Earlier attempts (newest first)

- 4 differing words, 104/104 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec114/orch1_rec114_001dbad0_v5.verification.json`
- 4 differing words, 104/104 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec114/orch1_rec114_001dbad0_v4.verification.json`
- 4 differing words, 104/104 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec114/orch1_rec114_001dbad0_v3.verification.json`
- 4 differing words, 104/104 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec114/orch1_rec114_001dbad0_v2.verification.json`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec114/001dbad0-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec114/001dbad0-packet.md`
