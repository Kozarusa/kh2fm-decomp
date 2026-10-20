#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u32 func_0016adc8(...);
extern "C" void func_0016aeb8(u8*, f32);

void func_0016ae18(u8* object) {
    Quad vector = *(Quad*)(object + 0x890);
    func_0016adc8(object, &vector);
    func_0016aeb8(object, *(f32*)(object + 0x89c));
}
