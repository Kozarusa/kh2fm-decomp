# Target packet 002a74c0

- Range: `002a74c0`..`002a752c`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_002a74c0`
- Registry names for this address: `func_002a74c0`
- Queue: state `leased`, queue `register-allocation`, attempts 2, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\rec181\\002a74c0-BLOCKED.md", "sha256": "fce82f3691ade81394a3b743e79ab59459944394cb8a4ea791f00ffb0a539982", "hypothesis": "Bind an existing increment or mask temporary to constrain scheduler without another live value"}`

## Callees

- `001058e8` registry: `_Z10getSaveRamv`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_00232510.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
002a74c0: 27bdfff0  addiu	sp,sp,-16
002a74c4: ffbf0000  sd	ra,0(sp)
002a74c8: 0c04163a  jal	0x1058e8
002a74cc: 00000000  nop
002a74d0: 244249f4  addiu	v0,v0,18932
002a74d4: 0000502d  move	t2,zero
002a74d8: 0000602d  move	t4,zero
002a74dc: 240b0001  li	t3,1
002a74e0: 000c7942  srl	t7,t4,0x5
002a74e4: 318d001f  andi	t5,t4,0x1f
002a74e8: 000f7880  sll	t7,t7,0x2
002a74ec: 258c0001  addiu	t4,t4,1
002a74f0: 01e27821  addu	t7,t7,v0
002a74f4: 01ab6804  sllv	t5,t3,t5
002a74f8: 8dee0000  lw	t6,0(t7)
002a74fc: 01cd7024  and	t6,t6,t5
002a7500: 11c00006  beqz	t6,0x2a751c
002a7504: 298f0040  slti	t7,t4,64
002a7508: 240a0001  li	t2,1
002a750c: dfbf0000  ld	ra,0(sp)
002a7510: 0140102d  move	v0,t2
002a7514: 03e00008  jr	ra
002a7518: 27bd0010  addiu	sp,sp,16
002a751c: 55e0fff1  bnezl	t7,0x2a74e4
002a7520: 000c7942  srl	t7,t4,0x5
002a7524: 1000fffa  b	0x2a7510
002a7528: dfbf0000  ld	ra,0(sp)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002a74c0(void)`

```c
undefined4 FUN_002a74c0(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = FUN_001058e8();
  uVar2 = 0;
  uVar4 = 0;
  while( true ) {
    uVar3 = uVar2 & 0x1f;
    uVar2 = uVar2 + 1;
    if ((*(uint *)(uVar4 * 4 + iVar1 + 0x49f4) & 1 << uVar3) != 0) {
      return 1;
    }
    if (0x3f < (int)uVar2) break;
    uVar4 = uVar2 >> 5;
  }
  return 0;
}
```

## Earlier attempts (newest first)

- 23 differing words, 104/108 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_07.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_07.cpp`)
- 16 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec181/orch1_rec181_002a74c0_v5.verification.json`
- 2 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec181/orch1_rec181_002a74c0_v4.verification.json`
- 2 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec181/orch1_rec181_002a74c0_v3.verification.json`
- 2 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec181/orch1_rec181_002a74c0_v2.verification.json`
- 11 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec181/orch1_rec181_002a74c0_v1.verification.json`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec181/002a74c0-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec181/002a74c0-packet.md`
