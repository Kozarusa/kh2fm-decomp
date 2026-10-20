#include "../common/types.h"
extern "C" f32 D_0036d9a0;
extern "C" void func_001ad990(f32,f32,f32,u8*);
void func_001b1be0(f32 scalar,u8* object)
{
 register const f32* limit asm("$15")=&D_0036d9a0;asm("" : "+r"(limit));
 register f32 bound asm("$f13")=*limit;
 asm("" : "+f"(bound));
 func_001ad990(0.0f,bound,scalar,object+8);
}
