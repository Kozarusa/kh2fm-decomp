#include "../common/types.h"
extern "C" u32 func_001a9ae8(...);
extern "C" u32 func_001a98e8(...);
extern "C" u64 func_00192cc0(...);
extern "C" char D_0036b248;

void func_00152688(int param_1,u64 param_2,u64 param_3,u32 param_4)

{
  u64 uVar1;
  u8 auStack_a0 [16];
  u8 auStack_90 [96];
  
  uVar1 = func_00192cc0(auStack_a0,(s32)(long)&D_0036b248,*(u32 *)(param_1 + 0x1bc));
  func_001a98e8(auStack_90,1,uVar1,*(u32 *)(param_1 + 0x1a8),0);
  func_001a9ae8(auStack_90,param_2,param_3,param_4);
  return;
}
