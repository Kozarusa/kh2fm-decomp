#include "../common/types.h"
extern "C" u64 func_001a1840(...);
extern "C" u8 D_01c62fb8[];
extern "C" s32 D_01c6c9b8[];
extern "C" s32 D_01c6cab8;

void func_001a17c8(u8* object) {
    func_001a1840();
    s32 count = *(s32*)(object + 600) - 1;
    *(s32*)(object + 600) = count;
    if (count < 1) {
        s32 index = D_01c6cab8;
        D_01c6cab8 = index + 1;
        D_01c6c9b8[index] = (((s32)object - (s32)D_01c62fb8) >> 3) * 0x3f2b3885;
    }
}
