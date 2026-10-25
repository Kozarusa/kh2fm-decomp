#include "../common/types.h"
extern "C" u32 func_00294000(u32);
extern "C" u32 D_0035f620;

s32 func_002ad7d0(s32 id) {
    s32 result = 1;
    u32 data = func_00294000(8);
    s32 count = *(s32*)(data + 8);
    u32 index = 0;
    u16* entry = (u16*)(data + 16);
    u32 base;

    if (count > 0) {
        base = D_0035f620 + 148;
        do {
            if (id < 0 || *entry == id) {
                if ((*(u32*)((index >> 5) * 4 + base) & (1 << (index & 0x1f))) == 0) {
                    result = 0;
                    break;
                }
            }
            index = index + 1;
            entry = entry + 8;
        } while ((s32)index < count);
    }
    return result;
}
