#include "../common/types.h"

extern "C" void func_0031a838(u32);
extern "C" void func_00239700(u32);
extern "C" s32 func_0014b920(u32);
extern "C" char D_00347f98;
extern "C" char D_00347e60;
extern "C" char D_0034a440;

s32 func_0031be70(u32* object) {
    object[0] = (u32)(long)&D_00347f98;
    func_0031a838((u32)(long)(object + 3));
    object[0] = (u32)(long)&D_00347e60;
    func_00239700((u32)(long)(object + 6));
    object[0x66] = 0;
    object[0] = (u32)(long)&D_0034a440;
    func_0014b920((u32)(long)(object + 0x70));
    return func_0014b920((u32)(long)(object + 0x78));
}
