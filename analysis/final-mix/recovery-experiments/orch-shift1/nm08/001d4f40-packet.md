# Target packet 001d4f40

- Range: `001d4f40`..`001d4fa8`, **104 bytes = 26 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d4f40`
- Registry names for this address: none
- Queue: state `leased`, queue `register-allocation`, attempts 2, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\rec105\\001d4f40-BLOCKED.md", "sha256": "311b61c5ea66753881efb0092b2f1aed8bb769c89c362eb49bb547daf9601797", "hypothesis": "bound constant 1 in t7 leaves li t7,1 two slots early; try empty asm +r on the constant after object load or moving the bind into the if body"}`

## Callees

- `001d1b60` registry: `_Z16wtarget_001d1b60jjjj`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`, `fm_primary_oneword_recovered_0022d1d8.cpp`
- `002f8b30` registry: `f_powf`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d4f40: 27bdffe0  addiu	sp,sp,-32
001d4f44: 44866800  mtc1	a2,$f13
001d4f48: e7b40010  swc1	$f20,16(sp)
001d4f4c: 3c0f0037  lui	t7,0x37
001d4f50: ffb00000  sd	s0,0(sp)
001d4f54: 46806b60  cvt.s.w	$f13,$f13
001d4f58: 4485a000  mtc1	a1,$f20
001d4f5c: 25efe530  addiu	t7,t7,-6864   ; = D_0036e530
001d4f60: ffbf0008  sd	ra,8(sp)
001d4f64: 0080802d  move	s0,a0
001d4f68: 4680a520  cvt.s.w	$f20,$f20
001d4f6c: 0c0be2cc  jal	0x2f8b30
001d4f70: c5ec0000  lwc1	$f12,0(t7)
001d4f74: 4600a502  mul.s	$f20,$f20,$f0
001d4f78: 8e05002c  lw	a1,44(s0)
001d4f7c: 0200202d  move	a0,s0
001d4f80: dfbf0008  ld	ra,8(sp)
001d4f84: 240f0001  li	t7,1
001d4f88: dfb00000  ld	s0,0(sp)
001d4f8c: 4600a024  cvt.w.s	$f0,$f20
001d4f90: 440e0000  mfc1	t6,$f0
001d4f94: c7b40010  lwc1	$f20,16(sp)
001d4f98: 01ee700a  movz	t6,t7,t6
001d4f9c: 00ae2821  addu	a1,a1,t6
001d4fa0: 080746d8  j	0x1d1b60
001d4fa4: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d4f40(void)`

```c
void FUN_001d4f40(undefined8 param_1,int param_2,int param_3)

{
  float fVar1;
  int iVar2;
  
  fVar1 = (float)FUN_002f8b30(DAT_0036e530,(float)param_3);
  iVar2 = (int)((float)param_2 * fVar1);
  if (iVar2 == 0) {
    iVar2 = 1;
  }
  FUN_001d1b60(param_1,*(int *)((int)param_1 + 0x2c) + iVar2);
  return;
}
```

## Earlier attempts (newest first)

- 2 differing words, 104/104 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec105/orch1_rec105_001d4f40_v8.verification.json`
- 6 differing words, 108/104 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec105/orch1_rec105_001d4f40_v7.verification.json`
- 4 differing words, 104/104 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec105/orch1_rec105_001d4f40_v6.verification.json`
- 19 differing words, 100/104 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec105/orch1_rec105_001d4f40_v5.verification.json`
- 19 differing words, 100/104 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec105/orch1_rec105_001d4f40_v4.verification.json`
- 19 differing words, 100/104 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec105/orch1_rec105_001d4f40_v3.verification.json`
- 20 differing words, 108/104 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec105/orch1_rec105_001d4f40_v2.verification.json`
- 25 differing words, 112/104 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec105/orch1_rec105_001d4f40_v1.verification.json`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec105/001d4f40-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec105/001d4f40-packet.md`
