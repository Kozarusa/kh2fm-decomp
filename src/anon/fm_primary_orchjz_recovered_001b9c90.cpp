#include "../common/types.h"
extern "C" u32 D_01d48db8[];
extern "C" u64 func_00105300(...);
extern "C" u8 func_0016a040(s32);

s32 func_001b9c90(u8* object) {
    s32 result = 0;
    u32 type = func_0016a040((s32)object);
    if (D_01d48db8[type >> 5] & (1 << (type & 0x1f))) goto done;
    if (*(u32*)(object + 0x10c) & 0x200000) goto done;
    if (func_00105300()) goto done;
    if (func_0016a040((s32)object)) goto set;
    if (!(*(u32*)(object + 0x7f8) & 0x80)) goto done;
set:
    result = 1;
done:
    return result;
}
