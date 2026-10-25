#include "../common/types.h"
#include "../kn/fvector.hpp"
extern "C" u32 D_003638d0;
extern "C" u64 func_00312db8(u64, u64);

void func_001e26b8(u8* entry, kn::FVector* source) {
    for (s32 count = 0; count < 200; count++) {
        if (entry[0x14c] == 0) {
            *(kn::FVector*)(entry + 0x140) = *source;
            entry[0x14d] = 0;
            entry[0x14c] = 0x80;
            D_003638d0 *= 0x10dcd;
            s32 roll = (s32)func_00312db8((u64)D_003638d0, 0x1010102);
            entry[0x14f] = 60;
            entry[0x14e] = roll;
            return;
        }
        entry += 16;
    }
}
