#include "../common/types.h"
extern "C" void* D_00363c90[];
void* func_002f35e8(u32 a) { if(a<10){register void**base asm("$2")=D_00363c90;asm("" : "+r"(base));return base[(s32)a];}return 0; }
