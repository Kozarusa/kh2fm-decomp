#include "../common/types.h"
extern "C" s32 D_0034ec60;
extern "C" u8 D_0036c5b0[];
extern "C" u64 func_0016a080(...);
extern "C" u32 func_002fee78(...);
extern "C" u32 func_00180058(u8*, s32, u8*, s32, s32, s32*, f32);

s32 func_001801b0(s32 extra, s32 key, s32 value, u8* object, s32* counter, f32 speed) {
    u8 code[16];
    func_002fee78(code, D_0036c5b0, func_0016a080(object));
    func_00180058(object + 0x140, key, code, value, extra, counter, speed);
    if (*(u32*)(object + 0x588) & 4) {
        u8** pointer = (u8**)(object + 0xaf8);
        s32 index = 1;
        do {
            u8* child = *pointer;
            code[3]++;
            pointer++;
            if (child != 0) {
                func_00180058(child + 0x140, key, code, value, extra, counter, speed);
            }
            index--;
        } while (index >= 0);
    }
    D_0034ec60--;
    if (D_0034ec60 >= 0) {
        D_0034ec60 = -1;
    }
    *(s32*)(object + 0x158) = D_0034ec60;
    return D_0034ec60;
}
