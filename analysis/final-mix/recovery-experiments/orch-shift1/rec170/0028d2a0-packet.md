# Target packet 0028d2a0

- Range: `0028d2a0`..`0028d320`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_0028d2a0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `00138840` registry: `func_00138840(void*)`
  - accepted sources that already call it (copy their declaration): `fm_primary_orchaq_recovered_0015ac68.cpp`
- `00313b80` registry: `func_00313b80`
  - accepted sources that already call it (copy their declaration): `fm_global_recovered_02.cpp`, `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`
- `003142e0` registry: `func_003142e0`
  - accepted sources that already call it (copy their declaration): `fm_primary_capacity_recovered_00303c48.cpp`, `fm_primary_conditionfinish_recovered.cpp`, `fm_primary_fourword_recovered_0013f498.cpp`, `fm_primary_fourword_recovered_0013f4d8.cpp`, `fm_primary_fourwordfresh_recovered_00140ce8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
0028d2a0: 27bdfff0  addiu	sp,sp,-16
0028d2a4: ffb00000  sd	s0,0(sp)
0028d2a8: ffbf0008  sd	ra,8(sp)
0028d2ac: 8c8f000c  lw	t7,12(a0)
0028d2b0: 31ef0100  andi	t7,t7,0x100
0028d2b4: 15e00016  bnez	t7,0x28d310
0028d2b8: 0080802d  move	s0,a0
0028d2bc: 0c04e210  jal	0x138840
0028d2c0: 00000000  nop
0028d2c4: 0c0c4ee0  jal	0x313b80
0028d2c8: c60c01a0  lwc1	$f12,416(s0)
0028d2cc: 0040282d  move	a1,v0
0028d2d0: 0c0c50b8  jal	0x3142e0
0028d2d4: 0000202d  move	a0,zero
0028d2d8: 3c0f0037  lui	t7,0x37
0028d2dc: 25ef443c  addiu	t7,t7,17468   ; = D_0037443c
0028d2e0: 1c40000b  bgtz	v0,0x28d310
0028d2e4: c5e10000  lwc1	$f1,0(t7)
0028d2e8: c60201a0  lwc1	$f2,416(s0)
0028d2ec: 46011034  c.lt.s	$f2,$f1
0028d2f0: 45000007  bc1f	0x28d310
0028d2f4: 3c0f0035  lui	t7,0x35
0028d2f8: c5e09e10  lwc1	$f0,-25072(t7)   ; = D_00349e10
0028d2fc: 46001000  add.s	$f0,$f2,$f0
0028d300: 46000834  c.lt.s	$f1,$f0
0028d304: 45000002  bc1f	0x28d310
0028d308: e60001a0  swc1	$f0,416(s0)
0028d30c: e60101a0  swc1	$f1,416(s0)
0028d310: dfb00000  ld	s0,0(sp)
0028d314: dfbf0008  ld	ra,8(sp)
0028d318: 03e00008  jr	ra
0028d31c: 27bd0010  addiu	sp,sp,16
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_0028d2a0(void)`

```c
void FUN_0028d2a0(int param_1)

{
  bool bVar1;
  float fVar2;
  undefined8 uVar3;
  long lVar4;
  float fVar5;
  
  if ((*(uint *)(param_1 + 0xc) & 0x100) == 0) {
    FUN_00138840();
    uVar3 = FUN_00313b80(*(undefined4 *)(param_1 + 0x1a0));
    lVar4 = FUN_003142e0(0,uVar3);
    fVar2 = DAT_0037443c;
    if (((lVar4 < 1) && (*(float *)(param_1 + 0x1a0) < DAT_0037443c)) &&
       (fVar5 = *(float *)(param_1 + 0x1a0) + DAT_00349e10, bVar1 = DAT_0037443c < fVar5,
       *(float *)(param_1 + 0x1a0) = fVar5, bVar1)) {
      *(float *)(param_1 + 0x1a0) = fVar2;
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- none found
