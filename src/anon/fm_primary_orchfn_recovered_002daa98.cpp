#include "../common/types.h"
extern "C" u8 D_00362858[];
extern "C" void func_002cfeb0(u32, u32, u32, u32);
extern "C" s32 func_002cf280(u32*, u32, u32);

s32 func_002daa98(u32* object, u32 first, u32 second) {
    func_002cfeb0((u32)object, first, 3, second);
    object[0] = (u32)D_00362858;
    return func_002cf280(object + 700, 1, 0);
}
