#include "../common/types.h"
extern "C" s32 D_0033caf0;
extern "C" u8 D_004f63d8[];
extern "C" u8 D_0036c450[];
extern "C" u32 func_002fee78(u8*, u8*, u8*, s32);

u8* func_0016f4b8(u8* object, u8* buffer) {
    u8* result = 0;
    u32 value = object[0x48];
    value = value ^ 1u;
    value = value & 1u;
    if (value) {
        u8* pointer = buffer;
        if (buffer == 0) {
            pointer = D_004f63d8;
        }
        func_002fee78(pointer, D_0036c450, object + 8, D_0033caf0);
        result = pointer;
    }
    return result;
}
