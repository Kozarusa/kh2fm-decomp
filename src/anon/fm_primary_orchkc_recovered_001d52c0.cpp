#include "../common/types.h"

struct FlagEntry {
    u16 flag;
    u8 values[3];
    u8 pad;
    u16 result;
};

extern "C" FlagEntry D_0036e568[];
extern "C" bool func_00181500(s64);

// Preserve original registry aliases.
u16 func_001d52c0(s32 kind, u32 value) asm("_Z16ctarget_001d52c0jjjj");

u16 func_001d52c0(s32 kind, u32 value) {
    if (kind != 16) {
        return 0;
    }
    for (u32 index = 0; index < 4; index++) {
        if (func_00181500(D_0036e568[index].flag)) {
            for (s32 slot = 0; slot < 3; slot++) {
                if (D_0036e568[index].values[slot] == value) {
                    return D_0036e568[index].result;
                }
            }
        }
    }
    return 0;
}
