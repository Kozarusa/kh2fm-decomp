#include "../common/types.h"
extern "C" void func_001b1bb8(f32,u32,u32,u32,u32,u32);
void func_00174af8(const u32* object)
{
 register const u32* saved asm("$15")=object;
 register u32 first asm("$4")=saved[0];
 asm("" : "+r"(saved) : "r"(first));
 f32 scalar=*(const f32*)(saved+4);
 asm("" : "+r"(saved) : "f"(scalar));
 u32 second=saved[1];
 asm("" : "+r"(saved) : "r"(second));
 u32 third=saved[2];
 asm("" : "+r"(saved) : "r"(third));
 u32 fourth=saved[3];
 func_001b1bb8(scalar,first,second,third,fourth,0x80);
}
