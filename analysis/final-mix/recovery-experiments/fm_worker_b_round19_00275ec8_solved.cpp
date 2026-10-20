#include "../common/types.h"

asm(".globl DAT_00360f20c
	DAT_00360f20c = 0x36f20c
");
extern "C" volatile u32 DAT_00360f20c;
extern "C" void func_00139d78(u32);

void func_00275ec8(u32 param_1)
{
  func_00139d78(*(u32 *)(long)&DAT_00360f20c + 872);
  *(u32 *)(*(u32 *)(long)&DAT_00360f20c + 1280) = param_1;
  return;
}
