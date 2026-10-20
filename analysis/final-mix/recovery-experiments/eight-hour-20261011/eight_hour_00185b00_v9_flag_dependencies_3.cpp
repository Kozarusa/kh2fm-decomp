#include "../common/types.h"
extern "C" u8 D_0034ed78;
extern "C" f32 D_0036c900;
extern "C" void func_001d7cd0(u32*,u64,u64);
extern "C" u32 func_0016a090(u32*);
void func_00185b00(u32* object,u64 second,u64 third)
{
 func_001d7cd0(object,second,third);
 register u32 table asm("$15")=(u32)&D_0034ed78;
 register u32 flags asm("$14")=object[0x162];
 asm("" : "+r"(table),"+r"(flags));
 *object=table;
 object[700]=0;
 asm ("ori %0,%0,0x10" : "+r"(flags) : "m"(*object),"m"(object[700]));
 object[0x162]=flags;
 register u32* receiver asm("$4");
 asm("daddu %0,%1,$0" : "=r"(receiver) : "r"(object),"m"(object[700]),"m"(*object),"m"(object[0x162]));
 register u32 high asm("$15");
 asm("lui %0,0x37" : "=r"(high) : "r"(receiver));
 register f32* scale asm("$15")=(f32*)(high+(-14080));
 asm("" : "+r"(scale));
 *(f32*)(object+0x2bd)=*scale;
 if(func_0016a090(receiver)==2)object[0x2af]|=0x8000;
}
