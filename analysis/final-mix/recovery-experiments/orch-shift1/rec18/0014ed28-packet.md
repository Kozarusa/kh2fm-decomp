# Target packet 0014ed28

- Range: `0014ed28`..`0014eda8`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_0014ed28`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00136958` registry: `func_00136958`
- `0014ecf8` registry: `func_0014ecf8`
- `002bc2e8` registry: `func_002bc2e8`
  - accepted sources that already call it (copy their declaration): `fm_primary_workertwo_recovered_002bc2e8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0014ed28: 27bdffd0  addiu	sp,sp,-48
0014ed2c: ffb30018  sd	s3,24(sp)
0014ed30: ffb20010  sd	s2,16(sp)
0014ed34: ffb00000  sd	s0,0(sp)
0014ed38: ffb10008  sd	s1,8(sp)
0014ed3c: ffbf0020  sd	ra,32(sp)
0014ed40: 0c053b3e  jal	0x14ecf8
0014ed44: 00a0982d  move	s3,a1
0014ed48: 10400010  beqz	v0,0x14ed8c
0014ed4c: 0040902d  move	s2,v0
0014ed50: 0c04da56  jal	0x136958
0014ed54: 3c110035  lui	s1,0x35
0014ed58: 8e30a400  lw	s0,-23552(s1)   ; = D_0034a400
0014ed5c: 3c0f0035  lui	t7,0x35
0014ed60: 25efa408  addiu	t7,t7,-23544   ; = D_0034a408
0014ed64: 0040282d  move	a1,v0
0014ed68: 00108080  sll	s0,s0,0x2
0014ed6c: 0240202d  move	a0,s2
0014ed70: 020f8021  addu	s0,s0,t7
0014ed74: 0c0af0ba  jal	0x2bc2e8
0014ed78: 0260302d  move	a2,s3
0014ed7c: 8e2fa400  lw	t7,-23552(s1)   ; = D_0034a400
0014ed80: ae020000  sw	v0,0(s0)
0014ed84: 25ef0001  addiu	t7,t7,1
0014ed88: ae2fa400  sw	t7,-23552(s1)   ; = D_0034a400
0014ed8c: dfb00000  ld	s0,0(sp)
0014ed90: dfb10008  ld	s1,8(sp)
0014ed94: dfb20010  ld	s2,16(sp)
0014ed98: dfb30018  ld	s3,24(sp)
0014ed9c: dfbf0020  ld	ra,32(sp)
0014eda0: 03e00008  jr	ra
0014eda4: 27bd0030  addiu	sp,sp,48
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0014ed28(void)`

```c
void FUN_0014ed28(undefined8 param_1,undefined8 param_2)

{
  undefined8 uVar1;
  undefined4 uVar2;
  long lVar3;
  undefined4 *puVar4;
  
  lVar3 = FUN_0014ecf8();
  if (lVar3 != 0) {
    uVar1 = FUN_00136958();
    puVar4 = &DAT_0034a408 + DAT_0034a400;
    uVar2 = FUN_002bc2e8(lVar3,uVar1,param_2);
    *puVar4 = uVar2;
    DAT_0034a400 = DAT_0034a400 + 1;
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
