#include "../common/types.h"
extern "C" u8* func_001050d8(u32);
extern "C" void func_002cb5d8(f32, u8*);
extern "C" void func_002cd290(u8*, s32, s32);

u8* func_002cd1d8(s32 arg1, s32 arg2) {
    u8* object = func_001050d8(160);
    func_002cb5d8(8.0f, object);
    object[134] = 0;
    *(s32*)(object + 12) = 32;
    *(u8**)(object + 128) = func_001050d8(1024);
    object[135] = 1;
    func_002cd290(object, arg1, arg2);
    return object;
}
