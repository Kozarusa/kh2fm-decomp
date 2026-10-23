#include "../common/types.h"

asm(".globl DAT_00350444
	DAT_00350444 = 0x350444
");

extern "C" u32 DAT_00350444;
extern "C" void func_0019cc20(void);

void func_0019c970(u32 param_1)
{
  u32 uVar1;
  u32 uVar2;
  uVar1 = param_1;
  func_0019cc20();
  uVar2 = DAT_00350444;
  if ((uVar2 ^ uVar1) == 0) {
    DAT_00350444 = 0;
  }
  else {
    DAT_00350444 = uVar2;
  }
  return;
}
