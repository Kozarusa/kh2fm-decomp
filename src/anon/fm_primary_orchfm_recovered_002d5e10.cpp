#include "../common/types.h"
extern "C" void func_002e7328(u32);
extern "C" void func_002cff98(u32);
extern "C" s32 func_00105110(u32);
extern "C" u8 D_00362428[];

s32 func_002d5e10(u32 object) {
    *(u32*)object = (u32)(long)D_00362428;
    func_002e7328(object + 2872);
    func_002cff98(object);
    return func_00105110(object);
}
