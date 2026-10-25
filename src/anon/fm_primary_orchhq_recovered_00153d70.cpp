#include "../common/types.h"
extern "C" u8 D_0035eb98[];
extern "C" u8 D_0034a7c0[];
extern "C" u8* func_0023ee30(s32);
extern "C" void func_002369a0(u8*);
extern "C" void func_0023c008(u8*);
extern "C" void func_00153cc8(u8*, s32, s32, s32, s32);
extern "C" u32 func_0013a9d0(...);
extern "C" void func_00236bb8(f32 value, s32 object);

u8* func_00153d70(s32 name, s32 size) {
    u8* object = func_0023ee30(164);
    *(s32*)(object + 12) = 0;
    *(u8**)(object + 0) = D_0035eb98;
    func_002369a0(object + 24);
    func_0023c008(object + 48);
    *(u8**)(object + 0) = D_0034a7c0;
    func_00153cc8(object, name, 4800, size, 0);
    if (func_0013a9d0()) {
        func_00236bb8(1.0f, (s32)(object + 24));
    }
    return object;
}
