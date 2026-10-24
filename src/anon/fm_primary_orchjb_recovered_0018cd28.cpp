#include "../common/types.h"
extern "C" u8* D_00352130;
extern "C" s32 func_0018ca48(u8);

s32 func_0018cd28(u8* object, f32* x, f32* y) {
    *x = *(f32*)(D_00352130 + 0x24);
    asm volatile("" ::: "memory"); // why: original reloads the global after this store
    *y = *(f32*)(D_00352130 + 0x28);
    s32 reaction = func_0018ca48(object[0x27]);
    if (reaction == 4) {
        u8* pointer = *(u8**)(object + 0x20);
        if (pointer != 0 && *(s32*)(pointer + 0xc) != 0) {
            *x = (f32)*(s16*)(pointer + 0xc);
            asm volatile("" ::: "memory"); // why: original reloads object + 0x20 after this store
            *y = (f32)*(s16*)(*(u8**)(object + 0x20) + 0xe);
        }
    }
    return reaction;
}
