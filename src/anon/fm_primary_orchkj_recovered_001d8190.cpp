#include "../common/types.h"
// why: vtable slots 0 and 5 have no accepted declaration; their results are never used (ruling #36: target is void)
typedef void (*SetByteFn)(u8*, s32);
typedef void (*SetWordsFn)(u8*, s32, s32, s32);
extern "C" u32 func_001d5370(...); // why: accepted call-site declaration of fm_primary_orchip_recovered_001ad158.cpp; the u64 form adds a widening move
extern "C" void func_001d16e8(u8*, s32, s32);

// Preserve original registry aliases.
void func_001d8190(u8* owner, u8* info, u8* object) asm("_Z16u_tail4_001d8190jjjj");

void func_001d8190(u8* owner, u8* info, u8* object) {
    ((SetByteFn)(*(void***)object)[0])(object, info[19]);
    ((SetWordsFn)(*(void***)object)[5])(object, *(s32*)(info + 4), *(s32*)(info + 8), *(s32*)(info + 12));
    s32 handle = *(s32*)(owner + 72);
    if (handle != 0) {
        u16 count = *(u16*)(info + 16);
        if (count != 0) {
            func_001d5370(object + 4, handle, count - 1);
            func_001d16e8(object, info[18], *(s32*)(owner + 712) + 3);
        }
    }
    ((u8**)(owner + 676))[(*(s32*)(owner + 712))++] = object;
}
