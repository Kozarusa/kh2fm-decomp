#include "../common/types.h"
extern "C" u8 D_00351ec8[];
extern "C" u64 func_00105300(...);
extern "C" u64 func_001d7ba8(...);
extern "C" bool func_001c8db8(...);

s32 func_00187920(u8* object) {
    s32 result = 0;
    if (*(u32*)(object + 0x108) & 0x100) goto set;
    if (*(u32*)(object + 0x160) & 0x400000) goto set;
    if (func_001d7ba8(object + 0x518)) goto set;
    if (*(u32*)(object + 0x108) & 0x10000000) goto set;
    if (*(u32*)(object + 0x108) & 0x80000) goto set;
    if (*(u32*)(object + 0x7f8) & 0x10) goto set;
    if (*(u32*)(object + 0x7f8) & 0x200) goto set;
    if (func_00105300()) goto set;
    if (!func_001c8db8(D_00351ec8, 0)) goto done;
set:
    result = 1;
done:
    return result;
}
