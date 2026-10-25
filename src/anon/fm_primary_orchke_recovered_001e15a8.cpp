#include "../common/types.h"
struct Object {
    u8 pad0[0x24];
    s32 state;
    f32 timer;
};
extern "C" u32 D_0034e948;
extern "C" f32 D_0036e8dc;
extern "C" f32 D_00349e10;
extern "C" u32 func_0017df58(s32);
extern "C" void func_001e1500(Object*);
extern "C" s32 func_001e1350(Object*, u32);

s32 func_001e15a8(Object* object) {
    func_001e1500(object);
    s32 result = func_001e1350(object, D_0034e948);
    if (result != 0) {
        return result;
    }
    result = func_001e1350(object, func_0017df58(0));
    if (result == 0) {
        f32 timer = object->timer;
        f32* limit = &D_0036e8dc;
        asm("" : "+r"(limit)); // why: original materializes the full address of D_0036e8dc before the load
        if (*limit <= timer) {
            object->timer = 0.0f;
            object->state = 6;
        } else {
            object->timer = timer + D_00349e10;
        }
    }
    return result;
}
