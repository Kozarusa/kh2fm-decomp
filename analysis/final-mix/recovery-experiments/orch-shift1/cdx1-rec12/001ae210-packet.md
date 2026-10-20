# Target packet 001ae210

- Range: `001ae210`..`001ae270`, **96 bytes = 24 instructions**. This size is the acceptance size.
- Layout name: `FUN_001ae210`
- Registry names for this address: none
- Queue: state `leased`, queue `general`, attempts 1, priority 2

## Callees

- none

## Original instructions (absolute addresses decoded; low halves are signed)

```
001ae210: 808f0000  lb	t7,0(a0)
001ae214: 2402ffff  li	v0,-1
001ae218: 11e00011  beqz	t7,0x1ae260
001ae21c: 24840001  addiu	a0,a0,1
001ae220: 3c0c04c1  lui	t4,0x4c1
001ae224: 3c0d8000  lui	t5,0x8000
001ae228: 358c1db7  ori	t4,t4,0x1db7
001ae22c: 000f7e00  sll	t7,t7,0x18
001ae230: 240e0007  li	t6,7
001ae234: 004f1026  xor	v0,v0,t7
001ae238: 004d7824  and	t7,v0,t5
001ae23c: 11e0000a  beqz	t7,0x1ae268
001ae240: 00027840  sll	t7,v0,0x1
001ae244: 01ec1026  xor	v0,t7,t4
001ae248: 25ceffff  addiu	t6,t6,-1
001ae24c: 05c1fffb  bgez	t6,0x1ae23c
001ae250: 004d7824  and	t7,v0,t5
001ae254: 808f0000  lb	t7,0(a0)
001ae258: 15e0fff4  bnez	t7,0x1ae22c
001ae25c: 24840001  addiu	a0,a0,1
001ae260: 03e00008  jr	ra
001ae264: 00021027  nor	v0,zero,v0
001ae268: 1000fff7  b	0x1ae248
001ae26c: 00021040  sll	v0,v0,0x1
```

## Ghidra pseudocode (advisory only: signatures, widths and returns are often wrong)

Signature: `undefined FUN_001ae210(void)`

```c
uint FUN_001ae210(char *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0xffffffff;
  cVar1 = *param_1;
  while (cVar1 != '\0') {
    param_1 = param_1 + 1;
    iVar3 = 7;
    uVar2 = uVar2 ^ (int)cVar1 << 0x18;
    do {
      if ((uVar2 & 0x80000000) == 0) {
        uVar2 = uVar2 << 1;
      }
      else {
        uVar2 = uVar2 << 1 ^ 0x4c11db7;
      }
      iVar3 = iVar3 + -1;
    } while (-1 < iVar3);
    cVar1 = *param_1;
  }
  return ~uVar2;
}
```

## Earlier attempts (newest first)

- 14 differing words, 96/96 bytes: `analysis/final-mix/recovery-experiments/fm_scalar_04.verification.json` (source: `analysis/final-mix/recovery-experiments/fm_scalar_04.cpp`)
