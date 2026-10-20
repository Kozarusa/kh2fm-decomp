#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));

struct Local {
    u8 head[12];
    s32 zero;
    Quad value;
};

extern "C" u32 func_001902a8(Local*, Local*);

Quad* func_00190388(Quad* destination, Local* source) {
    Local local;
    register Quad* result asm("$16") = &local.value; // why: original keeps the value address in s0
    asm("" : "+r"(result)); // why: keeps the value address live in s0 across the call
    local.zero = 0;
    func_001902a8(source, &local);
    *destination = *result;
    return destination;
}
