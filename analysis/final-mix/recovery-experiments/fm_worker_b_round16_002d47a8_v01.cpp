#include "../common/types.h"

extern "C" char func_003621a0;
extern "C" void func_002e7328(u32);
extern "C" void func_002d2a08(u32);

void func_002d47a8(u32 param_1)
{
  *(u32 *)param_1 = (u32)(long)&func_003621a0;
  func_002e7328(param_1 + 0x322);
  func_002d2a08(param_1);
  asm volatile ("");
  return;
}
