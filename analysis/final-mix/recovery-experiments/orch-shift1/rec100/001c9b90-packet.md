# Target packet 001c9b90

- Range: `001c9b90`..`001c9c00`, **112 bytes = 28 instructions**. This size is the acceptance size.
- Layout name: `FUN_001c9b90`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001c9c00` registry: none
- `001c9c78` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001c9b90: 27bdffe0  addiu	sp,sp,-32
001c9b94: ffb10008  sd	s1,8(sp)
001c9b98: ffb00000  sd	s0,0(sp)
001c9b9c: ffb20010  sd	s2,16(sp)
001c9ba0: ffbf0018  sd	ra,24(sp)
001c9ba4: 0c072700  jal	0x1c9c00
001c9ba8: 0000882d  move	s1,zero
001c9bac: 3c0e0035  lui	t6,0x35
001c9bb0: 8dcf1f30  lw	t7,7984(t6)   ; = D_00351f30
001c9bb4: 19e0000a  blez	t7,0x1c9be0
001c9bb8: 3c0f01d5  lui	t7,0x1d5
001c9bbc: 01c0902d  move	s2,t6
001c9bc0: 25f09980  addiu	s0,t7,-26240   ; = D_01d49980
001c9bc4: 8e040000  lw	a0,0(s0)
001c9bc8: 0c07271e  jal	0x1c9c78
001c9bcc: 26310001  addiu	s1,s1,1
001c9bd0: 8e4f1f30  lw	t7,7984(s2)
001c9bd4: 022f782a  slt	t7,s1,t7
001c9bd8: 15e0fffa  bnez	t7,0x1c9bc4
001c9bdc: 26100004  addiu	s0,s0,4
001c9be0: 3c0f0035  lui	t7,0x35
001c9be4: dfb00000  ld	s0,0(sp)
001c9be8: ade01f30  sw	zero,7984(t7)   ; = D_00351f30
001c9bec: dfb10008  ld	s1,8(sp)
001c9bf0: dfb20010  ld	s2,16(sp)
001c9bf4: dfbf0018  ld	ra,24(sp)
001c9bf8: 03e00008  jr	ra
001c9bfc: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001c9b90(void)`

```c
void FUN_001c9b90(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  FUN_001c9c00();
  if (0 < DAT_00351f30) {
    puVar1 = &DAT_01d49980;
    do {
      iVar2 = iVar2 + 1;
      FUN_001c9c78(*puVar1);
      puVar1 = puVar1 + 1;
    } while (iVar2 < DAT_00351f30);
  }
  DAT_00351f30 = 0;
  return;
}
```

## Earlier attempts (newest first)

- none found
