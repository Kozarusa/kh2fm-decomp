#include "../common/types.h"

extern "C" s32 func_001b9bc8(s32);

void func_001bf6a8() {
    s32 current = 0;
    while ((current = func_001b9bc8(current)) != 0) {
        if ((*(u32*)(current + 0x588) & 0x40000) != 0) {
            (*(void (**)(s32))(*(s32*)current + 0x28))(current);
        }
    }
}
