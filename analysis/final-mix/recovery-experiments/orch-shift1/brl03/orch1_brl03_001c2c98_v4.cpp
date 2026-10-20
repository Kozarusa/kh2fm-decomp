#include "../common/types.h"

extern "C" void func_001d7cd0(u32,u64,u64);
extern "C" u8 D_00351468;

void func_001c2c98(u32 object,u64 second,u64 third)
{
  // why: binds mode to the original register t6
  register u32 mode asm("$14");
  // why: binds flags to the original register t5
  register u32 flags asm("$13");
  func_001d7cd0(object,second,third);
  mode = *(u32 *)((u8 *)object + 2748);
  mode = mode | 4;
  flags = *(u32 *)((u8 *)object + 1416);
  // why: binds the flag bit to the original register t7
  register u32 bit asm("$15") = 0x200000;
  flags = flags | bit;
  // why: keeps the or result in t5 (flags) instead of reusing t7
  asm("" : "+r"(flags));
  *(u32 *)((u8 *)object + 1416) = flags;
  // why: binds the table address to the original register t7
  register u32 table asm("$15") = (u32)&D_00351468;
  // why: keeps store order (table is stored after the flags store)
  asm("" : "+r"(table), "+r"(mode) : "m"(*(u32 *)((u8 *)object + 1416)));
  *(u32 *)object = table;
  // why: keeps store order (mode is stored after the table store)
  asm("" : "+r"(mode) : "m"(*(u32 *)object));
  *(u32 *)((u8 *)object + 2748) = mode;
  return;
}
