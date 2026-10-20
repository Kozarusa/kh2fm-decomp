#include "../common/types.h"
extern "C" u32* D_01d49558;
extern "C" u8 D_00320c08;
extern "C" void func_002fd248(u64,u32*,u32,u32,u8*);
void func_001c2d48(u64 output)
{
 register u32* record asm("$5")=D_01d49558;
 register u8* callback asm("$8")=&D_00320c08;
 asm("" : "+r"(record),"+r"(callback));
 func_002fd248(output,record+2,record[1],8,callback);
}
