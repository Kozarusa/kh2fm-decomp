#include "../common/types.h"
extern "C" bool func_0019bad8(...);

bool func_0019c838(u8* object) {
    bool result = false;
    if (func_0019bad8(object) || (*(u32*)(object + 0x588) & 0x8000000) != 0) {
        result = (*(u32*)(object + 0x108) & 0x80) == 0;
    }
    return result;
}
