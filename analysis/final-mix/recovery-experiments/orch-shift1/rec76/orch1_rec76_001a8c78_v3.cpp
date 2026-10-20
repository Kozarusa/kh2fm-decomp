#include "../common/types.h"
extern "C" u32 func_001c9db0(s32);

s32 func_001a8c78(u8* base, s32 index) {
    if (index != 0) {
        u8 byte = base[index];
        if ((byte & 0x80) == 0) {
            u8 kind = byte & 0x1f;
            if (func_001c9db0(kind) == 0) {
                return 0;
            }
        }
    }
    return 1;
}