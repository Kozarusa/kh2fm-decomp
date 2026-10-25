#include "../common/types.h"
// Callee declarations copied from accepted callers: 00103570 (fm_primary_orchkx_recovered_00242f00.cpp),
// 001063c0 (fm_primary_orchjd_recovered_00287ed8.cpp), 00239700 (fm_primary_orchfv_recovered_0031be70.cpp).
extern "C" u32 func_00103570();
extern "C" s32 func_001063c0(u32, u32);
extern "C" void func_00239700(u32);
extern "C" s32 D_0035f608;
extern "C" s32 D_0035f60c;
extern "C" u8 D_00347e60[];
extern "C" u8 D_00347e40[];

void func_002a8948(void) {
    s32 count = 9;
    D_0035f608 = func_001063c0(772, func_00103570());
    s32 base = func_001063c0(4360, func_00103570());
    u32* object = (u32*)base;
    do {
        object[3] = 0;
        object[0] = (u32)D_00347e60;
        count--;
        func_00239700((u32)(object + 6));
        object[0] = (u32)D_00347e40;
        object[102] = 0;
        object += 109;
    } while (count != -1);
    D_0035f60c = base;
}
