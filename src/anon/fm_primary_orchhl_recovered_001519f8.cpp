#include "../common/types.h"
extern "C" u32 func_00138c68(...);
extern "C" u32 func_0023aa98(...);
extern "C" f32 func_00151690(u8* object);
extern "C" void func_00239f18(u8* object, f32 value);

u32 func_001519f8(u8* object) {
    u8* first = object + 1272;
    u8* second = object + 1680;
    u8* sprite = object + 2064;
    f32 scale = (f32)(s32)func_0023aa98(object + 2088);
    func_00239f18(first, func_00151690(object));
    f32 offset = func_00151690(object);

         func_00239f18(second, 1.0f - offset);
    return func_00138c68(sprite, (s32)(func_00151690(object) * scale), 0);
}
