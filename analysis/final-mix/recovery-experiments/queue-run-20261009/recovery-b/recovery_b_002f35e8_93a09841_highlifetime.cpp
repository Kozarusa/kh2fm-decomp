#include "../common/types.h"
void* func_002f35e8(u32 a) { register u32 valid asm("$2")=a<10;asm("" : "+r"(valid) : "r"(a));if(valid){register u8* base asm("$2");asm("lui %0,0x36" : "=r"(base));register u32 offset asm("$3")=a*4;asm("" : "+r"(offset) : "r"(base));base+=0x3c90;asm("" : "+r"(base));return *(void**)(base+offset);}return 0; }
