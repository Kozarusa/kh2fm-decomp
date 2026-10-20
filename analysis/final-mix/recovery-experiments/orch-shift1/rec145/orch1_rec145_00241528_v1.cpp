#include "../common/types.h"
extern "C" s32 func_002ff3fc(...);
extern "C" u32 func_002346a0(s32,s32,s32);
extern "C" s32 D_0035ec88;
extern "C" s8* D_0035ec94;
u32 func_00241528() {
    func_002ff3fc(D_0035ec88);
    return func_002346a0(*D_0035ec94, D_0035ec88, 0);
}
