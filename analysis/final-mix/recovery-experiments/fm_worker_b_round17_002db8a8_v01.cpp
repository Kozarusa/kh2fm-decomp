#include "../common/types.h"

asm(".globl PTR_0x362908
	PTR_0x362908 = 0x362908
");
extern "C" void func_002e7328(u32);
extern "C" void func_002cff98(u32);

void func_002db8a8(u32 param_1)
{
  *(u32 *)param_1 = (u32)(long)&PTR_0x362908;
  func_002e7328((u32)(long)((u8 *)param_1 + 2976));
  func_002cff98(param_1);
  asm volatile ("");
  return;
}
