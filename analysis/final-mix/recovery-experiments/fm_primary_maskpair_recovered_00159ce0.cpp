#include "../common/types.h"
struct __attribute__((aligned(16))) Quad { f32 value[4]; };
extern "C" u32 func_0016c028(u32);
extern "C" f32 D_0036b378;

void func_00159ce0(u32 object,u32 destination)
{
  u32 source=func_0016c028(*(u32 *)(object+0x44));
  if(destination!=source) asm volatile("lq $8,0(%1); sq $8,0(%2)" : "=m"(*(Quad *)destination) : "r"(source), "r"(destination), "m"(*(Quad *)source) : "$8");
  register f32 *constant asm("$15")=&D_0036b378;
  asm("" : "+r"(constant));
  *(f32 *)(destination+4)-=*constant;
}
