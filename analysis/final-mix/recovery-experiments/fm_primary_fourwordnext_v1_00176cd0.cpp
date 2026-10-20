#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_0017e310(...);
extern "C" bool func_00186ce8(...);
extern "C" bool func_00186d18(...);
extern "C" bool func_001883d8(...);
extern "C" bool func_0019ba60(...);
extern "C" bool func_0019c400(...);
extern "C" bool func_001a90a8(...);
extern "C" bool func_001dc9e0(...);
extern "C" f32 func_0017ce10(...);
extern "C" s32 func_0016c028(...);
extern "C" s32 func_00177860(...);
extern "C" s32 func_00189068(...);
extern "C" s32 func_001a6a20(...);
extern "C" s32 func_001a8bd0(...);
extern "C" s32 func_001b7818(...);
extern "C" s32 func_001b9bc8(...);
extern "C" u16 func_0016a070(...);
extern "C" u32 func_00114580(...);
extern "C" u32 func_00153e28(...);
extern "C" u32 func_00158920(...);
extern "C" u32 func_00159130(...);
extern "C" u32 func_00168b38(...);
extern "C" u32 func_0016ae58(...);
extern "C" u32 func_0016bc20(...);
extern "C" u32 func_0016bd60(...);
extern "C" u32 func_0016c460(...);
extern "C" u32 func_0016ced0(...);
extern "C" u32 func_0016f7d0(...);
extern "C" u32 func_00176a90(...);
extern "C" u32 func_00177498(...);
extern "C" u32 func_0017c4c8(...);
extern "C" u32 func_0017ee68(...);
extern "C" u32 func_0017f268(...);
extern "C" u32 func_0017f380(...);
extern "C" u32 func_00180ce0(...);
extern "C" u32 func_00181a70(...);
extern "C" u32 func_00183768(...);
extern "C" u32 func_00184780(...);
extern "C" u32 func_00184a90(...);
extern "C" u32 func_00187ab8(...);
extern "C" u32 func_00187b30(...);
extern "C" u32 func_001880b0(...);
extern "C" u32 func_00188398(...);
extern "C" u32 func_00188470(...);
extern "C" u32 func_0018a818(...);
extern "C" u32 func_0018c480(...);
extern "C" u32 func_0018c490(...);
extern "C" u32 func_00190140(...);
extern "C" u32 func_00190f80(...);
extern "C" u32 func_00198630(...);
extern "C" u32 func_00199468(...);
extern "C" u32 func_0019c5d0(...);
extern "C" u32 func_0019c6f0(...);
extern "C" u32 func_0019ca90(...);
extern "C" u32 func_0019d358(...);
extern "C" u32 func_001a34e0(...);
extern "C" u32 func_001a3a78(...);
extern "C" u32 func_001a5880(...);
extern "C" u32 func_001a97b8(...);
extern "C" u32 func_001ad990(...);
extern "C" u32 func_001b1bb8(...);
extern "C" u32 func_001d6ae0(...);
extern "C" u32 func_001d6b40(...);
extern "C" u32 func_001dc818(...);
extern "C" u32 func_002bc398(...);
extern "C" u32 func_002bc3f0(...);
extern "C" u32 func_002cd290(...);
extern "C" u32 func_0031cc28(...);
extern "C" u32 func_0016ac38(...);
extern "C" u32 func_0016e920(...);
extern "C" u32 func_0017df70(...);
extern "C" u32 func_001afe70(...);
extern "C" u32 func_001de168(...);
extern "C" u32 func_002bc420(...);
extern "C" u32 func_002cd1d8(...);
extern "C" u8 func_001a3570(...);

void func_00176cd0(int param_1,u32 param_2,u32 param_3)

{
  s32 lVar1;
  u32 uVar2;
  u32 uVar3;
  u32 auStack_30 [4];
  
  auStack_30[0] = param_3;
  asm volatile("" : : : "memory");
  if (*(int *)(param_1 + 0x9b8) != 0) {
    lVar1 = func_0019ba60(*(u32 *)(param_1 + 0x9f4)); asm volatile("" ::: "memory");
    uVar3 = 0;
    if ((lVar1 != 0) && (*(int *)(param_1 + 0x9f4) != param_1)) {
      uVar3 = func_0016a070(*(int *)(param_1 + 0x9f4)); asm volatile("" ::: "memory");
    }
    uVar2 = func_0016a070(param_1); asm volatile("" ::: "memory");
    lVar1 = func_001afe70(uVar2,param_2,uVar3,auStack_30); asm volatile("" ::: "memory");
    if (-1 < lVar1) {
      func_00198630(param_1,lVar1,auStack_30[0]); asm volatile("" ::: "memory");
    }
  }
  return;
}
