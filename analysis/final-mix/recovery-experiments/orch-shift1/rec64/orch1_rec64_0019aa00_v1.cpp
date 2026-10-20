#include "../common/types.h"
extern "C" s32 func_0019a9e0();
extern "C" void func_0019ab80(void*);

void func_0019aa00(u32* object, u8* other) {
    if ((u8)(object[1] & 1) == 0) {
        if ((*(u32*)(other + 0x588) & 0x800) != 0) {
            if (func_0019a9e0() == 0) {
                func_0019ab80(object);
            }
        }
    }
}
