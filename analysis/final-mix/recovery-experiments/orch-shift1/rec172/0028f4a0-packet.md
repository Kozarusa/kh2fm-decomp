# Target packet 0028f4a0

- Range: `0028f4a0`..`0028f4d4`, **52 bytes = 13 instructions**. This size is the acceptance size.
- Layout name: `FUN_0028f4a0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
0028f4a0: 3c0f0036  lui	t7,0x36
0028f4a4: 0000602d  move	t4,zero
0028f4a8: 25ebf470  addiu	t3,t7,-2960   ; = D_0035f470
0028f4ac: 000c7840  sll	t7,t4,0x1
0028f4b0: 01e47021  addu	t6,t7,a0
0028f4b4: 258c0001  addiu	t4,t4,1
0028f4b8: 95cd0000  lhu	t5,0(t6)
0028f4bc: 01eb7821  addu	t7,t7,t3
0028f4c0: 298e0003  slti	t6,t4,3
0028f4c4: 15c0fff9  bnez	t6,0x28f4ac
0028f4c8: a5ed0000  sh	t5,0(t7)
0028f4cc: 03e00008  jr	ra
0028f4d0: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0028f4a0(void)`

```c
void FUN_0028f4a0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 1;
    (&DAT_0035f470)[iVar1] = *(undefined2 *)(iVar1 * 2 + param_1);
    iVar1 = iVar2;
  } while (iVar2 < 3);
  return;
}
```

## Earlier attempts (newest first)

- none found
