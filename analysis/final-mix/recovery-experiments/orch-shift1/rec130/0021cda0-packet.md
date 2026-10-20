# Target packet 0021cda0

- Range: `0021cda0`..`0021cdcc`, **44 bytes = 11 instructions**. This size is the acceptance size.
- Layout name: `FUN_0021cda0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001e72a8` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0021cda0: 27bdfff0  addiu	sp,sp,-16
0021cda4: ffbf0000  sd	ra,0(sp)
0021cda8: 54800006  bnezl	a0,0x21cdc4
0021cdac: 3c040033  lui	a0,0x33
0021cdb0: 3c040033  lui	a0,0x33
0021cdb4: 2484a980  addiu	a0,a0,-22144   ; = D_0032a980
0021cdb8: dfbf0000  ld	ra,0(sp)
0021cdbc: 08079caa  j	0x1e72a8
0021cdc0: 27bd0010  addiu	sp,sp,16
0021cdc4: 1000fffc  b	0x21cdb8
0021cdc8: 2484b100  addiu	a0,a0,-20224
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0021cda0(void)`

```c
void FUN_0021cda0(long param_1)

{
  undefined **ppuVar1;
  
  if (param_1 == 0) {
    ppuVar1 = &PTR_DAT_0032a980;
  }
  else {
    ppuVar1 = &PTR_DAT_0032b100;
  }
  FUN_001e72a8(ppuVar1);
  return;
}
```

## Earlier attempts (newest first)

- 9 differing words, 44/44 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round6_0021cda0_v02.verification.json`
- 5 differing words, 44/44 bytes: `analysis/final-mix/recovery-experiments/fm_worker_b_round6_0021cda0_v01.verification.json`
