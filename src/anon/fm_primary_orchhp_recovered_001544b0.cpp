#include "../common/types.h"
extern "C" void func_00139598(u8*);
extern "C" void func_001395a8(u8*);

void func_001544b0(u8* object) {
    s32 row;
    s32 slot;
    s32 index;
    for (row = 0; row < 16; row++) {
        for (slot = 0; slot < 2; slot++) {
            func_00139598(object + 2496 + row * 816 + slot * 408);
        }
    }
    for (index = 0; index < *(s32*)(object + 15568); index++) {
        if (index < 16) {
            func_001395a8(object + 2496 + index * 816);
        }
    }
}
