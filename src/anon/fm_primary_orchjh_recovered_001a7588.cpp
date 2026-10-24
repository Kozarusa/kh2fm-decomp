#include "../common/types.h"
struct Vec { s32 x; s32 y; s32 z; s32 w; } __attribute__((aligned(16)));
struct Buf { Vec vec; s32 a; s32 b; };
extern "C" bool func_001d35e0(...);

s32 func_001a7588(u64 first, u64 second, Vec* dest) {
    Buf buf;
    asm("" : "+r"(dest)); // why: original treats dest as possibly aliasing buf and reloads the result after the copy
    if (func_001d35e0(&buf, first, second) != 0 && dest != &buf.vec) {
        // why: original copies with lq/sq through $8 (SDK quad copy primitive), kept out of the branch delay slot
        asm volatile("lq $8,0(%1); sq $8,0(%2)" : "=m"(*dest) : "r"(&buf.vec), "r"(dest), "m"(buf.vec) : "$8");
    }
    return buf.b;
}
