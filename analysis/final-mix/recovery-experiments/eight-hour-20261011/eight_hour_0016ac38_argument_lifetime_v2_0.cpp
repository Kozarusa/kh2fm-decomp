#include "../common/types.h"
extern "C" u64 func_001de168(u8*,u64,u64,s32,u64,u8*);
u64 func_0016ac38(u8*object,u64 second,u64 third,u64 fourth,u8*fallback){register u8*target asm("$9")=fallback?fallback:object;asm("":"+r"(target));if(*(u32*)(object+128))return func_001de168(object+128,second,third,1,fourth,target);return 0;}

