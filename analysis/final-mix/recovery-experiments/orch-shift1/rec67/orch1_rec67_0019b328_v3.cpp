#include "../common/types.h"

u8* func_0019b328(u8* object, s32 id) {
    s32 index = 0;
    u32 count = *(u16*)(*(u8**)(object + 8) + 8);
    u8* entry = *(u8**)(object + 0x2c);
    if (count != 0) {
        if (id >= 0) {
            do {
                if (*(u16*)entry == id) {
                    return entry;
                }
                index++;
                entry = entry + *(u16*)(entry + 2) * 12 + 8;
            } while (index < (s32)count);
        } else {
            return entry;
        }
    }
    return 0;
}
