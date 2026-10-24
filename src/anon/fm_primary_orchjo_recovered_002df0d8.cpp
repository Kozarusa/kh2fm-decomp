#include "../common/types.h"
extern "C" f32 D_00375e54;

typedef s32 (*QueryCallback)(u8*);

s32 func_002df0d8(u8* object, u8* owner) {
    u8* state = owner + 320;
    s32 current = *(s32*)(state + 20);
    s32 result = 0;
    s32 target = ((QueryCallback*)*(u32*)object)[12](object);
    if (current != target) {
        register f32* limit asm("$15") = &D_00375e54; // why: original keeps the formed address in t7
        asm("" : "+r"(limit)); // why: keeps the full address formed before the separate lwc1
        if (*limit <= *(f32*)(state + 48)) {
            result = 1;
        }
    }
    return result;
}
