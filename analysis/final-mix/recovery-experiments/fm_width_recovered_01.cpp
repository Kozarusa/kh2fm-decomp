#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_001a1de0(...);
extern "C" f32 func_00166d10(...);
extern "C" s32 func_00132130(...);
extern "C" s32 func_0013d7e0(...);
extern "C" s32 func_0014e648(...);
extern "C" s32 func_0016c028(...);
extern "C" u32 func_001024a8(...);
extern "C" u32 func_00102818(...);
extern "C" u32 func_00102c18(...);
extern "C" u32 func_00102c80(...);
extern "C" u32 func_001050c8(...);
extern "C" u32 func_001058e8(...);
extern "C" u32 func_0011c4b0(...);
extern "C" u32 func_0011c4e8(...);
extern "C" u32 func_001320b0(...);
extern "C" u32 func_00132208(...);
extern "C" u32 func_00138c10(...);
extern "C" u32 func_00138d60(...);
extern "C" u32 func_001391c8(...);
extern "C" u32 func_0013a4c8(...);
extern "C" u32 func_0013a600(...);
extern "C" u32 func_0013a6d0(...);
extern "C" u32 func_0013a7d0(...);
extern "C" u32 func_0013a7e8(...);
extern "C" u32 func_0013a9e8(...);
extern "C" u32 func_0013efe8(...);
extern "C" u32 func_0013f030(...);
extern "C" u32 func_0013f608(...);
extern "C" u32 func_0013f888(...);
extern "C" u32 func_0013fca8(...);
extern "C" u32 func_00142940(...);
extern "C" u32 func_00144450(...);
extern "C" u32 func_00144908(...);
extern "C" u32 func_001492c8(...);
extern "C" u32 func_001493b8(...);
extern "C" u32 func_00149428(...);
extern "C" u32 func_00149448(...);
extern "C" u32 func_00149bd0(...);
extern "C" u32 func_00149de0(...);
extern "C" u32 func_0014a9a0(...);
extern "C" u32 func_0014aa80(...);
extern "C" u32 func_0014aba8(...);
extern "C" u32 func_0014ae10(...);
extern "C" u32 func_0014b5e8(...);
extern "C" u32 func_0014dd60(...);
extern "C" u32 func_0014f148(...);
extern "C" u32 func_0014f1e0(...);
extern "C" u32 func_0014f220(...);
extern "C" u32 func_0014f288(...);
extern "C" u32 func_00150be8(...);
extern "C" u32 func_00151d48(...);
extern "C" u32 func_00153c80(...);
extern "C" u32 func_00154408(...);
extern "C" u32 func_00154cd0(...);
extern "C" u32 func_00155d58(...);
extern "C" u32 func_00155f40(...);
extern "C" u32 func_00156408(...);
extern "C" u32 func_001574a0(...);
extern "C" u32 func_00159ce0(...);
extern "C" u32 func_0015a850(...);
extern "C" u32 func_0015eba8(...);
extern "C" u32 func_0015edb8(...);
extern "C" u32 func_001616d8(...);
extern "C" u32 func_00165968(...);
extern "C" u32 func_00166618(...);
extern "C" u32 func_001666a0(...);
extern "C" u32 func_001666d0(...);
extern "C" u32 func_001666f0(...);
extern "C" u32 func_00166d38(...);
extern "C" u32 func_00167658(...);
extern "C" u32 func_001676b0(...);
extern "C" u32 func_001678f0(...);
extern "C" u32 func_00167e00(...);
extern "C" u32 func_00168b38(...);
extern "C" u32 func_0016b0d0(...);
extern "C" u32 func_0016cbc8(...);
extern "C" u32 func_0016cce8(...);
extern "C" u32 func_0017df58(...);
extern "C" u32 func_001a98e8(...);
extern "C" u32 func_001a9ae8(...);
extern "C" u32 func_001b7e68(...);
extern "C" u32 func_001b7f30(...);
extern "C" u32 func_001b80d8(...);
extern "C" u32 func_001dc5f8(...);
extern "C" u32 func_002362b0(...);
extern "C" u32 func_00239988(...);
extern "C" u32 func_00239bf8(...);
extern "C" u32 func_0023aa78(...);
extern "C" u32 func_00242b58(...);
extern "C" u32 func_002bea00(...);
extern "C" u32 func_002fee78(...);
extern "C" u32 func_00102788(...);
extern "C" u32 func_0014ca80(...);
extern "C" u32 func_0015c228(...);
extern "C" u32 func_00167cd0(...);
extern "C" u32 func_0016abf8(...);
extern "C" u32 func_0016d080(...);
extern "C" u32 func_00192cc0(...);

u32 func_00132180(u32 param_1,s32 param_2)

{
  s32 lVar1;
  
  while ((lVar1 = func_00132208(param_1), lVar1 != 0 &&
         (lVar1 = func_001320b0(param_1), lVar1 != 0x354e4b5f))) {
    lVar1 = func_001320b0(param_1);
    if (lVar1 == param_2) {
      return param_1;
    }
    param_1 = func_00132130(param_1);
  }
  return 0;
}

void func_001514e8(u32 param_1)

{
  func_00138c10((int)param_1 + 0x1f0,3);
  func_00138c10((int)param_1 + 0x388,9);
  func_00150be8(param_1);
  return;
}

void func_001520c0(u32 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(int *)(iVar1 + 0xb4c) = *(int *)(iVar1 + 0xb4c) + param_2;
  func_00138c10(iVar1 + 0x30,0x11);
  func_00151d48(param_1);
  return;
}

void func_00152508(u32 param_1,u32 param_2,u32 param_3,u32 param_4,
                 u32 param_5)

{
  u32 uVar1;
  u32 uVar2;
  int iVar3;
  
  uVar1 = func_0013a7e8(1);
  uVar2 = func_0013d7e0();
  func_00138d60(param_1,9000,uVar1,uVar2,param_2,param_4,0xe);
  iVar3 = (int)param_1;
  *(u32 *)(iVar3 + 0x174) = param_5;
  *(u32 *)(iVar3 + 0x1a8) = 0xe;
  func_0023aa78(iVar3 + 0x18);
  return;
}

void func_00157068(u32 param_1)

{
  u32 uVar1;
  
  uVar1 = func_00155f40();
  func_00138c10((int)param_1 + 0x2d80,uVar1);
  func_00156408(param_1);
  return;
}

void func_001614e8(u32 param_1,u32 param_2)

{
  int iVar1;
  
  iVar1 = (int)param_1;
  *(u32 *)(iVar1 + 0x44) = param_2;
  *(u32 *)(iVar1 + 0x40) = 0;
  *(u32 *)(iVar1 + 0x48) = 0;
  *(u32 *)(iVar1 + 0x4c) = 0;
  *(u32 *)(iVar1 + 0x50) = 0;
  func_00144450(iVar1 + 0x54);
  func_001616d8(param_1);
  return;
}
