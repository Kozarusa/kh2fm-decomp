#include "../common/types.h"
void func_0023e738(u32 object,u32 index,u32 firstWord,u32 secondWord)
{
 register u32 indexed asm("$5")=index*2+object;
 register s32 first asm("$6")=(s16)firstWord;register s32 second asm("$7")=(s16)secondWord;
 asm("" : "+r"(first),"+r"(second));
 register u32 pair asm("$15")=indexed+0xb70;
 asm("" : "+r"(pair),"+r"(indexed) : "r"(first),"r"(second));
 *(s16*)(indexed+0xb70)=first;*(s16*)(pair+8)=second;
}
