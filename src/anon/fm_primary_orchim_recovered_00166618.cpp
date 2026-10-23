#include "../common/types.h"
extern "C" u8 D_0034c7b0[];
extern "C" void func_002f28b8(void* a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);
extern "C" void func_003058a0(u32);
extern "C" u32 func_002f2be0(...);

u32 func_00166618(u32 value, s16 first, s16 second, s16 third, s16 fourth, s16 fifth, s32 index) {
    u8* entry = D_0034c7b0 + index * 96;
    func_002f28b8(entry, second, third >> 6, first, 0, fifth, third, fourth);
    func_003058a0(0);
    return func_002f2be0(entry, value);
}
