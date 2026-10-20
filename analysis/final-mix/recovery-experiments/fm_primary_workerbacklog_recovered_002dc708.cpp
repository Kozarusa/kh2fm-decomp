#include "../common/types.h"

asm(".globl PTR_0x3629e8
	PTR_0x3629e8 = 0x3629e8
");
extern "C" u32 PTR_0x3629e8;
extern "C" void func_002e4a90(u32);
extern "C" void func_002cea28(u32);

void func_002dc708(u32 param_1)
{
  *(u32 *)param_1 = (u32)(long)&PTR_0x3629e8;
  func_002e4a90((u32)(long)((u8 *)param_1 + 256));
  func_002cea28(param_1);
  asm volatile ("");
  return;
}
