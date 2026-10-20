#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Temp {
    u8 head[12];
    u32 zero;
    Quad value;
};
extern "C" u32 func_001903d0(u64, Temp*);

Quad* func_001904a8(Quad* result, u64 source) {
    Temp local;
    Quad* pointer = &local.value;
    local.zero = 0;
    func_001903d0(source, &local);
    // why: keeps the quad address in a saved register across the call
    asm("" : "+r"(pointer));
    // why: original copies the quad through t0 ($8)
    register Quad temp asm("$8") = *pointer;
    *result = temp;
    return result;
}