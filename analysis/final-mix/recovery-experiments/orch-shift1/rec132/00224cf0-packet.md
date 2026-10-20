# Target packet 00224cf0

- Range: `00224cf0`..`00224d3c`, **76 bytes = 19 instructions**. This size is the acceptance size.
- Layout name: `FUN_00224cf0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00224c20` registry: `func_00224c20`
  - accepted sources that already call it (copy their declaration): `fm_primary_queuegamma_recovered_00224c20.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00224cf0: 27bdfff0  addiu	sp,sp,-16
00224cf4: ffbf0000  sd	ra,0(sp)
00224cf8: 0c089308  jal	0x224c20
00224cfc: 00000000  nop
00224d00: 2c4f0006  sltiu	t7,v0,6
00224d04: 11e0000a  beqz	t7,0x224d30
00224d08: 3c0e0037  lui	t6,0x37
00224d0c: 00027880  sll	t7,v0,0x2
00224d10: 25ce0d28  addiu	t6,t6,3368   ; = D_00370d28
00224d14: 01ee7821  addu	t7,t7,t6
00224d18: 8ded0000  lw	t5,0(t7)
00224d1c: 01a00008  jr	t5
00224d20: 00000000  nop
00224d24: 3c0e0070  lui	t6,0x70
00224d28: 3c0f0036  lui	t7,0x36
00224d2c: adeedb18  sw	t6,-9448(t7)   ; = D_0035db18
00224d30: dfbf0000  ld	ra,0(sp)
00224d34: 03e00008  jr	ra
00224d38: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00224cf0(void)`

```c
void FUN_00224cf0(void)

{
  ulong uVar1;
  
  uVar1 = FUN_00224c20();
  if (uVar1 < 6) {
                    /* WARNING: Switch is manually overridden */
    switch((int)uVar1) {
    case 0:
      break;
    default:
      DAT_0035db18 = 0x700000;
      break;
    case 3:
      DAT_0035db18 = 0x600000;
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
