#include "../common/types.h"
struct Entry12 { s32 first; s32 second; s32 third; };

void func_00198aa8(u8* object, s32 index, s32 value, s32 slot) {
    if (slot == 0) {
        slot = -1;
        s32 entry = *(s32*)(object + 0x9b4);
        if (entry != 0) {
            slot = *(s16*)(entry + 2);
        }
    }
    s32 total = slot * 1000 + value;
    ((Entry12*)(object + 0x9e4))[index].first = total;
}
