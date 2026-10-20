#include "../common/types.h"

void func_001a2618(u8* object, s32 amount) {
    u8* item = *(u8**)(object + 0x244);
    if (item != 0) {
        u32 current = item[11];
        if ((s32)(current & 0xff) + amount > 100) {
            amount = 100 - (current & 0xff);
        }
        item[11] = current + amount;
    }
    *(u16*)(object + 0x18c) = *(u16*)(object + 0x18c) + amount;
    *(u16*)(object + 0x194) = *(u16*)(object + 0x194) + amount;
}