#include "../common/types.h"
extern "C" u32* D_0035f2e4;
// why: matches the accepted definition in fm_primary_orchbx_recovered_001a80c8.cpp (one s32 id, entry pointer result); extern "C" like the recovered call sites because the probe linker script defines only the plain symbol
extern "C" u8* func_001a80c8(s32 id);
// why: this call site sets only a0 (a loaded byte) and tests v0; the auto-lifted four-argument definition in misc_2.cpp does not decide the type
extern "C" s32 func_00286058(s32 kind);

s32 func_00286068(s32 id) {
    s32 result = 0;
    if (id >= 0) {
        if (id != 0) {
            if (func_00286058(func_001a80c8(id)[2]) != 0) {
                result = (D_0035f2e4[(u32)id >> 5] & (1 << (id & 31))) != 0;
            }
        }
    } else {
        for (id = 0; id < 640; id++) {
            if (D_0035f2e4[(u32)id >> 5] & (1 << (id & 31))) {
                if (func_00286058(func_001a80c8(id)[2]) != 0) {
                    result = 1;
                    break;
                }
            }
        }
    }
    return result;
}
