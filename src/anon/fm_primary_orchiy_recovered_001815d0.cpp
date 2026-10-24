#include "../common/types.h"
struct Pair {
    u32 first;
    u32 second;
};
extern "C" Pair D_0036c668[];
extern "C" const void* D_0036c690[32];
extern "C" s32 func_001a3458(s32,s32);
extern "C" u32 func_001a3570(...);
extern "C" u32 func_00181570(u32, u32);

u32 func_001815d0(s32 value) {
    // why: named label table keeps the switch targets while the dispatch reads the original table D_0036c690
    static const void* targets[32] asm("fm_switch_table_001815d0") = {
        &&reduce, &&fallback, &&fallback, &&fallback, &&fallback, &&fallback, &&fallback, &&fallback,
        &&reduce, &&fallback, &&fallback, &&fallback, &&fallback, &&fallback, &&fallback, &&fallback,
        &&reduce, &&fallback, &&fallback, &&fallback, &&fallback, &&fallback, &&fallback, &&fallback,
        &&reduce, &&fallback, &&fallback, &&fallback, &&fallback, &&fallback, &&fallback, &&reduce};
    u32 index = value - 0x2409;
    if (index >= 32) goto fallback;
    goto *D_0036c690[index];
reduce:
    return func_001a3458(32, 100);
fallback:
    u32 result = func_001a3570(32);
    if (result != 0) {
        for (s32 count = 0; count < 5; count++) {
            result = func_00181570(D_0036c668[count].first, D_0036c668[count].second);
        }
    }
    return result;
}
