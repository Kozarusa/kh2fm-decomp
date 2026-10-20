#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct Buf { Quad q; s32 a; s32 b; };
extern "C" bool func_001d35e0(Buf*, u64, u64);

s32 func_001a7588(u64 first, u64 second, Buf* dest) {
    Buf buf;
    if (func_001d35e0(&buf, first, second) != 0 && dest != &buf) {
        dest->q = buf.q;
    }
    return buf.b;
}
