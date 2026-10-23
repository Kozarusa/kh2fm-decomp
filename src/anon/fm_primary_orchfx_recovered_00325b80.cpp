#include "../common/types.h"
extern "C" u8 D_003638a8[];
extern "C" u8 D_003637e0[];
extern "C" void func_002361d0(u8*);
extern "C" s32 func_00239870(u8*);
extern "C" s32 func_00106420(u8*);

s32 func_00325b80(u8* object) {
    *(u8**)object = D_003638a8;
    func_00239870(object + 0x1d4);
    func_002361d0(object + 0x30);
    *(u8**)object = D_003637e0;
    return func_00106420(object);
}
