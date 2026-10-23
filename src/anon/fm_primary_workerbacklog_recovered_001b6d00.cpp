#include "../common/types.h"

asm(".globl DAT_00351184
	DAT_00351184 = 0x351184
");
asm(".globl PTR_00351214
	PTR_00351214 = 0x351214
");
extern "C" u32 DAT_00351184;
extern "C" u32 PTR_00351214;
extern "C" void func_00102670(u32, u32);

void func_001b6d00(void)
{
  u32 uVar1;
  uVar1 = DAT_00351184;
  if (__builtin_expect(uVar1 != 0, 0)) {
    func_00102670(PTR_00351214, ((u32 *)(long)uVar1)[6]);
    DAT_00351184 = 0;
  }
  return;
}
