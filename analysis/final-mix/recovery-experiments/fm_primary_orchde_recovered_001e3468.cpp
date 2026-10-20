#include "../common/types.h"
extern "C" u8 D_01d9e370[];
extern "C" u8 D_01d9e6f0[];
extern "C" void func_002f3cd8(u8*, u8*, u8*);

u8* func_001e3468(u8* object) {
    s32 index = 0;
    u8* base = *(u8**)(object + 140);
    do {
        s32 offset = index << 4;
        index++;
        func_002f3cd8(D_01d9e370 + offset, D_01d9e6f0, base + offset);
    } while (index < 8);
    return D_01d9e370;
}
