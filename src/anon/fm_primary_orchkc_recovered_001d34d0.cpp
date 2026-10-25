#include "../common/types.h"
// why: accepted definition fm_scalar_recovered_05.cpp is int func_001d3498(int, int) with C++ linkage; exact types kept, extern "C" for the isolated probe link
extern "C" int func_001d3498(int, int);
// why: accepted definition tiny_auto80_queue.cpp is u32 func_001d3558(u8*, u8*) with C++ linkage; exact types kept, extern "C" for the isolated probe link
extern "C" u32 func_001d3558(u8*, u8*);
extern "C" s32 D_01d5ba10[];

s32 func_001d34d0(s32 object) {
    s32* slot = D_01d5ba10;
    for (s32 index = 0; index < 3; index++, slot++) {
        if (*slot == 0) {
            continue;
        }
        if (object != 0) {
            if (func_001d3558((u8*)*slot, (u8*)object) == 0) {
                continue;
            }
        }
        object = func_001d3498(*slot, object);
        if (object != 0) {
            return object;
        }
    }
    return 0;
}
