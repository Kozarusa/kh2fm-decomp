#include "../common/types.h"
extern "C" u32 func_0028acc8(u32);
extern "C" u32 func_00239d30(u8*, s32);
// why: return type from the recovered definition u32 dk::Obj2D::isHide() in harata/libdk/obj2d.cpp; a0 is the
// object (its this pointer); extern "C" because the asm-label form fails the isolated link (v1: the probe linker
// script defines only the plain symbol); the full build PROVIDEs plain func_001396c0 in symbols.ld
extern "C" u32 func_001396c0(u8* object);

s32 func_0028ad50(u8* object) {
    if (func_0028acc8((u32)object) != 0) {
        for (s32 index = 0; index < *(s16*)(object + 4); index++) {
            u8* item = (*(u8***)(object + 40))[index];
            if (item != 0) {
                if (func_001396c0(item) == 0) {
                    u8* sequence = (*(u8***)(object + 40))[index] + 24;
                    if ((func_00239d30(sequence, *(s32*)(sequence + 276)) & 0xff) == 0) {
                        if (*((*(u8***)(object + 40))[index] + 404) == 0) {
                            return 0;
                        }
                    }
                }
            }
        }
        return 1;
    }
    return 0;
}
