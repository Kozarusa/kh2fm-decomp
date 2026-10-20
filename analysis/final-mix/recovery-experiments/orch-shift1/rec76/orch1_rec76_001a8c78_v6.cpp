#include "../common/types.h"
extern "C" u32 func_001c9db0(s32);

s32 func_001a8c78(u8* base, s32 index) {
    s32 result = 0;
    u8 byte = *(volatile u8*)(base + index);
    u8 kind = byte & 0x1f;
    if (index == 0 || (byte & 0x80) != 0 || func_001c9db0(kind) != 0) {
        result = 1;
    }
    return result;
}