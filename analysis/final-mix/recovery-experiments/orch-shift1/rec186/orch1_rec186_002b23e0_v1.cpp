#include "../common/types.h"
extern "C" s64 func_00276608(s32);
extern "C" s32 func_002b2338(s64);
extern "C" u32 D_0035f630;
u32 func_002b23e0(s64 value) {
    if (value < 0) value = func_00276608(28);
    s32 result = func_002b2338(value);
    return D_0035f630 + (u32)result * 36u;
}
