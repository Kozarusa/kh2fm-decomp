#include "../common/types.h"
extern "C" s32 D_0035e370;
extern "C" s32 (*D_0035e380[])();
s32 func_00236148() { s32 (**table)() = D_0035e380; s32 index = D_0035e370; return table[index](); }
