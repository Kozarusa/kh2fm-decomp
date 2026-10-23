#include "../common/types.h"
extern "C" void func_001ac378(u8*, s32, s32, s32, s32, s32, s32);
extern "C" void func_001aa668(u8*, u8*);
extern "C" u8 D_00350bf0[];

void func_001ac8b0(u8* object, s32 value) {
    func_001ac378(object, 4, 3, value, 0, 256, 365);
    *(s32*)(object + 100) = 4;
    *(u8**)object = D_00350bf0;
    func_001aa668(object + 12, object);
}
