#include "../common/types.h"
extern "C" u32 func_001ad990(u8*, f32, f32, f32);

void func_00174728(s32* object) {
    f32* floats = (f32*)object;
    func_001ad990(*(u8**)(object[0] + 4) + 0x8c8, floats[1], floats[2], floats[3]);
}
