#include "../common/types.h"
extern "C" u32 func_00239bf8(s32, s32);
extern "C" u8 D_00350a38[];

void func_001acfb0(u8* object, s32 index) {
    if (index != *(s32*)(object + 476)) {
        *(s32*)(object + 476) = index;
        if (*(s32*)(object + 112) == 0) {
            func_00239bf8((s32)(object + 132), D_00350a38[index * 3]);
        } else {
            func_00239bf8((s32)(object + 132), D_00350a38[index * 3 + 1]);
        }
    }
}