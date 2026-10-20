#include "../common/types.h"
extern "C" u64 func_00290960(...);
extern "C" s32 func_00290940(u32);
extern "C" u64 func_00293db8(s32,const char*);
extern "C" u32 D_0035f574;
u64 func_00293fc0() {
    func_00290940(D_0035f574);
    u64 result = func_00293db8(0,0);
    return func_00290960(D_0035f574,result,43);
}
