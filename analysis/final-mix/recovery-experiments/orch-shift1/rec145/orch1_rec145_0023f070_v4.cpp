#include "../common/types.h"
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0023f0c8(s32,u32);
void func_0023f070(u32 object,u32 value,u32 count)
{
  register u32 savedValue asm("$16") = value; // why: original preserves value in s0
  func_00139d78();
  *(u32 *)((int)object + 0x8c) = savedValue;
  *(u32 *)((int)object + 0x98) = savedValue;
  func_0023f0c8(object,count);
  return;
}



