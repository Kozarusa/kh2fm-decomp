#include "../common/types.h"
struct Block {
    u32 word[6];
};
struct Pair {
    u32 first;
    u32 second;
};
extern "C" f32 D_0036d618;
extern "C" u32 func_00192990(u32 handle, u32 value, Block block, Pair* result); // why: exact types of the accepted definition; C++ linkage fails the isolated probe link (v1)
extern "C" void func_001aa388(u8*, s32);

void func_001a9970(u8* object, s32 value) {
    f32 scale;
    if (value != 0) {
        scale = (f32)value / (f32)*(*(u8**)(object + 4) + 17);
    } else {
        f32* fallback = &D_0036d618;
        asm("" : "+r"(fallback)); // why: original forms the full address (lui+addiu) before the load
        scale = *fallback;
    }
    // why: keeps store order (the compiler emits this pair reversed; original stores +40 then +56)
    *(f32*)(object + 56) = scale;
    *(f32*)(object + 40) = scale;
    if (*(u32*)(object + 8) != 0) {
        Block block;
        block.word[0] = *(u32*)(object + 36);
        block.word[1] = *(u32*)(object + 40);
        block.word[2] = *(u32*)(object + 44);
        block.word[3] = *(u32*)(object + 48);
        block.word[4] = *(u32*)(object + 52);
        block.word[5] = *(u32*)(object + 56);
        func_00192990(*(u32*)(object + 8), *(u32*)(object + 4), block, (Pair*)(object + 80));
        func_001aa388(object, *(s32*)(object + 8));
    }
}
