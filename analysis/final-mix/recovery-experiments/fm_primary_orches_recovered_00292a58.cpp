#include "../common/types.h"
extern "C" u32 func_002fde18(...);
extern "C" u32 func_00292998(void);
extern "C" s16 D_0035f4d8;
extern "C" s32 D_0035f4bc;
extern "C" s32 D_0035f4d4;

u32 func_00292a58(void) {
    D_0035f4d8 = 0;
    func_002fde18(D_0035f4d4, 0, (s32)((u32)D_0035f4bc << 4));
    return func_00292998();
}
