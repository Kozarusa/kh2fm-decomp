#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" Quad D_0034aa50[2];
extern "C" Quad* func_0016c028(s32);

void func_00159ef8(u8* object) {
    register Quad* source asm("$16") = (Quad*)(object + 0x80);  // why: original keeps the source in s0 across the call
    asm("" : "+r"(source));  // why: stops the compiler re-deriving the source from object
    Quad* result = func_0016c028(*(s32*)(object + 0x44));
    register Quad* dest asm("$15") = D_0034aa50;  // why: original uses t7 as the destination cursor
    asm("" : "+r"(dest));  // why: keeps t7 cursor binding
    if (source != dest) {
        register Quad value asm("$8") = *source;  // why: original quad temp is t0
        asm("" : "+r"(value));  // why: keeps t0 quad temp binding
        *dest = value;
    }
    dest++;
    asm("" : "+r"(dest));  // why: keeps t7 cursor advance
    if (result != dest) {
        register Quad value asm("$8") = *result;  // why: original quad temp is t0
        asm("" : "+r"(value));  // why: keeps t0 quad temp binding
        *dest = value;
    }
}

