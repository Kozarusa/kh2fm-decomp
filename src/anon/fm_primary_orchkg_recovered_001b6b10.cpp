#include "../common/types.h"
extern "C" u8 D_0032f054;
extern "C" u8 D_0032bb30[];
extern "C" bool func_0019ba60(u8*);
extern "C" u32 func_001050d8(u64);
extern "C" void func_001b6298(u32, u8*, u32, u32);
extern "C" void func_0016bd60(u32, s32);
extern "C" void func_0017f488(f32, f32, s32, u32);
extern "C" void func_001c9860(s32);

void func_001b6b10(u8* object, s32 value) {
    func_0019ba60(object);
    if (value == D_0032f054) {
        return;
    }
    u32 block = func_001050d8(32);
    func_001b6298(block, object, value, 0);
    if (value != 0) {
        func_0016bd60((u32)object, 0);
        func_0017f488(0.0f, 0.0f, (s32)object + 0x140, 52);
        // why: original zero-fills the vector with a VU macro, pattern from accepted 002c17d8
        asm volatile("vsub.wxyz $vf1,$vf0,$vf0; sqc2 $vf1,0(%0)" : : "r"(object + 0x20) : "memory");
        func_001c9860(value);
    } else {
        *(u8*)(block + 28) = 1;
    }
    *(u32*)(object + 0x108) |= 0x100;
    // why: original forms the D_0032bb30 base in t6 ($14)
    register u8* state asm("$14") = D_0032bb30;
    asm("" : "+r"(state)); // why: original forms the full D_0032bb30 address before the byte store
    state[13604] = value;
}
