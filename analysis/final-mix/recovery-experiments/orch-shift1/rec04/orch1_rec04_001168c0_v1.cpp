#include "../common/types.h"
extern "C" f32 func_002f8ad0(f32, f32);
extern "C" u64 func_00313b80(f32);
extern "C" u64 func_003142e0(u64, u64);

void func_001168c0(u8* object) {
    f32 other;
    if (func_003142e0(func_00313b80(*(f32*)(object + 0x660)), 0) == 0) {
        if (func_003142e0(func_00313b80(*(f32*)(object + 0x664)), 0) == 0) {
            return;
        }
        other = *(f32*)(object + 0x664);
    } else {
        other = *(f32*)(object + 0x664);
    }
    *(f32*)(object + 0x65c) = func_002f8ad0(*(f32*)(object + 0x660), -other);
}
