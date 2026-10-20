#include "../common/types.h"
struct __attribute__((aligned(16))) Quad { f32 value[4]; };
void func_00144570(f32 *destination,f32 *source)
{
  Quad temporary;
  asm("" : "+r"(source));
  if((void *)&temporary!=(void *)source)
    asm volatile("lq $8,0(%1); sq $8,%0" : "=m"(temporary) : "r"(source), "m"(*(Quad *)source) : "$8");
  register f32 radius asm("$f0")=source[4];
  register f32 x asm("$f1")=temporary.value[0];
  register f32 y asm("$f2")=temporary.value[1];
  register f32 z asm("$f3")=temporary.value[2];
  asm("" : "+f"(radius), "+f"(x), "+f"(y), "+f"(z));
  register f32 px asm("$f4")=x+radius;
  register f32 py asm("$f5")=y+radius;
  register f32 pz asm("$f6")=z+radius;
  x-=radius; y-=radius; z-=radius;
  asm("" : "+f"(px), "+f"(py), "+f"(pz), "+f"(x), "+f"(y), "+f"(z));
  destination[3]=px; destination[4]=py; destination[5]=pz;
  destination[0]=x; destination[1]=y; destination[2]=z;
}
