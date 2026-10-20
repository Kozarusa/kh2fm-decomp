#include "../common/types.h"
struct __attribute__((aligned(16))) Quad { f32 value[4]; };
void func_00144570(f32 *destination,f32 *source)
{
  Quad temporary;
  asm("" : "+r"(source));
  if((void *)&temporary!=(void *)source)
    asm volatile("lq $8,0(%1); sq $8,%0" : "=m"(temporary) : "r"(source), "m"(*(Quad *)source) : "$8");
  f32 radius=source[4];
  f32 x=temporary.value[0],y=temporary.value[1],z=temporary.value[2];
  f32 px=x+radius,py=y+radius,pz=z+radius;
  f32 nx=x-radius,ny=y-radius,nz=z-radius;
  asm("" : "+f"(px), "+f"(py), "+f"(pz), "+f"(nx), "+f"(ny), "+f"(nz));
  destination[3]=px; destination[4]=py; destination[5]=pz;
  destination[0]=nx; destination[1]=ny; destination[2]=nz;
}
