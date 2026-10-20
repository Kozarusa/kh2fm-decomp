# Target packet 001b9bc8

- Range: `001b9bc8`..`001b9c24`, **92 bytes = 23 instructions**. This size is the acceptance size.
- Layout name: `FUN_001b9bc8`
- Registry names for this address: `_Z16ctarget_001b9bc8jjjj`
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- `0019baa8` registry: `_ZN2YS3OBJ8is_leaveEv`
  - accepted sources that already call it (copy their declaration): `fm_primary_clearsequence_recovered_001d7940.cpp`, `fm_primary_fiveword_recovered_001c9080.cpp`, `fm_primary_oneword_recovered_001c8710.cpp`, `fm_primary_oneword_recovered_001c8750.cpp`, `fm_primary_queuegamma_recovered_001c9df8.cpp`

## Original instructions (absolute addresses decoded; low halves are signed)

```
001b9bc8: 27bdffe0  addiu	sp,sp,-32
001b9bcc: ffb10008  sd	s1,8(sp)
001b9bd0: ffb20010  sd	s2,16(sp)
001b9bd4: ffb00000  sd	s0,0(sp)
001b9bd8: 0080882d  move	s1,a0
001b9bdc: ffbf0018  sd	ra,24(sp)
001b9be0: 3c1201d5  lui	s2,0x1d5
001b9be4: 56200002  bnezl	s1,0x1b9bf0
001b9be8: 8e3008b4  lw	s0,2228(s1)
001b9bec: 8e508da0  lw	s0,-29280(s2)   ; = D_01d48da0
001b9bf0: 12000005  beqz	s0,0x1b9c08
001b9bf4: 0200882d  move	s1,s0
001b9bf8: 0c066eaa  jal	0x19baa8
001b9bfc: 0200202d  move	a0,s0
001b9c00: 1440fff8  bnez	v0,0x1b9be4
001b9c04: 00000000  nop
001b9c08: 0200102d  move	v0,s0
001b9c0c: dfb10008  ld	s1,8(sp)
001b9c10: dfb00000  ld	s0,0(sp)
001b9c14: dfb20010  ld	s2,16(sp)
001b9c18: dfbf0018  ld	ra,24(sp)
001b9c1c: 03e00008  jr	ra
001b9c20: 27bd0020  addiu	sp,sp,32
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001b9bc8(void)`

```c
int FUN_001b9bc8(int param_1)

{
  int iVar1;
  long lVar2;
  
  do {
    iVar1 = DAT_01d48da0;
    if (param_1 != 0) {
      iVar1 = *(int *)(param_1 + 0x8b4);
    }
  } while ((iVar1 != 0) && (lVar2 = FUN_0019baa8(iVar1), param_1 = iVar1, lVar2 != 0));
  return iVar1;
}
```

## Earlier attempts (newest first)

- none found
