#include "../common/types.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern "C" u32 func_0016adc8(...);
extern "C" void func_0016aeb8(void*, f32);

struct Object {
    u8 pad[0x890];
    Quad position;
};

void func_0016ae18(Object* object) {
    Quad vector = object->position;
    func_0016adc8(object, &vector);
    func_0016aeb8(object, ((f32*)&object->position)[3]);
}
