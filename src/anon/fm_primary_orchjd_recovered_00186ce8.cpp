#include "../common/types.h"

// Preserve original registry aliases.
bool func_00186ce8(u8* object) asm("_Z16ctarget_00186ce8jjjj");

bool func_00186ce8(u8* object) {
    bool result = false;
    s32* inner = (s32*)(object + 0x140);
    if (inner[0] != 0) {
        s32 value = inner[5];
        if (value >= 10) {
            if (value < 40) {
                result = true;
            }
        }
    }
    return result;
}
