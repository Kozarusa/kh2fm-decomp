#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" Quad D_0034eef0[];
extern "C" Quad D_0034ef00[];

void func_0018e108(Quad* source0, Quad* source1) {
    register Quad* target0 asm("$15") = D_0034eef0; // why: original keeps the destination address in t7
    asm("" : "+r"(target0)); // why: stops the offset being folded into the store
    if (source0 != target0) {
        register Quad value asm("$8") = *source0; // why: original moves the quad through t0
        *target0 = value;
    }
    register Quad* target1 asm("$15") = D_0034ef00; // why: original keeps the destination address in t7
    asm("" : "+r"(target1)); // why: stops the offset being folded into the store
    if (source1 != target1) {
        register Quad value asm("$8") = *source1; // why: original moves the quad through t0
        *target1 = value;
    }
}
