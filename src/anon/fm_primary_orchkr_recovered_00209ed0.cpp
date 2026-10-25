#include "../common/types.h"
struct FmVector;
extern "C" u8* D_01d9e6e8;
extern "C" f32 D_01d9e730[];
extern "C" f32 D_01d9e8c0[];
extern "C" void func_002f4000(f32*);
// why: exact types of the accepted C++-linkage definition in fm_fallback_vector.cpp; extern "C" because the isolated probe linker script only defines the plain func_002f3f40 symbol (copied from fm_primary_orchkq_recovered_00200700.cpp)
extern "C" void func_002f3f40(FmVector* target, const FmVector* source, f32 multiplier);
extern "C" void func_002f3d08(u8*, f32*, u8*);
extern "C" void func_002f3cd8(u8*, u8*, u8*);
// why: copied from the call site in fm_primary_orchkq_recovered_001fcb90.cpp
extern "C" void func_002f3f98(u8*, u8*);

// why: a1 is never read but a2 (owner) is, so the second word parameter must exist; void because the only exit is the final call to func_002f3d08, whose accepted definition (fm_primary_queuezeta_recovered_002f3d08.cpp) is void (DEVIATIONS #36 stale-b), structure copied from the same-shape sibling fm_primary_orchkq_recovered_00200700.cpp

void func_00209ed0(u32 object, u32 unused, u32 owner) {
    f32 matrix[16];
    u32 base = object + *(s32*)(*(u32*)(owner + 12) + 4);
    func_002f4000(matrix);
    f32* source = (f32*)(base + 160);
    f32 x = source[16];
    f32 y = source[17];
    f32 z = source[18];
    matrix[12] = x;
    matrix[13] = y;
    matrix[14] = z;
    func_002f3d08((u8*)matrix, D_01d9e730, (u8*)matrix);
    func_002f3f40((FmVector*)(D_01d9e6e8 + 80), (const FmVector*)(D_01d9e6e8 + 16), source[20]);
    func_002f3f40((FmVector*)(D_01d9e6e8 + 96), (const FmVector*)(D_01d9e6e8 + 32), source[21]);
    func_002f3f40((FmVector*)(D_01d9e6e8 + 112), (const FmVector*)(D_01d9e6e8 + 48), source[22]);
    func_002f3cd8(D_01d9e6e8 + 128, (u8*)matrix, D_01d9e6e8 + 64);
    func_002f3f98((u8*)source, D_01d9e6e8 + 80);
    func_002f3d08(D_01d9e6e8 + 80, D_01d9e8c0, D_01d9e6e8 + 80);
}
