#include "../common/types.h"
extern "C" u32* D_01d49558;
extern "C" u8 D_00320c08;
extern "C" void func_002fd248(u64,u32*,u32,u32,u8*);
void func_001c2d48(u64 output)
{
 u32* record=D_01d49558;
 u8* callback=&D_00320c08;
 func_002fd248(output,record+2,record[1],8,callback);
}
