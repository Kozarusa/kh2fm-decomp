#include "../common/types.h"
extern "C" s32 D_003660a8;
extern "C" s32 D_003660ac;
extern "C" u32 func_003060f0(void);
extern "C" s32 func_0030edb0(void);

u32 func_002fded8(void) {
    u32 result = func_003060f0();
    if (result != 1) {
        if (D_003660a8 == 0) {
            result = func_0030edb0();
            D_003660ac = result;
        }
        D_003660a8 = D_003660a8 + 1;
    }
    return result;
}
