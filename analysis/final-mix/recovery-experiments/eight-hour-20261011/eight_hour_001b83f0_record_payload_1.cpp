#include "../common/types.h"
extern "C" u32* D_01d48cc4;
extern "C" u8 D_00320408;
extern "C" void func_002fd248(u64,u32*,u32,u32,u8*);
void func_001b83f0(u64 output)
{
 register u32* record asm("$5")=D_01d48cc4;
 register u8* callback asm("$8")=&D_00320408;
 asm("" : "+r"(record),"+r"(callback));
 func_002fd248(output,record+2,record[1],8,callback);
}
