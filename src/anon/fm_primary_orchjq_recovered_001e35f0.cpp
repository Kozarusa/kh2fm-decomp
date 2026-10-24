#include "../common/types.h"
extern "C" const void* D_0036eb28[13];

s32 func_001e35f0(u8* object) {
    // why: named label table keeps the switch targets while the dispatch reads the original table D_0036eb28
    static const void* targets[13] asm("fm_switch_table_001e35f0") = {
        &&other, &&other, &&kind2, &&other, &&kind4, &&other, &&kind6,
        &&other, &&kind8, &&other, &&kind10, &&other, &&kind12};
    u32 kind = object[168];
    if (kind >= 13) goto other;
    goto *D_0036eb28[kind];
kind2:
    return 1;
kind4:
    return 2;
kind6:
    return 3;
kind8:
    return 4;
kind10:
    return 5;
other:
    return 0;
kind12:
    return 6;
}
