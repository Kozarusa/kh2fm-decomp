#include "../common/types.h"
struct Object { u8 pad0[0x588]; u32 low : 2; u32 bit2 : 1; u32 mid : 3; u32 bit6 : 1; };
extern "C" u32 func_001c8ab0(...);

s32 func_0019c590(Object* object) {
    s32 result = 0;
    if (!object->bit2) {
        if (!object->bit6) {
            result = func_001c8ab0() == 1;
        }
    }
    return result;
}
