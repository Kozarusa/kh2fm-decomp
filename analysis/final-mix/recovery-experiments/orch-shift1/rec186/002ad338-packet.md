# Target packet 002ad338

- Range: `002ad338`..`002ad390`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_002ad338`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
002ad338: 3c0f0036  lui	t7,0x36
002ad33c: 24020001  li	v0,1
002ad340: 8deef620  lw	t6,-2528(t7)   ; = D_0035f620
002ad344: 0000602d  move	t4,zero
002ad348: 240a0001  li	t2,1
002ad34c: 25cb013c  addiu	t3,t6,316
002ad350: 000c7942  srl	t7,t4,0x5
002ad354: 318d001f  andi	t5,t4,0x1f
002ad358: 000f7880  sll	t7,t7,0x2
002ad35c: 258c0001  addiu	t4,t4,1
002ad360: 01eb7821  addu	t7,t7,t3
002ad364: 01aa6804  sllv	t5,t2,t5
002ad368: 8dee0000  lw	t6,0(t7)
002ad36c: 01cd7024  and	t6,t6,t5
002ad370: 15c00003  bnez	t6,0x2ad380
002ad374: 298f000d  slti	t7,t4,13
002ad378: 03e00008  jr	ra
002ad37c: 0000102d  move	v0,zero
002ad380: 55e0fff4  bnezl	t7,0x2ad354
002ad384: 000c7942  srl	t7,t4,0x5
002ad388: 03e00008  jr	ra
002ad38c: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_002ad338(void)`

```c
undefined4 FUN_002ad338(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0;
  uVar3 = 0;
  while( true ) {
    uVar2 = uVar1 & 0x1f;
    uVar1 = uVar1 + 1;
    if ((*(uint *)(uVar3 * 4 + DAT_0035f620 + 0x13c) & 1 << uVar2) == 0) {
      return 0;
    }
    if (0xc < (int)uVar1) break;
    uVar3 = uVar1 >> 5;
  }
  return 1;
}
```

## Earlier attempts (newest first)

- 20 differing words, 84/88 bytes: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_03_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_global_probes_v3_03_0.cpp`)
