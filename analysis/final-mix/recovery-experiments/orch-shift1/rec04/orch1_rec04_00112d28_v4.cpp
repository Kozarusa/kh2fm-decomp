#include "../common/types.h"
extern "C" s32 func_0019ba60(u8*);

bool func_00112d28(u8* object) {
    if (object == 0) {
        return false;
    }
    if (func_0019ba60(object) == 0) {
        return false;
    }
    if ((*(u32*)(object + 0x588) & 0x10) == 0) {
        return false;
    }
    if ((*(u32*)(object + 0x7f8) & 4) != 0) {
        return false;
    }
    return (*(u32*)(object + 0x108) & 0x8000) == 0;
}
