#include "../common/types.h"
extern "C" u32 *D_01d5ba70;
extern "C" char D_003217a0;
extern "C" void func_002fd248(u32,u32,u32,u32,u32);

void func_001d5b78(u32 index, u32 flag)
{
  u32 shifted = index << 4;
  // why: the original keeps the loaded pointer in t6
  register u32 *pointer asm("$14") = D_01d5ba70;
  // why: single reader of the load so it schedules after sd ra
  asm("" : "+r"(pointer));
  func_002fd248(shifted | flag, (u32)(pointer + 2), *(u32 *)((u32 *)pointer + 1), 8, (u32)&D_003217a0);
  // why: keeps the call from becoming a tail call
  asm volatile ("" ::: "memory");
  return;
}
