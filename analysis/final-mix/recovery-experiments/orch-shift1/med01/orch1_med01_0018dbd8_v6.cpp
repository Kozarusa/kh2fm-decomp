#include "../common/types.h"

bool func_0018dbd8(u8* object) {
    u32 flags = *(u32*)(object + 4);
    return (flags & 2) || ({
        u8 selected = 0;
        if (({ flags & 8; }) || ({ flags & 0x10; })) {
            selected = 1;
        }
        selected;
    }) || (flags & 0x200);
}
