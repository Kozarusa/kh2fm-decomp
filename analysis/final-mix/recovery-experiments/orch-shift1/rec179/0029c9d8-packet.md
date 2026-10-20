# Target packet 0029c9d8

- Range: `0029c9d8`..`0029ca50`, **120 bytes = 30 instructions**. This size is the acceptance size.
- Layout name: `FUN_0029c9d8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0028b040` registry: `Tz::JmReport::GetData(unsigned int)`
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_orchem_recovered_0028b040.cpp`, `fm_primary_twoword_recovered_0026ec70.cpp`, `fm_primary_twoword_recovered_00276410.cpp`, `fm_primary_twoword_recovered_002806c8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0029c9d8: 27bdfff0  addiu	sp,sp,-16
0029c9dc: ffbf0000  sd	ra,0(sp)
0029c9e0: 04810004  bgez	a0,0x29c9f4
0029c9e4: 0080102d  move	v0,a0
0029c9e8: 3c0f0036  lui	t7,0x36
0029c9ec: 0c0a2c10  jal	0x28b040
0029c9f0: 8de4f200  lw	a0,-3584(t7)   ; = D_0035f200
0029c9f4: 3c0f0036  lui	t7,0x36
0029c9f8: 0000602d  move	t4,zero
0029c9fc: 8deef5ac  lw	t6,-2644(t7)   ; = D_0035f5ac
0029ca00: 0000682d  move	t5,zero
0029ca04: 8dce0000  lw	t6,0(t6)
0029ca08: 01ae7807  srav	t7,t6,t5
0029ca0c: 31ef0001  andi	t7,t7,0x1
0029ca10: 31ef00ff  andi	t7,t7,0xff
0029ca14: 51e00005  beqzl	t7,0x29ca2c
0029ca18: 25ad0001  addiu	t5,t5,1
0029ca1c: 11820007  beq	t4,v0,0x29ca3c
0029ca20: 25afffff  addiu	t7,t5,-1
0029ca24: 258c0001  addiu	t4,t4,1
0029ca28: 25ad0001  addiu	t5,t5,1
0029ca2c: 29af0013  slti	t7,t5,19
0029ca30: 15e0fff6  bnez	t7,0x29ca0c
0029ca34: 01ae7807  srav	t7,t6,t5
0029ca38: 25afffff  addiu	t7,t5,-1
0029ca3c: dfbf0000  ld	ra,0(sp)
0029ca40: 24020010  li	v0,16
0029ca44: 01ed100b  movn	v0,t7,t5
0029ca48: 03e00008  jr	ra
0029ca4c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0029c9d8(void)`

```c
uint FUN_0029c9d8(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (param_1 < 0) {
    param_1 = FUN_0028b040(DAT_0035f200);
  }
  iVar1 = 0;
  uVar4 = *DAT_0035f5ac;
  uVar3 = 0;
  do {
    uVar2 = uVar3;
    if ((uVar4 & 1) != 0) {
      uVar3 = uVar2;
      uVar5 = uVar2 - 1;
      if (iVar1 == param_1) break;
      iVar1 = iVar1 + 1;
    }
    uVar3 = uVar2 + 1;
    uVar4 = (int)*DAT_0035f5ac >> (uVar3 & 0x1f);
    uVar5 = uVar2;
  } while ((int)uVar3 < 0x13);
  uVar4 = 0x10;
  if (uVar3 != 0) {
    uVar4 = uVar5;
  }
  return uVar4;
}
```

## Earlier attempts (newest first)

- none found
