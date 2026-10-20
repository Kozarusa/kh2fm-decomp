#include "../common/types.h"
extern "C" s32 D_0035e370;
extern "C" s32 (*D_0035e380[])();

s32 func_00236148() { s32 (**table)() = D_0035e380; s32 index = D_0035e370; // why: original indirect call uses register 13.
register s32 (*callback)() asm("$13") = 0; callback = table[index]; return callback(); }
