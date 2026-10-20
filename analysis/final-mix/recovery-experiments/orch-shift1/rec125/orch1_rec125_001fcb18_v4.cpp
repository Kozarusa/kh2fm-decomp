#include "../common/types.h"

extern "C" u8* D_01d9e6e8;
extern "C" u8 D_01d9e840[];
extern "C" u8 D_01d9e8c0[];
extern "C" void func_002f3d08(u8*, u8*, u8*);
extern "C" void func_002f3f98(u8*, u8*);

void func_001fcb18(u8* object, s32 unused, u8* other) {
    u8* self = object;
    asm("" : "+r"(self)); // why: keeps the copy of object in its own register early
    self += *(s32*)(*(u8**)(other + 12) + 4);
    func_002f3d08(D_01d9e6e8 + 80, D_01d9e840, D_01d9e6e8 + 16);
    func_002f3f98(self + 160, D_01d9e6e8 + 80);
    func_002f3d08(D_01d9e6e8 + 80, D_01d9e8c0, D_01d9e6e8 + 80);
}