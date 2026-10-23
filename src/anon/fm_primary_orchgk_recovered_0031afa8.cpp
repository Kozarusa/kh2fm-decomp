#include "../common/types.h"
extern "C" u8 D_003485b0[];
extern "C" u8 D_00347e60[];
extern "C" u8 D_00347f98[];
extern "C" s32 func_00239870(u8*);

s32 func_0031afa8(u8* object) {
    *(u8**)object = D_003485b0;
    func_00239870(object + 0x1b4);
    *(u8**)object = D_00347e60;
    s32 result = func_00239870(object + 24);
    *(u8**)object = D_00347f98;
    return result;
}
