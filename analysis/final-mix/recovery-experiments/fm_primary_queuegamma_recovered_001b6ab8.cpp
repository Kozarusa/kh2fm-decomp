#include "../common/types.h"
extern "C" u32 func_001a17c8(...);
extern "C" s32 func_00189200(...);
extern "C" u32 func_001a1cc0(...);
extern "C" char D_0032e020;

void func_001b6ab8(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x14) != 0) {
    iVar1 = func_00189200((s32)(long)&D_0032e020,*(u32 *)(param_1 + 4));
    func_001a1cc0(*(u32 *)(param_1 + 0x14),*(u32 *)(param_1 + 4),
                 *(u8 *)(iVar1 + 2));
    func_001a17c8(*(u32 *)(param_1 + 0x14));
    *(u32 *)(param_1 + 0x14) = 0;
  }
  return;
}
