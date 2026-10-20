#include "../common/types.h"

bool func_001ca448(u8* object) {
    switch (*(s32*)(object + 0x154)) {
    case 0x10:
    case 0x2c:
        return false;
    case 0xa1:
        return (*(u32*)(object + 0x588) & 0x80) == 0;
    default:
        return true;
    }
}
