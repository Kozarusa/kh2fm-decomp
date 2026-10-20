#include "../common/types.h"

void func_00141988(u8* object, u8* source, u32* result) {
    result[0] = *(u32*)(object + 16) + (*(u16*)(source + 2) << 4);
    result[1] = *(u32*)(object + 16) + (*(u16*)(source + 4) << 4);
    result[2] = *(u32*)(object + 16) + (*(u16*)(source + 6) << 4);
    u32 index = *(u16*)(source + 8);
    if (index != 0xffff) {
        result[3] = *(u32*)(object + 16) + (index << 4);
        result[4] = 4;
        return;
    }
    result[4] = 3;
}
