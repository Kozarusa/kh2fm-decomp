#include "../common/types.h"
extern "C" s32 D_003a99f0[];

void func_00148a68(u8* object, u8* item) {
    s32* table = D_003a99f0;
    u32 index = item[0x11f];
    while (table[index] != 0) {
        index++;
    }
    table[index] = (s32)item;
    (*(s32*)(object + 0x537c))++;
}
