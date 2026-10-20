# Target packet 00139ab0

- Range: `00139ab0`..`00139b24`, **116 bytes = 29 instructions**. This size is the acceptance size.
- Layout name: `FUN_00139ab0`
- Registry names for this address: none
- Queue: state `leased`, queue `boundary-review`, attempts 2, priority 2
- Earlier blocker: `{"report": "C:\\Users\\KoZa\\Documents\\AGENTS\\Codex\\analysis\\final-mix\\recovery-experiments\\orch-shift1\\cdx1-rec10\\00139ab0-BLOCKED.md", "sha256": "3eb33fa770b27de6ffb039edb846a3f40ec4479038b4bcb4ef964f5112f72bf7", "hypothesis": "Review the function boundary and authorize treatment of the backward branch after the internal epilogue."}`

## Callees

- `001396e0` registry: `func_001396e0`

## Original instructions (absolute addresses decoded; low halves are signed)

```
00139ab0: 27bdffe0  addiu	sp,sp,-32
00139ab4: ffb00000  sd	s0,0(sp)
00139ab8: ffb10008  sd	s1,8(sp)
00139abc: ffb20010  sd	s2,16(sp)
00139ac0: 0000802d  move	s0,zero
00139ac4: ffbf0018  sd	ra,24(sp)
00139ac8: 0080882d  move	s1,a0
00139acc: 3c120034  lui	s2,0x34
00139ad0: 16000012  bnez	s0,0x139b1c
00139ad4: 8e447f80  lw	a0,32640(s2)   ; = D_00347f80
00139ad8: 8c840004  lw	a0,4(a0)
00139adc: 14800008  bnez	a0,0x139b00
00139ae0: 0080802d  move	s0,a0
00139ae4: dfb00000  ld	s0,0(sp)
00139ae8: dfb10008  ld	s1,8(sp)
00139aec: dfb20010  ld	s2,16(sp)
00139af0: dfbf0018  ld	ra,24(sp)
00139af4: 03e00008  jr	ra
00139af8: 27bd0020  addiu	sp,sp,32
00139afc: 00000000  nop
00139b00: 8c8f0010  lw	t7,16(a0)
00139b04: 15f1fff2  bne	t7,s1,0x139ad0
00139b08: 00000000  nop
00139b0c: 0c04e5b8  jal	0x1396e0
00139b10: 00000000  nop
00139b14: 1000ffee  b	0x139ad0
00139b18: 00000000  nop
00139b1c: 1000ffef  b	0x139adc
00139b20: 8e040004  lw	a0,4(s0)
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_00139ab0(void)`

```c
void FUN_00139ab0(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  while( true ) {
    if (iVar1 == 0) {
      iVar1 = *(int *)(DAT_00347f80 + 4);
    }
    else {
      iVar1 = *(int *)(iVar1 + 4);
    }
    if (iVar1 == 0) break;
    if (*(int *)(iVar1 + 0x10) == param_1) {
      FUN_001396e0();
    }
  }
  return;
}
```

## Earlier attempts (newest first)

- report: `analysis/final-mix/recovery-experiments/orch-shift1/cdx1-rec10/00139ab0-BLOCKED.md`
- report: `analysis/final-mix/recovery-experiments/orch-shift1/cdx1-rec10/00139ab0-packet.md`
