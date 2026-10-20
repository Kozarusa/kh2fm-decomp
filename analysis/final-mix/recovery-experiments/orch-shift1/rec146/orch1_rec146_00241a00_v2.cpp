#include "../common/types.h"
extern "C" u8* D_0035ec94;
s32 func_00241a00() {
 register s32 result asm("$2")=0; // why: original initializes return value in v0
 s32 count=0;
 u32* pointer=(u32*)(D_0035ec94+8);
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

