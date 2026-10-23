#include "../common/types.h"

// Preserve original registry aliases.
void func_002956c0(u32 param_1) asm("_ZN2Tz10JmWorldSel8SelCheckEi");

#include "../common/types.h"

extern "C" u32 func_00294000(u32);
extern "C" u32 func_00295158(u32);
extern "C" void func_002941a8(u32);

void func_002956c0(u32 param_1)
{
  u32 *puVar1;
  u32 uVar1;
  uVar1 = func_00294000(0);
  puVar1 = (u32 *)((u8 *)uVar1 + 16);
  uVar1 = func_00295158(param_1);
  register u32 offset asm("$2")=uVar1; asm("sll %0,%0,4" : "+r"(offset)); puVar1 = (u32 *)((u8 *)puVar1 + offset);
  func_002941a8((u32)(long)puVar1);
  asm volatile ("");
  return;
}
