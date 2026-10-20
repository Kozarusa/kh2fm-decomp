#include "../common/types.h"
extern "C" f32 D_00349e10;
extern "C" u8* func_00167f18(s32);
extern "C" void func_0013fd78(u8*);
extern "C" void func_0013fdf0(u8*, u8*, f32);
extern "C" f32 func_0013fd10(u8*);

void func_001585e8(u8* object) {
    u8* state = func_00167f18(0);
    f32 value = D_00349e10;
    if ((*(u64*)(state + 8) & 0x20000) != 0) {
        func_0013fd78(object);
    } else {
        func_0013fdf0(object, state, value);
    }
    f32 result = func_0013fd10(object);
    *(f32*)(object + 0x4c) = result;
    *(f32*)(object + 0x50) = result;
}
