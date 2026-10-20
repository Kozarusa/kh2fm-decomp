#include "../common/types.h"
extern "C" u32 func_0016adc8(...);
extern "C" void func_0016aeb8(void*, f32);

struct Vec4 {
    f32 x, y, z, w;
} __attribute__((aligned(16)));

void func_0016ae18(u8* object) {
    Vec4 vector = *(Vec4*)(object + 0x890);
    func_0016adc8(object, &vector);
    func_0016aeb8(object, *(f32*)(object + 0x89c));
}
