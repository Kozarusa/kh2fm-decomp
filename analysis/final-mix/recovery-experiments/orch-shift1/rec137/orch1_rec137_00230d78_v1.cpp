#include "../common/types.h"
extern "C" s32 D_0035dce4;
void func_00230d78(u8* object) {
    s32 index = 0;
    do {
        s32 offset = index * 8;
        ++index;
        if (*(s32*)(D_0035dce4 + offset) == -1) {
            *(s32*)(D_0035dce4 + offset) = *(s16*)(object + 4);
            *(u16*)(D_0035dce4 + offset + 4) = *(u16*)(object + 6);
            *(u16*)(D_0035dce4 + offset + 6) = *(u16*)(object + 8);
            return;
        }
    } while (index < 128);
}
