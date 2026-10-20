#include "../common/types.h"

// Provisional scalar proposals translated from the saved Ghidra export.
// Compiler byte equality, registration and full-build provenance are separate gates.
extern "C" u64 func_001050d8(...);
extern "C" u64 func_00143fc8(...);
extern "C" u64 func_0014f688(...);
extern "C" u64 func_00168b38(...);
extern "C" u64 func_0016ed50(...);
extern "C" u64 func_00176cd0(...);
extern "C" u64 func_00178280(...);
extern "C" u64 func_00181500(...);
extern "C" u64 func_00190920(...);
extern "C" u64 func_00198450(...);
extern "C" u64 func_00198970(...);
extern "C" u64 func_0019aa00(...);
extern "C" u64 func_0019cc20(...);
extern "C" u64 func_001a3188(...);
extern "C" u64 func_001a3570(...);
extern "C" u64 func_001a35f8(...);
extern "C" u64 func_001a6d08(...);
extern "C" u64 func_001ada38(...);
extern "C" u64 func_001b40e0(...);
extern "C" u64 func_001b8958(...);
extern "C" u64 func_001ba158(...);
extern "C" u64 func_001bb4a0(...);
extern "C" u64 func_001bb4b0(...);
extern "C" u64 func_001bbcb0(...);
extern "C" u64 func_001c1748(...);
extern "C" u64 func_001d16f8(...);
extern "C" u64 func_001d1950(...);
extern "C" u64 func_001d2110(...);
extern "C" u64 func_001d2248(...);
extern "C" u64 func_001d2710(...);
extern "C" u64 func_001d3350(...);
extern "C" u64 func_001d3388(...);
extern "C" u64 func_001d4f40(...);
extern "C" u64 func_001d5f30(...);
extern "C" u64 func_001d6cc8(...);
extern "C" u64 func_001d7b10(...);
extern "C" u64 func_001d8718(...);
extern "C" u64 func_001da3d8(...);
extern "C" u64 func_001db200(...);
extern "C" u64 func_001db250(...);
extern "C" u64 func_001db950(...);
extern "C" u64 func_001dba18(...);
extern "C" u64 func_001dc700(...);
extern "C" u64 func_001dc738(...);
extern "C" u64 func_001dc840(...);
extern "C" u64 func_001dc978(...);
extern "C" u64 func_001dc9e0(...);
extern "C" u64 func_001dca20(...);
extern "C" u64 func_001dde40(...);
extern "C" u64 func_001ddef0(...);
extern "C" u64 func_001e0058(...);
extern "C" u64 func_001e0158(...);
extern "C" u64 func_001e01b8(...);
extern "C" u64 func_001e03b0(...);
extern "C" u64 func_001e0cc8(...);
extern "C" u64 func_001e0ce8(...);
extern "C" u64 func_001e1728(...);
extern "C" u64 func_001e17b8(...);
extern "C" u64 func_001e1988(...);
extern "C" u64 func_001e2c00(...);
extern "C" u64 func_001e2c78(...);
extern "C" u64 func_001e3468(...);
extern "C" u64 func_001e3650(...);
extern "C" u64 func_001e3660(...);
extern "C" u64 func_001e38f8(...);
extern "C" u64 func_001e3a88(...);
extern "C" u64 func_001e3c98(...);
extern "C" u64 func_001e3e48(...);
extern "C" u64 func_001e4028(...);
extern "C" u64 func_001e4248(...);
extern "C" u64 func_001e4320(...);
extern "C" u64 func_001e4e18(...);
extern "C" u64 func_001e6000(...);
extern "C" u64 func_001e6c00(...);
extern "C" u64 func_001e6cd8(...);
extern "C" u64 func_001e6ce8(...);
extern "C" u64 func_001e6cf8(...);
extern "C" u64 func_001e6d08(...);
extern "C" u64 func_001e7070(...);
extern "C" u64 func_001e7088(...);
extern "C" u64 func_001fa950(...);
extern "C" u64 func_001fab48(...);
extern "C" u64 func_001facf8(...);
extern "C" u64 func_00209178(...);
extern "C" u64 func_0020e2e8(...);
extern "C" u64 func_0021fa10(...);
extern "C" u64 func_0021fbc0(...);
extern "C" u64 func_0021fe28(...);
extern "C" u64 func_00220070(...);
extern "C" u64 func_002223e0(...);
extern "C" u64 func_002bea60(...);
extern "C" u64 func_002f3f88(...);
extern "C" u64 func_002fd348(...);
extern "C" u64 func_002fe0a0(...);
extern "C" u64 func_00321728(...);
extern "C" u64 func_00321cb0(...);
extern "C" u64 func_00321ce8(...);

void func_001d0200(u64 param_1)

{
  func_00198970();
  func_00178280(param_1);
  return;
}

void func_001d07e0(int param_1)

{
  func_001d2710(param_1 + 0xb74);
  func_0019cc20(*(u32 *)(param_1 + 0xb40));
  *(u32 *)(param_1 + 0x10c) = *(u32 *)(param_1 + 0x10c) | 0x200000;
  return;
}

int func_001d3498(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_1 + 8;
  if ((param_2 != 0) && (iVar1 = 0, param_2 != param_1 + *(int *)(param_1 + 4) * 0x60 + -0x58)) {
    iVar1 = param_2 + 0x60;
  }
  return iVar1;
}

void func_001d6148(int param_1,int param_2)

{
  if (*(int *)(param_1 + 0xb50) != 3) {
    return;
  }
  if (param_2 != 700) {
    if (param_2 < 0x2bd) {
      if (param_2 != 0x2ae) {
        return;
      }
    }
    else if ((param_2 != 0x2bf) && (param_2 != 0x2c2)) {
      return;
    }
  }
  func_001d5f30(param_1,1);
  return;
}

void func_001d71f0(s64 param_1)

{
  if (param_1 == 0xc) {
    func_002bea60();
    return;
  }
  return;
}

int func_001db888(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8) + -1;
  *(int *)(param_1 + 8) = iVar1;
  return *(int *)(param_1 + 0xc) +
         *(int *)(param_1 + 0x14) * *(int *)(iVar1 * 4 + *(int *)(param_1 + 0x10));
}

void func_001dc620(int param_1)

{
  func_001dc9e0();
  func_001e6cd8(*(u32 *)(param_1 + 0x1c));
  return;
}

void func_001dc648(int param_1)

{
  func_001dc9e0();
  func_001e6ce8(*(u32 *)(param_1 + 0x1c));
  return;
}

void func_001dc670(int param_1)

{
  func_001dc9e0();
  func_001e6cf8(*(u32 *)(param_1 + 0x1c));
  return;
}

void func_001dc878(int param_1)

{
  *(u32 *)(param_1 + 8) = *(u32 *)(param_1 + 8) | 0x10000;
  if (*(int *)(param_1 + 0x1c) != 0) {
    func_001e2c00(*(int *)(param_1 + 0x1c));
    func_001e6c00(*(u32 *)(param_1 + 0x1c));
    *(u32 *)(param_1 + 0x1c) = 0;
  }
  return;
}

void func_001dc920(int param_1)

{
  *(u32 *)(param_1 + 8) = *(u32 *)(param_1 + 8) | 0x10001;
  if (*(int *)(param_1 + 0x1c) != 0) {
    func_001e2c00(*(int *)(param_1 + 0x1c));
    func_001e6c00(*(u32 *)(param_1 + 0x1c));
    *(u32 *)(param_1 + 0x1c) = 0;
  }
  return;
}

void func_001e2238(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0xdcc)) {
    iVar1 = 0;
    do {
      iVar2 = iVar2 + 1;
      func_001e1728(*(int *)(param_1 + 0xdc8) + iVar1);
      iVar1 = iVar1 + 0x30;
    } while (iVar2 < *(int *)(param_1 + 0xdcc));
  }
  return;
}

void func_001e4f00(void)

{
  u64 uVar1;
  
  uVar1 = func_001e3650();
  uVar1 = func_001e3660(uVar1,1);
  uVar1 = func_001e4248(uVar1);
  uVar1 = func_001e4e18(uVar1);
  func_001e4320(uVar1);
  return;
}
