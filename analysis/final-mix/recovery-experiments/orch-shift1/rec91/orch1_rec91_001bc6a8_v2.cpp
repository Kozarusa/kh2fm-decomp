#include "../common/types.h"
extern "C" u8 func_001bc2a8(u16*, u32, u32);

void func_001bc6a8(u8* object, u16* source, u32 arg2, u32 arg3, u32 flag) {
    *(u16*)(object + 2) = *source;
    object[4] = flag;
    u8 result = func_001bc2a8(source, arg2, arg3);
    *(u32*)(object + 8) = arg3;
    object[5] = result;
    *(u16*)object = 0;
}
