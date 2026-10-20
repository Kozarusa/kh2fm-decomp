#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_00294480(...);
extern "C" s32 func_002b6708(...);
extern "C" s32 func_002b7440(...);
extern "C" s32 func_002b79cc(...);
extern "C" s32 func_002b9404(...);
extern "C" s32 func_002b986c(...);
extern "C" s32 func_002ba3e8(...);
extern "C" s32 func_002bbda0(...);
extern "C" s32 func_002bc0f0(...);
extern "C" s32 func_002ff3fc(...);
extern "C" u16 func_002bc988(...);
extern "C" u32 func_001a80c8(...);
extern "C" u32 func_002766d0(...);
extern "C" u32 func_0028dac8(...);
extern "C" u32 func_00294000(...);
extern "C" u32 func_002b6e24(...);
extern "C" u32 func_002baa78(...);
extern "C" u32 func_002bb100(...);
extern "C" u32 func_002bb5a8(...);
extern "C" u32 func_002bb9b8(...);
extern "C" u32 func_002bbbc8(...);
extern "C" u32 func_002bbc90(...);
extern "C" u32 func_002bc470(...);
extern "C" u32 func_002bc608(...);
extern "C" u32 func_002bc9a8(...);
extern "C" u32 func_002bce10(...);
extern "C" u32 func_002bcfe8(...);
extern "C" u32 func_002bd030(...);
extern "C" u32 func_002bd078(...);
extern "C" u32 func_002bd0b8(...);
extern "C" u32 func_002bd100(...);
extern "C" u32 func_002bd140(...);
extern "C" u32 func_002fee78(...);
extern "C" u32 func_00324718(...);
extern "C" u32 func_001a8190(...);
extern "C" u32 func_002b6adc(...);
extern "C" u32 func_002b6f28(...);

void func_002bc398(u32 param_1,u32 param_2)

{
  s32 lVar1;
  
  lVar1 = func_002bbda0();
  if (lVar1 != 0) {
    func_002bb5a8(lVar1,param_2);
    *(u32 *)((int)lVar1 + 0x24) = *(u32 *)((int)lVar1 + 0x24) & 0xfffffff7;
  }
  return;
}
