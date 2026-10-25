#include "../common/types.h"
struct FmVector;
extern "C" u8* D_01d9e6e8;
extern "C" f32 D_00354be0[];
extern "C" u8 D_01d9e840[];
extern "C" u8 D_01d9e8c0[];
extern "C" u8 D_01dad890[];
extern "C" u8 D_01dad8d0[];
// why: copied from the accepted call site in fm_primary_orchkf_recovered_001eb460.cpp (C++ definition in fm_fallback_vector.cpp)
extern "C" void func_002f3f40(FmVector* target, const FmVector* source, f32 multiplier);
// why: copied from the accepted call site in fm_primary_orchdh_recovered_001fcb18.cpp; accepted definition (queuezeta 002f3d08) is void
extern "C" void func_002f3d08(u8*, u8*, u8*);
// why: copied from the accepted call site in fm_primary_orchkf_recovered_001eb460.cpp
extern "C" void func_002f3cd8(u8*, u8*, u8*);

void func_001fcd70() {
    func_002f3d08(D_01dad890, D_01d9e840, D_01dad8d0);
    func_002f3f40((FmVector*)(D_01d9e6e8 + 80), (const FmVector*)(D_01d9e6e8 + 16), D_00354be0[0]);
    func_002f3f40((FmVector*)(D_01d9e6e8 + 96), (const FmVector*)(D_01d9e6e8 + 32), D_00354be0[1]);
    func_002f3f40((FmVector*)(D_01d9e6e8 + 112), (const FmVector*)(D_01d9e6e8 + 48), D_00354be0[2]);
    func_002f3cd8(D_01d9e6e8 + 128, D_01d9e840, D_01d9e6e8 + 64);
    func_002f3d08(D_01d9e6e8 + 80, D_01d9e8c0, D_01d9e6e8 + 80);
}
