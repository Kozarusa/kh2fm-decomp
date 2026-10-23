#include "../common/types.h"

// Preserve original registry aliases.
bool func_001c9d88(void) asm("_ZN2YS9SACRIFICE6CanEndEv");

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_00181500(...);
extern "C" bool func_001a6d08(...);
extern "C" bool func_001b8958(...);
extern "C" bool func_001bb4a0(...);
extern "C" bool func_001bb4b0(...);
extern "C" bool func_001c5f38(...);
extern "C" bool func_001ca448(...);
extern "C" bool func_001db200(...);
extern "C" bool func_001dc9e0(...);
extern "C" bool func_001e6c40(...);
extern "C" bool func_001e6d08(...);
extern "C" s32 func_00189200(...);
extern "C" s32 func_001a35f8(...);
extern "C" s32 func_001db888(...);
extern "C" s32 func_0017e668(...);
extern "C" s32 func_001db9a8(...);
extern "C" s32 func_001e6b90(...);
extern "C" u16 func_001a8b68(...);
extern "C" u16 func_001d01e0(...);
extern "C" u32 func_001050d8(...);
extern "C" u32 func_00105868(...);
extern "C" u32 func_0014c9d8(...);
extern "C" u32 func_0014c9f0(...);
extern "C" u32 func_0014f688(...);
extern "C" u32 func_00168b38(...);
extern "C" u32 func_0016bd60(...);
extern "C" u32 func_0016c5b8(...);
extern "C" u32 func_0016c640(...);
extern "C" u32 func_0016ed50(...);
extern "C" u32 func_00170320(...);
extern "C" u32 func_00176cd0(...);
extern "C" u32 func_001780d8(...);
extern "C" u32 func_0017c4c8(...);
extern "C" u32 func_0017df58(...);
extern "C" u32 func_0017f488(...);
extern "C" u32 func_0017f5e0(...);
extern "C" u32 func_00190920(...);
extern "C" u32 func_00198450(...);
extern "C" u32 func_001987a8(...);
extern "C" u32 func_00198860(...);
extern "C" u32 func_0019baa8(...);
extern "C" u32 func_001a3188(...);
extern "C" u32 func_001a4ff8(...);
extern "C" u32 func_001a6c90(...);
extern "C" u32 func_001ada38(...);
extern "C" u32 func_001ba158(...);
extern "C" u32 func_001bbcb0(...);
extern "C" u32 func_001bbe38(...);
extern "C" u32 func_001bbe78(...);
extern "C" u32 func_001bdab0(...);
extern "C" u32 func_001c1748(...);
extern "C" u32 func_001c1890(...);
extern "C" u32 func_001c6748(...);
extern "C" u32 func_001c6760(...);
extern "C" u32 func_001c8d80(...);
extern "C" u32 func_001c8d98(...);
extern "C" u32 func_001c99b0(...);
extern "C" u32 func_001c9ab8(...);
extern "C" u32 func_001ca988(...);
extern "C" u32 func_001ce3e8(...);
extern "C" u32 func_001d16f8(...);
extern "C" u32 func_001d1950(...);
extern "C" u32 func_001d2110(...);
extern "C" u32 func_001d2248(...);
extern "C" u32 func_001d3350(...);
extern "C" u32 func_001d3388(...);
extern "C" u32 func_001d4f40(...);
extern "C" u32 func_001d6cc8(...);
extern "C" u32 func_001d7b10(...);
extern "C" u32 func_001d8718(...);
extern "C" u32 func_001d87b8(...);
extern "C" u32 func_001d8c70(...);
extern "C" u32 func_001da3d8(...);
extern "C" u32 func_001db250(...);
extern "C" u32 func_001db8b8(...);
extern "C" u32 func_001dbd68(...);
extern "C" u32 func_001dc738(...);
extern "C" u32 func_001dca30(...);
extern "C" u32 func_001e2c00(...);
extern "C" u32 func_001e6c00(...);
extern "C" u32 func_001e7070(...);
extern "C" u32 func_001e7088(...);
extern "C" u32 func_00276fd0(...);
extern "C" u32 func_00321728(...);
extern "C" u32 func_001bd3e0(...);
extern "C" u8 func_001a3570(...);
extern "C" u8 func_001e2c78(...);

void func_001bd4e8(u32 param_1,u32 *param_2,u32 param_3)

{
  int iVar1;
  int iVar2;
  
  if ((*(u32 *)(*(int *)((int)param_1 + 0x9e0) + 0x588) & 0x2000000) == 0) {
    iVar2 = 0;
    func_001bdab0();
    do {
      iVar1 = iVar2 + 3;
      iVar2 = iVar2 + 1;
      func_001bd3e0(param_1,iVar1,*param_2,param_3,1,100);
      param_2 = param_2 + 1;
    } while (iVar2 < 4);
  }
  return;
}

bool func_001c9d88(void)

{
  u32 uVar1;
  s32 lVar2;
  
  uVar1 = func_001a8b68();
  lVar2 = func_0017e668(uVar1);
  return lVar2 == 0;
}

void func_001d18c0(u32 param_1)

{
  int iVar1;
  
  func_001d16f8();
  iVar1 = (int)param_1;
  if (*(int *)(iVar1 + 4) != 0) {
    func_0014f688(*(int *)(iVar1 + 4),*(u32 *)(iVar1 + 8),*(u32 *)(iVar1 + 0x20),
                 *(u32 *)(iVar1 + 0x24),*(u32 *)(iVar1 + 0x1c));
  }
  func_001d1950(param_1,*(u32 *)(iVar1 + 0x14));
  return;
}

void func_001d6da8(u16 *param_1)

{
  s32 lVar1;
  s32 lVar2;
  
  lVar2 = 0;
  while (lVar2 = func_001d6cc8(lVar2), lVar2 != 0) {
    lVar1 = func_001a3570(((u16 *)lVar2)[1]);
    if (0 < lVar1) {
      *param_1 = *(u16 *)lVar2;
      param_1 = param_1 + 1;
    }
  }
  *param_1 = 0;
  return;
}

void func_001d7e00(u32 param_1)

{
  func_00190920((int)param_1 + 0x9f4,2,param_1);
  func_00198450(param_1);
  return;
}
