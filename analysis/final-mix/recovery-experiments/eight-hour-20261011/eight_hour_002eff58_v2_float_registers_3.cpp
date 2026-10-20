#include "../common/types.h"
extern "C" f32 D_00376224;
bool func_002eff58(f32* object)
{
 register f32 first asm("$f1")=object[0x44];
 register f32* scale asm("$15")=&D_00376224;
 register f32 second asm("$f2")=object[0x45];
 asm("" : "+f"(first),"+r"(scale),"+f"(second));
 register f32 factor asm("$f0")=*scale;
 asm("" : "+f"(factor),"+f"(first),"+f"(second));
 first+=second;
 register f32 limit asm("$f3")=object[7];
 asm("" : "+f"(first),"+f"(limit));
 return first*factor<=limit;
}
