#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_001805a8(...);
extern "C" bool func_00180cd0(...);
extern "C" bool func_00187e20(...);
extern "C" bool func_00187e58(...);
extern "C" bool func_00197c28(...);
extern "C" bool func_0019a9e0(...);
extern "C" bool func_0019f060(...);
extern "C" bool func_001c0cd8(...);
extern "C" f32 func_0018a970(...);
extern "C" s32 func_00168b88(...);
extern "C" s32 func_0016c028(...);
extern "C" s32 func_0017ec98(...);
extern "C" s32 func_001801b0(...);
extern "C" s32 func_001947c0(...);
extern "C" s32 func_0019ad58(...);
extern "C" s32 func_0019b260(...);
extern "C" s32 func_001a6a20(...);
extern "C" s32 func_001b9bc8(...);
extern "C" s32 func_002fd248(...);
extern "C" s32 func_0017edf0(...);
extern "C" u32 func_00158f90(...);
extern "C" u32 func_00169f98(...);
extern "C" u32 func_0016a9b8(...);
extern "C" u32 func_0016bd60(...);
extern "C" u32 func_0016ed50(...);
extern "C" u32 func_00170320(...);
extern "C" u32 func_0017f380(...);
extern "C" u32 func_0017f488(...);
extern "C" u32 func_0017f5e0(...);
extern "C" u32 func_00186378(...);
extern "C" u32 func_001863a8(...);
extern "C" u32 func_00186740(...);
extern "C" u32 func_00187018(...);
extern "C" u32 func_00187ab8(...);
extern "C" u32 func_00187b90(...);
extern "C" u32 func_0018c8b8(...);
extern "C" u32 func_0018c960(...);
extern "C" u32 func_0018eb98(...);
extern "C" u32 func_0018ee10(...);
extern "C" u32 func_001902a8(...);
extern "C" u32 func_001903d0(...);
extern "C" u32 func_00192800(...);
extern "C" u32 func_00192868(...);
extern "C" u32 func_00195430(...);
extern "C" u32 func_00195700(...);
extern "C" u32 func_00196e88(...);
extern "C" u32 func_00197930(...);
extern "C" u32 func_00198660(...);
extern "C" u32 func_00198bd0(...);
extern "C" u32 func_00198ee8(...);
extern "C" u32 func_00199810(...);
extern "C" u32 func_0019ab80(...);
extern "C" u32 func_0019ad00(...);
extern "C" u32 func_0019ae60(...);
extern "C" u32 func_0019ef70(...);
extern "C" u32 func_0019f070(...);
extern "C" u32 func_001a49a0(...);
extern "C" u32 func_001a4d40(...);
extern "C" u32 func_001ad990(...);
extern "C" u32 func_001b50e0(...);
extern "C" u32 func_001b58f0(...);
extern "C" u32 func_001ce2d8(...);
extern "C" u32 func_001ce328(...);
extern "C" u32 func_001d30f8(...);
extern "C" u32 func_001d5770(...);
extern "C" u32 func_001dc5f8(...);
extern "C" u32 func_001dc670(...);
extern "C" u32 func_001dc920(...);
extern "C" u32 func_001dcb98(...);
extern "C" u32 func_0031cc28(...);
extern "C" u32 func_001de168(...);
extern "C" u8 func_00227118(...);

void func_0018ef98(int param_1,u32 param_2)

{
  s32 lVar1;
  
  lVar1 = 0;
  while (lVar1 = func_0018ee10(lVar1), lVar1 != 0) {
    if (*(int *)((int)lVar1 + 0xc) == param_1) {
      *(u32 *)((int)lVar1 + 0xc) = param_2;
    }
  }
  return;
}
