#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
union ScriptCell { u32 word; f32 value; Quad* quad; u8* object; };
extern "C" Quad* func_001a78c0(Quad*, Quad*, s32, f32, f32, f32, f32);
extern "C" Quad D_01c5f480;

Quad* func_001735b0(ScriptCell* record) {
    Quad temporary;
    Quad* result = func_001a78c0(&temporary, record[0].quad, 2, record[1].value, record[2].value, record[3].value, record[4].value);
    register Quad* destination asm("$15") = &D_01c5f480; // why: original keeps the destination address in t7
    asm("" : "+r"(destination)); // why: keeps the conditional sixteen-byte load out of the branch delay slot
    if (&temporary != destination) {
        register Quad value asm("$8") = *(volatile Quad*)&temporary; // why: original copies through t0
        asm("" : "+r"(value)); // why: keeps the quad copy in t0
        *destination = value;
    }
    record[0].quad = destination;
    return result;
}
