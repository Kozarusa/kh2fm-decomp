#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u32 func_0016e920(u32);
extern "C" void func_001a7888(Quad*,Quad*,s32,f32,f32);
extern "C" Quad* func_001a78c0(Quad*, Quad*, s32, f32, f32, f32, f32);

Quad* func_0019b0e8(Quad* result, u32 chara, Quad* position, f32 first, f32 second) {
    u8* data = (u8*)func_0016e920(chara);
    u8 flag = (*(u16*)(data + 0x48) >> 3) & 1;
    if (flag) {
        func_001a78c0(result, position, 2, 0.0f, first, -second, second);
    } else {
        func_001a7888(result, position, 1, 0.0f, first);
    }
    return result;
}
