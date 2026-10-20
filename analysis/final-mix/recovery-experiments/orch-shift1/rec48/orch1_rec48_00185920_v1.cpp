#include "../common/types.h"
extern "C" u8* D_01c6088c;
extern "C" u8 D_01c60890[];
extern "C" u8 D_0036c8f0[];
extern "C" u32 func_002fee78(...);

u8* func_00185920(s32 row, s32 column, u8* buffer) {
    u8* result = 0;
    s8* entry = (s8*)(column * 32 + D_01c6088c + row * 64);
    if (*entry != 0) {
        result = buffer;
        if (buffer == 0) {
            result = D_01c60890;
        }
        func_002fee78(result, D_0036c8f0, entry);
    }
    return result;
}
