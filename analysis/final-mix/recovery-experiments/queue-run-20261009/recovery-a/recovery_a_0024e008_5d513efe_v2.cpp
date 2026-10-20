#include "../common/types.h"
extern "C" s32 D_0035edf4;
extern "C" char D_00372160;
extern "C" char D_00372178;
extern "C" void func_0024dfe0(u32);
u32 func_0024e008(u32 param_1) {
 func_0024dfe0(param_1);
 u32 scaled = param_1*6;
 u32 result;
 if(D_0035edf4 == 0) result = scaled+(s32)(long)&D_00372178;
 else result = scaled+(s32)(long)&D_00372160;
 return result;
}
