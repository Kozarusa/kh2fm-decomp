#include "../common/types.h"

// Preserve original registry aliases.
void func_001721d8(u32 *param_1) asm("_ZN2YS20trap_obj_jump_directEP8BD_VALUE");

typedef void (*code)(u32, u32, u32);

void func_001721d8(u32 *param_1)
{
  u32 iVar1;
  u32 iVar2;
  u32 iVar3;
  u32 iVar4;
  iVar1 = *(u32 *)param_1;
  iVar2 = param_1[1];
  iVar3 = *(u32 *)(iVar1 + 4);
  iVar4 = *(u32 *)(iVar3 + 12);
  (*(code *)(*(u32 *)iVar4 + 8))(iVar4, iVar3, iVar2);
  asm volatile ("");
}
