#include "../common/types.h"
extern "C" u8* func_001b9bc8(u8*);

u8* func_001dba18(s32 id) {
    u8* object = 0;
    u8* result = 0;
    while ((object = func_001b9bc8(object)) != 0) {
        if ((*(u32*)(object + 0x588) & 0x10000000) != 0) {
            if (*(s32*)(object + 8) == id) {
                result = object;
                break;
            }
        }
    }
    return result;
}
