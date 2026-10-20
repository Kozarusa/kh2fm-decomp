#include "../common/types.h"
extern "C" void func_001b1bb8(f32,u32,u32,u32,u32,u32);
void func_00174af8(const u32* object)
{
 register const u32* saved asm("$15")=object;
 asm("" : "+r"(saved));
 register u32 first asm("$4")=saved[0];
 register f32 scalar asm("$f12")=*(const f32*)(saved+4);
 asm("" : "+f"(scalar));
 func_001b1bb8(scalar,first,saved[1],saved[2],saved[3],0x80);
}
