#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
struct FmVector;
extern "C" u8* D_01d9e6e8;
extern "C" f32 D_00354be0[];
extern "C" f32 D_01d9e940[];
extern "C" u8 D_01d9e900[];
// why: exact types of the accepted C++-linkage definition in fm_fallback_vector.cpp; extern "C" because the isolated probe linker script only defines the plain func_002f3f40 symbol
extern "C" void func_002f3f40(FmVector* target, const FmVector* source, f32 multiplier);
extern "C" void func_002f3d08(u8*, f32*, u8*);
extern "C" void func_002f3cd8(u8*, u8*, u8*);

void func_001eb460() {
    func_002f3f40((FmVector*)(D_01d9e6e8 + 80), (const FmVector*)(D_01d9e6e8 + 16), D_00354be0[0]);
    func_002f3f40((FmVector*)(D_01d9e6e8 + 96), (const FmVector*)(D_01d9e6e8 + 32), D_00354be0[1]);
    func_002f3f40((FmVector*)(D_01d9e6e8 + 112), (const FmVector*)(D_01d9e6e8 + 48), D_00354be0[2]);
    f32* matrix = D_01d9e940;
    asm("" : "+r"(matrix)); // why: original materializes the D_01d9e940 address before the quad copy
    *(Quad*)(D_01d9e6e8 + 128) = *(Quad*)(D_01d9e6e8 + 64);
    asm volatile("" ::: "memory"); // why: keeps store order, original reloads D_01d9e6e8 after the quad store
    func_002f3d08(D_01d9e6e8 + 80, matrix, D_01d9e6e8 + 80);
    func_002f3cd8(D_01d9e6e8 + 128, D_01d9e900, D_01d9e6e8 + 64);
}
