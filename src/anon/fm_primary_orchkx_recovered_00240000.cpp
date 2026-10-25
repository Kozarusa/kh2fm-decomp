#include "../common/types.h"
extern "C" u32 D_0035ec88;
extern "C" u32 D_0035ec8c;
extern "C" u32 D_0035ec90;
extern "C" u32 D_0035ec94;
extern "C" u32 D_0035ec98;
extern "C" u32 D_0035ec9c;
extern "C" u32 D_0035eca0;
extern "C" u32 D_0035eca4;
// why: the recovered call sites declare the parameter s64, but probes v1 and v2 of this target show that type adds a 64-bit extension the original does not have; the original passes the loaded word unchanged
extern "C" u32 func_00106450(u32);
extern "C" void func_00106420(u32);
// why: no recovered source calls or defines this callee; one word argument in a0 taken from its instructions, result unused here
extern "C" void func_00242048(u32);

// Preserve original registry aliases.
void func_00240000() asm("_Z16u_call0_00240000v");

void func_00240000() {
    u32 object;
    if (D_0035ec88 != 0) {
        func_00106450(D_0035ec88);
        D_0035ec88 = 0;
    }
    if (D_0035ec8c != 0) {
        func_00106450(D_0035ec8c);
        D_0035ec8c = 0;
    }
    if (D_0035ec90 != 0) {
        func_00106450(D_0035ec90);
        D_0035ec90 = 0;
    }
    if (D_0035ec94 != 0) {
        func_00106420(D_0035ec94);
        D_0035ec94 = 0;
    }
    if (D_0035ec98 != 0) {
        func_00106420(D_0035ec98);
        D_0035ec98 = 0;
    }
    if (D_0035eca0 != 0) {
        func_00106450(D_0035eca0);
        D_0035eca0 = 0;
    }
    object = D_0035eca4;
    D_0035ec9c = 0;
    if (object != 0) {
        func_00242048(object);
        func_00106420(object);
        D_0035eca4 = 0;
    }
}
