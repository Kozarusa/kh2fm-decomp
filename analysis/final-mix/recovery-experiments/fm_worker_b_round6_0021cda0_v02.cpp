#include "../common/types.h"

asm(".globl PTR_0033a980
	PTR_0033a980 = 0x33a980
"
    ".globl PTR_0033b100
	PTR_0033b100 = 0x33b100
");

extern "C" u32 PTR_0033a980;
extern "C" u32 PTR_0033b100;
extern "C" void func_001e72a8(u32 *);

void func_0021cda0(s32 param_1)
{
  u32 *puVar1;
  if (param_1 != 0) {
    puVar1 = (u32 *)&PTR_0033b100;
  }
  else {
    puVar1 = (u32 *)&PTR_0033a980;
  }
  func_001e72a8(puVar1);
}
