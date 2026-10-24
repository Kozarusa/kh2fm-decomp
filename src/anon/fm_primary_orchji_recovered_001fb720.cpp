#include "../common/types.h"

union Cell {
    u8 b;
    u16 h;
    u32 w;
    f32 f;
};

extern "C" u32 func_001fa950(...);

u32 func_001fb720(u8* object, Cell* source, u8* other) {
    asm("" : "+r"(other)); // why: keeps the load of other+12 after the prologue moves
    u8* base = object + **(s32**)(other + 12) + 160;
    u32 result = func_001fa950(object);
    if (source[0].w == *(u32*)(object + 12)) {
        ((Cell*)(base + 68))->f = ((Cell*)((u8*)source + 12))->f;
        ((Cell*)(base + 64))->f = (f32)((Cell*)((u8*)source + 20))->h;
    }
    return result;
}
