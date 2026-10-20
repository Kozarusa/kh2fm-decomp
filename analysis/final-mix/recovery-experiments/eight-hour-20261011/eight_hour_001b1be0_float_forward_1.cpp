#include "../common/types.h"
extern "C" f32 D_0036d9a0;
extern "C" void func_001ad990(f32,f32,f32,u8*);
void func_001b1be0(f32 scalar,u8* object)
{
 register const f32* limit asm("$15")=&D_0036d9a0;asm("" : "+r"(limit));
 func_001ad990(0.0f,*limit,scalar,object+8);
}
