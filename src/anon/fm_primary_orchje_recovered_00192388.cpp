#include "../common/types.h"
extern "C" u8 D_0036cea0[];

u8* func_00192388(u8* text) {
    u8* result;
    u32 ch = *text;
    if (ch < 32) goto control;
    text += 1;
    goto advance;
control:
    result = 0;
    if (ch == 0) goto done;
    text += D_0036cea0[ch];
advance:
    result = text;
done:
    return result;
}
