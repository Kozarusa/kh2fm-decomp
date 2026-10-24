#include "../common/types.h"
extern "C" u32 func_001ab800(...);
extern "C" u32 func_00236788(...);
extern "C" u32 func_0023bc58(...);
extern "C" u32 func_0023acd8(...);
extern "C" u32 func_0023ade0(...);
extern "C" u32 func_001ac108(...);
extern "C" u32 func_001ac6d0(...);
extern "C" u32 func_001abf38(...);
extern "C" u32 func_00239bf8(...);
extern "C" u32 func_002367a0(...);

u32 func_001acdc0(u8* object, s32 x, s32 y, s32 width, s32 height, s32 font) {
    func_00236788(func_001ab800());
    if (font == 0) {
        font = *(s32*)(object + 92);
    }
    u8* text = object + 132;
    func_0023bc58(text, font, *(s32*)(object + 96));
    func_0023acd8(text);
    *(s32*)(text + 328) = x;
    *(s32*)(text + 332) = y;
    func_0023ade0(text);
    if (*(s32*)(object + 112) > 0) {
        func_001ac108(object + 1196, x, y, *(s32*)(object + 92), *(s32*)(object + 96));
    }
    if ((u32)(*(s32*)(object + 112) - 1) < 5) {
        func_001ac6d0(object);
        if (*(s32*)(object + 112) >= 2) {
            func_001abf38(object + 480, width, height);
        }
        s32 index;
        for (index = 0; index < *(s32*)(object + 2920); index++) {
            func_0023acd8(object + 1544 + index * 344);
            func_0023ade0(object + 1544 + index * 344);
        }
        for (index = *(s32*)(object + 2920); index < 4; index++) {
            func_00239bf8(object + 1544 + index * 344, 0);
        }
        *(s32*)(object + 2920) = 0;
    }
    func_001ab800();
    return func_002367a0();
}
