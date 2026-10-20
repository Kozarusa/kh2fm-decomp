# Target packet 0022afa0

- Range: `0022afa0`..`0022afe4`, **68 bytes = 17 instructions**. This size is the acceptance size.
- Layout name: `FUN_0022afa0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00224828` registry: `func_00224828`
- `0022afe8` registry: `func_0022afe8`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0022afa0: 27bdfff0  addiu	sp,sp,-16
0022afa4: ffb00000  sd	s0,0(sp)
0022afa8: ffbf0008  sd	ra,8(sp)
0022afac: 0c08920a  jal	0x224828
0022afb0: 0080802d  move	s0,a0
0022afb4: 44900000  mtc1	s0,$f0
0022afb8: 3c0f0037  lui	t7,0x37
0022afbc: 25ef1110  addiu	t7,t7,4368   ; = D_00371110
0022afc0: dfbf0008  ld	ra,8(sp)
0022afc4: 46800020  cvt.s.w	$f0,$f0
0022afc8: dfb00000  ld	s0,0(sp)
0022afcc: c5e10000  lwc1	$f1,0(t7)
0022afd0: 46010002  mul.s	$f0,$f0,$f1
0022afd4: 46000064  cvt.w.s	$f1,$f0
0022afd8: 44040800  mfc1	a0,$f1
0022afdc: 0808abfa  j	0x22afe8
0022afe0: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0022afa0(void)`

```c
void FUN_0022afa0(int param_1)

{
  FUN_00224828();
  FUN_0022afe8((int)((float)param_1 * DAT_00371110));
  return;
}
```

## Earlier attempts (newest first)

- none found
