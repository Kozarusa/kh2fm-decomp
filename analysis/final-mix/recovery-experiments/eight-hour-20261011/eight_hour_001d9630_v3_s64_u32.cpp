#include "../common/types.h"
extern "C" s64 func_001a3188(u32,s32,s32);
void func_001d9630(u16* p,s32 n) { if(n<=0) return; s32 count=n; do { if(*p) { func_001a3188(*p,100,0); *p=0; } --count; ++p; } while(count); }
