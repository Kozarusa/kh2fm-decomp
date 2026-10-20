#include "../common/types.h"

// Provisional scalar proposals translated from the saved Ghidra export.
// Compiler byte equality, registration and full-build provenance are separate gates.
extern "C" u32 func_00319a60(...);
extern "C" u32 func_00319d20(...);
extern "C" u32 func_00319d58(...);
extern "C" u32 func_00321198(...);

u32 func_0031a9d8(u32 param_1,int param_2)

{
  int iVar1;
  u32 uVar2;
  u32 uVar3;
  u32 uVar4;
  u32 uVar5;
  u32 uVar6;
  u32 uVar7;
  u32 uVar8;
  
  iVar1 = (int)param_1;
  uVar3 = *(u32 *)(param_2 + 8);
  uVar2 = *(u32 *)(param_2 + 0xc);
  *(u32 *)(iVar1 + 4) = *(u32 *)(param_2 + 4);
  *(u32 *)(iVar1 + 8) = uVar3;
  *(u32 *)(iVar1 + 0xc) = uVar2;
  *(u32 *)(iVar1 + 0x10) = *(u32 *)(param_2 + 0x10);
  *(u32 *)(iVar1 + 0x14) = *(u32 *)(param_2 + 0x14);
  *(u32 *)(iVar1 + 0x18) = *(u32 *)(param_2 + 0x18);
  *(u32 *)(iVar1 + 0x1c) = *(u32 *)(param_2 + 0x1c);
  *(u32 *)(iVar1 + 0x20) = *(u32 *)(param_2 + 0x20);
  *(u32 *)(iVar1 + 0x24) = *(u32 *)(param_2 + 0x24);
  *(u32 *)(iVar1 + 0x28) = *(u32 *)(param_2 + 0x28);
  *(u32 *)(iVar1 + 0x2c) = *(u32 *)(param_2 + 0x2c);
  *(u32 *)(iVar1 + 0x30) = *(u32 *)(param_2 + 0x30);
  uVar3 = *(u32 *)(param_2 + 0x38);
  uVar2 = *(u32 *)(param_2 + 0x3c);
  uVar4 = *(u32 *)(param_2 + 0x40);
  *(u32 *)(iVar1 + 0x34) = *(u32 *)(param_2 + 0x34);
  *(u32 *)(iVar1 + 0x38) = uVar3;
  *(u32 *)(iVar1 + 0x3c) = uVar2;
  *(u32 *)(iVar1 + 0x40) = uVar4;
  *(u32 *)(iVar1 + 0x44) = *(u32 *)(param_2 + 0x44);
  uVar3 = *(u32 *)(param_2 + 0x4c);
  *(u32 *)(iVar1 + 0x48) = *(u32 *)(param_2 + 0x48);
  *(u32 *)(iVar1 + 0x4c) = uVar3;
  *(u32 *)(iVar1 + 0x50) = *(u32 *)(param_2 + 0x50);
  *(u32 *)(iVar1 + 0x54) = *(u32 *)(param_2 + 0x54);
  *(u32 *)(iVar1 + 0x58) = *(u32 *)(param_2 + 0x58);
  *(u32 *)(iVar1 + 0x5c) = *(u32 *)(param_2 + 0x5c);
  *(u32 *)(iVar1 + 0x60) = *(u32 *)(param_2 + 0x60);
  *(u32 *)(iVar1 + 100) = *(u32 *)(param_2 + 100);
  uVar3 = *(u32 *)(param_2 + 0x6c);
  uVar2 = *(u32 *)(param_2 + 0x70);
  uVar5 = *(u32 *)(param_2 + 0x74);
  uVar4 = *(u32 *)(param_2 + 0x78);
  uVar7 = *(u32 *)(param_2 + 0x7c);
  uVar6 = *(u32 *)(param_2 + 0x80);
  uVar8 = *(u32 *)(param_2 + 0x84);
  *(u32 *)(iVar1 + 0x68) = *(u32 *)(param_2 + 0x68);
  *(u32 *)(iVar1 + 0x6c) = uVar3;
  uVar3 = *(u32 *)(param_2 + 0x88);
  *(u32 *)(iVar1 + 0x70) = uVar2;
  *(u32 *)(iVar1 + 0x74) = uVar5;
  *(u32 *)(iVar1 + 0x78) = uVar4;
  *(u32 *)(iVar1 + 0x7c) = uVar7;
  *(u32 *)(iVar1 + 0x80) = uVar6;
  *(u32 *)(iVar1 + 0x84) = uVar8;
  *(u32 *)(iVar1 + 0x88) = uVar3;
  uVar3 = *(u32 *)(param_2 + 0xa8);
  *(u32 *)(iVar1 + 0xa0) = *(u32 *)(param_2 + 0xa0);
  *(u32 *)(iVar1 + 0xa8) = uVar3;
  uVar3 = *(u32 *)(param_2 + 0xac);
  uVar2 = *(u32 *)(param_2 + 0x90);
  uVar4 = *(u32 *)(param_2 + 0x94);
  uVar5 = *(u32 *)(param_2 + 0x98);
  uVar6 = *(u32 *)(param_2 + 0x9c);
  uVar7 = *(u32 *)(param_2 + 0xa4);
  *(u32 *)(iVar1 + 0x8c) = *(u32 *)(param_2 + 0x8c);
  *(u32 *)(iVar1 + 0x90) = uVar2;
  *(u32 *)(iVar1 + 0x94) = uVar4;
  *(u32 *)(iVar1 + 0x98) = uVar5;
  *(u32 *)(iVar1 + 0x9c) = uVar6;
  *(u32 *)(iVar1 + 0xa4) = uVar7;
  *(u32 *)(iVar1 + 0xac) = uVar3;
  return param_1;
}

void func_00321068(int param_1)

{
  u32 *puVar1;
  int iVar2;
  
  puVar1 = (u32 *)(param_1 + 0xc);
  iVar2 = 0x13;
  do {
    *puVar1 = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 1;
  } while (-1 < iVar2);
  puVar1 = (u32 *)(param_1 + 0x5c);
  iVar2 = 2;
  do {
    *puVar1 = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 1;
  } while (-1 < iVar2);
  puVar1 = (u32 *)(param_1 + 0x68);
  iVar2 = 0x11;
  do {
    *puVar1 = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 1;
  } while (-1 < iVar2);
  puVar1 = (u32 *)(param_1 + 0xb0);
  iVar2 = 8;
  do {
    *puVar1 = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 1;
  } while (-1 < iVar2);
  *(u32 *)(param_1 + 0xd8) = 0;
  puVar1 = (u32 *)(param_1 + 0x844);
  *(u32 *)(param_1 + 0xd4) = 0;
  iVar2 = 3;
  *(u32 *)(param_1 + 0x83c) = 0;
  *(u32 *)(param_1 + 0x840) = 0;
  do {
    *puVar1 = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 1;
  } while (-1 < iVar2);
  *(u8 *)(param_1 + 0x854) = 0;
  func_00319d20(param_1 + 0x858);
  func_00319d20(param_1 + 0x860);
  func_00321198(param_1 + 0x868);
  func_00321198(param_1 + 0x874);
  func_00321198(param_1 + 0x880);
  func_00319d20(param_1 + 0x88c);
  func_00319d58(param_1 + 0xa99);
  func_00319a60(param_1 + 0xa9c);
  return;
}
