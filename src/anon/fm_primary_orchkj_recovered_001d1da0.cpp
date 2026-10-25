#include "../common/types.h"
// why: only placeholder declarations (fm_scalar_extra_recovered_12.cpp) exist; parameters derived from registers (a0 object, a1 code); its result is never used
extern "C" void func_001d1720(u8*, s32);
// why: accepted definition (auto80_199_queue.cpp) is void; a1 is read by its callee func_001d1760, so the second parameter is derived from registers
extern "C" void func_001d17b0(u8*, s32);

// why: void per DEVIATIONS #36; the only exit follows the final call to func_001d17b0, whose accepted definition is void (its exits leave its entry v0, func_001d1760's flag, or an indirect vtable call; no $f0 result): stale-b. $f0 before that call is only this function's cvt.w.s temporary (own).

void func_001d1da0(u8* object, f32 value) {
    if (value <= 0.0f) {
        if (0.0f < *(f32*)(object + 44)) {
            func_001d1720(object, 136);
        }
        value = 0.0f;
    } else if ((f32)*(s32*)(object + 24) <= value) {
        if (*(f32*)(object + 44) < (f32)*(s32*)(object + 24)) {
            func_001d1720(object, 137);
        }
        value = (f32)*(s32*)(object + 24);
    }
    func_001d17b0(object, (s32)value);
    *(f32*)(object + 44) = value;
}
