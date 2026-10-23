#include "../common/types.h"

asm(".globl PTR_00352bd0
	PTR_00352bd0 = 0x352bd0
");
extern "C" u32 PTR_00352bd0;
extern "C" u64 func_001e0cc8(void);
extern "C" void func_001e26b8(u32, u64);

void func_001e0f90(u32 *param_1)
{
  u64 uVar1;
  u32 *puVar1 = param_1;
  uVar1 = func_001e0cc8();
  func_001e26b8(PTR_00352bd0, uVar1);
  puVar1[0xa] = 0;
  puVar1[9] = 5;
  return;
}
