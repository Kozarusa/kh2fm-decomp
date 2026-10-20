#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u8 D_01d498d0[];
extern "C" f32 D_0036df90;
extern "C" u64 func_00143928(...);

void func_001c7148(u8* source) {
    u8* dest = D_01d498d0;
    u8* owner;
    if (source != dest) {
        *(Quad*)dest = *(Quad*)source;
    }
    owner = *(u8**)(source + 0x4c);
    f32 constant = D_0036df90;
    *(f32*)(dest + 4) = *(f32*)(dest + 4) + *(f32*)(owner + 4);
    source = source + 0x30;
    *(f32*)(dest + 12) = constant;
    if (source != dest + 0x10) {
        *(Quad*)(dest + 0x10) = *(Quad*)source;
    }
    *(f32*)(dest + 28) = constant;
    func_00143928(dest);
}