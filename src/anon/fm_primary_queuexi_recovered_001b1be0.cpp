#include "../common/types.h"
extern "C" void func_001ad990(f32,f32,f32,u8*);

void func_001b1be0(f32 scalar,u8* object)
{

 register f32 bound asm("$f13")=1.0f;
 asm("" : "+f"(bound));
 func_001ad990(0.0f,bound,scalar,object+8);
}
