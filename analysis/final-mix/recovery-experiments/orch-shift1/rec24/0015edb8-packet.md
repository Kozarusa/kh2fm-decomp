# Target packet 0015edb8

- Range: `0015edb8`..`0015ee10`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_0015edb8`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00142f50` registry: none
- `001dde40` registry: none
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_primary_fourwordfresh_recovered_0022ae98.cpp`, `fm_primary_fourwordfresh_recovered_0022aef0.cpp`, `fm_primary_fourwordfresh_recovered_0022af48.cpp`
- `001de568` registry: `_ZN3ryj3PAX11ThisIsValidEPS0_`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0015edb8: 27bdfff0  addiu	sp,sp,-16
0015edbc: 3c0f0035  lui	t7,0x35
0015edc0: ffb00000  sd	s0,0(sp)
0015edc4: 240e0001  li	t6,1
0015edc8: ffbf0008  sd	ra,8(sp)
0015edcc: 91edc70c  lbu	t5,-14580(t7)   ; = D_0034c70c
0015edd0: 15ae000b  bne	t5,t6,0x15ee00
0015edd4: dfb00000  ld	s0,0(sp)
0015edd8: 3c100035  lui	s0,0x35
0015eddc: 2610c6f0  addiu	s0,s0,-14608   ; = D_0034c6f0
0015ede0: 0c07795a  jal	0x1de568
0015ede4: 0200202d  move	a0,s0
0015ede8: 10400003  beqz	v0,0x15edf8
0015edec: 0200202d  move	a0,s0
0015edf0: 0c077790  jal	0x1dde40
0015edf4: 00000000  nop
0015edf8: 3c0f0035  lui	t7,0x35
0015edfc: dfb00000  ld	s0,0(sp)
0015ee00: a1e0c70c  sb	zero,-14580(t7)   ; = D_0034c70c
0015ee04: dfbf0008  ld	ra,8(sp)
0015ee08: 08050bd4  j	0x142f50
0015ee0c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0015edb8(void)`

```c
void FUN_0015edb8(void)

{
  long lVar1;
  
  if ((DAT_0034c70c == '\x01') && (lVar1 = FUN_001de568(0x34c6f0), lVar1 != 0)) {
    FUN_001dde40(0x34c6f0);
  }
  DAT_0034c70c = 0;
  FUN_00142f50();
  return;
}
```

## Earlier attempts (newest first)

- none found
