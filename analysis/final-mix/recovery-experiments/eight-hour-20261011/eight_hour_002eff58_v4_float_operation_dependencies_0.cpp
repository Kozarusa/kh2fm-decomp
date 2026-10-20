#include "../common/types.h"
extern "C" f32 D_00376224;
bool func_002eff58(f32* object)
{
 register f32 first asm("$f1")=object[0x44];
 register f32* scale asm("$15")=&D_00376224;
 register f32 second asm("$f2")=object[0x45];
 asm("" : "+r"(scale));
 register f32 factor asm("$f0")=*scale;
 asm("add.s %0,%0,%1" : "+f"(first) : "f"(second),"f"(factor));
 register f32 limit asm("$f3")=object[7];
 asm("mul.s %0,%0,%1" : "+f"(first) : "f"(factor),"f"(limit));
 return first<=limit;
}
