#include "../common/types.h"
extern "C" u64 func_001d22a8(u32);

u64 func_001a8190(u8* object) {
    s32 type = object[2];
    u16 id;
    if (type < 2) {
        return 0;
    }
    if (type < 14) {
        id = *(u16*)(object + 6);
    } else if (type < 16) {
        id = *(u16*)(object + 4);
    } else {
        return 0;
    }
    return func_001d22a8(id);
}
