#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u8 D_01d498d0[];
extern "C" f32 D_0036df90;
extern "C" u64 func_00143928(...);

void func_001c7148(u8* source) {
    u8* dest = D_01d498d0;
    if (source != dest) {
        *(Quad*)dest = *(Quad*)source;
    }
    u8* owner = *(u8**)(source + 0x4c);
    *(f32*)(dest + 4) = *(f32*)(dest + 4) + *(f32*)(owner + 4);
    *(f32*)(dest + 12) = D_0036df90;
    if (source + 0x30 != dest + 0x10) {
        *(Quad*)(dest + 0x10) = *(Quad*)(source + 0x30);
    }
    *(f32*)(dest + 28) = D_0036df90;
    func_00143928(dest);
}