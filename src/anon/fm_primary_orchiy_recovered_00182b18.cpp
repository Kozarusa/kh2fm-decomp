#include "../common/types.h"
extern "C" u8 D_01c60588[];
extern "C" s32 D_0034ed00;
extern "C" u8 D_00182c60[];
extern "C" u32 func_00102c18(u32,u32,u32);
extern "C" u32 func_00182940(u8*);

u32 func_00182b18() {
    s32 index = 0;
    u32 result = func_00102c18(1, 12000, (u32)D_00182c60);
    if (index < D_0034ed00) {
        s32 offset = 0;
        do {
            if ((*(u32*)(offset + (D_01c60588 + 4)) & 2) == 0) {
                result = func_00182940(offset + D_01c60588);
            }
            index++;
            offset += 12;
        } while (index < D_0034ed00);
    }
    return result;
}
