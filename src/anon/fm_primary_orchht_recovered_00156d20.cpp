#include "../common/types.h"
extern "C" s32 func_00158290();
extern "C" s32 func_0013a7e8(s32);
extern "C" s32 func_0013d7e0();
extern "C" s32 func_00155f40(u8*);
extern "C" s32 func_00155fc0(u8*);
extern "C" u32 func_00138c10(u8*, s32);
extern "C" s32 func_00139c18(u8*);
extern "C" u32 func_001386e0(u8*, s32, s32, s32, s32, s32);
extern "C" u32 func_001396b0(u8*);
extern "C" u32 func_0031a260(u8*, s32);

u32 func_00156d20(u8* object) {
    s32 group = func_00158290();
    s32 square = func_0013a7e8(1);
    s32 image = func_0013d7e0();
    func_00138c10(object + 0x2d80, func_00155f40(object));
    u32 result = func_00138c10(object + 0x2f1c, func_00155fc0(object));
    object[0x3cf6] = 1;
    if (object[0x3cfb] != 1) {
        return result;
    }
    s32 index = func_00139c18(object + 0x1054);
    u8* select = object + index * 0x198 + 0x1054;
    func_001386e0(select, 7000, square, image, 53, group);
    *(u8**)(select + 0x18c) = object + 0x2d80;
    result = func_001396b0(select);
    if (*(s32*)(select + 0x18c) == 0) {
        return result;
    }
    *(s32*)(select + 0x190) = 0;
    result = func_001396b0(select);
    if (*(s32*)(select + 0x190) == 0) {
        return result;
    }
    return func_0031a260(select, 0);
}
