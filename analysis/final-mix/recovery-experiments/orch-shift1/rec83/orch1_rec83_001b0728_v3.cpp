#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" f32 D_0036d96c;
extern "C" void func_001ad990(u32 pointer, f32 a, f32 b, f32 c);

void func_001b0728(u8* object, Quad* source, s32 value, f32 scale) {
    Quad* destination = (Quad*)(object + 32);
    if (*(s32*)(object + 12) < 0) return;
    *(s32*)(object + 4) = 1;
    if (destination != source) {
        *destination = *source;
    }
    func_001ad990((u32)(object + 16), 0.0f, D_0036d96c, scale);
    *(s32*)(object + 8) = value;
}
