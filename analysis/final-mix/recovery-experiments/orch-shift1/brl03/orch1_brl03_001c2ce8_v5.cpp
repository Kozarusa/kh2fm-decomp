#include "../common/types.h"

extern "C" void func_001d7cd0(u32,u64,u64);
extern "C" u8 D_00351468;

void func_001c2ce8(u32 object,u64 second,u64 third)
{
  // why: binds mode to the original register t6
  register u32 mode asm("$14");
  // why: binds flags to the original register t5
  register u32 flags asm("$13");
  func_001d7cd0(object,second,third);
  mode = *(u32 *)((u8 *)object + 2748);
  mode = mode | 4;
  flags = *(u32 *)((u8 *)object + 1416);
  flags = flags | 0x200000;
  *(u32 *)((u8 *)object + 1416) = flags;
  u32 table = (u32)&D_00351468;
  // why: keeps store order (table is stored after the flags store)
  asm("" : "+r"(table), "+r"(mode) : "m"(*(u32 *)((u8 *)object + 1416)));
  *(u32 *)object = table;
  // why: keeps store order (mode is stored after the table store)
  asm("" : "+r"(mode) : "m"(*(u32 *)object));
  *(u32 *)((u8 *)object + 2748) = mode;
  return;
}
