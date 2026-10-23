#include "../common/types.h"
extern "C" u32 func_003160e0(s32* first, s32* second, u32 payload, u32* output);

u32 func_00316110(u32* object, u32 first, u32 second, u32 third) {
    if (func_003160e0((s32*)object, (s32*)first, second, (u32*)third)) {
        return 1;
    }
    u32* child = *(u32**)((u8*)object + 8);
    u32* table = *(u32**)child;
    return ((u32 (*)(u32*, u32, u32, u32))(table[6]))(child, first, second, third);
}
