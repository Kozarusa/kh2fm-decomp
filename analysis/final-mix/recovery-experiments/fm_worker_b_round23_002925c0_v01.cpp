#include "../common/types.h"

extern "C" u32 func_00103eb0(void);
extern "C" void func_00102818(u32,u32,u32,u32,u32);
extern "C" char func_00292608;
extern "C" char func_00292620;

void func_002925c0(void)
{
  u32 *puVar1;
  puVar1 = (u32 *)func_00103eb0();
  func_00102818(*(u32 *)(puVar1 + 1), 0, 0x222e0, (u32)(long)&func_00292608, 4096);
  *(u32 *)(puVar1 + 12) = (u32)(long)&func_00292620;
  return;
}
