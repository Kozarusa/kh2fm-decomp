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
 register f32* block asm("$14")=(f32*)(object+0x300);
 asm("" : "+r"(block));
 register f32 copied asm("$f1")=*(volatile f32*)(object+0x2fc);
 asm("" : "+f"(copied) : "r"(block));
 block[3]=copied;
 block[1]=copied;
 block[2]=copied;
 register f32* scale asm("$15")=&D_00375af0;
 asm("" : "+r"(scale));
 object[0x30d]=0;
 *(f32*)(object+0x304)=*scale;
 *(f32*)(object+0x300)=copied;
 object[0x307]=0;
 object[0x306]=0;
 object[0x305]=0;
 object[0x30c]=0;
}
