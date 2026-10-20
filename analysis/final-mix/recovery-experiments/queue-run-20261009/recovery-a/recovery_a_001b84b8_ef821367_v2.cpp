#include "../common/types.h"
extern "C" u32 func_001db610(...);
extern "C" s32 func_001b8420(...);
extern "C" char func_001b8520;

bool func_001b84b8(u32 param_1,u32 param_2)

{
  bool bVar1;
  u32 uVar2;
  s32 lVar3;
  u32 *puVar4;
  
  bVar1 = false;
  puVar4 = (u32 *)param_1;
  if (puVar4[1] != 0) {
    puVar4[4] = param_2;
    asm volatile ("" ::: "memory");
    if (puVar4[2] == 0) {
      puVar4[2] = func_001b8420(*puVar4);

    }
    lVar3 = func_001db610(puVar4[2],(s32)(long)&func_001b8520,param_1);
    puVar4[2] = (int)lVar3;
    bVar1 = lVar3 != 0;
  }
  return bVar1;
}
