#include "../common/types.h"
extern "C" u32 func_001ad990(s32, f32, f32, f32);

void func_00174728(s32* object) {
    f32 third = ((f32*)object)[3];
    f32 first = ((f32*)object)[1];
    s32 target = *(s32*)(object[0] + 4);
    f32 second = ((f32*)object)[2];
    func_001ad990(target + 0x8c8, first, second, third);
}
