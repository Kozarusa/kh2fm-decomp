# Target packet 001dee10

- Range: `001dee10`..`001dee88`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_001dee10`
- Registry names for this address: none
- Queue: state `leased`, queue `register-allocation`, attempts 2, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\rec118\\001dee10-BLOCKED.md", "sha256": "56adf26eb4368d15fb09016e49600178f912720c6412c958cd12a6db989ea149", "hypothesis": "Fixed compare base lands in t5 and counter in t6 vs t6/t7 in original; try separate scope for base or empty asm guard on the counter"}`

## Callees

- `001e0158` registry: `func_001e0158`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`
- `001e01b8` registry: `func_001e01b8`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001dee10: 27bdfff0  addiu	sp,sp,-16
001dee14: ffbf0000  sd	ra,0(sp)
001dee18: 8c8e005c  lw	t6,92(a0)
001dee1c: 31cf0004  andi	t7,t6,0x4
001dee20: 11e00013  beqz	t7,0x1dee70
001dee24: 31cf0008  andi	t7,t6,0x8
001dee28: 8c840058  lw	a0,88(a0)
001dee2c: 1080000d  beqz	a0,0x1dee64
001dee30: 240fffe0  li	t7,-32
001dee34: 108f0009  beq	a0,t7,0x1dee5c
001dee38: 248f0040  addiu	t7,a0,64
001dee3c: 248e0020  addiu	t6,a0,32
001dee40: 00000000  nop
001dee44: 00000000  nop
001dee48: 00000000  nop
001dee4c: 00000000  nop
001dee50: 00000000  nop
001dee54: 15cffffa  bne	t6,t7,0x1dee40
001dee58: 25effff0  addiu	t7,t7,-16
001dee5c: 0c078056  jal	0x1e0158
001dee60: 00000000  nop
001dee64: dfbf0000  ld	ra,0(sp)
001dee68: 03e00008  jr	ra
001dee6c: 27bd0010  addiu	sp,sp,16
001dee70: 51e0fffd  beqzl	t7,0x1dee68
001dee74: dfbf0000  ld	ra,0(sp)
001dee78: 0c07806e  jal	0x1e01b8
001dee7c: 8c840058  lw	a0,88(a0)
001dee80: 1000fff9  b	0x1dee68
001dee84: dfbf0000  ld	ra,0(sp)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001dee10(void)`

```c
void FUN_001dee10(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if ((*(uint *)(param_1 + 0x5c) & 4) == 0) {
    if ((*(uint *)(param_1 + 0x5c) & 8) != 0) {
      FUN_001e01b8(*(undefined4 *)(param_1 + 0x58));
    }
  }
  else {
    iVar2 = *(int *)(param_1 + 0x58);
    if (iVar2 != 0) {
      iVar3 = iVar2 + 0x40;
      if (iVar2 != -0x20) {
        do {
          bVar1 = iVar2 + 0x20 != iVar3;
          iVar3 = iVar3 + -0x10;
        } while (bVar1);
      }
      FUN_001e0158();
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- 24 differing words, 120/120 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_08_1.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_08_1.cpp`)
- 7 differing words, 120/120 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec118/orch1_rec118_001dee10_v6.verification.json`
- 5 differing words, 120/120 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec118/orch1_rec118_001dee10_v5.verification.json`
- 7 differing words, 120/120 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec118/orch1_rec118_001dee10_v4.verification.json`
- 5 differing words, 120/120 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec118/orch1_rec118_001dee10_v3.verification.json`
- 7 differing words, 120/120 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec118/orch1_rec118_001dee10_v2.verification.json`
- 7 differing words, 120/120 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec118/orch1_rec118_001dee10_v1.verification.json`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec118/001dee10-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec118/001dee10-packet.md`
