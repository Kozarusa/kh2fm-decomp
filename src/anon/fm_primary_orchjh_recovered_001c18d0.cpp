#include "../common/types.h"

u32 func_001c18d0(u8* object) {
    s64 ok = ((s64 (*)())*(u32*)(object + 0x10))();
    if (ok == 0) {
        return 0;
    }
    register u8* data asm("$14") = *(u8**)(object + 0x20); // why: original keeps the data pointer in t6
    if (data == 0) {
        return 1;
    }
    s32 kind = *(s32*)(*(u8**)(object + 0x1c) + 4);
    u8 value;
    switch (kind) {
    case 0:
        value = data[0xf];
        break;
    case 1:
        value = data[0xd];
        break;
    default:
        value = 0;
        break;
    }
    object[0x17] = value;
    return 1;
}
