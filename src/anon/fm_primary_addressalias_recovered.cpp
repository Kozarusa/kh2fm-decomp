#include "../common/types.h"

extern "C" char D_01d5ba78;
extern "C" char D_00352780;
extern "C" void func_001ce378(u32);

void func_001d6538(u32 param_1)
{
  func_001ce378(param_1);
  *(u32 *)param_1 = (u32)(long)&D_00352780;
  *(u32 *)(param_1 + 0x9f8) = (u32)(long)&D_01d5ba78;
  return;
}
