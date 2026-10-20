#include "../common/types.h"

extern "C" u8 D_0032bae0[];
extern "C" u8* D_01c61af0;

u8* func_001947c0(s32 a, s32 b) {
    u8* result = 0;
    u8* defaults = D_0032bae0;
    if (a < 0) {
        a = defaults[1];
    }
    if (b < 0) {
        b = D_0032bae0[0];
    }
    if (b >= 0 && b < *(s32*)(D_01c61af0 + 4) && a >= 0) {
        u8* entry = D_01c61af0 + b * 4;
        if (a < *(u16*)(entry + 8)) {
            result = D_01c61af0 + *(u16*)(entry + 10) + a * 0x40;
        }
    }
    return result;
}
