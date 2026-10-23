#include "../common/types.h"
extern "C" void func_002d2948(u32, u32, u32, u32);
extern "C" s32 func_002e7308(u32);
extern "C" u8 D_003621a0[];

s32 func_002d4200(u32 object, u32 entry, u32 vector) {
    func_002d2948(object, entry, 1, vector);
    *(u32*)object = (u32)(long)D_003621a0;
    return func_002e7308(object + 3208);
}
