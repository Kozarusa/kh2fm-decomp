#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Buf { Quad q; s32 a; s32 b; };
extern "C" bool func_001d35e0(...);

s32 func_001a7588(u64 first, u64 second, Quad* dest) {
    Buf buf;
    volatile s32* result = &buf.b; // why: forces a fresh load of the result on each path
    s32 value;
    bool ok = func_001d35e0(&buf, first, second) != 0;
    value = *result;
    if (ok && dest != &buf.q) {
        *dest = buf.q;
        value = *result;
    }
    return value;
}
