#include "../common/types.h"
union Slot { s32 word; u64 dword; };
extern "C" u64 func_002223e0(...);

u64 func_001f4e18(u8* object, u8* other) {
    u8* base = object + **(s32**)(other + 12);
    u8* first = base + 0xa0;
    u8* second = base + 0xb0;
    u64 result = func_002223e0(first);
    ((Slot*)(first + 0x70))->dword = 0;
    ((Slot*)(first + 0x78))->dword = 0;
    ((Slot*)(first + 0x80))->dword = 0;
    ((Slot*)(first + 0x88))->dword = 0;
    ((Slot*)(first + 0x6c))->word = 0;
    ((Slot*)(second + 0xc))->word = 0;
    ((Slot*)(second + 0x24))->word = 0;
    ((Slot*)(second + 0x2c))->word = 0;
    return result;
}
