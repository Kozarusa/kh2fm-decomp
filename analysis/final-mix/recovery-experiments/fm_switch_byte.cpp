#include "../common/types.h"

extern const void* D_003739b0[5];
extern s8* D_0035f12c;

// Original signed byte loads and the common fallback return are preserved.
s32 func_00272c20(u32 index) {
    static const void* targets[5] asm("fm_switch_table_00272c20") = {&&case0, &&case1, &&case2, &&case3, &&case4};
    s32 result = -1;
    if (index >= 5) goto done;
    goto *D_003739b0[index];
case0: return 4;
case1: return D_0035f12c[0];
case2: return D_0035f12c[1];
case3: return 1;
case4: result = D_0035f12c[2];
done:
    return result;
}
