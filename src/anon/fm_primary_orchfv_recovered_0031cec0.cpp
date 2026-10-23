#include "../common/types.h"
extern "C" u8 D_0034a800[];
extern "C" u8 D_00347e60[];
extern "C" u8 D_00347f98[];
extern "C" void func_002361d0(u8*);
extern "C" s32 func_00239870(u8*);

s32 func_0031cec0(u8* object) {
    *(u8**)object = D_0034a800;
    func_002361d0(object + 0x1a0);
    *(u8**)object = D_00347e60;
    s32 result = func_00239870(object + 0x18);
    *(u8**)object = D_00347f98;
    return result;
}
