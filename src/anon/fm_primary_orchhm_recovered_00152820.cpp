#include "../common/types.h"
extern "C" u32 func_0023a918(s32);
extern "C" u64 func_0023a9c0(...);
extern "C" u32 func_0023aa98(...);

s32 func_00152820(u8* object, s32* outX, s32* outY, s32* baseX, s32* baseY, u32* color) {
    u8* sequence = object + 24;
    s32 x;
    s32 y;
    x = 0;
    y = 0;
    func_0023a9c0(sequence, &x, &y);
    *color = *(u32*)(object + 420);
    u32 rgba = func_0023a918((s32)sequence);
    *color = (*color & 0xffffff) | (rgba & 0xff000000);
    *outX = *(s32*)(object + 368) + x;
    *outY = *(s32*)(object + 372) + y;
    s32 result = func_0023aa98(sequence);
    *baseX = *outX + result;
    *baseY = *outY;
    return result;
}
