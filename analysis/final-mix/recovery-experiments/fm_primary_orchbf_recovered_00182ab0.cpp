#include "../common/types.h"
extern "C" s32 D_0034ed00;
extern "C" u8 D_01c60588[];
extern "C" void func_00182910(u8*);

void func_00182ab0() {
    s32 index = 0;
    if (D_0034ed00 > 0) {
        u8* entry = D_01c60588;
        do {
            index++;
            func_00182910(entry);
            entry += 12;
        } while (index < D_0034ed00);
    }
}
