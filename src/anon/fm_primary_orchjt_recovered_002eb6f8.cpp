#include "../common/types.h"
extern "C" void func_00180c88(s32, s32, f32);
extern "C" u32 func_002eaf40(s32);
extern "C" void func_0017f488(f32, f32, s32, u32);

void func_002eb6f8(s32 object, s32 index, f32 value) {
    if (index >= 0) {
        func_00180c88(object + 320, index, value);
        func_002eaf40(object);
        func_0017f488(value, 0.0f, func_002eaf40(object) + 320, index - 101);
    }
}
