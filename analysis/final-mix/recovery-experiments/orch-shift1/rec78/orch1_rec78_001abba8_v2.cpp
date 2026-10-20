#include "../common/types.h"
extern "C" u32 func_0023acd8(u8*);
extern "C" u32 func_0023ade0(u8*);

void func_001abba8(u8* object) {
    u8* base = object + 20;
    func_0023acd8(base);
    u32 first = *(u32*)(object + 16);
    u32 second = *(u32*)(object + 12);
    *(u32*)(base + 332) = first;
    *(u32*)(base + 328) = second;
    func_0023ade0(base);
}
