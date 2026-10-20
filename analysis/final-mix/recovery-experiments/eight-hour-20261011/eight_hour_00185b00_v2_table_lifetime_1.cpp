#include "../common/types.h"
extern "C" u8 D_0034ed78;
extern "C" f32 D_0036c900;
extern "C" void func_001d7cd0(u32*,u64,u64);
extern "C" u32 func_0016a090(u32*);
void func_00185b00(u32* object,u64 second,u64 third)
{
 func_001d7cd0(object,second,third);
 register u32 table asm("$15")=(u32)&D_0034ed78;
 asm("" : "+r"(table) : "m"(object[700]));
 object[700]=0;
 *(volatile u32*)object=table;
 object[0x162]|=0x10;
 register f32* scale asm("$15")=&D_0036c900;
 asm("" : "+r"(scale));
 *(f32*)(object+0x2bd)=*scale;
 if(func_0016a090(object)==2)object[0x2af]|=0x8000;
}
