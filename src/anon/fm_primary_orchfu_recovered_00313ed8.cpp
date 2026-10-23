#include "../common/types.h"
extern "C" u32 func_003147a0(void*, void*);
extern "C" void* func_00313c58(void*, void*, void*);
extern "C" u64 func_003146c8(void*);

u64 func_00313ed8(u64 first, u64 second) {
    u8 left[32];
    u32 right[8];
    u8 output[32];
    u64 firstSlot = first;
    u64 secondSlot = second;
    func_003147a0(&firstSlot, left);
    func_003147a0(&secondSlot, right);
    right[1] = right[1] ^ 1;
    void* handle = func_00313c58(left, right, output);
    return func_003146c8(handle);
}
