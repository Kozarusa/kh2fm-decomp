#include "../common/types.h"
extern "C" u32 func_0020e2e8(u32,u32,u32);
extern "C" u32 func_002fd348(u64);
extern "C" u32 func_002fe0a0(...);
extern "C" char D_00370748;

void func_0020e548(int param_1,u64 param_2,u64 param_3)

{
  register u32 object asm("$14") = param_1;
  register u32 transport asm("$4") = object;
  asm volatile ("" : "+r"(transport));
  if (*(int *)(param_1 + 4) == 0) {
    func_002fe0a0((s32)(long)&D_00370748,param_2,param_3,param_2); asm volatile("" ::: "memory");
    func_002fd348(1); asm volatile("" ::: "memory");
  }
  asm volatile ("" : "+r"(transport));
  func_0020e2e8(transport,*(u8 *)(object+9),*(u16 *)object);
  return;
}
