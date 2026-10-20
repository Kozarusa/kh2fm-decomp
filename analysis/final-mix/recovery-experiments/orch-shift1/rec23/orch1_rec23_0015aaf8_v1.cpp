#include "../common/types.h"
struct Object;
struct VTable {
    u8 pad[20];
    void (*method)(Object*);
};
struct Object {
    VTable* vtable;
    u8 pad[24];
    f32 timer;
};
extern "C" bool func_00197920(...);
extern "C" f32 D_00349e14;

void func_0015aaf8(Object* object) {
    if (func_00197920(object)) {
        object->vtable->method(object);
        return;
    }
    if (object->timer <= 0.0f) {
        object->vtable->method(object);
    }
    object->timer = object->timer - D_00349e14;
}
