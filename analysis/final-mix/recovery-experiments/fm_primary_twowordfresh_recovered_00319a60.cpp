#include "../common/types.h"

// Provisional scalar proposals translated from the saved Ghidra export.
// Compiler byte equality, registration and full-build provenance are separate gates.
extern "C" s64 func_00101698(...);
extern "C" int func_00192b30(...);
extern "C" int func_00192c90(...);
extern "C" u32 func_002fde18(...);
extern "C" u32 func_00303c18(...);
extern "C" u64 func_00303c48(...);
extern "C" u32 func_00303fc0(...);
extern "C" u32 func_00303ff8(...);
extern "C" u32 func_00316e20(...);
extern "C" u32 func_00316e88(...);
extern "C" u32 func_00316f38(...);
extern "C" u32 func_00316fc8(...);
extern "C" u32 func_00317140(...);
extern "C" u32 func_00317868(...);
extern "C" u64 func_0031a9d8(...);

void func_00319a60(u32 *param_1)

{
  int iVar1;
  u32 *puVar2;
  
  iVar1 = 0xf;
  puVar2 = param_1;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (-1 < iVar1);
  param_1[0x10] = 0;
  puVar2 = param_1 + 0x11;
  iVar1 = 0xf;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (iVar1 != -1);
  param_1[0x21] = 0;
  puVar2 = param_1 + 0x22;
  iVar1 = 2;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (-1 < iVar1);
  puVar2 = param_1 + 0x25;
  iVar1 = 5;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (-1 < iVar1);
  puVar2 = param_1 + 0x2b;
  iVar1 = 0xf;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (iVar1 != -1);
  puVar2 = param_1 + 0x3b;
  iVar1 = 0xf;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (-1 < iVar1);
  puVar2 = param_1 + 0x4b;
  iVar1 = 3;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2 = puVar2 + 1;
  } while (-1 < iVar1);
  param_1[0x4f] = 0;
  puVar2 = param_1 + 0x51;
  param_1[0x50] = 0;
  iVar1 = 9;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2[1] = 0;
    puVar2 = puVar2 + 2;
  } while (iVar1 != -1);
  puVar2 = param_1 + 0x65;
  iVar1 = 9;
  do {
    *puVar2 = 0;
    iVar1 = iVar1 + -1;
    puVar2[1] = 0;
    puVar2 = puVar2 + 2;
  } while (iVar1 != -1);
  *(u16 *)((int)param_1 + 0x1e6) = 0;
  asm volatile("" : : : "memory");
  *(u16 *)(param_1 + 0x79) = 0;
  return;
}
