#include "../common/types.h"
extern "C" s32 func_001b9bc8(s32);

void func_00198700(s32 object) {
    do {
        object = func_001b9bc8(object);
        if (object == 0) {
            return;
        }
    } while ((u8)(*(u32*)(object + 0x588) & 1) == 0);
}