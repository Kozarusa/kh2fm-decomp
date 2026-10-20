#include "../common/types.h"
extern "C" u64 func_001a1840(...);
extern "C" u8 D_01c62fb8[];

void func_001a17c8(u8* object) {
    func_001a1840();
    s32 count = *(s32*)(object + 600) - 1;
    *(s32*)(object + 600) = count;
    if (count < 1) {
        u8* region = D_01c62fb8 + 0x8000;
        s32 index = *(s32*)(region + 0x1b00);
        *(s32*)(region + 0x1b00) = index + 1;
        *(s32*)(D_01c62fb8 + index * 4 + 0x9a00) = (((s32)object - (s32)D_01c62fb8) >> 3) * 0x3f2b3885;
    }
}
