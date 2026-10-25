#include "../common/types.h"

extern "C" u8* D_01d9e6e8;
extern "C" u8 D_01d9e730[];
extern "C" u8 D_01d9e8c0[];
// why: declarations copied from the accepted sibling fm_primary_orchdh_recovered_001fcb18.cpp, which calls both
extern "C" void func_002f3d08(u8*, u8*, u8*);
extern "C" void func_002f3f98(u8*, u8*);

void func_00209df0(u8* object, s32 unused, u8* other) {
    object += *(s32*)(*(u8**)(other + 12) + 4);
    register u8* global asm("$4") = D_01d9e6e8; // why: original loads the global into a0
    func_002f3d08(global + 80, object + 224, global + 16);
    func_002f3d08(D_01d9e6e8 + 80, D_01d9e730, D_01d9e6e8 + 80);
    func_002f3f98(object + 160, D_01d9e6e8 + 80);
    func_002f3d08(D_01d9e6e8 + 80, D_01d9e8c0, D_01d9e6e8 + 80);
    asm volatile("" ::: "memory"); // why: original calls with jal and returns itself (no sibling tail call, v1 emitted j)
}
