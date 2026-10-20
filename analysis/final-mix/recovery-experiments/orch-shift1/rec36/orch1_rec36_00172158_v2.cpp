#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u32 func_0017c4c8(...);
extern "C" void func_0017f488(s32, s32, f32, f32);

struct Args {
    s32* owner;
    Quad* vector;
    s32 index;
    f32 scale;
    s32 flag;
};

void func_00172158(Args* object) {
    u8* target = (u8*)object->owner[1];
    Quad vector = *object->vector;
    func_0017c4c8(target, &vector);
    func_0017f488((s32)(target + 320), object->index, object->scale, 0.0f);
    if (object->flag != 0) {
        s32 index = object->index;
        *(s32*)(target + 260) = index + 2;
        *(s32*)(target + 256) = index + 1;
    }
}

