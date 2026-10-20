#include "../common/types.h"
extern "C" u32 func_00288f48(s32,u16,u16,u16,u16);
extern "C" u32 func_0028af18(s32,u64);
extern "C" u32 func_0028b1b0(s32,u32);
u32 func_0028b078(u32 object,u32 value,u16 count)
{
  int pointer;
  pointer = (int)object;
  *(u8 *)(pointer + 0x26) = 0;
  *(u16 *)(pointer + 0x18) = value;
  *(u8 *)(pointer + 0x25) = 1;
  *(u16 *)(pointer + 0x1a) = count;
  func_00288f48(object,0x10,0x20,0x40,0x80);
  func_0028af18(object,0x7f);
  return func_0028b1b0(object,0);
}

