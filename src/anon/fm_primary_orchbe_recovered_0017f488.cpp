#include "../common/types.h"
extern "C" void func_0017f380(s32);
extern "C" void func_0017f268(s32, s32, f32, f32);

// Preserve original registry aliases.
void func_0017f488(s32 a, s32 b, f32 x, f32 y) asm("_Z13func_0017f488iiff");

void func_0017f488(s32 a, s32 b, f32 x, f32 y) {
    func_0017f380(a);
    func_0017f268(a, b, x, y);
}
