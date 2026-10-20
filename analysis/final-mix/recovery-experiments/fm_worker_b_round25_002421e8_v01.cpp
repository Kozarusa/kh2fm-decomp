#include "../common/types.h"

#include "../common/types.h"

extern "C" volatile u32 DAT_0035ecb8;
asm(".globl DAT_0035ecb8
	DAT_0035ecb8 = 0x35ecb8
");
extern "C" u32 func_002efa40(u32);

u32 func_002421e8(u32 param_1)
{
  u32 uVar1;
  int iVar1;
  iVar1 = 0;
  if (func_002efa40(*(u32 *)((u8 *)param_1 + 4)) == 0) {
    uVar1 = DAT_0035ecb8 & 0xff;
    if ((uVar1 & 1) != 0) {
      iVar1 = 1;
    }
  }
  return iVar1;
}
