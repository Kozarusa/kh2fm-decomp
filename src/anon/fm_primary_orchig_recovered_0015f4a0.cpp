#include "../common/types.h"
extern "C" u64 D_0034c710;
extern "C" u8 D_0034c70c;
extern "C" u8 D_0034c6f0[];
extern "C" void func_00143228();
extern "C" void func_0015c4a0(u32);
extern "C" void func_001de3d8(u8*, u32);

void func_0015f4a0() {
    s32 index;
    func_00143228();
    for (index = 0; index < 64; index++) {
        u64 mask = (u64)1 << index;
        if ((D_0034c710 & mask) != 0) {
            func_0015c4a0(index);
            if (D_0034c70c == 1) {
                func_001de3d8(D_0034c6f0, index);
            }
        }
    }
}
