#include "../common/types.h"
extern "C" u8* D_01d48cb0;
extern "C" s32 func_0016cfa0(s32, s32, s32, s32, s32);

s32 func_001b58b8(s32 a, s32 b, s32 c) {
    return func_0016cfa0(*(s32*)(D_01d48cb0 + 0x34), 0, a, b, c);
}
