#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" s32 D_0034e948;
extern "C" Quad D_01d5bab0;
extern "C" f32 D_00352ad0;
extern "C" f32 D_00349e10;
extern "C" bool func_0019ba60(s32);
extern "C" Quad* func_0016c028(s32);

void func_001dbcd0() {
    if (func_0019ba60(D_0034e948)) {
        Quad* source = func_0016c028(D_0034e948);
        Quad* destination = &D_01d5bab0;
        if (source != destination) {
            *destination = *source;
        }
    }
    D_00352ad0 = D_00352ad0 - D_00349e10;
}