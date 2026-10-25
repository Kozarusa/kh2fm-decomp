#include "../common/types.h"

typedef s32 (*QueryCallback)(u8*);

s32 func_002df0d8(u8* object, u8* owner) {
    u8* state = owner + 320;
    s32 current = *(s32*)(state + 20);
    s32 result = 0;
    s32 target = ((QueryCallback*)*(u32*)object)[12](object);
    if (current != target) {
                          if (8.0f <= *(f32*)(state + 48)) {
            result = 1;
        }
    }
    return result;
}
