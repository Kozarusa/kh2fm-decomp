#include "../common/types.h"
extern "C" u32 func_0019a1a0(s32, s64);
extern "C" u32 func_0019ae60(s32);

void func_00172a80(s32* param) {
    s32 object = *(s32*)(*(s32*)(*param + 4) + 0x818);
    if (object != 0 && (u8)(*(u32*)(object + 4) & 1) == 0) {
        func_0019ae60(object);
        func_0019a1a0(object, 0);
    }
}