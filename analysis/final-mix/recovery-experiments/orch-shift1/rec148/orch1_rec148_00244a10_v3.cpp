#include "../common/types.h"
extern "C" s32 func_001d56c8(...);
extern "C" u32 func_00276c18(...);
s32 func_00244a10() {
 register s32 result asm("$16")=0; // why: original persistent result occupies s0
 asm("" : "+r"(result)); // why: keeps initial zero live before calls
 u8* pointer=(u8*)func_001d56c8(8);
 if(*pointer>=2) result=1;
 else if(func_00276c18()) result=1;
 return result;
}


