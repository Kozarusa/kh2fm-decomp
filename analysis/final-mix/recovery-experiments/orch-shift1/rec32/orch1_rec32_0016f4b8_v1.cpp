#include "../common/types.h"
extern "C" s32 D_0033caf0;
extern "C" u8 D_004f63d8[];
extern "C" u8 D_0036c450[];
extern "C" u32 func_002fee78(u8*, u8*, u8*, s32);

u8* func_0016f4b8(u8* object, u8* buffer) {
    u8* result = 0;
    if (((object[0x48] ^ 1) & 1) != 0) {
        result = buffer;
        if (buffer == 0) {
            result = D_004f63d8;
        }
        func_002fee78(result, D_0036c450, object + 8, D_0033caf0);
    }
    return result;
}