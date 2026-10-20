#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u32 func_00185118(...);
extern "C" u64 func_00143928(...);

s32 func_0019bf50(u8* object, Quad* other) {
    func_00185118();
    Quad* dst = (Quad*)(object + 0x590);
    if (dst != (Quad*)(object + 0x540)) {
        // why: original copies the quad through t0 ($8)
        register Quad temp asm("$8") = *(Quad*)(object + 0x540);
        *dst = temp;
    }
    Quad* vec = (Quad*)(object + 0x5a0);
    if (vec != other) {
        // why: original copies the quad through t0 ($8)
        register Quad temp2 asm("$8") = *other;
        *vec = temp2;
    }
    u64* flags = (u64*)(object + 0x600);
    *flags = *flags & ~1ull;
    func_00143928();
    return (s32)*(u32*)(object + 0x604) & 1;
}