#include "../common/types.h"
extern "C" u32 func_0023acd8(u8*);
extern "C" u32 func_0023ade0(u8*);

void func_001abba8(u8* object) {
    u8* base = object + 20;
    func_0023acd8(base);
    // why: volatile reads keep both loads before the stores
    *(u32*)(base + 332) = *(volatile u32*)(object + 16);
    *(u32*)(base + 328) = *(volatile u32*)(object + 12);
    func_0023ade0(base);
}
