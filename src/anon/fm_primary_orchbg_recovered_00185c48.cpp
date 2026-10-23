#include "../common/types.h"
extern "C" f32 D_00349e10;
extern "C" u32 func_00188758(u8*);
extern "C" void func_00187750(u8*);

void func_00185c48(u8* object) {
    if (func_00188758(object + 0x300) != 0 && (*(u32*)(object + 0x39c) & 4) == 0 && *(f32*)(object + 0xaf0) > 0.0f) {
        f32 value = *(f32*)(object + 0xaf0) - D_00349e10;
        *(f32*)(object + 0xaf0) = value;
        if (value < 0.0f) {
            *(f32*)(object + 0xaf0) = 0.0f;
        }
    }
    func_00187750(object);
}
