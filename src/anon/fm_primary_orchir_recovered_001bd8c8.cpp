#include "../common/types.h"
extern "C" bool func_001bd918(...);
extern "C" u32 func_001b8e88(...);

bool func_001bd8c8(u32 object) {
    s32 table;
    u32 value;
    table = **(s32**)(object + 0x8c0);
    u16* entry = (u16*)(table + *(s32*)(table + 0x6c) * 0xc + 0xe);
    value = func_001b8e88(*entry);
    return func_001bd918(object, value, 0);
}
