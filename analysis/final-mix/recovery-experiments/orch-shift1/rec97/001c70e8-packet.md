# Target packet 001c70e8

- Range: `001c70e8`..`001c7148`, **96 bytes = 24 instructions**. This size is the acceptance size.
- Layout name: `FUN_001c70e8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001c70e8: 3c0f0037  lui	t7,0x37
001c70ec: 3c0b01d5  lui	t3,0x1d5
001c70f0: 25efdf88  addiu	t7,t7,-8312   ; = D_0036df88
001c70f4: 8d6e9940  lw	t6,-26304(t3)   ; = D_01d49940
001c70f8: c5e10000  lwc1	$f1,0(t7)
001c70fc: 3c0a01d5  lui	t2,0x1d5
001c7100: 254c98f0  addiu	t4,t2,-26384   ; = D_01d498f0
001c7104: 240fff87  li	t7,-121
001c7108: 258dffe0  addiu	t5,t4,-32
001c710c: 01cf7024  and	t6,t6,t7
001c7110: 35ce0030  ori	t6,t6,0x30
001c7114: ad6e9940  sw	t6,-26304(t3)   ; = D_01d49940
001c7118: 3c0e0037  lui	t6,0x37
001c711c: e5810008  swc1	$f1,8(t4)
001c7120: 25cedf8c  addiu	t6,t6,-8308   ; = D_0036df8c
001c7124: c5c00000  lwc1	$f0,0(t6)
001c7128: ddaf0070  ld	t7,112(t5)
001c712c: e5a0006c  swc1	$f0,108(t5)
001c7130: 35ef0001  ori	t7,t7,0x1
001c7134: e54198f0  swc1	$f1,-26384(t2)   ; = D_01d498f0
001c7138: fdaf0070  sd	t7,112(t5)
001c713c: e5810004  swc1	$f1,4(t4)
001c7140: 03e00008  jr	ra
001c7144: ad80000c  sw	zero,12(t4)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001c70e8(void)`

```c
void FUN_001c70e8(void)

{
  DAT_01d498f8 = DAT_0036df88;
  DAT_01d4993c = DAT_0036df8c;
  DAT_01d498f0 = DAT_0036df88;
  DAT_01d49940 = DAT_01d49940 & 0xffffffffffffff87 | 0x31;
  DAT_01d498f4 = DAT_0036df88;
  DAT_01d498fc = 0;
  return;
}
```

## Earlier attempts (newest first)

- none found
