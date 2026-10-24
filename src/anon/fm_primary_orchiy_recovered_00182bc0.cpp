#include "../common/types.h"
extern "C" s32 D_0034ed00;
extern "C" u8 D_01c60588[];
extern "C" void func_00182940(u8*);

void func_00182bc0(s8* name) {
    s32 index = 0;
    s32 low = name[0] | (name[3] << 24);
    s32 high = (name[2] << 16) | (name[1] << 8);
    s32 tag = low | high;
    if (0 < D_0034ed00) {
        u8* unit = D_01c60588;
        do {
            if (*(s32*)unit == tag) {
                func_00182940(unit);
            }
            index++;
            unit += 12;
        } while (index < D_0034ed00);
    }
}
