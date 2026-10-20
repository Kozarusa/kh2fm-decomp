#include "../common/types.h"

extern "C" char D_0035f3a0;
extern "C" void func_0028b8a0(void*);
extern "C" void func_0023f820(u32);

void func_0028b7f8(u32 object)
{
  u32 table = (u32)&D_0035f3a0;
  // why: keeps the table address ahead of the frame saves and the store after them
  asm volatile ("" : : "r"(table));
  *(volatile u32 *)object = table;
  func_0028b8a0((void*)object);
  func_0023f820(object);
  // why: keeps the call from becoming a tail call
  asm volatile ("");
  return;
}
