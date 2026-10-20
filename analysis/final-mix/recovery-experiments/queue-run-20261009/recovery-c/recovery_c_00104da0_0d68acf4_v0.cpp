#include "../common/types.h"
extern "C" u8 D_003a7b00;
extern "C" s32 D_0032b96c;
extern "C" void func_001052a8(void),func_00104a48(void);
extern "C" u32 func_00102818(s32,s32,s32,void(*)(void),s32);
u32 func_00104da0(void){D_003a7b00=0;func_001052a8();return func_00102818(D_0032b96c,1,5000,func_00104a48,0x2000);}
