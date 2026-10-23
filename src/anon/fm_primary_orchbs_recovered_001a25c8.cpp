#include "../common/types.h"

void func_001a25c8(u8* object, s32 amount) {
    u8* item = *(u8**)(object + 0x244);
    if (item != 0) {
        u32 current = item[10];
        if ((s32)(current & 0xff) + amount > 100) {
            amount = 100 - (current & 0xff);
        }
        item[10] = current + amount;
    }
    *(u16*)(object + 0x18a) = *(u16*)(object + 0x18a) + amount;
    *(u16*)(object + 0x192) = *(u16*)(object + 0x192) + amount;
}
