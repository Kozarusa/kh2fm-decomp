#include "../common/types.h"
extern "C" bool func_001bb4b0(void);
extern "C" u32 func_001bbcb0(void);
extern "C" u32 func_001d8718(s32,s32);
void func_001d86a0(u32 p,u32 i) {
if(func_001bb4b0()) {
register u32 a asm("$2")=func_001bbcb0();
register s32 offset asm("$14")=(s32)i*0x38;
a+=offset;
asm("" : "+r"(a));
if((*(u32*)(a+0xf4)&1)!=0) {func_001d8718(p,i);return;}
}
}
