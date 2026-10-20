#include "../common/types.h"
extern "C" u8 D_003625e0;
extern "C" void func_002d0ea8(u32*,u64,u64,u64);
void func_002d9730(u32* object,u64 second,u64 third,u64 fourth)
{
 func_002d0ea8(object,second,third,fourth);
 register u32 one asm("$14")=1;
 object[0x2fc]=0;
 *(u8*)(object+0x301)=one;
 *object=(u32)&D_003625e0;
 asm ("sw $0,3060(%2)" : "+r"(one),"=m"(object[0x2fd]) : "r"(object),"m"(*object));
 *(u8*)(object+0x2ff)=one;
 object[0x300]=0;
 object[0x324]=0;
 object[0x325]=0;
 object[0x326]=0;
}
