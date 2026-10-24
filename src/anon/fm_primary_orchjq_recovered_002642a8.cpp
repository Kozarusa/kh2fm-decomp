#include "../common/types.h"
extern "C" const void* D_003732a0[17];
extern "C" u32 func_001a80c8(...);

s32 func_002642a8() {
    // why: named label table keeps the switch targets while the dispatch reads the original table D_003732a0
    static const void* targets[17] asm("fm_switch_table_002642a8") = {
        &&eight, &&eight, &&one, &&one, &&one, &&one, &&one, &&one,
        &&one, &&one, &&one, &&one, &&one, &&one, &&two, &&four,
        &&sixteen};
    u32 index = *(u8*)(func_001a80c8() + 2);
    s32 result = 0;
    if (index >= 17) goto done;
    goto *D_003732a0[index];
eight:
    result = 8;
    goto done;
one:
    result = 1;
    goto done;
two:
    result = 2;
    goto done;
four:
    result = 4;
    goto done;
sixteen:
    result = 16;
done:
    return result;
}
