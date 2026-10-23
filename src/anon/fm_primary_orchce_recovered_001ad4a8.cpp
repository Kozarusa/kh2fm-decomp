#include "../common/types.h"
extern "C" void func_001ac970(u8*, s32, s32, s32, s32, s32, s32, s32);
extern "C" void func_001ac078(u8*, s32, s32, s32);
extern "C" void func_001aa388(u8*, s32);
extern "C" u8 D_00350b30[];

void func_001ad4a8(u8* object, s32 value) {
    func_001ac970(object, 3, 5, value, 0, 256, 336, 0);
    *(s32*)(object + 104) = 0;
    *(s32*)(object + 100) = 3;
    *(u8**)object = D_00350b30;
    func_001ac078(object + 1196, 1, 1, 0);
    object = object + 12;
    func_001aa388(object, *(s32*)(object + 12));
}
