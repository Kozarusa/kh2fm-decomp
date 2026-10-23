#include "../common/types.h"

extern "C" s32 func_00239700(u32);
extern "C" char D_0034a618;
extern "C" char D_00347e60;

s32 func_0031bf50(u32* object) {
    s32 result;
    u32* cursor;
    s32 count;
    object[0] = (u32)(long)&D_0034a618;
    object[0xc] = (u32)(long)&D_00347e60;
    cursor = object + 0x72;
    count = 6;
    object[3] = 0;
    object[0xf] = 0;
    func_00239700((u32)(long)(object + 0x12));
    do {
        count = count - 1;
        result = func_00239700((u32)(long)cursor);
        cursor = cursor + 0x56;
    } while (count != -1);
    return result;
}
