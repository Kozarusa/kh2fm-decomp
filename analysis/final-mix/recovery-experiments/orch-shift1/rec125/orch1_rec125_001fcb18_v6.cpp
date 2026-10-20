#include "../common/types.h"

extern "C" u8* D_01d9e6e8;
extern "C" u8 D_01d9e840[];
extern "C" u8 D_01d9e8c0[];
extern "C" void func_002f3d08(u8*, u8*, u8*);
extern "C" void func_002f3f98(u8*, u8*);

void func_001fcb18(u8* object, s32 unused, u8* other) {
    object += *(s32*)(*(u8**)(other + 12) + 4);
    u8* global = D_01d9e6e8;
    u8* third = global + 16;
    func_002f3d08(global + 80, D_01d9e840, third);
    func_002f3f98(object + 160, D_01d9e6e8 + 80);
    func_002f3d08(D_01d9e6e8 + 80, D_01d9e8c0, D_01d9e6e8 + 80);
}