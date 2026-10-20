#include "../common/types.h"
extern "C" f32 D_0036abec;
extern "C" f32 D_0036abf0;
s32 func_001317a8(f32 value,u32 object)
{
  register u32 base asm("$15")=*(u32 *)(object+4);
  asm volatile("" : "+r"(base));
  s32 count=*(s32 *)(base+0x24);
  f32 scaled=value**(f32 *)(base+0x58);
  register f32 *denominator asm("$15")=&D_0036abec;
  asm volatile("" : "+r"(denominator));
  register f32 *addition asm("$15")=&D_0036abf0;
  asm volatile("" : "+r"(addition));
  s32 index=(s32)(scaled / *denominator+*addition);
  if(index<0) index=0;
  if(count<=index) index=count-1;
  return index;
}
