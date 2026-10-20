#include "../common/types.h"
extern "C" u8 func_0013ef80();
extern "C" u32 func_0014aba8();

bool func_00197c28(u32 object) {
    s32 type = *(u8*)(*(u32*)(object + 0x3c) + 1);
    if (type != 0) {
        if (type < 3) {
            u32 fade = func_0014aba8();
            return *(s32*)(fade + 0xfc) != 4;
        }
        if (type == 3) {
            u8 result = func_0013ef80();
            return result ^ 1;
        }
    }
    return false;
}