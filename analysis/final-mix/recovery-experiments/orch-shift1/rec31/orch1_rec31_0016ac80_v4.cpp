#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u32 func_001dc5f8(u64);
extern "C" u64 func_0016abf8(s32,u64,u64,u64);

u64 func_0016ac80(s32 a, u64 b, Quad* source, u64 c, u64 d) {
    u64 result = func_0016abf8(a, b, c, d);
    if (result != 0) {
        Quad* dest = (Quad*)func_001dc5f8(result);
        if (dest != source) {
            // why: original used t0 ($8) for the quad copy temporary
            register Quad tmp asm("$8") = *source;
            *dest = tmp;
        }
    }
    return result;
}
