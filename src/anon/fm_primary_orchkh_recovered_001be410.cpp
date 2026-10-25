#include "../common/types.h"
extern "C" s32 func_001818e8(u8*);
extern "C" bool func_001bd590(u64);
// why: accepted C++-linkage definition (auto80_199_queue.cpp) cannot link in the isolated probe; same types with C linkage
extern "C" u32 func_001bdb10(u32 a0, u32 a1);
extern "C" u32 func_001bc720(s32);

void func_001be410(u8* object) {
    if (func_001818e8(object) == 0) {
        return;
    }
    if ((**(u64**)(object + 0x9e4) & 0x800000) != 0) {
        if (func_001bd590((u64)object) == 0) {
            if (func_001bdb10((u32)object, 5) == 0) {
                return;
            }
            *(u32*)(object + 0x20) |= 2;
            return;
        }
    }
    if (func_001bdb10((u32)object, *(u32*)(object + 0xaa4)) == 0) {
        return;
    }
    func_001bc720(**(s32**)(object + 0x8c0));
    *(u32*)(object + 0x20) &= ~2;
}
