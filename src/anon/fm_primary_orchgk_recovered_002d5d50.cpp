#include "../common/types.h"
extern "C" void func_002cfeb0(u32, u32, u32, u32);
extern "C" s32 func_002e7308(u32);
extern "C" u8 D_00362428[];

s32 func_002d5d50(u32 object, u32 value, u32 argument) {
    func_002cfeb0(object, value, 1, argument);
    *(u32*)object = (u32)D_00362428;
    return func_002e7308(object + 2872);
}
