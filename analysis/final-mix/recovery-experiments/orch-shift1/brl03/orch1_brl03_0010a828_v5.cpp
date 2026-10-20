#include "../common/types.h"
extern "C" f32 D_0036a3dc;
extern "C" f32 D_0036a3e0;
extern "C" f32 D_00340eb4;
extern "C" f32 D_00340eb8;
extern "C" f32 D_00340ebc;
extern "C" f32 D_00340ec0;

void func_0010a828(f32 near, f32 far) {
    f32* scalePointer = &D_0036a3dc;
    // why: original materializes the constant address with lui+addiu and loads from 0(reg)
    asm("" : "+r"(scalePointer));
    f32 scaled = far * *scalePointer;
    D_00340eb8 = far;
    D_00340eb4 = near;
    f32 range = far - near;
    f32* offsetPointer = &D_0036a3e0;
    // why: original materializes the constant address with lui+addiu and loads from 0(reg)
    asm("" : "+r"(offsetPointer));
    f32 offset = *offsetPointer;
    D_00340ebc = offset / range;
    D_00340ec0 = scaled / range;
}
