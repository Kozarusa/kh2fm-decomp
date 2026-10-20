#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" s32 D_0034e948;
extern "C" Quad D_01d5bab0;
extern "C" f32 D_00352ad0;
extern "C" f32 D_00349e10;
extern "C" bool func_0019ba60(s32);
extern "C" Quad* func_0016c028(s32);

void func_001dbcd0() {
    if (func_0019ba60(D_0034e948)) {
        Quad* source = func_0016c028(D_0034e948);
        register Quad* destination asm("$15") = &D_01d5bab0; // why: original keeps the destination address in t7
        asm("" : "+r"(destination)); // why: keeps the address in one register for the compare and the store
        if (source != destination) {
            register Quad copy asm("$8") = *source; // why: original copies the quad through t0
            asm("" : "+r"(copy)); // why: keeps the quad in t0 until the store
            *destination = copy;
        }
    }
    D_00352ad0 = D_00352ad0 - D_00349e10;
}
