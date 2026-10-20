#include "../common/types.h"

extern "C" u64 func_00155d58(...);
extern "C" void func_00138c10(...);
extern "C" void func_00154408(...);

void func_001576e8(u32 *param_1)
{
  s32 iVar1;
  iVar1 = (int)param_1;
  func_00138c10(func_00155d58(param_1,0),iVar1 + 0x1a30);
  func_00138c10(func_00155d58(param_1,1),iVar1 + 0x1bcc);
  func_00138c10(func_00155d58(param_1,2),iVar1 + 0x20a0);
  func_00154408((char *)param_1 + 0x40,*(u32 *)(param_1 + 6));
}
