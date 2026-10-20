#include "../common/types.h"
extern "C" u8 D_003622c0;
extern "C" f32 D_00375af0;
extern "C" void func_002d0ea8(u32*,u64,u64,u64);
void func_002d49c0(u32* object,u64 second,u64 third,u64 fourth)
{
 func_002d0ea8(object,second,third,fourth);
 register u32 table asm("$15")=(u32)&D_003622c0;
 asm("" : "+r"(table));
 *(f32*)(object+0x2fc)=0.0f;
 *object=table;
 asm("" : "+r"(object) : "m"(*object));
 register f32* block asm("$14");
 asm("addiu %0,%1,3072" : "=r"(block) : "r"(object),"m"(*object));
 register f32 copied asm("$f1");
 asm ("lwc1 %0,%2" : "=f"(copied) : "r"(block),"m"(*(f32*)(object+0x2fc)));
 register u32 high asm("$15");
 asm("lui %0,0x37" : "=r"(high) : "f"(copied));
 register f32* scale asm("$15")=(f32*)(high+0x5af0);
 asm("" : "+r"(scale));
 ((volatile f32*)block)[3]=copied;
 ((volatile f32*)block)[1]=copied;
 ((volatile f32*)block)[2]=copied;
 register f32 value asm("$f0")=*(volatile f32*)scale;
 *(u32*)(object+0x30d)=0;
 *(f32*)(object+0x304)=value;
 *(f32*)(object+0x300)=copied;
 *(u32*)(object+773)=0;
 *(u32*)(object+774)=0;
 *(u32*)(object+775)=0;
 *(u32*)(object+780)=0;
}
