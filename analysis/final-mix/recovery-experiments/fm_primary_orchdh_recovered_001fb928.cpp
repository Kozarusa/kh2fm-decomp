#include "../common/types.h"

union Cell {
    u8 b;
    u16 h;
    u32 w;
    f32 f;
};

extern "C" void func_001fab48(void*);

void func_001fb928(u8* object, Cell* source, u8* other) {
    asm("" : "+r"(other)); // why: keeps the load of other+12 after the prologue moves
    u8* base = object + **(s32**)(other + 12) + 160;
    func_001fab48(object);
    if (source[0].w == *(u32*)(object + 12)) {
        ((Cell*)(base + 32))->f = ((Cell*)((u8*)source + 12))->f;
        ((Cell*)(base + 40))->f = (f32)((Cell*)((u8*)source + 16))->h;
        ((Cell*)(base + 44))->f = (f32)((Cell*)((u8*)source + 18))->h;
    }
}
