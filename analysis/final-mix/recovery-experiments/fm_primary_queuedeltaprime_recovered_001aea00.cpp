#include "../common/types.h"
extern "C" u8 D_00350ce0;
extern "C" f32 D_0036d85c;
extern "C" void func_00185b00(u32*,u64,u64);

void func_001aea00(u32* object,u64 second,u64 third)
{
 func_00185b00(object,second,third);
 register u32 table asm("$15")=(u32)&D_00350ce0;
 register u32 flags asm("$14")=object[0x162];
 asm("" : "+r"(table),"+r"(flags));
 *object=table;
 asm("ori %0,%0,0x400" : "+r"(flags) : "m"(*object));
 object[0x162]=flags;
 register u8* nested asm("$13");
 asm("addiu %0,%1,1648" : "=r"(nested) : "r"(object),"m"(object[0x162]));
 register u32 high asm("$15");
 asm ("lui %0,0x37" : "=r"(high) : "r"(nested),"m"(object[0x162]));
 register f32* scale asm("$15")=(f32*)(high+(-10148));
 asm("" : "+r"(scale) : "m"(*(f32*)(nested+264)));
 *(f32*)(nested+264)=0.0f;
 *(f32*)(nested+260)=*scale;
 asm("" : "+r"(object) : "m"(*(f32*)(nested+260)));
 register u32 mode asm("$15")=object[0x2af];
 asm("" : "+r"(mode));
 object[0x2af]=mode|0x8404;
}
