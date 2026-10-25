#include "../common/types.h"
extern "C" s32 D_0035eea4;
extern "C" s16 D_0035eea0;
extern "C" s16* D_0035ee9c;
extern "C" u32 func_00139d78(...);
extern "C" u32 func_0023f0c0(...);
// why: Layout::getNextNum (layout.cpp) returns s32; extern "C" because the isolated probe linker script defines only the plain symbol
extern "C" s32 func_0023f100(...);
// why: accepted definition in fm_primary_close_recovered.cpp is void func_0023f0c8(s32, u32); extern "C" because the isolated probe linker script defines only the plain symbol
extern "C" void func_0023f0c8(s32, u32);

void func_00252ce0(void) {
    func_00139d78(D_0035eea4);
    if (func_0023f100(D_0035eea4) == -1) {
        u32 number = func_0023f0c0(D_0035eea4);
        s32 value = -1;
        s32 index;
        for (index = 0; index < D_0035eea0; index++) {
            if ((s32)number == D_0035ee9c[index]) {
                value = D_0035ee9c[index + 1];
                break;
            }
        }
        if (value >= 0) {
            func_0023f0c8(D_0035eea4, value);
        }
    }
}
