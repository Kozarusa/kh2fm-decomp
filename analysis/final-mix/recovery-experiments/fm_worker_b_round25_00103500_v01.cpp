#include "../common/types.h"

#include "../common/types.h"

extern "C" volatile u32 DAT_0032ba20;
asm(".globl DAT_0032ba20
	DAT_0032ba20 = 0x32ba20
");
extern "C" volatile u32 DAT_003a6a50;
asm(".globl DAT_003a6a50
	DAT_003a6a50 = 0x3a6a50
");
extern "C" u32 func_00103b38(u32);

void func_00103500(u32 param_1)
{
  u32 uVar1;
  if (func_00103b38(param_1) == 0) {
    uVar1 = DAT_0032ba20;
    if (uVar1 != param_1) {
      DAT_003a6a50 = param_1;
      DAT_0032ba20 = 0xffffffff;
    }
  }
  return;
}
