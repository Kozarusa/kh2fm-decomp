#include "../common/types.h"
extern "C" u16 func_001a67b0(s32);
extern "C" u32 func_001a80c8(...);

u32 func_001a3820() {
    u8* command = (u8*)func_001a80c8();
    u32 type = command[2];
    u32 result;
    if (type == 0) {
        result = *(u16*)(command + 16);
    } else {
        if (type == 18) {
            return func_001a67b0(*(u16*)(command + 4));
        }
        result = 0;
    }
    return result;
}