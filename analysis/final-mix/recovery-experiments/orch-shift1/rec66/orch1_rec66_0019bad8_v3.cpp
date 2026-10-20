#include "../common/types.h"
struct Object { u8 pad0[0x108]; s32 flagsA; u8 pad1[0x6ec]; s32 flagsB; };
extern "C" s32 func_001c0cd8(s32);

s32 func_0019bad8(Object* object) {
    s32 result = 0;
    if ((object->flagsB & 1) != 0) {
        if ((object->flagsA & 1) == 0) {
            result = func_001c0cd8((s32)object) == 0;
        }
    }
    return result;
}