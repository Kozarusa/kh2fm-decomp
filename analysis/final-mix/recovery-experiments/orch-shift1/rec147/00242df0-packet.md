# Target packet 00242df0

- Range: `00242df0`..`00242e48`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_00242df0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001058e8` registry: `_Z10getSaveRamv`
  - accepted sources that already call it (copy their declaration): `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_dependencyfamily_recovered_0014b4b0.cpp`, `fm_primary_dependencyfamily_recovered_00272a00.cpp`, `fm_primary_dependencyfamily_recovered_00272a70.cpp`, `fm_primary_oneword_recovered_00232510.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00242df0: 27bdfff0  addiu	sp,sp,-16
00242df4: ffb00000  sd	s0,0(sp)
00242df8: ffbf0008  sd	ra,8(sp)
00242dfc: 0c04163a  jal	0x1058e8
00242e00: 0080802d  move	s0,a0
00242e04: 244241a0  addiu	v0,v0,16800
00242e08: 3a0e0002  xori	t6,s0,0x2
00242e0c: 12000004  beqz	s0,0x242e20
00242e10: 0000682d  move	t5,zero
00242e14: 240d0002  li	t5,2
00242e18: 240f0001  li	t7,1
00242e1c: 01ee680b  movn	t5,t7,t6
00242e20: 8c4f0004  lw	t7,4(v0)
00242e24: 240ef9ff  li	t6,-1537
00242e28: 000d6a40  sll	t5,t5,0x9
00242e2c: dfb00000  ld	s0,0(sp)
00242e30: 01ee7824  and	t7,t7,t6
00242e34: dfbf0008  ld	ra,8(sp)
00242e38: 01ed7825  or	t7,t7,t5
00242e3c: ac4f0004  sw	t7,4(v0)
00242e40: 03e00008  jr	ra
00242e44: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00242df0(void)`

```c
void FUN_00242df0(long param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_001058e8();
  iVar2 = 0;
  if ((param_1 != 0) && (iVar2 = 2, param_1 != 2)) {
    iVar2 = 1;
  }
  *(uint *)(iVar1 + 0x41a4) = *(uint *)(iVar1 + 0x41a4) & 0xfffff9ff | iVar2 << 9;
  return;
}
```

## Earlier attempts (newest first)

- 17 differing words, 84/88 bytes: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_09_0.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_call_fixed_return_variants_v2_09_0.cpp`)
