#include "../common/types.h"

extern "C" char func_00367860;
extern "C" void func_003167f8(void);
extern "C" void func_00106420(u32);

void func_00315678(u32 param_1)
{
  u32 *puVar1;
  puVar1 = (u32 *)param_1;
  *puVar1 = (u32)(long)&func_00367860;
  func_003167f8();
  func_00106420(param_1);
  asm volatile ("");
  return;
}
