#include "../common/types.h"
extern "C" u32* D_01d48cc4;
extern "C" u8 D_00320408;
extern "C" void func_002fd248(u64,u32*,u32,u32,u8*);

void func_001b83f0(u64 output)
{
 u32* record=D_01d48cc4;
 u8* callback=&D_00320408;
 func_002fd248(output,record+2,record[1],8,callback);
}
