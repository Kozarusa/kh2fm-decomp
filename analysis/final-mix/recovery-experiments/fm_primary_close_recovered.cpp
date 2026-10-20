#include "../common/types.h"

extern "C" u32 func_00195558(void*);
extern "C" u32 func_002fde18(...);
extern "C" u32 func_001050d8(u32);
extern "C" u32 func_00135e50(u32);
extern "C" u32 func_00139d78(void);
extern "C" u32 func_00306f30(s32);
extern u8 D_0034f250, D_0034fa78;

void func_00195750(void) {
    func_00195558(&D_0034f250);
    func_00195558(&D_0034fa78);
}

void func_00135dc8(s32* destination) {
    u32 allocated = func_001050d8(0x110);
    func_00135e50(allocated);
    *(volatile u32*)(allocated + 4) = (u32)destination;
    *(volatile u32*)destination = allocated;
}

void func_0023f0c8(s32 object, u32 value) {
    register s32 savedObject asm("$16") = object;
    register u32 savedValue asm("$17") = value;
    func_00139d78();
    asm("" : : "r"(savedObject), "r"(savedValue));
    *(u32*)(savedObject + 0x90) = savedValue;
}
