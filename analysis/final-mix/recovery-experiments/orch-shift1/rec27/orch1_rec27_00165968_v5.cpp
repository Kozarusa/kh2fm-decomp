#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" void func_00106420(...);
extern "C" u8* D_0034c7a0;

void func_00165968() {
    // why: original keeps the pointer in a0 and the loop cursor in t7
    register u8* base asm("$4") = D_0034c7a0;
    if (base != 0) {
        register Quad* cursor asm("$15") = (Quad*)(base + 0x400);
        asm("" : "+r"(base), "+r"(cursor));
        do {
            // why: original loop body is five nop words (inlined empty destructor loop)
            asm volatile("nop\n\tnop\n\tnop\n\tnop\n\tnop");
        } while ((u8*)cursor-- != base);
        func_00106420();
        D_0034c7a0 = 0;
    }
}
