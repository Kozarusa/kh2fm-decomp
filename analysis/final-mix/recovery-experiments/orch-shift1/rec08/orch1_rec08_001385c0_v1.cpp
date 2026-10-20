#include "../common/types.h"

extern "C" s32 D_00347e08;
extern "C" u8 D_001384d0[];
extern "C" u32 func_00102c48(u32, u32, u32, u32);

void func_001385c0() {
    D_00347e08 = 0;
    func_00102c48(1, 310000, (u32)D_001384d0, 4096);
}