#include "../common/types.h"
extern "C" const void* D_0036eaf8[12];

s32 func_001e3590(u8* object) {
    // why: named label table keeps the switch targets while the dispatch reads the original table D_0036eaf8
    static const void* targets[12] asm("fm_switch_table_001e3590") = {
        &&other, &&kind1, &&other, &&kind3, &&other, &&kind5,
        &&other, &&kind7, &&other, &&kind9, &&other, &&kind11};
    u32 kind = object[168];
    if (kind >= 12) goto other;
    goto *D_0036eaf8[kind];
kind1:
    return 1;
kind3:
    return 2;
kind5:
    return 3;
kind7:
    return 4;
kind9:
    return 5;
other:
    return 0;
kind11:
    return 6;
}
