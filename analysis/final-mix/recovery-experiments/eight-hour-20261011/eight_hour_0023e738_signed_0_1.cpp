#include "../common/types.h"
void func_0023e738(u32 object,u32 index,s16 first,s16 second)
{
 register u32 indexed asm("$5")=object+index*2;
 register u32 pair asm("$15")=indexed+0xb70;
 asm("" : "+r"(pair));
 *(s16*)(indexed+0xb70)=first;*(s16*)(pair+8)=second;
}
