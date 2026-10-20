# Target packet 001a81f0

- Range: `001a81f0`..`001a8258`, **104 bytes = 26 instructions**. This size is the acceptance size.
- Layout name: `FUN_001a81f0`
- Registry names for this address: none
- Queue: state `leased`, queue `register-allocation`, attempts 2, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\rec76\\001a81f0-BLOCKED.md", "sha256": "aebd090d874b881154c5e7166c7d4ffe3251e7b24211742f64b1c40d07be0a56", "hypothesis": "register binding or asm barrier on count to force lhu into t7 then move t4,t7"}`

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001a81f0: 3c0f01c7  lui	t7,0x1c7
001a81f4: 0000682d  move	t5,zero
001a81f8: 8deecb98  lw	t6,-13416(t7)   ; = D_01c6cb98
001a81fc: 95cf0002  lhu	t7,2(t6)
001a8200: 11e00012  beqz	t7,0x1a824c
001a8204: 25ce0004  addiu	t6,t6,4
001a8208: 01e0602d  move	t4,t7
001a820c: 91cf0004  lbu	t7,4(t6)
001a8210: 55e0000b  bnezl	t7,0x1a8240
001a8214: 25ad0001  addiu	t5,t5,1
001a8218: 91cf0005  lbu	t7,5(t6)
001a821c: 55e40008  bnel	t7,a0,0x1a8240
001a8220: 25ad0001  addiu	t5,t5,1
001a8224: 91cf0006  lbu	t7,6(t6)
001a8228: 55e50005  bnel	t7,a1,0x1a8240
001a822c: 25ad0001  addiu	t5,t5,1
001a8230: 91cf0007  lbu	t7,7(t6)
001a8234: 11e60006  beq	t7,a2,0x1a8250
001a8238: 01c0102d  move	v0,t6
001a823c: 25ad0001  addiu	t5,t5,1
001a8240: 01ac782a  slt	t7,t5,t4
001a8244: 15e0fff1  bnez	t7,0x1a820c
001a8248: 25ce000c  addiu	t6,t6,12
001a824c: 0000102d  move	v0,zero
001a8250: 03e00008  jr	ra
001a8254: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001a81f0(void)`

```c
int FUN_001a81f0(ulong param_1,ulong param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  iVar2 = DAT_01c6cb98 + 4;
  if (*(ushort *)(DAT_01c6cb98 + 2) != 0) {
    do {
      if ((((*(char *)(iVar2 + 4) == '\0') && (*(byte *)(iVar2 + 5) == param_1)) &&
          (*(byte *)(iVar2 + 6) == param_2)) && (*(byte *)(iVar2 + 7) == param_3)) {
        return iVar2;
      }
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 0xc;
    } while (iVar1 < (int)(uint)*(ushort *)(DAT_01c6cb98 + 2));
  }
  return 0;
}
```

## Earlier attempts (newest first)

- 20 differing words, 104/104 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_01_0.cpp`)
- 24 differing words, 100/104 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec76/orch1_rec76_001a81f0_v4.verification.json`
- 26 differing words, 116/104 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec76/orch1_rec76_001a81f0_v3.verification.json`
- 22 differing words, 100/104 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec76/orch1_rec76_001a81f0_v2.verification.json`
- 22 differing words, 100/104 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec76/orch1_rec76_001a81f0_v1.verification.json`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec76/001a81f0-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec76/001a81f0-packet.md`
