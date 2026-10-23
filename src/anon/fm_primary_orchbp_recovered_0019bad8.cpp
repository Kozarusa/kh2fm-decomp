#include "../common/types.h"
struct Object { u8 pad0[0x108]; u32 bitA : 1; u32 restA : 31; u8 pad1[0x6ec]; u32 bitB : 1; };
extern "C" s32 func_001c0cd8(s32);

s32 func_0019bad8(Object* object) {
    s32 result = 0;
    if (object->bitB) {
        if (!object->bitA) {
            result = func_001c0cd8((s32)object) == 0;
        }
    }
    return result;
}
