#include "../common/types.h"
extern "C" void func_001666a0(void);

struct Object {
    u8 pad[0x1d0];
    u32 field1D0;
    u16 field1D4;
    u8 field1D6;
    u8 field1D7;
    u8 field1D8;
    u8 field1D9;
};

void func_0014dbc8(Object* object) {
    func_001666a0();
    object->field1D0 = 0;
    object->field1D4 = 0;
    object->field1D6 = 0;
    object->field1D7 = 0;
    object->field1D8 = 0;
    object->field1D9 = 0;
}

