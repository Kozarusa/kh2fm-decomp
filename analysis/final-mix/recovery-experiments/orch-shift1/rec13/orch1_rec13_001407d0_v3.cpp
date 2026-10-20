#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u32 func_0015ce80(...);
extern "C" void func_0015ce90(...);
extern "C" void func_0015cea0(Quad*);
extern "C" void func_0015ceb8(Quad*);
extern "C" f32 func_0015ced0();
extern "C" f32 func_0015cee0();

void func_001407d0(u8* object) {
    Quad temp;
    if (func_0015ce80(object) != 0) {
        func_0015ceb8(&temp);
        if (object != (u8*)&temp) {
            // why: original moves the quad through t0 ($8), like the accepted copy helpers
            asm volatile("lq $8,0(%1); sq $8,0(%0)" : : "r"(object), "r"(&temp) : "$8", "memory");
        }
        u8* second = object + 16;
        func_0015cea0(&temp);
        if (second != (u8*)&temp) {
            // why: original moves the quad through t0 ($8), like the accepted copy helpers
            asm volatile("lq $8,0(%1); sq $8,0(%0)" : : "r"(second), "r"(&temp) : "$8", "memory");
        }
        *(f32*)(object + 32) = func_0015ced0();
        *(f32*)(object + 36) = func_0015cee0();
        func_0015ce90();
    }
}