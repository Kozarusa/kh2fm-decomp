#include "../common/types.h"
typedef s32 (*Method)(void*);
struct Interface { Method* table; };
extern "C" f32 D_00349e10;
extern "C" void func_0013f5f0(u8*);
extern "C" u32 func_00167f18(s32);
extern "C" s32 func_0013ff08(f32, u8*, u32);
extern "C" s32 func_00140370(u8*, s32);
extern "C" void func_00140210(f32, u8*, u32);
extern "C" void func_0013f828(u32);
extern "C" u32 func_0013f888(...);
extern "C" u32 func_0013fca8(s32);

u32 func_001403b0(u8* object) {
    s32 result = 0;
    func_0013f5f0(object);
    u32 state = func_00167f18(0);
    f32 scale = D_00349e10;
    Interface* target = *(Interface**)(object + 68);
    if (target->table[16](target) != 0) {
        result = func_0013ff08(scale, object, state);
    }
    result = func_00140370(object, result);
    if (result == 0 && object[58] == 1) {
        func_00140210(scale, object, state);
    }
    func_0013f828((u32)object);
    func_0013f888(object, object + 128, result);
    return func_0013fca8((s32)object);
}
