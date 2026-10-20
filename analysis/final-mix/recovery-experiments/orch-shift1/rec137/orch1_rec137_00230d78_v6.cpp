#include "../common/types.h"
extern "C" s32 D_0035dce4;
void func_00230d78(u8* object) {
    s32 index = 0;
    do {
        s32 offset = index * 8;
        ++index;
        if (*(s32*)(offset + D_0035dce4) == -1) {
            *(s32*)(offset + D_0035dce4) = *(s16*)(object + 4);
            asm volatile("" ::: "memory"); // why: keeps first store before reload
            *(u16*)(offset + D_0035dce4 + 4) = *(u16*)(object + 6);
            asm volatile("" ::: "memory"); // why: keeps second store before reload
            *(u16*)(offset + D_0035dce4 + 6) = *(u16*)(object + 8);
            return;
        }
    } while (index < 128);
}
