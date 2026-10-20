#include "../common/types.h"
extern "C" u8 D_0036cea0[];

u8* func_00192388(u8* text) {
    u32 ch = *text;
    u8* result;
    if (ch < 32) {
        result = 0;
        if (ch != 0) {
            text += D_0036cea0[ch];
            result = text;
        }
    } else {
        text += 1;
        result = text;
    }
    return result;
}