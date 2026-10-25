#include "../common/types.h"
#include "../kn/fvector.hpp"
struct __attribute__((aligned(16))) Matrix { f32 columns[4][4]; };
struct __attribute__((aligned(16))) Bounds { f32 values[8]; };
extern "C" void func_002d0718(Bounds*);
extern "C" void func_0011b6a8(void*);
extern "C" Matrix* func_0011b720(void*, f32);
extern "C" void func_001449a8(u8* box, kn::FVector* rows);
extern "C" s32 func_002cec08(u8*, Bounds*);

bool func_002cee58(u8* frustum, u8* object) {
    Bounds bounds;
    Matrix matrix;
    func_002d0718(&bounds);
    func_0011b6a8(&matrix);
    func_0011b720(&matrix, *(f32*)(object + 20));
    kn::FVector offset;
    f32* lanes = (f32*)&offset;
    lanes[0] = *(f32*)(object + 4);
    lanes[1] = *(f32*)(object + 8);
    lanes[2] = *(f32*)(object + 12);
    lanes[3] = 0.0f;
    // why: VU0 macro vector add on xyz of the matrix translation row; accepted sibling pattern (0018e8f0 vadd), no plain C form for lqc2/vadd/sqc2
    asm volatile("lqc2 $vf1,48(%0); lqc2 $vf2,0(%1); vadd.xyz $vf1,$vf1,$vf2; sqc2 $vf1,48(%0)"
                 : : "r"(&matrix), "r"(&offset) : "memory");
    func_001449a8((u8*)&bounds, (kn::FVector*)&matrix);
    return func_002cec08(frustum, &bounds) != 0;
}
