#include "../common/types.h"
extern "C" s32 func_002ff3fc(...);
extern "C" u32 func_002ff2e8(...);
extern "C" s32 D_0034d840[2];

void func_00168958(s32* object, s32 value, u32 arg) {
    object[12] = value;
    object[1] = 0;
    object[17] = 0;
    *(s16*)((u8*)object + 0x4a) = 0;
    func_002ff3fc(arg);
    func_002ff2e8(object + 2, arg);
    if (D_0034d840[0] == 0) {
        D_0034d840[1] = (s32)object;
        D_0034d840[0] = (s32)object;
        object[0] = 0;
    } else {
        object[0] = D_0034d840[0];
        D_0034d840[0] = (s32)object;
    }
}
