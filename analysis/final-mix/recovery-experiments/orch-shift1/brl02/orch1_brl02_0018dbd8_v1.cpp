#include "../common/types.h"

bool func_0018dbd8(u8* object) {
    u32 flags = *(u32*)(object + 4);
    return (flags & 2) || ({
        bool result;
        result = ({ bool low = (flags & 8) != 0; low; }) || ({ bool high = (flags & 0x10) != 0; high; });
        result;
    }) || (flags & 0x200);
}
