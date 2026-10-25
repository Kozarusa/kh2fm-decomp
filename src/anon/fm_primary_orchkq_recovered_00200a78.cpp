#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct FmVector;
extern "C" u8* D_01d9e6e8;
extern "C" f32 D_01d9e730[];
extern "C" f32 D_01d9e8c0[];
extern "C" f32 D_01d9e940[];
extern "C" void func_002f4000(f32*);
// why: exact types of the accepted C++-linkage definition in fm_fallback_vector.cpp; extern "C" because the isolated probe linker script only defines the plain func_002f3f40 symbol (copied from the call site in fm_primary_orchkf_recovered_001eb460.cpp)
extern "C" void func_002f3f40(FmVector* target, const FmVector* source, f32 multiplier);
extern "C" void func_002f3d08(u8*, f32*, u8*);
extern "C" void func_002f3cd8(u8*, u8*, u8*);

void func_00200a78(u8* object, s32 unused, u8* other) {
    f32 matrix[16];
    object += *(s32*)(*(u8**)(other + 12) + 4);
    func_002f4000(matrix);
    f32* values = (f32*)(object + 160);
    f32 x = values[0];
    f32 y = values[1];
    f32 z = values[2];
    matrix[12] = x;
    matrix[13] = y;
    matrix[14] = z;
    func_002f3d08((u8*)matrix, D_01d9e730, (u8*)matrix);
    func_002f3d08((u8*)matrix, D_01d9e8c0, (u8*)matrix);
    func_002f3f40((FmVector*)(D_01d9e6e8 + 80), (const FmVector*)(D_01d9e6e8 + 16), values[4]);
    func_002f3f40((FmVector*)(D_01d9e6e8 + 96), (const FmVector*)(D_01d9e6e8 + 32), values[5]);
    func_002f3f40((FmVector*)(D_01d9e6e8 + 112), (const FmVector*)(D_01d9e6e8 + 48), values[6]);
    f32* rotation = D_01d9e940;
    asm("" : "+r"(rotation)); // why: original materializes the D_01d9e940 address before the quad copy (pattern of accepted fm_primary_orchkf_recovered_001eb460.cpp)
    *(Quad*)(D_01d9e6e8 + 128) = *(Quad*)(D_01d9e6e8 + 64);
    asm volatile("" ::: "memory"); // why: keeps store order, original reloads D_01d9e6e8 after the quad store
    func_002f3d08(D_01d9e6e8 + 80, rotation, D_01d9e6e8 + 80);
    func_002f3cd8(D_01d9e6e8 + 128, (u8*)matrix, D_01d9e6e8 + 64);
}
