#include "../common/types.h"
extern "C" void func_001b1be0(f32,u8*);
void func_001b1bb8(f32 scalar,u8* object,u32 first,u32 second,u32 third,u32 fourth)
{
 object[20]=(u8)first;
 register volatile u8* cursor asm("$15")=object+20;
 asm("" : "+r"(cursor));
 cursor[3]=(u8)fourth;cursor[1]=(u8)second;cursor[2]=(u8)third;
 func_001b1be0(scalar,object);
}
