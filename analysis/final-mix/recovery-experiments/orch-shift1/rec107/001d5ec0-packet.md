# Target packet 001d5ec0

- Range: `001d5ec0`..`001d5f2c`, **108 bytes = 27 instructions**. This size is the acceptance size.
- Layout name: `FUN_001d5ec0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001d5ec0: 240f000a  li	t7,10
001d5ec4: 00073840  sll	a3,a3,0x1
001d5ec8: 00cf3018  mult	a2,a2,t7
001d5ecc: 0000682d  move	t5,zero
001d5ed0: 3c0f0037  lui	t7,0x37
001d5ed4: 25efe5a0  addiu	t7,t7,-6752   ; = D_0036e5a0
001d5ed8: 25effff6  addiu	t7,t7,-10
001d5edc: 00cf3021  addu	a2,a2,t7
001d5ee0: 00c73021  addu	a2,a2,a3
001d5ee4: 94c20000  lhu	v0,0(a2)
001d5ee8: 18a0000e  blez	a1,0x1d5f24
001d5eec: 94ccfffe  lhu	t4,-2(a2)
001d5ef0: 304b7fff  andi	t3,v0,0x7fff
001d5ef4: 948e0000  lhu	t6,0(a0)
001d5ef8: 31cf7fff  andi	t7,t6,0x7fff
001d5efc: 55ec0006  bnel	t7,t4,0x1d5f18
001d5f00: 25ad0001  addiu	t5,t5,1
001d5f04: 240f8000  li	t7,-32768
001d5f08: 01cf7824  and	t7,t6,t7
001d5f0c: 01eb7825  or	t7,t7,t3
001d5f10: 03e00008  jr	ra
001d5f14: a48f0000  sh	t7,0(a0)
001d5f18: 01a5782a  slt	t7,t5,a1
001d5f1c: 15e0fff5  bnez	t7,0x1d5ef4
001d5f20: 24840002  addiu	a0,a0,2
001d5f24: 03e00008  jr	ra
001d5f28: 00000000  nop
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001d5ec0(void)`

```c
void FUN_001d5ec0(ushort *param_1,int param_2,int param_3,int param_4)

{
  ushort *puVar1;
  int iVar2;
  
  iVar2 = 0;
  puVar1 = (ushort *)(param_3 * 10 + 0x36e596 + param_4 * 2);
  if (0 < param_2) {
    do {
      if ((*param_1 & 0x7fff) == puVar1[-1]) {
        *param_1 = *param_1 & 0x8000 | *puVar1 & 0x7fff;
        return;
      }
      iVar2 = iVar2 + 1;
      param_1 = param_1 + 1;
    } while (iVar2 < param_2);
  }
  return;
}
```

## Earlier attempts (newest first)

- 24 differing words, 108/108 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_05.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_05.cpp`)
