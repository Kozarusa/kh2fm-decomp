#include "../common/types.h"
extern "C" u32 D_0035f638;
extern "C" u32 func_0023f900(u32);
extern "C" s64 func_00292630();
extern "C" u32 func_00294000(u32);
extern "C" u64 func_00293db8(s32,const char*);
extern "C" u32 func_0023fa08(s32,u64);
s64 func_002b27c8() {
    func_0023f900(D_0035f638);
    s64 result = func_00292630();
    if (result != 0) return result;
    u32 address = func_00294000(9);
    u64 data = func_00293db8(5, (const char*)((address + ((u32)(s32)*(s8*)(D_0035f638 + 52) << 4)) + 22));
    result = (s32)func_0023fa08(D_0035f638, data);
    *(u32*)(D_0035f638 + 52) |= 0x200;
    return result;
}

