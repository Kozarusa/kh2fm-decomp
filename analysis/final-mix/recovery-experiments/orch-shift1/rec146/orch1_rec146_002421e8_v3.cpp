#include "../common/types.h"
extern "C" s32 D_0035ecb8;
extern "C" s64 func_002efa40(s32);
s32 func_002421e8(u8* object) {
 register s32 result asm("$16")=0; // why: original preserves result in s0 across call
 asm("" : "+r"(result)); // why: original initializes s0 before call
 if (func_002efa40(*(s32*)(object+4))) result=1;
 else { u8 flag=D_0035ecb8&1; if (flag) result=1; }
 return result;
}


