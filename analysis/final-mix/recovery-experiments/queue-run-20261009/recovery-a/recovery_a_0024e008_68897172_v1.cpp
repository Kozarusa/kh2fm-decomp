#include "../common/types.h"
extern "C" s32 D_0035edf4;
extern "C" char D_00372160;
extern "C" char D_00372178;
extern "C" void func_0024dfe0(u32);
u32 func_0024e008(u32 param_1) {
 func_0024dfe0(param_1);
 register u32 scaled asm("$13") = param_1*6;
 asm volatile ("" : "+r"(scaled));
 u32 result = scaled+(s32)(long)&D_00372160;
 register s32 flag asm("$12") = D_0035edf4;
 asm volatile ("" : "+r"(flag));
 if(flag != 0) result = scaled+(s32)(long)&D_00372178;
 return result;
}
