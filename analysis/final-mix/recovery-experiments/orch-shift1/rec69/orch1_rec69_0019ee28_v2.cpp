#include "../common/types.h"
struct State {
    s32 a;
    u8 pad[24];
    f32 x;
    f32 y;
};
extern "C" State D_00350448;

void func_0019ee28(s32 flag, s64 id) {
    if (id == 0xffff && flag == 1) {
        D_00350448.y = 0.0f;
        D_00350448.a = 0;
        D_00350448.x = 0.0f;
    }
}