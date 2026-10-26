#include "../common/types.h"
extern "C" u8 D_00351e18[];
extern "C" u8 D_00345c08[];
extern "C" u8 D_0034ebc8[];
extern "C" u32 D_01d49960[];
extern "C" u32 D_01d49968;
extern "C" void func_00320fa8(u32*);
extern "C" u32 func_00105110(...);

u32 func_001c81d0(u32* object) {
    object[0] = (u32)D_00351e18;
    u32* entry = D_01d49960;
    s32 count = 0;
    s32 index;
    for (index = 1; index >= 0; index--) {
        u32 value = *entry;
        if (value != 0) {
            if (value == (u32)object) {
                *entry = 0;
            } else {
                count++;
            }
        }
        entry++;
    }
    if (count == 0) {
        D_01d49968 = 0;
    }
    object[0] = (u32)D_00345c08;
    if ((s32)object != -3184) {
        u32* cursor = object + 0x334;
        u32* end = object + 0x31c;
        while (1) {
            if (end == cursor) {
                cursor = cursor - 4;
                break;
            }
            cursor = cursor - 4;
        }
    }
    object[0] = (u32)D_0034ebc8;
    func_00320fa8(object);
    return func_00105110(object);
}

