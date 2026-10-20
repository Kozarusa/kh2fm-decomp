#include "../common/types.h"
extern "C" u32 D_003486a4;
extern "C" u32 D_003486a0;
extern "C" void func_0013e2d8(u32,u32,u32);
s32 func_0013e610(u32 param)
{
  register u32 argument asm("$5")=param;
  asm("" : "+r"(argument));
  u32 base=D_003486a4;
  register s32 index asm("$14")=*(s32 *)(base+0x1fa4)-1;
  register u32 scaled asm("$15")=(u32)index*4;
  asm("" : "+r"(scaled) : "r"(index));
  *(u32 *)(base+0x1fa4)=index;
  register u32 entry asm("$13")=*(u32 *)(base+scaled+0x1f80);
  asm("" : "+r"(entry));
  u32 result=base+entry*0x380;
  func_0013e2d8(result,argument,D_003486a0+0x20);
  return result;
}
