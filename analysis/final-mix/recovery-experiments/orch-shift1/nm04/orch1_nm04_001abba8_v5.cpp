#include "../common/types.h"
extern "C" u32 func_0023acd8(u32*);
extern "C" u32 func_0023ade0(u32*);

void func_001abba8(u32* object) {
    u32* base = object + 5;
    func_0023acd8(base);
    base[83] = object[4];
    // why: keeps store order
    *(volatile u32*)&base[82] = object[3];
    func_0023ade0(base);
}