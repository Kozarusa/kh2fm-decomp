#include "../common/types.h"
extern "C" u8* D_00361dd8;
extern "C" s32 func_002c5150(s32);
extern "C" void func_002c8490(u8*);
extern "C" u32 func_001050d8(u32);
extern "C" s32 func_002c77b8(u32, s32);

s32 func_002c85c8(s32 value) {
    s32 result = func_002c5150(value);
    if (result == 0) {
        u8* current = D_00361dd8;
        if (current == 0 || *(s32*)(current + 0xc0) != value) {
            if (current != 0) {
                func_002c8490(current);
                D_00361dd8 = 0;
            }
            return func_002c77b8(func_001050d8(0x1738), value);
        }
    }
    return result;
}
