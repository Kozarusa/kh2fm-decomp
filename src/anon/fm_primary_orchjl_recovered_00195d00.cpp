#include "../common/types.h"
struct Object;
typedef s32 (*Finish)(Object*, u8*);
typedef s32 (*Fallback)(Object*, u8*, s32);
struct Object {
    void** methods;
};
extern "C" u8 D_00195c80[];
extern "C" s32 func_00143448(u16);
extern "C" void func_0017f488(u8*, s32, f32, f32);
extern "C" s32 func_0017f5e0(u8*, s32, s32, f32, f32);

s32 func_00195d00(Object* object, u8* actor) {
    s32 result;
    f32 zero = 0.0f;
    if (*(f32*)(actor + 0x14) < zero) {
        u8* motion = actor + 0x140;
        func_0017f488(motion, 8, zero, zero);
        func_0017f5e0(motion, 4, (s32)D_00195c80, zero, zero);
        register Finish finish asm("$15") = (Finish)object->methods[1]; // why: original calls through t7, not v0
        result = finish(object, actor);
    } else {
        result = func_00143448(*(u16*)(actor + 0xb34));
        if (result == 0) {
            register Fallback fallback asm("$14") = (Fallback)object->methods[8]; // why: original calls through t6, not v0
            result = fallback(object, actor, 0);
        }
    }
    return result;
}
