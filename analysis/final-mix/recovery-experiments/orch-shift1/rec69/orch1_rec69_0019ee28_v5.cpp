#include "../common/types.h"
struct State {
    s32 a;
    u8 pad[28];
    f32 y;
};
extern "C" State D_00350448;
extern "C" f32 D_00350464;

void func_0019ee28(s32 flag, s64 id) {
    if (id == 0xffff && flag == 1) {
        State* state = &D_00350448;
        f32 zero = 0.0f;
        state->y = zero;
        D_00350448.a = 0;
        D_00350464 = zero;
    }
}