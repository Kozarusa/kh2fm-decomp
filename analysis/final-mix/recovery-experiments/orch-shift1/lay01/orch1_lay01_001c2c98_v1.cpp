#include "../common/types.h"

extern "C" void func_001d7cd0(u32,u64,u64);
extern "C" u8 D_00351468;

void func_001c2c98(u32 object,u64 second,u64 third)
{
  u32 mode;
  u32 flags;
  func_001d7cd0(object,second,third);
  mode = *(u32 *)((u8 *)object + 2748);
  mode = mode | 4;
  flags = *(u32 *)((u8 *)object + 1416);
  flags = flags | 0x200000;
  *(u32 *)((u8 *)object + 1416) = flags;
  *(u32 *)object = (u32)&D_00351468;
  *(u32 *)((u8 *)object + 2748) = mode;
  return;
}
