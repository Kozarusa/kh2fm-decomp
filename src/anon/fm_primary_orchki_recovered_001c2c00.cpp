#include "../common/types.h"
extern "C" s32 D_01d49530[];
extern "C" s32 D_01d49550;
extern "C" u32 func_001dc978(s32, f32);

void func_001c2c00(u32 value) {
    s32 effect = D_01d49530[D_01d49550];
    if (effect != 0) {

        func_001dc978(effect, 4.0f);
    }
    s32 index = D_01d49550;
    D_01d49530[index] = value;
    D_01d49550 = (index + 1) % 8;
}
