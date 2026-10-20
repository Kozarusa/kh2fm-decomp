#include "../common/types.h"
extern "C" u32 func_00321728(s32,u32,u8);
extern "C" void func_001d4f40(u32,u16);
void func_001d4ef0(u32 p,u8* q) { u32 object=func_00321728(p+0x38,1,*q);
register u32 byte asm("$6")=*(u8*)(object+1);
register u32 incremented asm("$15"); asm("addiu %0,%1,1" : "=r"(incremented) : "r"(byte)); *(u8*)(object+1)=incremented;
func_001d4f40(p,*(u16*)(q+0x42)); }
