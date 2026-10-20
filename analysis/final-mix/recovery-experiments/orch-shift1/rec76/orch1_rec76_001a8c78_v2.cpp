#include "../common/types.h"
extern "C" u32 func_001c9db0(s32);

s32 func_001a8c78(u8* base, s32 index) {
    s32 result = 0;
    if (index != 0) {
        u8 byte = base[index];
        u8 kind = byte & 0x1f;
        if ((byte & 0x80) == 0) {
            if (func_001c9db0(kind) == 0) {
                return result;
            }
        }
        result = 1;
    }
    return result;
}