#include "../common/types.h"
struct FmVector;
extern "C" u8* D_01d9e6e8;
extern "C" f32 D_00354be0[];
extern "C" u8 D_01d9e840[];
extern "C" u8 D_01d9e8c0[];
// why: exact types of the accepted C++-linkage definition in fm_fallback_vector.cpp; extern "C" because the isolated probe linker script only defines the plain func_002f3f40 symbol (copied from the call site in fm_primary_orchkf_recovered_001eb460.cpp)
extern "C" void func_002f3f40(FmVector* target, const FmVector* source, f32 multiplier);
extern "C" void func_002f3cd8(u8*, u8*, u8*);
extern "C" void func_002f3d08(u8*, u8*, u8*);
extern "C" void func_002f3f98(u8*, u8*);

void func_001fcb90(u8* object, s32 unused, u8* other) {
    object += *(s32*)(*(u8**)(other + 12) + 4);
    register u8* global asm("$4") = D_01d9e6e8; // why: original loads the global into a0 (same pattern as accepted fm_primary_orchdh_recovered_001fcb18.cpp)
    func_002f3f40((FmVector*)(global + 80), (const FmVector*)(global + 16), D_00354be0[0]);
    func_002f3f40((FmVector*)(D_01d9e6e8 + 96), (const FmVector*)(D_01d9e6e8 + 32), D_00354be0[1]);
    func_002f3f40((FmVector*)(D_01d9e6e8 + 112), (const FmVector*)(D_01d9e6e8 + 48), D_00354be0[2]);
    func_002f3cd8(D_01d9e6e8 + 128, D_01d9e840, D_01d9e6e8 + 64);
    func_002f3f98(object + 160, D_01d9e6e8 + 80);
    func_002f3d08(D_01d9e6e8 + 80, D_01d9e8c0, D_01d9e6e8 + 80);
}
