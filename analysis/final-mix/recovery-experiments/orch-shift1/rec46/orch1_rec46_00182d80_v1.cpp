#include "../common/types.h"
extern "C" s32 D_0034ed00;
extern "C" u8 D_01c60588[];
extern "C" void func_001828b8(u8*);
extern "C" void func_001827a8(u8*);

void func_00182d80() {
    s32 index = D_0034ed00 - 1;
    if (index >= 0) {
        u8* entry = D_01c60588 + index * 12;
        do {
            if (entry != 0) {
                func_001828b8(entry);
                func_001827a8(entry);
            }
            index--;
            entry -= 12;
        } while (index >= 0);
    }
}