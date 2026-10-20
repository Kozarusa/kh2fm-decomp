#include "../common/types.h"

extern "C" u32 func_00155d58(u32,u32);
extern "C" void func_00138c10(u32,u32);
extern "C" void func_00154408(u32,u32);

void func_001576e8(u32 param_1)
{
  u32 uVar1;
  uVar1 = func_00155d58(param_1,0);
  func_00138c10(param_1 + 0x1a30,uVar1);
  uVar1 = func_00155d58(param_1,1);
  func_00138c10(param_1 + 0x1bcc,uVar1);
  uVar1 = func_00155d58(param_1,2);
  func_00138c10(param_1 + 0x20a0,uVar1);
  func_00154408(param_1 + 0x40,*(u32 *)(param_1 + 0x18));
  return;
}
