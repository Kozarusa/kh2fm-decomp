#include "../common/types.h"

asm(".globl PTR_0x347e60
	PTR_0x347e60 = 0x347e60
");
extern "C" u32 PTR_0x347e60;
extern "C" void func_00239870(u32);
extern "C" void func_0031a840(u32);

void func_0031c8e8(u32 param_1)
{
  *(u32 *)param_1 = (u32)(long)&PTR_0x347e60;
  func_00239870((u32)(long)((u8 *)param_1 + 24));
  func_0031a840(param_1);
  asm volatile ("");
  return;
}
