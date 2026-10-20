#include "../common/types.h"
extern "C" u64 func_001d22a8(u32);

u64 func_001a8190(u8* object) {
    s32 type = object[2];
    if (type >= 2) {
        if (type < 14) {
            return func_001d22a8(*(u16*)(object + 6));
        }
        if (type < 16) {
            return func_001d22a8(*(u16*)(object + 4));
        }
    }
    return 0;
}
