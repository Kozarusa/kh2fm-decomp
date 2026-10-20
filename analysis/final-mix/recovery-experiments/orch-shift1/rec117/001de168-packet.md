# Target packet 001de168

- Range: `001de168`..`001de1c0`, **88 bytes = 22 instructions**. This size is the acceptance size.
- Layout name: `FUN_001de168`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `001ddef0` registry: none
  - accepted sources that already call it (copy their declaration): `fm_primary_fiveword_recovered_001e0958.cpp`, `fm_scalar_extra_recovered_05.cpp`, `fm_scalar_extra_recovered_12.cpp`, `fm_scalar_recovered_05.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001de168: 27bdfff0  addiu	sp,sp,-16
001de16c: 8c8f0000  lw	t7,0(a0)
001de170: ffbf0000  sd	ra,0(sp)
001de174: 00a0602d  move	t4,a1
001de178: 0000702d  move	t6,zero
001de17c: 8ded0008  lw	t5,8(t7)
001de180: 19a00007  blez	t5,0x1de1a0
001de184: 0000102d  move	v0,zero
001de188: 8c850004  lw	a1,4(a0)
001de18c: 94af0002  lhu	t7,2(a1)
001de190: 15ec0006  bne	t7,t4,0x1de1ac
001de194: 25ce0001  addiu	t6,t6,1
001de198: 0c0777bc  jal	0x1ddef0
001de19c: 00000000  nop
001de1a0: dfbf0000  ld	ra,0(sp)
001de1a4: 03e00008  jr	ra
001de1a8: 27bd0010  addiu	sp,sp,16
001de1ac: 01cd782a  slt	t7,t6,t5
001de1b0: 15e0fff6  bnez	t7,0x1de18c
001de1b4: 24a50050  addiu	a1,a1,80
001de1b8: 1000fffa  b	0x1de1a4
001de1bc: dfbf0000  ld	ra,0(sp)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001de168(void)`

```c
undefined8 FUN_001de168(int *param_1,ulong param_2)

{
  undefined8 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < *(int *)(*param_1 + 8)) {
    iVar2 = param_1[1];
    do {
      iVar3 = iVar3 + 1;
      if (*(ushort *)(iVar2 + 2) == param_2) {
        uVar1 = FUN_001ddef0();
        return uVar1;
      }
      iVar2 = iVar2 + 0x50;
    } while (iVar3 < *(int *)(*param_1 + 8));
  }
  return 0;
}
```

## Earlier attempts (newest first)

- 21 differing words, 88/88 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_05.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_05.cpp`)
