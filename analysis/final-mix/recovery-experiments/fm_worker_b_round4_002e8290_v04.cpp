#include "../common/types.h"

asm(".globl DAT_003637d0\n\tDAT_003637d0 = 0x3637d0\n");

extern "C" u32 DAT_003637d0;
extern "C" void func_002eda90(u32,u32,float);

void func_002e8290(u32 *param_1)
{
  u32 uVar1;
  uVar1 = DAT_003637d0;
  func_002eda90(uVar1,param_1[0],*(float *)((char *)param_1 + 4));
}
