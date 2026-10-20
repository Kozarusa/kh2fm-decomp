#include "../common/types.h"
extern "C" u32 func_0023acd8(u32*);
extern "C" u32 func_0023ade0(u32*);

void func_001abba8(u32* object) {
    u32* base = object + 5;
    func_0023acd8(base);
    u32 high = object[4];
    base[83] = high;
    base[82] = object[3];
    func_0023ade0(base);
}