#include "../common/types.h"
extern "C" bool func_002282f0(...);
// why: no recovered call site or definition exists for these six; parameters come from the registers and masks set before each jal, results are not used here
extern "C" void func_0014a768(u8);
extern "C" void func_0014a788(u16, u16);
extern "C" f32 func_00227c78(u8*);
extern "C" void func_0014a7b8(s32, f32);
extern "C" void func_0014a7e8(u8);
extern "C" void func_0014a7f8(u8);

// why: void per DEVIATIONS #36: the early exit leaves the direct bool v0 of 002282f0 (no float in its chain) and the 0014a7f8 tail is stale-b (0014a7f8 and its tail 0014a7b8 write neither v0 nor $f0; $f0 still holds the 00227c78 result that crossed later calls)

void func_0022cd48(u8* object) {
    if (func_002282f0(*(s16*)(object + 4))) {
        return;
    }
    u8 enable;
    if (object[6] == 0) {
        u8* event = object + 8;
        func_0014a768(object[7]);
        func_0014a788(*(s16*)(object + 12) >> 1, *(s16*)(object + 14) >> 1);
        if (func_00227c78(event) != 0.0f) {
            func_0014a7b8(*(s16*)(object + 16), func_00227c78(event));
        }
        func_0014a7e8(1);
        enable = 1;
    } else {
        enable = 0;
    }
    func_0014a7f8(enable);
}
