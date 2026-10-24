#include "../common/types.h"
extern "C" s8* D_0035ec94;
extern "C" s32 D_0035ec88;
extern "C" s32 D_0035ec90;
extern "C" s32 func_002346f0(u64,u64,u64,u64,u64);
extern "C" u64 func_002416d8(u64);

s32 func_00241608(u64 value, u64 first, u64 second) {
    u64 result = func_002416d8(value);
    s8* pointer = D_0035ec94;
    u64 chosen = first;
    if (!first) chosen = D_0035ec88;
    u64 other = second;
    if (!other) other = D_0035ec90;
    return func_002346f0(*pointer, chosen, other, result, 0);
}
