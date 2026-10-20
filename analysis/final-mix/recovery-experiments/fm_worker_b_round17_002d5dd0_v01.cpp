#include "../common/types.h"

asm(".globl PTR_0x362428
	PTR_0x362428 = 0x362428
");
extern "C" void func_002e7328(u32);
extern "C" void func_002cff98(u32);

void func_002d5dd0(u32 param_1)
{
  *(u32 *)param_1 = (u32)(long)&PTR_0x362428;
  func_002e7328((u32)(long)((u8 *)param_1 + 2872));
  func_002cff98(param_1);
  asm volatile ("");
  return;
}
