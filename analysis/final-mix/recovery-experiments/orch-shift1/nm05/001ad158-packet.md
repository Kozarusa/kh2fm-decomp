# Target packet 001ad158

- Range: `001ad158`..`001ad1cc`, **116 bytes = 29 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ad158`
- Registry names for this address: none
- Queue: state `leased`, queue `register-allocation`, attempts 2, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\rec80\\001ad158-BLOCKED.md", "sha256": "1af2ac3bbf3da23ffdb0d0660cfed5d780e4e3b7e45450c70c70e6428fd7bd4e", "hypothesis": "C11: bind or asm+r param_3 so s3=a2, s4=a1"}`

## Callees

- `001050d8` registry: `_ZN4AREA5AllocEj`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_oct7_extended_recovered_00.cpp`, `fm_oct7_extended_recovered_01.cpp`, `fm_primary_addresspair_recovered_001a6c60.cpp`, `fm_primary_callbackreturn_recovered_001050d8.cpp`
- `001ad0f8` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fourwordnext_recovered_001afe70.cpp`, `fm_primary_oneword_recovered_001bf0c8.cpp`, `fm_primary_twoword_recovered_001b2488.cpp`, `fm_primary_twoword_recovered_001ba310.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ad158: 27bdffd0  addiu	sp,sp,-48
001ad15c: ffb20010  sd	s2,16(sp)
001ad160: ffb10008  sd	s1,8(sp)
001ad164: ffb30018  sd	s3,24(sp)
001ad168: 0080902d  move	s2,a0
001ad16c: ffb40020  sd	s4,32(sp)
001ad170: 00e0882d  move	s1,a3
001ad174: ffbf0028  sd	ra,40(sp)
001ad178: 00c0982d  move	s3,a2
001ad17c: ffb00000  sd	s0,0(sp)
001ad180: 00a0a02d  move	s4,a1
001ad184: 0c041436  jal	0x1050d8
001ad188: 24040b6c  li	a0,2924
001ad18c: 0040802d  move	s0,v0
001ad190: 0220282d  move	a1,s1
001ad194: 0040202d  move	a0,v0
001ad198: 0c06b43e  jal	0x1ad0f8
001ad19c: 0000302d  move	a2,zero
001ad1a0: ae5004a8  sw	s0,1192(s2)
001ad1a4: dfb10008  ld	s1,8(sp)
001ad1a8: ae130008  sw	s3,8(s0)
001ad1ac: ae140004  sw	s4,4(s0)
001ad1b0: dfb20010  ld	s2,16(sp)
001ad1b4: dfb00000  ld	s0,0(sp)
001ad1b8: dfb30018  ld	s3,24(sp)
001ad1bc: dfb40020  ld	s4,32(sp)
001ad1c0: dfbf0028  ld	ra,40(sp)
001ad1c4: 03e00008  jr	ra
001ad1c8: 27bd0030  addiu	sp,sp,48
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ad158(void)`

```c
void FUN_001ad158(int param_1,undefined4 param_2,undefined4 param_3,undefined8 param_4)

{
  undefined8 uVar1;
  int iVar2;
  
  uVar1 = FUN_001050d8(0xb6c);
  FUN_001ad0f8(uVar1,param_4,0);
  iVar2 = (int)uVar1;
  *(int *)(param_1 + 0x4a8) = iVar2;
  *(undefined4 *)(iVar2 + 8) = param_3;
  *(undefined4 *)(iVar2 + 4) = param_2;
  return;
}
```

## Earlier attempts (newest first)

- 6 differing words, 116/116 bytes: `analysis/final-mix/recovery-experiments/fm_width_all_06_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_width_all_06_1.cpp`)
- 6 differing words, 116/116 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec80/orch1_rec80_001ad158_v4.verification.json`
- 12 differing words, 116/116 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec80/orch1_rec80_001ad158_v3.verification.json`
- 8 differing words, 116/116 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec80/orch1_rec80_001ad158_v2.verification.json`
- 6 differing words, 116/116 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec80/orch1_rec80_001ad158_v1.verification.json`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec80/001ad158-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec80/001ad158-packet.md`
