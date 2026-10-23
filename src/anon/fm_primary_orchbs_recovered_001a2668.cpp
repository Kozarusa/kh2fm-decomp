#include "../common/types.h"

void func_001a2668(u8* object, s32 amount) {
    u8* item = *(u8**)(object + 0x244);
    if (item != 0) {
        u32 current = item[8];
        if ((s32)(current & 0xff) + amount > 100) {
            amount = 100 - (current & 0xff);
        }
        item[8] = current + amount;
    }
    *(u16*)(object + 0x18e) = *(u16*)(object + 0x18e) + amount;
    *(u16*)(object + 0x196) = *(u16*)(object + 0x196) + amount;
}
