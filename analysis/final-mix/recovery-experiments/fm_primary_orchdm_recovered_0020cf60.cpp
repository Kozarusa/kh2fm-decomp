#include "../common/types.h"
extern "C" s32 D_00354688;
extern "C" s32 D_0035468c;
extern "C" void func_00223e98(s32, f32, f32, u8*, u8, u8, s32);

void func_0020cf60(s32 unused, u8* object) {
    if (D_00354688 != 0) {
        if (D_0035468c > 0) {
            func_00223e98(*(s32*)(object + 4), *(f32*)(object + 0xc), *(f32*)(object + 0x10), object + 8, object[0x1c], object[0x1d], *(s32*)(object + 0x14));
        }
    }
}
