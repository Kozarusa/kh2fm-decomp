#include "../common/types.h"
// Complete original-memory/register recovery proposal.
typedef void (*Call)(u32,u32);

void func_0018f218(u32* object) { u32 first=object[0]; u32 argument=object[1]; u32 child=*(u32*)(first+4); register u32 table asm("$14")=*(u32*)child; asm("" : "+r"(table)); (*(Call*)(table+0x68))(child,argument); asm volatile(""); }
