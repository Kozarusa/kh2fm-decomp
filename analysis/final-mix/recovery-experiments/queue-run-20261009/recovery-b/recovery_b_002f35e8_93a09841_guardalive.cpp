#include "../common/types.h"
extern "C" void* D_00363c90[];
void* func_002f35e8(u32 a) { register u32 valid asm("$2")=a<10;asm("" : "+r"(valid) : "r"(a));if(valid){register void**base asm("$2")=D_00363c90;return base[(s32)a];}return 0; }
