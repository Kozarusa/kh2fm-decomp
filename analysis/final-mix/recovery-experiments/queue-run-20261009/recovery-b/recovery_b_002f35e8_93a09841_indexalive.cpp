#include "../common/types.h"
extern "C" void* D_00363c90[];
void* func_002f35e8(u32 a) { register u32 valid asm("$2")=a<10;asm("" : "+r"(valid) : "r"(a));if(valid){u32 input=a;asm("" : "+r"(input) : "r"(valid));return D_00363c90[(s32)input];}return 0; }
