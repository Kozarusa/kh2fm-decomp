#include "../common/types.h"
extern "C" u8 D_00347e60[];
extern "C" u8 D_0035f420[];
extern "C" s32 func_00239700(u32);
extern "C" s32 func_0028d188(u8*);

// Preserve original registry aliases.
s32 func_0028d140(u8* object) asm("_ZN2Tz8ItemStatC1Ev");

s32 func_0028d140(u8* object) {
    *(u32*)(object + 12) = 0;
    *(u8**)object = D_00347e60;
    func_00239700((u32)(object + 24));
    *(u8**)object = D_0035f420;
    return func_0028d188(object);
}
