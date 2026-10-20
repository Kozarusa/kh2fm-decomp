# Target packet 001b5a10

- Range: `001b5a10`..`001b5a60`, **80 bytes = 20 instructions**. This size is the acceptance size.
- Layout name: `FUN_001b5a10`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001b5cb8` registry: `_ZNK2YS11LIMIT_TABLE6is_kh1Ev`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001b5a10: 27bdfff0  addiu	sp,sp,-16
001b5a14: 0000102d  move	v0,zero
001b5a18: ffb00000  sd	s0,0(sp)
001b5a1c: ffbf0008  sd	ra,8(sp)
001b5a20: 3c1001d5  lui	s0,0x1d5
001b5a24: 8e0f8cb0  lw	t7,-29520(s0)   ; = D_01d48cb0
001b5a28: 11e00007  beqz	t7,0x1b5a48
001b5a2c: 01e0202d  move	a0,t7
001b5a30: 0c06d72e  jal	0x1b5cb8
001b5a34: 00000000  nop
001b5a38: 10400007  beqz	v0,0x1b5a58
001b5a3c: 8e0f8cb0  lw	t7,-29520(s0)   ; = D_01d48cb0
001b5a40: 8dee000c  lw	t6,12(t7)
001b5a44: 25c20080  addiu	v0,t6,128
001b5a48: dfb00000  ld	s0,0(sp)
001b5a4c: dfbf0008  ld	ra,8(sp)
001b5a50: 03e00008  jr	ra
001b5a54: 27bd0010  addiu	sp,sp,16
001b5a58: 1000fffb  b	0x1b5a48
001b5a5c: 25e20018  addiu	v0,t7,24
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001b5a10(void)`

```c
int FUN_001b5a10(void)

{
  int iVar1;
  long lVar2;
  
  iVar1 = 0;
  if (DAT_01d48cb0 != 0) {
    lVar2 = FUN_001b5cb8(DAT_01d48cb0);
    if (lVar2 == 0) {
      iVar1 = DAT_01d48cb0 + 0x18;
    }
    else {
      iVar1 = *(int *)(DAT_01d48cb0 + 0xc) + 0x80;
    }
  }
  return iVar1;
}
```

## Earlier attempts (newest first)

- 18 differing words, 64/80 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round25_001b5a10_v03.verification.json`
- 13 differing words, 80/80 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round25_001b5a10_v02.verification.json`
- 16 differing words, 76/80 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round25_001b5a10_v01.verification.json`
