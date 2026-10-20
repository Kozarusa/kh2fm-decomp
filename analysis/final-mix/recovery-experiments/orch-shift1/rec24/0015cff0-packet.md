# Target packet 0015cff0

- Range: `0015cff0`..`0015d058`, **104 bytes = 26 instructions**. This size is the acceptance size.
- Layout name: `FUN_0015cff0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0015cff0: 3c0f004f  lui	t7,0x4f
0015cff4: 3c0e004f  lui	t6,0x4f
0015cff8: 25ef37b0  addiu	t7,t7,14256   ; = D_004f37b0
0015cffc: 25ce37a0  addiu	t6,t6,14240   ; = D_004f37a0
0015d000: 51ee0004  beql	t7,t6,0x15d014
0015d004: 3c0f004f  lui	t7,0x4f
0015d008: 79c80000  lq	t0,0(t6)
0015d00c: 7de80000  sq	t0,0(t7)   ; = D_004f0000
0015d010: 3c0f004f  lui	t7,0x4f
0015d014: 3c0e004f  lui	t6,0x4f
0015d018: 25ef3790  addiu	t7,t7,14224   ; = D_004f3790
0015d01c: 25ce3780  addiu	t6,t6,14208   ; = D_004f3780
0015d020: 51ee0004  beql	t7,t6,0x15d034
0015d024: 3c0f004f  lui	t7,0x4f
0015d028: 79c80000  lq	t0,0(t6)
0015d02c: 7de80000  sq	t0,0(t7)   ; = D_004f0000
0015d030: 3c0f004f  lui	t7,0x4f
0015d034: 3c0e004f  lui	t6,0x4f
0015d038: 25ef37e0  addiu	t7,t7,14304   ; = D_004f37e0
0015d03c: 25ce37d0  addiu	t6,t6,14288   ; = D_004f37d0
0015d040: 11ee0003  beq	t7,t6,0x15d050
0015d044: 00000000  nop
0015d048: 79c80000  lq	t0,0(t6)
0015d04c: 7de80000  sq	t0,0(t7)
0015d050: 03e00008  jr	ra
0015d054: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0015cff0(void)`

```c
/* WARNING: Removing unreachable block (ram,0x0015d000) */
/* WARNING: Removing unreachable block (ram,0x0015d020) */

void FUN_0015cff0(void)

{
  DAT_004f37b0 = DAT_004f37a0;
  DAT_004f37b4 = DAT_004f37a4;
  DAT_004f37b8 = DAT_004f37a8;
  DAT_004f37bc = DAT_004f37ac;
  DAT_004f3790 = DAT_004f3780;
  DAT_004f3794 = DAT_004f3784;
  DAT_004f3798 = DAT_004f3788;
  DAT_004f379c = DAT_004f378c;
  DAT_004f37e0 = DAT_004f37d0;
  DAT_004f37e4 = DAT_004f37d4;
  DAT_004f37e8 = DAT_004f37d8;
  DAT_004f37ec = DAT_004f37dc;
  return;
}
```

## Earlier attempts (newest first)

- none found
