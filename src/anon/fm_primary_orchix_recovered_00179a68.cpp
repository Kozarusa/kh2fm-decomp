#include "../common/types.h"
extern "C" u8* D_00352130;
extern "C" s32 func_00177860(...);
extern "C" u64 func_001a1de0(u32);
extern "C" f32 func_001bbfd0(void);
extern "C" void func_001a1aa0(u8*, s32);
extern "C" void func_001a1b68(u8*, f32);

void func_00179a68(u8* object, f32 scale) {
    u8* other = *(u8**)(object + 0x48c);
    switch (other[0x1af]) {
    case 1: {
        u8* base;
        if (func_001a1de0((u32)other) != 0) {
            base = D_00352130;
            scale = scale * (*(f32*)(base + 0x78) * *(f32*)(func_00177860(object) + 0x3c));
        }
        scale = scale * func_001bbfd0();
        func_001a1aa0(*(u8**)(object + 0x48c), (s32)scale);
        break;
    }
    case 2:
        if ((*(s32*)(object + 0xb50) ^ 0xc) == 0) {
            break;
        }
    case 3:
        func_001a1b68(other, scale * *(f32*)(D_00352130 + 0x70));
        break;
    }
}
