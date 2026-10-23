#include "../common/types.h"
extern "C" u8 func_0013ef80();
extern "C" u32 func_0014aba8();

u8 func_00197c28(u32* object) {
    u8* info = (u8*)object[15];
    s32 type = info[1];
    switch (type) {
    case 1:
    case 2: {
        u32 fade = func_0014aba8();
        return *(s32*)(fade + 0xfc) != 4;
    }
    case 3: {
        u8 result = func_0013ef80();
        return result ^ 1;
    }
    default:
        return 0;
    }
}
