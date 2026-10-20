# Target packet 001c05b0

- Range: `001c05b0`..`001c0614`, **100 bytes = 25 instructions**. This size is the acceptance size.
- Layout name: `FUN_001c05b0`
- Registry names for this address: `_Z16wtarget_001c05b0jjjj`
- Queue: state `leased`, queue `address-materialization`, attempts 2, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\rec95\\001c05b0-BLOCKED.md", "sha256": "aa671ec7d02e4efe834bfa3eb63eec20830f8caa0976bf667a173c99ec985f0f", "hypothesis": "Treat D_01d49350 as a 2-word array/struct with pointer set before the first store, ordering the addiu ahead of sw"}`

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001c05b0: 340fffff  li	t7,0xffff
001c05b4: 14af0015  bne	a1,t7,0x1c060c
001c05b8: 240f0001  li	t7,1
001c05bc: 548f000c  bnel	a0,t7,0x1c05f0
001c05c0: 340fffff  li	t7,0xffff
001c05c4: 3c0f01d5  lui	t7,0x1d5
001c05c8: 240e0007  li	t6,7
001c05cc: 25ef9328  addiu	t7,t7,-27864   ; = D_01d49328
001c05d0: ade00000  sw	zero,0(t7)
001c05d4: 25ceffff  addiu	t6,t6,-1
001c05d8: 00000000  nop
001c05dc: 00000000  nop
001c05e0: 00000000  nop
001c05e4: 05c1fffa  bgez	t6,0x1c05d0
001c05e8: 25ef0004  addiu	t7,t7,4
001c05ec: 340fffff  li	t7,0xffff
001c05f0: 14af0006  bne	a1,t7,0x1c060c
001c05f4: 240f0001  li	t7,1
001c05f8: 148f0004  bne	a0,t7,0x1c060c
001c05fc: 3c0f01d5  lui	t7,0x1d5
001c0600: 25ee9350  addiu	t6,t7,-27824   ; = D_01d49350
001c0604: ade09350  sw	zero,-27824(t7)   ; = D_01d49350
001c0608: adc00004  sw	zero,4(t6)
001c060c: 03e00008  jr	ra
001c0610: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001c05b0(void)`

```c
void FUN_001c05b0(int param_1,long param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_2 == 0xffff) {
    if (param_1 == 1) {
      iVar1 = 7;
      puVar2 = &DAT_01d49328;
      do {
        *puVar2 = 0;
        iVar1 = iVar1 + -1;
        puVar2 = puVar2 + 1;
      } while (-1 < iVar1);
    }
    if (param_1 == 1) {
      DAT_01d49350 = 0;
      DAT_01d49354 = 0;
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- 13 differing words, 92/100 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.cpp`)
- 3 differing words, 100/100 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec95/orch1_rec95_001c05b0_v5.verification.json`
- 2 differing words, 100/100 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec95/orch1_rec95_001c05b0_v4.verification.json`
- 2 differing words, 100/100 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec95/orch1_rec95_001c05b0_v3.verification.json`
- 2 differing words, 100/100 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec95/orch1_rec95_001c05b0_v2.verification.json`
- 13 differing words, 92/100 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec95/orch1_rec95_001c05b0_v1.verification.json`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec95/001c05b0-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec95/001c05b0-packet.md`
