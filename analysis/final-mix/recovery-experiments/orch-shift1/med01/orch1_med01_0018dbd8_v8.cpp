#include "../common/types.h"

bool func_0018dbd8(u8* object) {
    u32 flags = *(u32*)(object + 4);
    return (flags & 2) || ({
        bool selected = ({ flags & 8; }) || ({ flags & 0x10; });
        selected;
    }) || (flags & 0x200);
}
