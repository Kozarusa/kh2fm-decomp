#include "../common/types.h"
extern "C" f32 D_0036c558;
extern "C" f32 D_0036c55c;
extern "C" f32 D_0036c560;
extern "C" f32 func_002f8aa0(f32);
// Preserve the dot-product clamps and defer the interior case to the original
// symbolic scalar helper, including the original unordered comparison path.
f32 func_0017d160(const f32* first,const f32* second)
{
 register f32 dot asm("$f12");
 asm volatile("lqc2 $vf1,0(%1); lqc2 $vf2,0(%2); vmul.xyz $vf1,$vf1,$vf2; vaddy.x $vf1,$vf1,$vf1y; vaddz.x $vf1,$vf1,$vf1z; qmfc2 $8,$vf1; mtc1 $8,%0"
              : "=f"(dot) : "r"(first),"r"(second) : "$8","memory");
 register f32 result asm("$f0");
 register const f32* lower asm("$15")=&D_0036c558;
 asm("" : "+r"(lower));
 f32 threshold=*lower;
 if(threshold<=dot) {result=0.0f;goto finish;}
 asm volatile("" : : : "$15","memory");
 register const f32* upper asm("$15")=&D_0036c55c;
 asm("" : "+r"(upper));
 threshold=*upper;
 if(dot<=threshold) {
 register const f32* limit asm("$15")=&D_0036c560;
 asm("" : "+r"(limit));
 result=*limit;goto finish;
 }
 return func_002f8aa0(dot);
 finish: return result;
}
