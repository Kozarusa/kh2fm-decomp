#include "../common/types.h"
extern "C" s32 D_0034a7d8[];
extern "C" s32 D_0034a7e8[];
extern "C" u8* func_0013d7e0();
extern "C" s32 func_00236490(u8*);
extern "C" s32 func_002364f8(u8*);

s32 func_00154100(u8* object, s32* width, s32* height) {
    s32 index;
    u8* image;
    s32 result;
    *width = 0;
    index = 0;
    *height = 0;
    if (*(s32*)(object + 832) > 0) {
        do {
            *width += D_0034a7d8[index];
            *height += D_0034a7e8[index];
            index++;
        } while (index < *(s32*)(object + 832));
    }
    image = func_0013d7e0();
    *width += func_00236490(image) + 0x3500;
    result = func_002364f8(image);
    *height += result + 0x2800;
    return result;
}
