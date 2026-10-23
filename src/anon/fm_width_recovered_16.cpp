#include "../common/types.h"

// Provisional result signatures; exact compiler gates remain mandatory.
extern "C" bool func_00181500(...);
extern "C" bool func_001c0cd8(...);
extern "C" bool func_001c3888(...);
extern "C" bool func_002cf270(...);
extern "C" s32 func_0016c028(...);
extern "C" s32 func_00176fb0(...);
extern "C" s32 func_001b9bc8(...);
extern "C" s32 func_001bc780(...);
extern "C" s32 func_002cb890(...);
extern "C" u32 func_001050c8(...);
extern "C" u32 func_00105110(...);
extern "C" u32 func_001063f0(...);
extern "C" u32 func_00106450(...);
extern "C" u32 func_00106a18(...);
extern "C" u32 func_00106a60(...);
extern "C" u32 func_00106f30(...);
extern "C" u32 func_00107368(...);
extern "C" u32 func_00107478(...);
extern "C" u32 func_00108398(...);
extern "C" u32 func_00138c10(...);
extern "C" u32 func_00160fd0(...);
extern "C" u32 func_00161000(...);
extern "C" u32 func_00168b38(...);
extern "C" u32 func_0016b070(...);
extern "C" u32 func_0016bd60(...);
extern "C" u32 func_0016c568(...);
extern "C" u32 func_00177008(...);
extern "C" u32 func_001780d8(...);
extern "C" u32 func_00178888(...);
extern "C" u32 func_00179b68(...);
extern "C" u32 func_0017a7d8(...);
extern "C" u32 func_00190128(...);
extern "C" u32 func_00190140(...);
extern "C" u32 func_001906f0(...);
extern "C" u32 func_00198450(...);
extern "C" u32 func_00198860(...);
extern "C" u32 func_001b2210(...);
extern "C" u32 func_001b6d70(...);
extern "C" u32 func_001bc778(...);
extern "C" u32 func_001c2b58(...);
extern "C" u32 func_001c3748(...);
extern "C" u32 func_001dc818(...);
extern "C" u32 func_002b9b78(...);
extern "C" u32 func_002ba390(...);
extern "C" u32 func_002ba9c0(...);
extern "C" u32 func_002baa08(...);
extern "C" u32 func_002baa60(...);
extern "C" u32 func_002bbf98(...);
extern "C" u32 func_002bc188(...);
extern "C" u32 func_002bc470(...);
extern "C" u32 func_002bc608(...);
extern "C" u32 func_002bc798(...);
extern "C" u32 func_002bced8(...);
extern "C" u32 func_002bcee8(...);
extern "C" u32 func_002bcf58(...);
extern "C" u32 func_002bcfa0(...);
extern "C" u32 func_002c1b48(...);
extern "C" u32 func_002c1b60(...);
extern "C" u32 func_002c6490(...);
extern "C" u32 func_002c7060(...);
extern "C" u32 func_002cc620(...);
extern "C" u32 func_002cd428(...);
extern "C" u32 func_002cf280(...);
extern "C" u32 func_002cf2b0(...);
extern "C" u32 func_002cf2d0(...);
extern "C" u32 func_002d10a0(...);
extern "C" u32 func_002d1260(...);
extern "C" u32 func_002d24e8(...);
extern "C" u32 func_002d5c40(...);
extern "C" u32 func_002dc7c8(...);
extern "C" u32 func_002e34c8(...);
extern "C" u32 func_002e34d8(...);
extern "C" u32 func_002e64b0(...);
extern "C" u32 func_002e64b8(...);
extern "C" u32 func_002e6ab0(...);
extern "C" u32 func_002e7670(...);
extern "C" u32 func_002e76b0(...);
extern "C" u32 func_002e77a8(...);
extern "C" u32 func_002e9cb8(...);
extern "C" u32 func_002e9d08(...);
extern "C" u32 func_002e9fe0(...);
extern "C" u32 func_002eac70(...);
extern "C" u32 func_002eb990(...);
extern "C" u32 func_002f1900(...);
extern "C" u32 func_00325320(...);
extern "C" u32 func_0016ac38(...);
extern "C" u32 func_002b7fbc(...);
extern "C" u32 func_002c04c8(...);
extern "C" u32 func_002d3fa8(...);

void func_002bf5a0(u32 param_1)

{
  int iVar1;
  
  iVar1 = func_001b6d70(*(u8 *)(*(int *)((int)param_1 + 0xaf8) + 4));
  if (((*(u8 *)((int)param_1 + 0xae7) & 1) == 0) && ((*(u8 *)(iVar1 + 3) & 1) != 0)) {
    func_0016ac38(param_1,0,1,0,0);
    return;
  }
  return;
}

void func_002d25f0(u32 param_1)

{
  s32 lVar1;
  
  lVar1 = 0;
  while (lVar1 = func_001b9bc8(lVar1), lVar1 != 0) {
    if ((*(u32 *)((int)lVar1 + 0x588) & 0x8000000) != 0) {
      func_002d24e8(param_1,lVar1);
    }
  }
  return;
}

void func_002d3f18(u32 param_1)

{
  s32 lVar1;
  int iVar2;
  
  iVar2 = (int)param_1 + 0xaf0;
  if ((*(int *)((int)param_1 + 0xb6c) < 0) && (lVar1 = func_002cf270(iVar2,0x100), lVar1 != 0)) {
    func_002cf2b0(iVar2,0x100);
    func_0016ac38(param_1,0,1,0,0);
    func_002cf280(iVar2,4,0);
    return;
  }
  return;
}

void func_002e7738(u32 param_1)

{
  func_002e7670();
  func_002e76b0((int)param_1 + 4);
  func_002e77a8(param_1);
  return;
}

void func_002e7768(u32 param_1)

{
  func_002e7670();
  func_002e76b0((int)param_1 + 4);
  func_002e77a8(param_1);
  return;
}
