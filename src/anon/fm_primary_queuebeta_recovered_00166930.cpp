#include "../common/types.h"
extern "C" void func_001666a0(void);
struct Object { u8 pad[10]; u16 field0A; u16 field0C; u8 field0E; };
void func_00166930(Object* object) {
    func_001666a0();
    object->field0C = 0;
    object->field0E = 1;
    object->field0A = 0;
}
