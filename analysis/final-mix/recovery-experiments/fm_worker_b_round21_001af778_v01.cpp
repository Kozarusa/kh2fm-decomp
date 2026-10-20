#include "../common/types.h"

asm(".globl PTR_00352f34
	PTR_00352f34 = 0x352f34
");
extern "C" u32 PTR_00352f34;
extern "C" u64 func_001708f8(u32);
extern "C" u32 func_001af7c0(u32);

void func_001af778(u32 param_1)
{
  u32 *puVar1;
  u32 uVar1;
  puVar1 = (u32 *)param_1;
  uVar1 = func_001708f8(PTR_00352f34);
  puVar1[13] = func_001af7c0(puVar1[0]);
  puVar1[1] = uVar1;
  return;
}
