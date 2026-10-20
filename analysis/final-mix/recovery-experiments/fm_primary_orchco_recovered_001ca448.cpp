#include "../common/types.h"

u32 func_001ca448(u8* object) {
    switch (*(s32*)(object + 0x154)) {
    case 0x10:
    case 0x2c:
        return 0;
    case 0xa1: {
        u32 bits = *(u32*)(object + 0x588) & 0x80;
        // why: empty asm keeps the mask as its own andi so the test stays sltiu
        asm("" : "+r"(bits));
        return bits == 0;
    }
    default:
        return 1;
    }
}
