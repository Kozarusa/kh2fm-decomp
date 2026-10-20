#include "../common/types.h"
extern "C" u32 func_001050c8(void);
extern "C" u32 func_00127c70(u32,u32,u32);

void func_0017ee68(int param_1)
{
  int iVar1;
  u32 uVar2;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 0x670);
  if (*(int *)(param_1 + 0xd0) != 0) {
    uVar2 = func_001050c8();
    func_00127c70(iVar1,uVar2,*(u32 *)(param_1 + 0xd0));
    *(u32 *)(param_1 + 0xd0) = 0;
  }
  if (*(int *)(param_1 + 0xd4) != 0) {
    uVar2 = func_001050c8();
    func_00127c70(iVar1,uVar2,*(u32 *)(param_1 + 0xd4));
    *(u32 *)(param_1 + 0xd4) = 0;
  }
}
