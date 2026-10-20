#include "../common/types.h"
extern "C" u8 D_0036cea0[];

u8* func_00192388(u8* text) {
    u32 ch = *text;
    if (ch < 32) {
        if (ch == 0) {
            return 0;
        }
        text = text + D_0036cea0[ch];
        return text;
    }
    text = text + 1;
    return text;
}