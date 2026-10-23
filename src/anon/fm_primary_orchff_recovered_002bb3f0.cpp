#include "../common/types.h"
extern "C" u32 func_002bb100(s32,s32,u8);
extern "C" u32 func_002bb5a8(s32,s32);

u32 func_002bb3f0(s32 object,s32 first,s32 second,s32 third,
                 s32 half)
{
  int base;
  u32 result;

  func_002bb100(object,1,6);
  result = func_002bb5a8(object,third);
  base = (int)object;
  *(u32 *)(base + 0x18) = first;
  *(u32 *)(base + 0x10) = second;
  *(u16 *)(base + 0x2a) = half;
  return result;
}
