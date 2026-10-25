#include "../common/types.h"
extern "C" u8* D_0035f5ac;
extern "C" const void* D_00374aac[9];
extern "C" u32 func_00287bc0(void);
extern "C" u32 func_00294000(u32);
// why: a0 is a pointer into the 36-byte entry table, v0 is tested as a flag
extern "C" u32 func_002943b0(u32);
extern "C" u32 func_002954e0(s32);
// why: probe linker script defines only the plain symbol; the C++ form of the accepted definition fails the isolated link (v1)
extern "C" s32 func_0029c9d8(s32);

s32 func_0029ecf0(s32 index) {
    // why: named label table keeps the switch targets while the dispatch reads the original table D_00374aac (pattern of func_001815d0)
    static const void* targets[9] asm("fm_switch_table_0029ecf0") = {
        &&world, &&entry, &&open, &&none, &&entry, &&open, &&none, &&entry, &&open};
    u32 mode = func_00287bc0();
    u32 entries = func_00294000(3) + 16;
    u32 slot = mode - 14;
    if (slot >= 9) goto none;
    goto *D_00374aac[slot];
world:
    if (index < 0) return 1;
    return func_002954e0(func_0029c9d8(index)) != 0;
none:
    return 0;
entry:
    if (index < 0) return 1;
    return func_002943b0(entries + *(s16*)(D_0035f5ac + index * 2 + 8) * 36) != 0;
open:
    return 1;
}
