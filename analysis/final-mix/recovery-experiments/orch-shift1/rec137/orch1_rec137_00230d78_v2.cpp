#include "../common/types.h"
union Value { s32 word; u16 half; };
extern "C" s32 D_0035dce4;
void func_00230d78(u8* object) {
    s32 index = 0;
    do {
        s32 offset = index * 8;
        ++index;
        if (((Value*)(offset + D_0035dce4))->word == -1) {
            ((Value*)(offset + D_0035dce4))->word = *(s16*)(object + 4);
            ((Value*)(offset + D_0035dce4 + 4))->half = *(u16*)(object + 6);
            ((Value*)(offset + D_0035dce4 + 6))->half = *(u16*)(object + 8);
            return;
        }
    } while (index < 128);
}
