#include "../common/types.h"
extern "C" s64 func_001db9a8(u64, u64, u64);
extern "C" u32 func_001050d8(u64);
extern "C" void func_001ce3e8(u32, u32, u32, u32, f32);

u32 func_001ce488(u32 first, u32 second, f32 scale) {
    u32 handle = func_001db9a8(first, 0, 1000);
    u32 object = func_001050d8(0xa00);
    func_001ce3e8(object, handle, first, second, scale);
    return object;
}