#include "../common/types.h"

asm(".globl DAT_00351680
	DAT_00351680 = 0x351680
");
extern "C" u32 DAT_00351680;
extern "C" void func_001c5e88(void);

u32 func_001c5f38(u8 *param_1)
{
  s32 iVar1;
  iVar1 = *(s32 *)((u8 *)(long)&DAT_00351680 + param_1[0x52] * 32 + 20);
  if (0 < iVar1) {
    func_001c5e88();
    return 1;
  }
  return 0;
}
