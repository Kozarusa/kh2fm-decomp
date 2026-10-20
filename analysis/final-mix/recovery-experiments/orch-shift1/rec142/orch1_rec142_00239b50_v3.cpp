#include "../common/types.h"
s32 func_00239b50(u8* object, s32 index) {
    u8* base = *(u8**)(object + 176);
    s32 result = 0;
    u16* entry = (u16*)(*(u8**)(object + 180) + index * 36);
    s32 count = entry[1];
    u8* cursor = base + entry[0] * 144;
    if (count > 0) {
        do {
            s32 value = *(s32*)(cursor + 12);
            s32 lowered = value - 1;
            if (result < value) {
                result = lowered;
                if ((*(u32*)cursor & 0x8000) == 0) result = value;
            }
            --count;
            cursor += 144;
        } while (count > 0);
    }
    return result + 1;
}