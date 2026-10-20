#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" f32 func_0016c460(s32, s32);

f32* func_0017c030(f32* destination, u8* object, s32 argument, u8 flag) {
    if (destination != (f32*)(object + 0x10)) {
        *(Quad*)destination = *(Quad*)(object + 0x10);
    }
    destination[1] = func_0016c460((s32)object, argument);
    if (flag != 0) {
        *(u32*)(object + 0x108) = *(u32*)(object + 0x108) | 0x10000;
    }
    return destination;
}