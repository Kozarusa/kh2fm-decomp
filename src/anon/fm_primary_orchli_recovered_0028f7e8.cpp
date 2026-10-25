#include "../common/types.h"
extern "C" u32 D_0035f480;
extern "C" s32 func_00139d78(u32);
extern "C" void func_00139510(u32);
extern "C" u32 func_0028d6e8(u32);

// Preserve original registry aliases.
void func_0028f7e8(s32 index) asm("_ZN2Tz7JmStory12LeaveAllPostEz");

void func_0028f7e8(s32 index) {
    if (D_0035f480 != 0) {
        u32 offset = index * 884;
        if (func_00139d78(D_0035f480 + offset) != 0) {
            func_00139510(D_0035f480 + offset);
        }
        if (func_0028d6e8(D_0035f480 + offset + 436) != 0) {
            func_00139510(D_0035f480 + offset + 436);
        }
    }
}
