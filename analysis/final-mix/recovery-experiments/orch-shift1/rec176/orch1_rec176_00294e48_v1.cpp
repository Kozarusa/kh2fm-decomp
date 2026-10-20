#include "../common/types.h"
extern "C" u32 func_0023f900(s32);
extern "C" s64 func_00292630();
extern "C" u64 func_00293db8(s32,const char*);
extern "C" u32 func_0023fa08(s32,u64);
extern "C" s32 D_0035f57c;
extern "C" u8 D_0035f580;
s64 func_00294e48() {
    func_0023f900(D_0035f57c);
    s64 result = func_00292630();
    if (result == 0) {
        u64 value = func_00293db8(1,0);
        result = func_0023fa08(D_0035f57c,value);
        D_0035f580 = 1;
    }
    return result;
}
