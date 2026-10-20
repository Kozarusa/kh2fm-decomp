#include "../common/types.h"
extern "C" u32 D_003486a4;
extern "C" u32 D_003486a0;
extern "C" void func_0013e2d8(u32,u32,u32);

s32 func_0013e610(u32 param)
{
  u32 base=D_003486a4;
  register s32 index asm("$14")=*(s32 *)(base+0x1fa4)-1;
  register u32 lookup asm("$15");
  register u32 entry asm("$13");
  asm("sll %0,%2,2\n\tsw %2,0x1fa4(%3)\n\taddu %0,%0,%3\n\tlw %1,0x1f80(%0)"
      : "=&r"(lookup), "=r"(entry) : "r"(index), "r"(base) : "memory");
  register u32 address asm("$14");
  register u32 argument asm("$6");
  // Symbolic paired relocations retain the source global's original address.
  asm("lui %0,%%hi(D_003486a0)\n\tlw %1,%%lo(D_003486a0)(%0)"
      : "=&r"(address), "=r"(argument) : "r"(entry) : "memory");
  register u32 stride asm("$15")=0x380;
  asm("" : "+r"(stride) : "r"(argument));
  u32 result=base+entry*stride;
  func_0013e2d8(result,param,argument+0x20);
  return result;
}
