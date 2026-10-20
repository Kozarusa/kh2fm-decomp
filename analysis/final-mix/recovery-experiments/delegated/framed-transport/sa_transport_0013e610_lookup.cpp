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
  // Preserve the original scaled-index operand order and counter write.
  asm("sll %0,%2,2\n\tsw %2,0x1fa4(%3)\n\taddu %0,%0,%3\n\tlw %1,0x1f80(%0)"
      : "=&r"(lookup), "=r"(entry) : "r"(index), "r"(base) : "memory");
  u32 result=base+entry*0x380;
  func_0013e2d8(result,param,D_003486a0+0x20);
  return result;
}
