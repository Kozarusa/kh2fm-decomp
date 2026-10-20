#include "../common/types.h"
extern "C" u8 D_00350ce0;
extern "C" f32 D_0036d858;
extern "C" void func_00185b00(u32*,u64,u64);
void func_001ae9a0(u32* object,u64 second,u64 third)
{
 func_00185b00(object,second,third);
 register u32 table asm("$15")=(u32)&D_00350ce0;
 register u32 flags asm("$14")=object[0x162];
 asm("" : "+r"(table),"+r"(flags));
 *object=table;
 asm("" : "+r"(flags) : "m"(*object));
 object[0x162]=flags|0x400;
 register u8* nested asm("$13")=(u8*)object+1648;
 asm("" : "+r"(nested));
 register f32* scale asm("$15")=&D_0036d858;
 asm("" : "+r"(scale) : "m"(*(u32*)(nested+264)));
 *(u32*)(nested+264)=0;
 *(f32*)(nested+260)=*scale;
 asm("" : "+r"(object) : "m"(*(f32*)(nested+260)));
 register u32 mode asm("$15")=object[0x2af];
 asm("" : "+r"(mode));
 object[0x2af]=mode|0x8404;
}
