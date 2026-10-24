#include "../common/types.h"

extern "C" u8 D_00348590[];
extern "C" u8 D_00347e60[];
extern "C" u8 D_00347f98[];
extern "C" u32 D_00347f80;
extern "C" s32 func_00239870(u8*);

typedef s32 (*Callback)(u32, u32);

s32 func_0031b0c0(u8* object) {
    u8* self = object;
    *(u32*)self = (u32)D_00348590;
    *(u32*)(self + 260) = (u32)D_00347e60;
    func_00239870(self + 284);
    *(u32*)(self + 260) = (u32)D_00347f98;
    *(u32*)self = (u32)D_00347f98;

    u32 base = *(u32*)(u32)&D_00347f80;
    u32 receiver = *(u32*)(base + 20);
    register Callback callback asm("$15") = (Callback)*(u32*)(*(u32*)receiver + 4); // why: original loads the callback into t7, not the return register
    return callback(receiver, (u32)self);
}
