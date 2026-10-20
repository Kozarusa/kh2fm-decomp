#include "../common/types.h"
extern "C" volatile f32 D_0036a3dc;
extern "C" volatile f32 D_0036a3e0;
extern "C" f32 D_00340eb4;
extern "C" f32 D_00340eb8;
extern "C" f32 D_00340ebc;
extern "C" f32 D_00340ec0;

void func_0010a828(f32 near, f32 far) {
    f32 scaled = far * D_0036a3dc;
    D_00340eb8 = far;
    D_00340eb4 = near;
    far = far - near;
    D_00340ec0 = scaled / far;
    D_00340ebc = D_0036a3e0 / far;
}

