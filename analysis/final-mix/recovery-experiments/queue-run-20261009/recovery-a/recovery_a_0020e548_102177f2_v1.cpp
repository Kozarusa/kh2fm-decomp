#include "../common/types.h"
extern "C" u32 func_0020e2e8(...);
extern "C" u32 func_002fd348(u64);
extern "C" u32 func_002fe0a0(...);
extern "C" char D_00370748;

void func_0020e548(int param_1,u64 param_2,u64 param_3)

{
  if (*(int *)(param_1 + 4) == 0) {
    func_002fe0a0((s32)(long)&D_00370748,param_2,param_3,param_2); asm volatile("" ::: "memory");
    func_002fd348(1); asm volatile("" ::: "memory");
  }
  func_0020e2e8(); asm volatile("" ::: "memory");
  return;
}
