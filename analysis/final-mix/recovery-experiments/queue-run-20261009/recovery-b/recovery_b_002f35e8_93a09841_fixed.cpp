#include "../common/types.h"
extern "C" void* D_00363c90[];
void* func_002f35e8(u32 a) { register u32 valid asm("$2")=a<10;asm("" : "+r"(valid));if(valid){register u32 offset asm("$3")=a*4;asm("" : "+r"(offset)); register u8* base asm("$2")=(u8*)D_00363c90;asm("" : "+r"(base));return *(void**)(base+offset);}return 0; }
