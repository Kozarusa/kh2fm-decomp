#include "../common/types.h"
// Original 002fd348 calls thunk 001002a0, which tail-jumps through
// 0030f468 to _Exit at 00305240. The diagnostic failure path does not return.
extern "C" void func_002fd348(u64) __attribute__((noreturn));
extern "C" void func_002fe0a0(s32);
extern "C" void func_0020e2e8(s32,u32,u16,u64);
extern "C" char D_00370748;

void func_0020e548(s32 object, u64 wait)
{
  if (*(s32 *)(object+4) == 0) {
    func_002fe0a0((s32)(long)&D_00370748);
    func_002fd348(1);
  }
  func_0020e2e8(object, *(u8 *)(object+9), *(u16 *)object, wait);
}
