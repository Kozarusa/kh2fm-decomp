#include "../common/types.h"

extern "C" u8 D_003590b0;
extern "C" void func_0021f5d8(u8*);

void func_001fb478(u8* object, s32** other) {
    u8* base = object + **(s32**)((u8*)other + 12);
    base += 160;
    func_0021f5d8(base);
    *(s32*)(base + 156) = 0;
    *(s32*)(base + 168) = 0;
    u8 value = D_003590b0;
    base[141] = 2;
    base[140] = value;
    base[193] = 0;
    base[192] = 0;
    D_003590b0 = D_003590b0 + 1;
}