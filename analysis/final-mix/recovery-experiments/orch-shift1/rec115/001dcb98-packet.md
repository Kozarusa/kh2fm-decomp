# Target packet 001dcb98

- Range: `001dcb98`..`001dcc00`, **104 bytes = 26 instructions**. This size is the acceptance size.
- Layout name: `FUN_001dcb98`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001dc670` registry: `_ZN3ryj6EFFECT5colorEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_0016fa58.cpp`, `fm_primary_fiveword_recovered_00171a40.cpp`, `fm_primary_floatarguments_recovered_0018f9b8.cpp`, `fm_primary_fourwordfresh_recovered_00195558.cpp`, `fm_primary_fourwordfresh_recovered_00197390.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001dcb98: 27bdffe0  addiu	sp,sp,-32
001dcb9c: 3c0f0037  lui	t7,0x37
001dcba0: ffbf0010  sd	ra,16(sp)
001dcba4: 25efe7e8  addiu	t7,t7,-6168   ; = D_0036e7e8
001dcba8: 0000682d  move	t5,zero
001dcbac: 03a0602d  move	t4,sp
001dcbb0: c5e10000  lwc1	$f1,0(t7)
001dcbb4: 00ad7821  addu	t7,a1,t5
001dcbb8: 91ee0000  lbu	t6,0(t7)
001dcbbc: 25ad0001  addiu	t5,t5,1
001dcbc0: 448e0000  mtc1	t6,$f0
001dcbc4: 29af0004  slti	t7,t5,4
001dcbc8: 46800020  cvt.s.w	$f0,$f0
001dcbcc: 46010002  mul.s	$f0,$f0,$f1
001dcbd0: e5800000  swc1	$f0,0(t4)
001dcbd4: 15e0fff7  bnez	t7,0x1dcbb4
001dcbd8: 258c0004  addiu	t4,t4,4
001dcbdc: 0c07719c  jal	0x1dc670
001dcbe0: 00000000  nop
001dcbe4: 105d0004  beq	v0,sp,0x1dcbf8
001dcbe8: dfbf0010  ld	ra,16(sp)
001dcbec: 7ba80000  lq	t0,0(sp)
001dcbf0: 7c480000  sq	t0,0(v0)
001dcbf4: dfbf0010  ld	ra,16(sp)
001dcbf8: 03e00008  jr	ra
001dcbfc: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001dcb98(void)`

```c
void FUN_001dcb98(undefined8 param_1,int param_2)

{
  float fVar1;
  float *pfVar2;
  int iVar3;
  byte *pbVar4;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  
  fVar1 = DAT_0036e7e8;
  pfVar2 = &fStack_20;
  iVar3 = 0;
  do {
    pbVar4 = (byte *)(param_2 + iVar3);
    iVar3 = iVar3 + 1;
    *pfVar2 = (float)*pbVar4 * fVar1;
    pfVar2 = pfVar2 + 1;
  } while (iVar3 < 4);
  pfVar2 = (float *)FUN_001dc670();
  if (pfVar2 != &fStack_20) {
    *pfVar2 = fStack_20;
    pfVar2[1] = fStack_1c;
    pfVar2[2] = fStack_18;
    pfVar2[3] = fStack_14;
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
