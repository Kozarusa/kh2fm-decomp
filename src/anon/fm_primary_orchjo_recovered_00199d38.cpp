#include "../common/types.h"
extern "C" u32 func_0016ed50(void*,s64,s64);
extern "C" u32 func_00199810(void*);

void func_00199d38(u8* object) {
    u8* table = *(u8**)(object + 8);
    s32 index = 0;
    if (*(u16*)(table + 4) != 0) {
        do {
            s32 offset = index * 0x40;
            index++;
            if (func_00199810(table + offset + 0x2c) != 0) {
                u32 current = *(u32*)(object + 8);
                func_0016ed50(*(void**)(offset + current + 0x2c), -1, 30);
            }
            table = *(u8**)(object + 8);
        } while (index < *(u16*)(table + 4));
    }
}
