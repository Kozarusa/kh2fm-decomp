#include "../common/types.h"

asm(".globl PTR_0x3621a0
	PTR_0x3621a0 = 0x3621a0
");
extern "C" void func_002e7328(u32);
extern "C" void func_002d2a08(u32);

void func_002d47e8(u32 param_1)
{
  *(u32 *)param_1 = (u32)(long)&PTR_0x3621a0;
  func_002e7328((u32)(long)((u8 *)param_1 + 3208));
  func_002d2a08(param_1);
  asm volatile ("");
  return;
}
