#include "../common/types.h"
struct Vec { u32 x, y, z, w; } __attribute__((aligned(16)));
struct Temp {
    u8 head[12];
    u32 zero;
    Vec value;
};
extern "C" u32 func_001903d0(u64, Temp*);

Vec func_001904a8(u64 source) {
    Temp local;
    Vec* pointer = &local.value;
    local.zero = 0;
    func_001903d0(source, &local);
    // why: keeps the quad address in a saved register across the call
    asm("" : "+r"(pointer));
    return *pointer;
}