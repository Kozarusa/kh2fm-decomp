#include "../common/types.h"
extern "C" f32 D_0036a3dc;
extern "C" f32 D_0036a3e0;
extern "C" f32 D_00340eb4;
extern "C" f32 D_00340eb8;
extern "C" f32 D_00340ebc;
extern "C" f32 D_00340ec0;

void func_0010a828(f32 near, f32 far) {
    // why: original materializes each constant address with lui+addiu before the load
    volatile f32* scalePointer = &D_0036a3dc;
    volatile f32* offsetPointer = &D_0036a3e0;
    f32 scaled = far * *scalePointer;
    D_00340eb8 = far;
    D_00340eb4 = near;
    far = far - near;
    f32 offset = *offsetPointer;
    D_00340ec0 = scaled / far;
    D_00340ebc = offset / far;
}
