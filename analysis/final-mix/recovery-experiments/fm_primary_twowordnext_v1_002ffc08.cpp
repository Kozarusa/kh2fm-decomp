#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_0030edb0(void);
extern "C" bool func_0030ee00(void);
extern "C" s32 func_00102210(...);
extern "C" s32 func_0010fa28(s32);
extern "C" s32 func_0010fa58(s32);
extern "C" s32 func_003071d0(void*,u32,u32,void*,void*);
extern "C" s32 func_00308dc0(...);
extern "C" s32 func_0030a8f8(...);
extern "C" s32 func_0030ab88(...);
extern "C" s32 func_00305168(void*,u64,u64,u64);
extern "C" u32 func_00102080(...);
extern "C" u32 func_001031b0(...);
extern "C" u32 func_00105c30(void);
extern "C" u32 func_0010c7e8(s32);
extern "C" u32 func_00110500(u64);
extern "C" u32 func_00110618(s32);
extern "C" u32 func_00114438(...);
extern "C" u32 func_0011a408(...);
extern "C" u32 func_0011a938(f32,f32,s32,u64);
extern "C" u32 func_0011cdf0(...);
extern "C" u32 func_0016bd60(u64,u64);
extern "C" u32 func_0016c568(...);
extern "C" u32 func_0017c030(void*,u64,u64,s8);
extern "C" u32 func_0017c430(...);
extern "C" u32 func_0017c4c8(...);
extern "C" u32 func_0017f488(u32,u32,u64,u64);
extern "C" u32 func_0017f5e0(...);
extern "C" u32 func_0017f5f8(...);
extern "C" u32 func_00180c88(...);
extern "C" u32 func_0018a008(...);
extern "C" u32 func_00190128(...);
extern "C" u32 func_0019bc38(u64);
extern "C" u32 func_001c1748(...);
extern "C" u32 func_0023a918(s32);
extern "C" u32 func_0023cc18(s32);
extern "C" u32 func_002bc1e8(u64);
extern "C" u32 func_002e95a0(u32,u32,s32);
extern "C" u32 func_002e9610(void*,void*);
extern "C" u32 func_002eaf40(s32);
extern "C" u32 func_002ee730(void*);
extern "C" u32 func_002ee840(...);
extern "C" u32 func_002ef618(void);
extern "C" u32 func_002f25a0(...);
extern "C" u32 func_002f3c28(void*);
extern "C" u32 func_002f3f88(...);
extern "C" u32 func_002f40a0(f32);
extern "C" u32 func_002f4148(...);
extern "C" u32 func_002f41f0(...);
extern "C" u32 func_002fd220(u64);
extern "C" u32 func_002feac0(...);
extern "C" u32 func_003032d0(...);
extern "C" u32 func_00305110(void*,u64,u64,u64);
extern "C" u32 func_00306e80(...);
extern "C" u32 func_003080d0(...);
extern "C" u32 func_0030af40(u64,u64,u64);
extern "C" u32 func_0030f468(s32);
extern "C" u32 func_0030ffd8(void);
extern "C" u32 func_00316d08(void);

u32 func_002ffc08(u32 param_1,int param_2)

{
  u32 uVar1;
  
  if (*(int *)(param_2 + 8) == 0) {
    *(volatile u32 *)(param_2 + 4) = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = func_003032d0();
    *(volatile u32 *)(param_2 + 4) = 0;
    *(volatile u32 *)(param_2 + 8) = 0;
  }
  return uVar1;
}
