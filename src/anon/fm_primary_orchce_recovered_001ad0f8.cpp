#include "../common/types.h"
extern "C" void func_001ac970(u8*, s32, s32, s32, s32, s32, s32, s32);
extern "C" f32 D_0036d7a0;
extern "C" u8 D_00350b70[];

void func_001ad0f8(u8* object, s32 first, s32 second) {
    func_001ac970(object, 3, 5, first, second, 128, 104, 0);
    // why: bind pointer to t7 like the original so the vtable address reuses it
    register f32* source asm("$15") = &D_0036d7a0;
    // why: empty guard keeps the global address in a register instead of folding it into lwc1
    asm("" : "+r"(source));
    *(f32*)(object + 104) = *source;
    // why: vtable address also lives in t7 in the original
    register u8* table asm("$15") = D_00350b70;
    asm("" : "+r"(table));
    *(u8**)object = table;
}
