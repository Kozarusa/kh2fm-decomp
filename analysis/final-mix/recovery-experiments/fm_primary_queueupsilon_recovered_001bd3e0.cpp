#include "../common/types.h"
extern "C" s32 func_001bd418(u32);

s32 func_001bd3e0(u32 object)
{
 register u32 mask asm("$14")=0x02000000;
 u32 child=*(u32*)(object+2528);
 if(*(u32*)(child+1416)&mask)return 0;
 return func_001bd418(object);
}
