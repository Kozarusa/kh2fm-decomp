#include "../common/types.h"
extern "C" u64 D_0034c710;
extern "C" u8 D_0034c70c;
extern "C" u8 D_0034c6f0[];
extern "C" void func_00143228();
extern "C" void func_00160de0(s32);
extern "C" bool func_001dc9e0(...);
extern "C" void func_001dcc30(u32);
extern "C" u32 func_001de4b0(s32, s32, s32);

void func_0015f618() {
    s32 index;
    s32 slot;
    u32 entry;

    func_00143228();
    for (index = 0; index < 64; index++) {
        u64 bit = (u64)1 << index;
        if (D_0034c710 & bit) {
            func_00160de0(index);
        }
    }
    entry = 0;
    if (D_0034c70c == 1) {
        for (slot = 0; slot < 64; slot++) {
            while ((entry = func_001de4b0((s32)D_0034c6f0, slot, entry)) != 0) {
                if (func_001dc9e0(entry)) {
                    func_001dcc30(entry);
                }
            }
        }
    }
}
