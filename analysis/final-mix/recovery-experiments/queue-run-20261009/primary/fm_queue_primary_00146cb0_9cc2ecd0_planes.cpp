#include "../common/types.h"
// Return zero upon the first nonnegative ordered projection; return one only
// after all five planes and eight points pass the original negative tests.
s32 func_00146cb0(const f32* planes,const f32* points)
{
 register f32 zero asm("$f2")=0.0f;
 asm("" : "+f"(zero));
 register s32 planeIndex asm("$11")=0;
 asm("" : "+r"(planeIndex));
 register u32 planeAddress asm("$4")=(u32)planes;
 do {
  register f32 offset asm("$f1")=*(f32*)(planeAddress+12);
  register s32 pointIndex asm("$13")=0;
  register u32 currentPlane asm("$12")=planeAddress;
  register u32 pointAddress asm("$15")=(u32)points;
  do {
   register f32 dot asm("$f0");
   asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vmul.xyz $vf1,$vf1,$vf2; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; qmfc2 $8,$vf1; mtc1 $8,%0"
                : "=f"(dot) : "r"(pointAddress),"r"(currentPlane),"r"(pointIndex),"r"(planeIndex) : "$8","memory");
   dot+=offset;
   ++pointIndex; pointAddress+=16;
   if(zero<=dot) return 0;
  } while(pointIndex<8);
  ++planeIndex; planeAddress+=16;
 } while(planeIndex<5);
 return 1;
}
