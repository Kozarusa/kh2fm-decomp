#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_00294480(void*);
extern "C" s32 func_002b6708(...);
extern "C" s32 func_002b7440(s32,s32,s32);
extern "C" s32 func_002b79cc(s32,s32,s32);
extern "C" s32 func_002b9404(s32,s32,void*,void*);
extern "C" s32 func_002b986c(u32,u32);
extern "C" s32 func_002ba3e8(...);
extern "C" s32 func_002bbda0(...);
extern "C" s32 func_002bc0f0(void);
extern "C" s32 func_002ff3fc(...);
extern "C" u16 func_002bc988(s32);
extern "C" u32 func_001a80c8(u64);
extern "C" u32 func_002766d0(void);
extern "C" u32 func_0028dac8(...);
extern "C" u32 func_00294000(u64);
extern "C" u32 func_002b6e24(s32,void*,u32);
extern "C" u32 func_002baa78(void);
extern "C" u32 func_002bb100(s32,s32,u8);
extern "C" u32 func_002bb5a8(s64,s64);
extern "C" u32 func_002bb9b8(...);
extern "C" u32 func_002bbbc8(...);
extern "C" u32 func_002bbc90(...);
extern "C" u32 func_002bc470(...);
extern "C" u32 func_002bc608(...);
extern "C" u32 func_002bc9a8(void*,s32,s32);
extern "C" u32 func_002bce10(void*,s32);
extern "C" u32 func_002bcfe8(s32);
extern "C" u32 func_002bd030(...);
extern "C" u32 func_002bd078(s32);
extern "C" u32 func_002bd0b8(...);
extern "C" u32 func_002bd100(s32);
extern "C" u32 func_002bd140(...);
extern "C" u32 func_002fee78(...);
extern "C" u32 func_00324718(void*,s32);
extern "C" u32 func_001a8190(s32);
extern "C" u32 func_002b6adc(u32,u32);
extern "C" u32 func_002b6f28(u32,u32,u32);

void func_002bcbf0(u32 param_1,u32 param_2,u32 param_3,u32 *param_4,
                 u32 *param_5)

{
  u32 uVar1;
  int iVar2;
  
  uVar1 = func_002bc988(param_2);
  *param_5 = uVar1;
  iVar2 = (int)param_1;
  uVar1 = *(u32 *)(iVar2 + 0x14c);
  *param_4 = uVar1;
  func_002bc9a8(param_1,uVar1,*param_5);
  register u32 flag asm("$13") = 0x15;
  if (*(int *)(iVar2 + 0x14c) != 0x14) {
    flag = 0x14;
  }
  *(u32 *)(iVar2 + 0x14c) = flag;
  return;
}
