#include "../common/types.h"
extern "C" const void* D_0036b2b0[5];
extern "C" s32 D_0034a8f0[];
extern "C" s32 D_0034a8a0[];
extern "C" s32 D_0034a8c8[];
extern "C" u32 func_00155d80(u32);

s32 func_00155e30(u32 object) {
    // why: named label table keeps the switch targets while the dispatch reads the original table D_0036b2b0
    static const void* targets[5] asm("fm_switch_table_00155e30") = {
        &&fallback, &&fallback, &&second, &&third, &&fallback};
    u32 owner = *(u32*)(object + 52);
    if (owner == 0) goto fallback;
    {
        u32 index = *(u8*)(*(u32*)(owner + 1164) + 431);
        if (index >= 5) goto fallback;
        goto *D_0036b2b0[index];
    }
second:
    func_00155d80(object);
    return D_0034a8f0[func_00155d80(object)];
third:
    func_00155d80(object);
    return D_0034a8a0[func_00155d80(object)];
fallback:
    func_00155d80(object);
    return D_0034a8c8[func_00155d80(object)];
}
