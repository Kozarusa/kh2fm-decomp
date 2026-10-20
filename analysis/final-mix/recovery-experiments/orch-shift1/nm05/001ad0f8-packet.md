# Target packet 001ad0f8

- Range: `001ad0f8`..`001ad154`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ad0f8`
- Registry names for this address: none
- Queue: state `leased`, queue `address-materialization`, attempts 2, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\rec81\\001ad0f8-BLOCKED.md", "sha256": "f03a217d80b6b9433cc6dedcc26a43eaa0c3cbb06af275a6d6119ec68620b1b9", "hypothesis": "Force address materialization with lui+addiu into t7 then lwc1 0(t7): pointer variable with asm +r, or pointer kept live"}`

## Callees

- `001ac970` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_orchcd_recovered_001ad1d0.cpp`, `fm_primary_orchcd_recovered_001ad228.cpp`, `fm_primary_orchcd_recovered_001ad430.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ad0f8: 27bdfff0  addiu	sp,sp,-16
001ad0fc: 00a0382d  move	a3,a1
001ad100: ffb00000  sd	s0,0(sp)
001ad104: 00c0402d  move	t0,a2
001ad108: ffbf0008  sd	ra,8(sp)
001ad10c: 24050003  li	a1,3
001ad110: 0080802d  move	s0,a0
001ad114: 24060005  li	a2,5
001ad118: 24090080  li	t1,128
001ad11c: 240a0068  li	t2,104
001ad120: 0c06b25c  jal	0x1ac970
001ad124: 0000582d  move	t3,zero
001ad128: 3c0f0037  lui	t7,0x37
001ad12c: dfbf0008  ld	ra,8(sp)
001ad130: 25efd7a0  addiu	t7,t7,-10336   ; = D_0036d7a0
001ad134: c5e00000  lwc1	$f0,0(t7)
001ad138: 3c0f0035  lui	t7,0x35
001ad13c: e6000068  swc1	$f0,104(s0)
001ad140: 25ef0b70  addiu	t7,t7,2928   ; = D_00350b70
001ad144: ae0f0000  sw	t7,0(s0)
001ad148: dfb00000  ld	s0,0(sp)
001ad14c: 03e00008  jr	ra
001ad150: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ad0f8(void)`

```c
void FUN_001ad0f8(undefined8 param_1,undefined8 param_2,undefined8 param_3)

{
  FUN_001ac970(param_1,3,5,param_2,param_3,0x80,0x68,0);
  ((undefined4 *)param_1)[0x1a] = DAT_0036d7a0;
  *(undefined4 *)param_1 = &PTR_FUN_00350b70;
  return;
}
```

## Earlier attempts (newest first)

- 10 differing words, 88/92 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec81/orch1_rec81_001ad0f8_v4.verification.json`
- 10 differing words, 88/92 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec81/orch1_rec81_001ad0f8_v3.verification.json`
- 10 differing words, 88/92 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec81/orch1_rec81_001ad0f8_v2.verification.json`
- 10 differing words, 88/92 bytes: `analysis/final-mix/recovery-experiments/orch-shift1/rec81/orch1_rec81_001ad0f8_v1.verification.json`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec81/001ad0f8-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/rec81/001ad0f8-packet.md`
