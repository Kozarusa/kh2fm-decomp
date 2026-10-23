#include "../common/types.h"

extern "C" u32 func_002f3f88(u32, u32);
extern "C" u8 D_00354bc0[];
extern "C" u8 D_00354be0[];

u32 func_002006b0(u32 object, u32 owner)
{
  u32 table = *(u32 *)(owner + 12);
  s32 offset = *(s32 *)(table + 4);
  u32 base = object + offset;
  func_002f3f88(base + 160, (u32)D_00354bc0);
  base = base + 176;
  u32 result = func_002f3f88(base, (u32)D_00354be0);
  asm("" : "+r"(result)); // why: keeps the callee result live so the second call stays a jal
  return result;
}
