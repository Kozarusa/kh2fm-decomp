#include "../common/types.h"
extern "C" u8* D_0035ec94;
s32 func_00241a00() {
 register s32 result asm("$2")=0; // why: original initializes return value in v0
 s32 count=0;
 register u32* pointer asm("$14")=(u32*)(D_0035ec94+8); // why: original cursor uses t6
 asm("" : "+r"(pointer)); // why: preserve cursor increment before read
 u32 value=*pointer;
 while (1) {
 pointer+=8;
 if (value&16) return 1;
 ++count;
 if (count>=99) break;
 value=*pointer;
 }
 return result;
}



