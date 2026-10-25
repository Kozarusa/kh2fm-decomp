#include "../common/types.h"
extern "C" u8 D_01dad990[];
extern "C" u8 D_0022cf18[];
extern "C" bool func_002282f0(...);
// why: copied from the accepted definition in fm_primary_oneword_recovered_00225b00.cpp (u32 return, one int parameter)
extern "C" u32 func_00225b00(s32);
// why: no recovered source calls Shake::start; parameters derived from registers a0, a1, $f12-$f15 at the call, its result crosses the later call so it is unused
extern "C" void func_002f1460(u8*, s32, f32, f32, f32, f32);
extern "C" u32 func_00102c18(u32,u32,u32);

u32 func_0022cf60(u8* object) {
    u32 result = func_002282f0(*(s16*)(object + 4));
    if (result != 0) return result;
    result = func_00225b00(*(s16*)(object + 4));
    if (result != 0) return result;
    f32 depth = (f32)*(s16*)(object + 12);
    func_002f1460(D_01dad990, *(s16*)(object + 14), (f32)*(s16*)(object + 6),
                  (f32)*(s16*)(object + 8), (f32)*(s16*)(object + 10), depth + depth);
    return func_00102c18(1, 29999, (u32)D_0022cf18);
}
