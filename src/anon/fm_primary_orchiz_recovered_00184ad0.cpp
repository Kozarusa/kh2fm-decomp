#include "../common/types.h"
extern "C" f32 D_00349e10;
extern "C" bool func_0019c400(u8*);
extern "C" f32 func_002f8ad0(f32, f32);
extern "C" f32 func_0017ce10(f32);
extern "C" void func_0016aeb8(u32,f32);

s32 func_00184ad0(u8* object, f32* vector, f32 speed) {
    s32 result = 1;
    if (func_0019c400(object)) {
        return 0;
    }
    if (speed == 0.0f) {
        speed = *(f32*)(object + 284);
    }
    speed = speed * D_00349e10;
    f32 angle = func_002f8ad0(vector[0], vector[2]);
    f32 delta = func_0017ce10(angle - *(f32*)(object + 1372));
    f32 target;
    if (speed < delta) {
        target = func_0017ce10(*(f32*)(object + 1372) + speed);
    } else if (delta < -speed) {
        target = func_0017ce10(*(f32*)(object + 1372) - speed);
    } else {
        target = angle;
        result = 0;
    }
    func_0016aeb8((u32)object, target);
    return result;
}
