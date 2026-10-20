# Target packet 001c3aa0

- Range: `001c3aa0`..`001c3b20`, **128 bytes = 32 instructions**. This size is the acceptance size.
- Layout name: `FUN_001c3aa0`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0016bd60` registry: `_ZN2YS3OBJ13change_actionENS_6ACTION2IDE`
  - accepted sources that already call it (copy their declaration): `fm_primary_animation_recovered.cpp`, `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_0017a8f8.cpp`, `fm_primary_fiveword_recovered_001b2780.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`
- `0017f540` registry: `_ZN2YS6MOTION6changeEiff`
  - accepted sources that already call it (copy their declaration): `fm_primary_orchbd_recovered_0017c108.cpp`, `fm_primary_queuexiprime_recovered_00176818.cpp`
- `001c39d0` registry: none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001c3aa0: 27bdffe0  addiu	sp,sp,-32
001c3aa4: 44800000  mtc1	zero,$f0
001c3aa8: ffb00000  sd	s0,0(sp)
001c3aac: 24af0140  addiu	t7,a1,320
001c3ab0: ffb10008  sd	s1,8(sp)
001c3ab4: 46000346  mov.s	$f13,$f0
001c3ab8: ffbf0010  sd	ra,16(sp)
001c3abc: 00a0802d  move	s0,a1
001c3ac0: 0080882d  move	s1,a0
001c3ac4: c4a1001c  lwc1	$f1,28(a1)
001c3ac8: 01e0202d  move	a0,t7
001c3acc: 46010034  c.lt.s	$f0,$f1
001c3ad0: 45000008  bc1f	0x1c3af4
001c3ad4: 240500d0  li	a1,208
001c3ad8: 0200202d  move	a0,s0
001c3adc: dfb10008  ld	s1,8(sp)
001c3ae0: dfb00000  ld	s0,0(sp)
001c3ae4: 24050012  li	a1,18
001c3ae8: dfbf0010  ld	ra,16(sp)
001c3aec: 0805af58  j	0x16bd60
001c3af0: 27bd0020  addiu	sp,sp,32
001c3af4: 3c0f0037  lui	t7,0x37
001c3af8: 25efde10  addiu	t7,t7,-8688   ; = D_0036de10
001c3afc: 0c05fd50  jal	0x17f540
001c3b00: c5ec0000  lwc1	$f12,0(t7)
001c3b04: 0220202d  move	a0,s1
001c3b08: dfbf0010  ld	ra,16(sp)
001c3b0c: 0200282d  move	a1,s0
001c3b10: dfb10008  ld	s1,8(sp)
001c3b14: dfb00000  ld	s0,0(sp)
001c3b18: 08070e74  j	0x1c39d0
001c3b1c: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001c3aa0(void)`

```c
void FUN_001c3aa0(undefined4 param_1,undefined8 param_2,undefined8 param_3)

{
  if (*(float *)((int)param_3 + 0x1c) <= 0.0) {
    FUN_0017f540(DAT_0036de10,(int)param_3 + 0x140,0xd0);
    FUN_001c39d0(param_2,param_3);
    return;
  }
  FUN_0016bd60(param_1,0,param_3,0x12);
  return;
}
```

## Earlier attempts (newest first)

- none found
