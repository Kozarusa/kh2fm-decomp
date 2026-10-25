#include "../common/types.h"
extern "C" u8 D_0032bb30[];
extern "C" u8* D_00352130;
extern "C" u32 D_003638d0;
extern "C" f32 D_0036d884;
extern "C" u64 func_0017df58(...);
extern "C" u64 func_0017e280(...);
extern "C" u64 func_0019ba60(...);
extern "C" f32 func_002f8b30(f32, f32);

void func_001aefa0(u8* object) {
    s32 index = 0;
    do {
        u64 member = func_0017df58(index);
        index++;
        if (func_0019ba60(member) != 0 && func_0017e280(member) == 0) {
            return;
        }
    } while (index < 2);
    u8* table = D_0032bb30;
    f32 power = func_002f8b30(*(f32*)(D_00352130 + 0xd8), (f32)*(u16*)(table + 0x3db0));
    f32 limit = *(f32*)(D_00352130 + 0xdc);
    f32 chance = (limit < power) ? func_002f8b30(*(f32*)(D_00352130 + 0xd8), (f32)*(u16*)(table + 0x3db0)) : limit;
    D_003638d0 *= 0x10dcd;
    f32 roll = (f32)D_003638d0;
    f32* scale = &D_0036d884;
    asm("" : "+r"(scale)); // why: original materializes the full D_0036d884 address (lui+addiu) after the conversion, before lwc1 0(t7)
    if (roll * *scale < chance) {
        object[12] = 1;
    }
}
