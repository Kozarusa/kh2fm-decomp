#include "../common/types.h"
extern "C" u8 D_0032bb30[];
extern "C" u32 func_001ada38(s64);
extern "C" void func_00177710();
extern "C" u32 func_0016c008(s32, s32);
extern "C" u16 func_0016a070(s32);
extern "C" u32 func_0016a020(s32);
extern "C" u32 func_00253180(...);

u32 func_00179648(s32 object, s32 target) {
    func_001ada38(7);
    func_00177710();
    u8* state = D_0032bb30;
    state[14] = func_0016c008(target, 1);
    if (func_0016a070(object) == 14) {
        *(u32*)(state + 9372) |= 1;
    } else {
        *(u32*)(state + 9372) &= ~1;
    }
    return func_00253180(1, func_0016a020(target) == 0x239 ? 0 : 2);
}
