#include "../common/types.h"
extern "C" u8 D_0034ef18[];
extern "C" u8 D_01c60cd8[];
extern "C" void func_0031ee68(u32 a0, u32 a1);
extern "C" void func_0018e040(u8*);
extern "C" void func_001c0058(u32);
extern "C" s32 func_001c0248(u8*);
extern "C" u32 func_00105110(...);

u32 func_0018d590(u8* object) {
    *(u8**)object = D_0034ef18;
    u8* first = *(u8**)(object + 0x8);
    if (first != 0) {
        *(s32*)(first + 0x488) -= 1;
    }
    u8* second = *(u8**)(object + 0x10);
    if (second != 0) {
        *(s32*)(second + 0x488) -= 1;
    }
    func_0031ee68((u32)D_01c60cd8, (u32)object);
    if ((*(u32*)(object + 0x4) & 0x400) == 0) {
        func_0018e040(object);
        func_001c0058(*(u32*)(object + 0x1c));
    }
    func_001c0248(object + 0x30);
    return func_00105110(object);
}
