# Target packet 00109cc0

- Range: `00109cc0`..`00109d00`, **64 bytes = 16 instructions**. This size is the acceptance size.
- Layout name: `FUN_00109cc0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
00109cc0: 3c0f0034  lui	t7,0x34
00109cc4: 00042080  sll	a0,a0,0x2
00109cc8: 25efcc90  addiu	t7,t7,-13168   ; = D_0033cc90
00109ccc: 008f7821  addu	t7,a0,t7
00109cd0: 8def0000  lw	t7,0(t7)
00109cd4: 55e00005  bnezl	t7,0x109cec
00109cd8: ade50010  sw	a1,16(t7)
00109cdc: 3c0f0034  lui	t7,0x34
00109ce0: 25efcc78  addiu	t7,t7,-13192   ; = D_0033cc78
00109ce4: 008f7821  addu	t7,a0,t7
00109ce8: ade50000  sw	a1,0(t7)
00109cec: 3c0f0034  lui	t7,0x34
00109cf0: 25efcc90  addiu	t7,t7,-13168   ; = D_0033cc90
00109cf4: 008f7821  addu	t7,a0,t7
00109cf8: 03e00008  jr	ra
00109cfc: ade50000  sw	a1,0(t7)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00109cc0(void)`

```c
void FUN_00109cc0(int param_1,undefined4 param_2)

{
  if (*(int *)(&DAT_0033cc90 + param_1 * 4) == 0) {
    (&DAT_0033cc78)[param_1] = param_2;
  }
  else {
    *(undefined4 *)(*(int *)(&DAT_0033cc90 + param_1 * 4) + 0x10) = param_2;
  }
  *(undefined4 *)(&DAT_0033cc90 + param_1 * 4) = param_2;
  return;
}
```

## Earlier attempts (newest first)

- none found
