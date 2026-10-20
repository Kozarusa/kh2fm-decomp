#include "../common/types.h"

extern "C" u8 D_01e22040[];
extern "C" s32 D_01e21f40;
extern "C" s32 func_003094b8(u8*, s32, s32, s32*, s32, s32*, s32, s32, s32);

s32 func_002b84b8()
{
    s32 result;
    do {
        result = func_003094b8(D_01e22040, 4, 0, &D_01e21f40, 0x100,
                               &D_01e21f40, 0x100, 0, 0);
    } while (result != 0);
    return D_01e21f40;
}
